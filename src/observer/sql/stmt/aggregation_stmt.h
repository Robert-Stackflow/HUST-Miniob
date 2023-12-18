// created by NieYang on 2023/10/19

#pragma once

#include <vector>
#include <unordered_map>
#include "sql/parser/parse_defs.h"
#include "sql/stmt/stmt.h"
#include "sql/expr/expression.h"

class FieldMeta;

class AggrFuncUnit
{
public:
  AggrFuncUnit() = default;
  ~AggrFuncUnit(){};

  AggrFuncType type() const { return type_; }
  void         setType(AggrFuncType type) { type_ = type; }
  RC           add_field(Field *&field);
  bool         exist(Field *&field)
  {
    if (aggr_field_ == nullptr) {
      return false;
    } else {
      if (0 == strcmp(field->table_name(), aggr_field_->table_name()) &&
          0 == strcmp(field->field_name(), aggr_field_->field_name())) {
        return true;
      } else {
        return false;
      }
    }
    return false;
  }
  Field           *aggr_fields() { return aggr_field_; }
  AggregationExpr *get_aggr_expr() { return new AggregationExpr(*aggr_field_, type_); }
  bool             check_all_field(Field *field);
  bool             is_all_field() { return all_field_; }

private:
  AggrFuncType type_;
  Field       *aggr_field_ = nullptr;
  bool         all_field_  = false;
};

class AggrStmt
{
public:
  AggrStmt() = default;
  virtual ~AggrStmt()
  {
  }

public:

public:
  static RC create_aggr_func_item(Db *db, Table *default_table, std::unordered_map<std::string, Table *> *tables,
      AggrFuncSqlNode &aggr_func_sql_node, AggrFuncUnit *&aggr_func_item);

private:
};
