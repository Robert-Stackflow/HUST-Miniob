//
// Created by NieYang on 2023/10/20.
//

#pragma once

#include "sql/operator/logical_operator.h"
#include "sql/expr/expression.h"
#include "sql/stmt/order_stmt.h"

class Expression;
class OrderUnit;
class OrderStmt;

/**
 * @brief Order逻辑算子
 * @ingroup LogicalOperator
 */
class OrderLogicalOperator : public LogicalOperator 
{
public:
  OrderLogicalOperator(std::vector<OrderStmt*> stmts){
    std::vector<OrderUnit*> orders;
    for(auto stmt:stmts){
      orders.push_back(stmt->order_unit());
    }
    orders_.swap(orders);
  }
  OrderLogicalOperator(std::vector<OrderUnit*> orders);
  virtual ~OrderLogicalOperator() = default;

  LogicalOperatorType type() const override
  {
    return LogicalOperatorType::ORDER_BY;
  }

  std::vector<OrderUnit*>& orders()
  {
    return orders_;
  }

private:
  std::vector<OrderUnit*> orders_;
};
