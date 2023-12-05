//
// Created by NieYang on 2023/10/16.
//

#pragma once

#include "sql/operator/physical_operator.h"

class Trx;
class DeleteStmt;

/**
 * @brief Update物理算子
 * @ingroup PhysicalOperator
 */
class UpdatePhysicalOperator : public PhysicalOperator
{
public:
  UpdatePhysicalOperator(Table *table, Value *value, std::string field) : table_(table), value_(value), field_(field)
  {}

  virtual ~UpdatePhysicalOperator() = default;

  PhysicalOperatorType type() const override
  {
    return PhysicalOperatorType::UPDATE;
  }

  RC open(Trx *trx) override;
  RC next() override;
  RC close() override;

  Tuple *current_tuple() override
  {
    return nullptr;
  }

private:
  Table *table_ = nullptr;
  Value *value_ = nullptr;
  std::string field_;
  Trx *trx_ = nullptr;
};