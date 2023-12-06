//
// Created by NieYang on 2023/10/20.
//

#pragma once

#include "sql/operator/physical_operator.h"
#include "storage/record/record_manager.h"
#include "common/rc.h"
#include <memory>

using namespace std;
class Table;

/**
 * @brief 聚合物理算子
 * @ingroup LogicalOperator
 */
class AggrPhysicalOperator : public PhysicalOperator
{
public:
    AggrPhysicalOperator(std::vector<Expression*> expressions)
        :expressions_(expressions)
    {}

    virtual ~AggrPhysicalOperator()
    {
        for (Expression* ptr : expressions_) {
            if (ptr != nullptr)
                delete ptr;
        }
    }

    PhysicalOperatorType type() const override
    {
        return PhysicalOperatorType::AGGREGATION;
    }
    
    RC open(Trx *trx) override;
    RC next() override;
    RC close() override;

    Tuple *current_tuple() override;
private:
    std::vector<Expression*> expressions_;//一系列聚合操作一起进行
    int index_ = 0;
    ValueListTuple aggred_tuple_;
};