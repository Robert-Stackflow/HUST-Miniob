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
// Created by Wangyunlai on 2023/6/13.
//

#include "sql/stmt/create_table_stmt.h"
#include "event/sql_debug.h"

RC CreateTableStmt::create(Db *db, const CreateTableSqlNode &create_table, Stmt *&stmt)
{
  CreateTableSqlNode tmp;
  tmp.relation_name=create_table.relation_name;
  for (auto attr : create_table.attr_infos) {
    AttrInfoSqlNode node;
    node.name=attr.name;
    node.nullable=attr.nullable;
    node.type=attr.type;
    node.length = attr.length > 5 ? attr.length : 5;
    if(node.type==DATES)
      node.length=10;
    tmp.attr_infos.emplace_back(node);
  }
  stmt = new CreateTableStmt(tmp.relation_name, tmp.attr_infos);
  sql_debug("create table statement: table name %s", tmp.relation_name.c_str());
  return RC::SUCCESS;
}
