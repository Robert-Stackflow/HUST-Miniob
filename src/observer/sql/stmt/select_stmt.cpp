/* Copyright (c) 2021 OceanBase and/or its affiliates. All rights reserved.
miniob is licensed under Mulan PSL v2.
You can use this software according to the terms and conditions of the Mulan PSL v2.
You may obtain a copy of Mulan PSL v2 at:
         http://license.coscl.org.cn/MulanPSL2
THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
See the Mulan PSL v2 for more details. */

//
// Created by Wangyunlai on 2022/6/6.
//

#include "sql/stmt/select_stmt.h"
#include "sql/stmt/filter_stmt.h"
#include "common/log/log.h"
#include "common/lang/string.h"
#include "sql/stmt/aggregation_stmt.h"
#include "storage/db/db.h"
#include "storage/table/table.h"
#include "sql/stmt/join_stmt.h"
#include "sql/stmt/order_stmt.h"
#include "sql/stmt/group_stmt.h"

SelectStmt::~SelectStmt()
{
  if (nullptr != filter_stmt_) {
    delete filter_stmt_;
    filter_stmt_ = nullptr;
  }
}

static void wildcard_fields(Table *table, std::vector<Field> &field_metas)
{
  const TableMeta &table_meta = table->table_meta();
  const int field_num = table_meta.field_num();
  for (int i = table_meta.sys_field_num(); i < field_num; i++) {
    field_metas.push_back(Field(table, table_meta.field(i)));
  }
}

static void wildcard_query_exprs(Table *table, std::vector<Expression *> &expressions)
{
  const TableMeta &table_meta = table->table_meta();
  const int field_num = table_meta.field_num();
  for (int i = table_meta.sys_field_num(); i < field_num; i++) {
    expressions.emplace_back(new FieldExpr(Field(table, table_meta.field(i))));
  }
}

RC SelectStmt::create(Db *db, const SelectSqlNode &select_sql, Stmt *&stmt)
{
  if (nullptr == db) {
    LOG_WARN("invalid argument. db is null");
    return RC::INVALID_ARGUMENT;
  }

  std::vector<Table *> tables;
  std::unordered_map<std::string, Table *> table_map;
  
  // 检查所有表是否存在
  for (size_t i = 0; i < select_sql.relations.size(); i++) {
    const char *table_name = select_sql.relations[i].c_str();
    if (nullptr == table_name) {
      LOG_WARN("invalid argument. relation name is null. index=%d", i);
      return RC::INVALID_ARGUMENT;
    }

    Table *table = db->find_table(table_name);
    if (nullptr == table) {
      LOG_WARN("no such table. db=%s, table_name=%s", db->name(), table_name);
      return RC::SCHEMA_TABLE_NOT_EXIST;
    }

    tables.push_back(table);
    table_map.insert(std::pair<std::string, Table *>(table_name, table));
  }

  // 检查join的所有表是否存在
  for (size_t i = 0; i < select_sql.joins.size(); i++) {
    const char *table_name = select_sql.joins[i].relation.c_str();
    LOG_WARN("Relation name is %s", table_name);
    if (nullptr == table_name) {
      LOG_WARN("invalid argument. relation name is null. index=%d", i);
      return RC::INVALID_ARGUMENT;
    }

    Table *table = db->find_table(table_name);
    if (nullptr == table) {
      LOG_WARN("no such table. db=%s, table_name=%s", db->name(), table_name);
      return RC::SCHEMA_TABLE_NOT_EXIST;
    }

    tables.push_back(table);
    table_map.insert(std::pair<std::string, Table *>(table_name, table));
  }

  std::vector<Expression *> query_exprs;
  int num_attr = 0; // 属性数
  int num_aggr = 0; // 聚合数
  for (int i = static_cast<int>(select_sql.select_exprs.size()) - 1; i >= 0; i--) {
    const SelectExprSqlNode &s_expr_node = select_sql.select_exprs[i];
    if (s_expr_node.type == AGGR_FUNC_SELECT_T) {
      Table *default_table = nullptr;
      if (tables.size() == 1) {
        default_table = tables[0];
      }
      AggrFuncUnit *aggr_unit = nullptr;

      RC rc = AggrStmt::create_aggr_func_item(db,
        default_table,
        &table_map,
        *s_expr_node.aggrfunc,
        aggr_unit);
      if (rc != RC::SUCCESS) {
        return rc;
      }
      query_exprs.emplace_back(aggr_unit->get_aggr_expr());
      num_aggr++;
      continue;
    }else if (s_expr_node.type == REL_ATTR_SELECT_T){
      num_attr++;
      const RelAttrSqlNode &relation_attr = *s_expr_node.attribute;
      if (common::is_blank(relation_attr.relation_name.c_str()) &&
          0 == strcmp(relation_attr.attribute_name.c_str(), "*")) {
        for (Table *table : tables) {
          wildcard_query_exprs(table, query_exprs);
        }
      }else if (!common::is_blank(relation_attr.relation_name.c_str())) {
        const char *table_name = relation_attr.relation_name.c_str();
        const char *field_name = relation_attr.attribute_name.c_str();
        if (0 == strcmp(table_name, "*")) {
          if (0 != strcmp(field_name, "*")) {
            LOG_WARN("invalid field name while table is *. attr=%s", field_name);
            return RC::SCHEMA_FIELD_MISSING;
          }
          for (Table *table : tables) {
            wildcard_query_exprs(table, query_exprs);
          }
        } else {
          auto iter = table_map.find(table_name);
          if (iter == table_map.end()) {
            LOG_WARN("no such table in from list: %s", table_name);
            return RC::SCHEMA_FIELD_MISSING;
          }

          Table *table = iter->second;
          if (0 == strcmp(field_name, "*")) {
            wildcard_query_exprs(table, query_exprs);
          } else {
            const FieldMeta *field_meta = table->table_meta().field(field_name);
            if (nullptr == field_meta) {
              LOG_WARN("no such field. field=%s.%s.%s", db->name(), table->name(), field_name);
              return RC::SCHEMA_FIELD_MISSING;
            }
            query_exprs.emplace_back(new FieldExpr(Field(table, field_meta)));
          }
        }
      } else {
        if (tables.size() != 1) {
          LOG_WARN("invalid. I do not know the attr's table. attr=%s", relation_attr.attribute_name.c_str());
          return RC::SCHEMA_FIELD_MISSING;
        }
        Table *table = tables[0];
        const FieldMeta *field_meta = table->table_meta().field(relation_attr.attribute_name.c_str());
        if (nullptr == field_meta) {
          LOG_WARN("no such field. field=%s.%s.%s", db->name(), table->name(), relation_attr.attribute_name.c_str());
          return RC::SCHEMA_FIELD_MISSING;
        }
        query_exprs.emplace_back(new FieldExpr(Field(table, field_meta)));
      }
    }
  }

  Table *default_table = nullptr;
  if (tables.size() == 1) {
    default_table = tables[0];
  }

  // create filter statement in `where` statement
  FilterStmt *filter_stmt = nullptr;
  RC rc = FilterStmt::create(db,
      default_table,
      &table_map,
      select_sql.conditions.data(),
      static_cast<int>(select_sql.conditions.size()),
      filter_stmt);
  if (rc != RC::SUCCESS) {
    LOG_WARN("cannot construct filter stmt");
    return rc;
  }

  std::vector<JoinStmt*> join_stmts;
  for (size_t i = 0; i < select_sql.joins.size(); i++) {
    RC rc = RC::SUCCESS;
    JoinStmt* join_stmt = nullptr;
    rc = JoinStmt::create(db, default_table, &table_map, select_sql.joins[i], join_stmt);
    if (rc != RC::SUCCESS) {
      return rc;
    }
    join_stmts.push_back(join_stmt);
  }

  std::vector<OrderStmt*> orders;
  for (size_t i = 0; i < select_sql.orders.size(); i++) {
    RC rc = RC::SUCCESS;
    OrderStmt* order_stmt = nullptr;
    rc = OrderStmt::create(db, default_table, &table_map, select_sql.orders[i], order_stmt);
    if (rc != RC::SUCCESS) {
      return rc;
    }
    orders.push_back(order_stmt);
  }

  std::vector<GroupStmt*> groups;
  for (size_t i = 0; i < select_sql.groups.size(); i++) {
    RC rc = RC::SUCCESS;
    GroupStmt* group_stmt = nullptr;
    rc = GroupStmt::create(db, default_table, &table_map, select_sql.groups[i], group_stmt);
    if (rc != RC::SUCCESS) {
      return rc;
    }
    groups.push_back(group_stmt);
  }

  // everything alright
  SelectStmt *select_stmt = new SelectStmt();
  select_stmt->tables_.swap(tables);
  select_stmt->filter_stmt_ = filter_stmt;
  select_stmt->query_exprs_.swap(query_exprs);
  select_stmt->join_stmts_.swap(join_stmts);
  select_stmt->orders_.swap(orders);
  select_stmt->groups_.swap(groups);
  stmt = select_stmt;
  return RC::SUCCESS;
}