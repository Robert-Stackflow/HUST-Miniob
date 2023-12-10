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
class GroupUnit;

/**
 * @brief 聚合物理算子
 * @ingroup LogicalOperator
 */
class AggrPhysicalOperator : public PhysicalOperator
{
public:
    AggrPhysicalOperator(std::vector<Expression*> expressions,std::vector<Field> query_fields,std::vector<GroupUnit*> groups)
        :expressions_(expressions),query_fields_(query_fields),groups_(groups)
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

    RC fetch_and_split();
    RC aggr_tuples(std::vector<Tuple *> tuples,ValueListTuple & result);
    Tuple *current_tuple() override;
private:
    std::vector<Expression*> expressions_;//一系列聚合操作一起进行
    std::vector<GroupUnit*> groups_;
    std::vector<Field> query_fields_;
    std::vector<ValueListTuple> aggred_tuples_;
    int index_ = 0;
};