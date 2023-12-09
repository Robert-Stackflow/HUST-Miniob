//
// Created by NieYang on 2023/10/20.
//

#pragma once

#include "sql/operator/physical_operator.h"
#include "storage/record/record_manager.h"
#include "common/rc.h"
#include "sql/stmt/order_stmt.h"
#include <memory>

using namespace std;
class Table;

/**
 * @brief 聚合物理算子
 * @ingroup LogicalOperator
 */
class OrderPhysicalOperator : public PhysicalOperator
{
public:
    OrderPhysicalOperator(std::vector<OrderUnit*> orders)
        :orders_(orders)
    {}

    virtual ~OrderPhysicalOperator()
    {
    for (auto tuple : tuples_) {
        if (tuple) {
        delete tuple;
        }
    }
    }

    PhysicalOperatorType type() const override
    {
        return PhysicalOperatorType::ORDER_BY;
    }
    
    RC open(Trx *trx) override;
    RC next() override;
    RC close() override;
    RC fetch_and_sort_table();
    Tuple *current_tuple() override;
private:
    std::vector<OrderUnit*> orders_;
    std::vector<Tuple *>    tuples_;
    int index_ = 0;
};