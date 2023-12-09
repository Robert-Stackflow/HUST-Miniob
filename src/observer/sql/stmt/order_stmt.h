#pragma once

#include <vector>
#include <unordered_map>
#include "sql/parser/parse_defs.h"
#include "sql/stmt/stmt.h"
#include "sql/expr/expression.h"

class Db;
class Table;
class FieldMeta;


class OrderUnit 
{
public:
  OrderUnit() = default;
  ~OrderUnit()
  {}

  void set_type(OrderType type)
  {
    type_ = type;
  }
  void set_field(Field field)
  {
    field_ = field;
  }
  const OrderType &type() const
  {
    return type_;
  }
  const Field &field() const
  {
    return field_;
  }
private:
  OrderType type_;
  Field field_;
};

/**
 * @brief Order By语句
 * @ingroup Statement
 */
class OrderStmt 
{
public:
  OrderStmt() = default;
  virtual ~OrderStmt();

public:
  OrderUnit* &order_unit()
  {
    return order_unit_;
  }
  void set_unit(OrderUnit *order_unit){
    order_unit_=order_unit;
  }
public:
  static RC create(Db *db, Table *default_table, std::unordered_map<std::string, Table *> *tables,
      const OrderSqlNode &order, OrderStmt *&stmt);

private:
  OrderUnit* order_unit_;
};