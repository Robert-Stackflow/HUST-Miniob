//
// Created by NieYang on 2023/10/20.
//

#include "sql/operator/aggr_physical_operator.h"
#include "storage/table/table.h"
#include "event/sql_debug.h"
#include "sql/stmt/group_stmt.h"

std::vector<std::vector<Tuple *>> group_by_field(std::vector<Tuple *> tuples,const TupleCellSpec &tuple_schema);

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

    rc = fetch_and_split();

    return rc;
}

RC AggrPhysicalOperator::fetch_and_split() {
    RC rc = RC::SUCCESS;
    // 循环从孩子节点获取数据
    PhysicalOperator *oper = children_.front().get();
    std::vector<Tuple *> tuples;

    while (RC::SUCCESS == (rc = oper->next())) {
        Tuple* tuple = oper->current_tuple()->clone();
        tuples.push_back(tuple);
    }

    std::vector<std::vector<Tuple *>> tuples_list;

    tuples_list.push_back(tuples);

    // 分组
    for (auto &group: groups_) {
        auto table_name = group->field().table()->name();
        auto field_name = group->field().field_name();
        auto tuple_schema = TupleCellSpec(table_name, field_name);

        std::vector<std::vector<Tuple *>> tmp;

        for(auto tuples:tuples_list){
            auto splited_tuples=group_by_field(tuples,tuple_schema);
            for(auto t : splited_tuples){
                tmp.push_back(t);
            }
        }
        tuples_list.swap(tmp);
    }

    for(auto tuples:tuples_list){
        if(tuples.empty())
            continue;
        ValueListTuple aggred_tuple;
        aggr_tuples(tuples,aggred_tuple);
        aggred_tuples_.push_back(aggred_tuple);
    }

    index_ = -1;
    return RC::SUCCESS;
}

std::vector<std::vector<Tuple *>> group_by_field(std::vector<Tuple *> tuples,const TupleCellSpec &tuple_schema){
    /// 排序
    std::sort(tuples.begin(), tuples.end(), [&](Tuple *left, Tuple *right) {
        Value left_value;
        left->find_cell(tuple_schema, left_value);
        Value right_value;
        right->find_cell(tuple_schema, right_value);
        int res = left_value.compare(right_value);
        return res < 0;
    });
    /// 分割
    Value last_value(NULLS);
    Value cur_value(NULLS);
    std::vector<Tuple*> cur_tuples;
    std::vector<std::vector<Tuple *>> tuples_list;
    for(auto tuple : tuples){
        tuple->find_cell(tuple_schema,cur_value);
        if(last_value.attr_type()==NULLS || last_value.compare(cur_value)==0){
        cur_tuples.push_back(tuple);
        last_value = cur_value;
        }else if(last_value.compare(cur_value)!=0){
        std::vector<Tuple*> tmp;
        tmp.swap(cur_tuples);
        tuples_list.push_back(tmp);
        cur_tuples.push_back(tuple);
        last_value = cur_value;
        }
    }
    if(cur_tuples.size()>0){
        tuples_list.push_back(cur_tuples);
    }
    return tuples_list;
}

RC AggrPhysicalOperator::aggr_tuples(std::vector<Tuple *> tuples , ValueListTuple &result){
    Tuple *tuple = nullptr;

    for (Expression* expr: expressions_) {
        AggregationExpr *aggr_expr = static_cast<AggregationExpr *>(expr);
        aggr_expr->begin_aggr();
    }

    for(auto tuple:tuples){
        for (Expression* expr: expressions_) {
            AggregationExpr *aggr_expr = static_cast<AggregationExpr *>(expr);
            aggr_expr->aggr_tuple(tuple);
        }
    }

    std::vector<Value> results;
    std::vector<TupleCellSpec> speces;
    for (Field field: query_fields_) {
        Value value;
        FieldExpr *field_expr = new FieldExpr(field);
        field_expr->get_value(*tuples[0], value);
        results.push_back(value);
        speces.push_back(field_expr->cell_spec());
    }
    for (Expression* expr: expressions_) {
        Value value;
        AggregationExpr *aggr_expr = static_cast<AggregationExpr *>(expr);
        aggr_expr->get_result(value);
        results.push_back(value);
        speces.push_back(aggr_expr->cell_spec());
    }
    result.set_cells(results);
    result.set_speces(speces);
    return RC::SUCCESS;
}

RC AggrPhysicalOperator::next() 
{ 
    RC rc = RC::SUCCESS;

    if (index_ == aggred_tuples_.size() -1) {
        return RC::RECORD_EOF;
    }
    index_++;
    return RC::SUCCESS;
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
    return &aggred_tuples_[index_];
}
