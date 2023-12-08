// Created by NieYang on 2023/10/12

#pragma once

#include "sql/stmt/stmt.h"
#include "storage/table/table.h"

#include <memory>
#include <unordered_map>
#include "filter_stmt.h"

using namespace std;

// Join表达式
class JoinStmt 
{
public:
  JoinStmt() = default;
  ~JoinStmt() {
    if (filter_ != nullptr) {
      delete filter_;
    }
  }

public:
  FilterStmt* join_condition() 
  { 
    return filter_; 
  }
public:
    static RC create(Db *db, Table *default_table, std::unordered_map<std::string, Table *> *table_map, 
        const JoinSqlNode &sql_node, JoinStmt*&stmt);
private:
  FilterStmt* filter_ = nullptr;
};