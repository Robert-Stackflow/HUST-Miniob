//
// Created by NieYang on 2023/10/20.
//

#pragma once

#include "sql/operator/logical_operator.h"
#include "sql/expr/expression.h"
#include"sql/stmt/group_stmt.h"

class Expression;
class GroupUnit;
class GroupStmt;

/**
 * @brief 聚合逻辑算子
 * @ingroup LogicalOperator
 */
class AggregationLogicalOperator : public LogicalOperator 
{
public:
  AggregationLogicalOperator(std::vector<Expression*> expressions,std::vector<Field> query_fields,std::vector<GroupStmt*> stmts){
    select_exprs_.swap(expressions);
    std::vector<GroupUnit*> groups;
    for(auto stmt:stmts){
      groups.push_back(stmt->group_unit());
    }
    groups_.swap(groups);
    query_fields_.swap(query_fields);
  }
  AggregationLogicalOperator(std::vector<Expression*> expressions,std::vector<Field> query_fields,std::vector<GroupUnit*> groups);
  virtual ~AggregationLogicalOperator() = default;

  LogicalOperatorType type() const override
  {
    return LogicalOperatorType::AGGREGATION;
  }

  std::vector<Expression*>& select_exprs()
  {
    return select_exprs_;
  }

  std::vector<GroupUnit*>& groups()
  {
    return groups_;
  }

  std::vector<Field>& query_fields()
  {
    return query_fields_;
  }
private:
  std::vector<Expression*> select_exprs_;
  std::vector<GroupUnit*> groups_;
  std::vector<Field> query_fields_;
};
