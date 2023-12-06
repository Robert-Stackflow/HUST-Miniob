//
// Created by NieYang on 2023/10/20.
//

#include "sql/operator/aggr_logical_operator.h"

AggregationLogicalOperator::AggregationLogicalOperator(std::vector<Expression*> expressions)
  : select_exprs_(expressions)
{}
