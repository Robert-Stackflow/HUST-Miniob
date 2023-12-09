//
// Created by NieYang on 2023/10/20.
//

#include "sql/operator/order_logical_operator.h"

OrderLogicalOperator::OrderLogicalOperator(std::vector<OrderUnit*> orders)
  : orders_(orders)
{}
