#pragma once

#include <vector>
#include <unordered_map>
#include "sql/parser/parse_defs.h"
#include "sql/stmt/stmt.h"
#include "sql/expr/expression.h"

class Db;
class Table;
class FieldMeta;

class GroupUnit 
{
public:
  GroupUnit() = default;
  ~GroupUnit()
  {}

  void set_field(Field field)
  {
    field_ = field;
  }
  const Field &field() const
  {
    return field_;
  }
private:
  Field field_;
};

/**
 * @brief Order By语句
 * @ingroup Statement
 */
class GroupStmt 
{
public:
  GroupStmt() = default;
  virtual ~GroupStmt();

public:
  GroupUnit* &group_unit()
  {
    return group_unit_;
  }
  void set_unit(GroupUnit *group_unit){
    group_unit_=group_unit;
  }
public:
  static RC create(Db *db, Table *default_table, std::unordered_map<std::string, Table *> *tables,
      const GroupSqlNode &order, GroupStmt *&stmt);

private:
  GroupUnit* group_unit_;
};