//
// Created by NieYang on 2023/10/20.
//

#include "sql/operator/aggr_physical_operatior.h"
#include "storage/table/table.h"
#include "event/sql_debug.h"

RC AggrPhysicalOperator::open(Trx *trx) 
{ 
    if (children_.size() != 1) {
        LOG_WARN("aggregation operator must has one child");
        return RC::INTERNAL;
    }
    RC rc = RC::SUCCESS;
    for (int i = 0; i < children_.size(); i++) {
        if ((rc = children_[i]->open(trx)) != RC::SUCCESS) {
            return rc;
        }
    }
    return rc;
}

RC AggrPhysicalOperator::next() 
{ 
    RC rc = RC::SUCCESS;
    // group by 放置多个在 children_ 中创建分组？
    if (index_ >= children_.size()) {
        return RC::RECORD_EOF;
    }

    PhysicalOperator *oper = children_[index_++].get();
    Tuple *tuple = nullptr;

    for (Expression* expr: expressions_) {
        if (expr->type() == ExprType::AGGREGATION) {
            AggregationExpr *aggr_expr = static_cast<AggregationExpr *>(expr);
            aggr_expr->begin_aggr();
        } else {
            if (children_.size() <= 1) {  // 没有group by
                return RC::INTERNAL;
            }
        }
    }

    while (RC::SUCCESS == (rc = oper->next())) {
        tuple = oper->current_tuple();
        if (nullptr == tuple) {
            rc = RC::INTERNAL;
            LOG_WARN("failed to get tuple from operator");
            break;
        }
        for (Expression* expr: expressions_) {
            if (expr->type() == ExprType::AGGREGATION ) {
                AggregationExpr *aggr_expr = static_cast<AggregationExpr *>(expr);
                aggr_expr->aggr_tuple(tuple);
            }
        }
    }

    if (rc != RC::RECORD_EOF) {
        return RC::INTERNAL;
    }
    rc = RC::SUCCESS;

    std::vector<Value> results;
    std::vector<TupleCellSpec> speces;
    for (Expression* expr: expressions_) {
        Value value;
        if (expr->type() == ExprType::AGGREGATION) {
            AggregationExpr *aggr_expr = static_cast<AggregationExpr *>(expr);
            aggr_expr->get_result(value);
            results.emplace_back(value);
            speces.emplace_back(aggr_expr->cell_spec());
        } else if (expr->type() == ExprType::FIELD) {
            FieldExpr *field_expr = static_cast<FieldExpr *>(expr);
            field_expr->get_value(*tuple, value);
            results.emplace_back(value);
        }
    }
    aggred_tuple_.set_cells(results);
    aggred_tuple_.set_speces(speces);
    return rc;
}

RC AggrPhysicalOperator::close() 
{ 
    RC rc = RC::SUCCESS;
    for (int i = 0; i < children_.size(); i++) {
        if (children_[i]->close() != RC::SUCCESS) {
            rc = RC::INTERNAL;
        }
    }
    return rc;
}

Tuple *AggrPhysicalOperator::current_tuple() 
{ 
    return &aggred_tuple_;
}
