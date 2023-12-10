//
// Created by NieYang on 2023/10/20.
//

#include "sql/operator/aggr_logical_operator.h"

AggregationLogicalOperator::AggregationLogicalOperator(std::vector<Expression*> expressions,std::vector<Field> query_fields,std::vector<GroupUnit*> groups)
  : select_exprs_(expressions),query_fields_(query_fields),groups_(groups)
{}
