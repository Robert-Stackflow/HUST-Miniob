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
// Created by Wangyunlai on 2022/5/22.
//

#include "common/rc.h"
#include "common/log/log.h"
#include "common/lang/string.h"
#include "sql/stmt/filter_stmt.h"
#include "storage/db/db.h"
#include "storage/table/table.h"
#include "common/util.h"

FilterStmt::~FilterStmt()
{
  for (FilterUnit *unit : filter_units_) {
    delete unit;
  }
  filter_units_.clear();
}

RC FilterStmt::create(Db *db, Table *default_table, std::unordered_map<std::string, Table *> *tables,
    const ConditionSqlNode *conditions, int condition_num, FilterStmt *&stmt)
{
  RC rc = RC::SUCCESS;
  stmt = nullptr;

  FilterStmt *tmp_stmt = new FilterStmt();
  for (int i = 0; i < condition_num; i++) {
    FilterUnit *filter_unit = nullptr;
    rc = create_filter_unit(db, default_table, tables, conditions[i], filter_unit);
    if (rc != RC::SUCCESS) {
      delete tmp_stmt;
      LOG_WARN("failed to create filter unit. condition index=%d", i);
      return rc;
    }
    tmp_stmt->filter_units_.push_back(filter_unit);
  }

  stmt = tmp_stmt;
  return rc;
}

RC FilterStmt::create_filter_unit(Db *db, Table *default_table, std::unordered_map<std::string, Table *> *tables,
    const ConditionSqlNode &condition, FilterUnit *&filter_unit)
{
  RC rc = RC::SUCCESS;

  CompOp comp = condition.comp;
  if (comp < EQUAL_TO || comp >= NO_OP) {
    LOG_WARN("invalid compare operator : %d", comp);
    return RC::INVALID_ARGUMENT;
  }

  filter_unit = new FilterUnit;

  if(condition.comp==IS||condition.comp==IS_NOT){
    // 运算符为IS或IS_NOT
    // 右值只能为NULL类型的值
    if(condition.right_is_attr||condition.right_value.attr_type()!=NULLS){
      LOG_WARN("invalid right value : right value has to be null");
      return RC::INVALID_ARGUMENT;
    }
    // 设置左值
    if (condition.left_is_attr) {
      Table *table = nullptr;
      const FieldMeta *field = nullptr;
      rc = Util::get_table_and_field(db, default_table, tables, condition.left_attr, table, field);
      if (rc != RC::SUCCESS) {
        LOG_WARN("cannot find attr");
        return rc;
      }
      FilterObj filter_obj_left;
      filter_obj_left.init_attr(Field(table, field));
      filter_unit->set_left(filter_obj_left);
    }else{
      FilterObj filter_obj;
      filter_obj.init_value(condition.left_value);

      if (filter_obj.value.attr_type() == DATES && filter_obj.value.get_date() == 0)
        return RC::VARIABLE_NOT_VALID;

      filter_unit->set_left(filter_obj);
    }
    // 设置右值
    FilterObj filter_obj_right;
    filter_obj_right.init_value(condition.right_value);
    filter_unit->set_right(filter_obj_right);

    filter_unit->set_comp(condition.comp);
  }else{
    // 设置左值
    if (condition.left_is_attr) {
      Table *table = nullptr;
      const FieldMeta *field = nullptr;
      rc = Util::get_table_and_field(db, default_table, tables, condition.left_attr, table, field);
      if (rc != RC::SUCCESS) {
        LOG_WARN("cannot find attr");
        return rc;
      }
      FilterObj filter_obj;
      filter_obj.init_attr(Field(table, field));
      filter_unit->set_left(filter_obj);
    } else {
      FilterObj filter_obj;
      filter_obj.init_value(condition.left_value);
      // 检查date不合法
      if (filter_obj.value.attr_type() == DATES && filter_obj.value.get_date() == 0)
        return RC::VARIABLE_NOT_VALID;

      filter_unit->set_left(filter_obj);
    }
    // 设置右值
    if (condition.right_is_attr) {
      Table *table = nullptr;
      const FieldMeta *field = nullptr;
      rc = Util::get_table_and_field(db, default_table, tables, condition.right_attr, table, field);
      if (rc != RC::SUCCESS) {
        LOG_WARN("cannot find attr");
        return rc;
      }
      FilterObj filter_obj;
      filter_obj.init_attr(Field(table, field));
      filter_unit->set_right(filter_obj);
    } else {
      FilterObj filter_obj;
      filter_obj.init_value(condition.right_value);
      // 检查date不合法
      if (filter_obj.value.attr_type() == DATES && filter_obj.value.get_date() == 0)
        return RC::VARIABLE_NOT_VALID;

      filter_unit->set_right(filter_obj);
    }

    filter_unit->set_comp(comp);
  }
  return rc;
}
