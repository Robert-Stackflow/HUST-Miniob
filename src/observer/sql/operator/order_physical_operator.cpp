//
// Created by NieYang on 2023/10/20.
//

#include "sql/operator/order_physical_operator.h"
#include "storage/table/table.h"
#include "event/sql_debug.h"
#include "sql/stmt/order_stmt.h"

std::vector<std::vector<Tuple *>> split_tuples(std::vector<Tuple *> tuples,const TupleCellSpec &tuple_schema);

RC OrderPhysicalOperator::open(Trx *trx) {
  if (children_.empty()) {
    return RC::SUCCESS;
  }

  // 递归调用open，递归调用的目的就是将trx传给每一个算子
  RC rc = children_[0]->open(trx);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to open child operator: %s", strrc(rc));
    return rc;
  }
  rc = fetch_and_sort_table();

  return rc;
}

RC OrderPhysicalOperator::fetch_and_sort_table() {
  RC rc = RC::SUCCESS;
  // 循环从孩子节点获取数据
  PhysicalOperator *oper = children_.front().get();

  while (RC::SUCCESS == (rc = oper->next())) {
    Tuple* tuple = oper->current_tuple()->clone();
    tuples_.push_back(tuple);
  }
  for (auto &t: tuples_) {
    auto temp = t->to_string();
    int i = 1;
  }

  std::vector<std::vector<Tuple *>> tuples_list;

  tuples_list.push_back(tuples_);

  // 排序
  for (auto &order: orders_) {
    auto table_name = order->field().table()->name();
    auto field_name = order->field().field_name();
    auto tuple_schema = TupleCellSpec(table_name, field_name);
    auto order_type = order->type();

    std::vector<std::vector<Tuple *>> tmp;

    for(auto tuples:tuples_list){
      std::sort(tuples.begin(), tuples.end(), [&](Tuple *left, Tuple *right) {
        Value left_value;
        left->find_cell(tuple_schema, left_value);
        Value right_value;
        right->find_cell(tuple_schema, right_value);
        int res = left_value.compare(right_value);
        if (order_type == ASC) {
          return res < 0;
        }
        return res > 0;
      });

      auto splited_tuples=split_tuples(tuples,tuple_schema);
      for(auto t : splited_tuples){
        tmp.push_back(t);
      }
    }
    
    tuples_list.swap(tmp);
  }

  std::vector<Tuple *> tmp_tuples;

  for(auto tuples:tuples_list){
    for(auto tuple:tuples){
      tmp_tuples.push_back(tuple);
    }
  }

  tuples_.swap(tmp_tuples);

  index_ = -1;
  return RC::SUCCESS;
}

std::vector<std::vector<Tuple *>> split_tuples(std::vector<Tuple *> tuples,const TupleCellSpec &tuple_schema){
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

RC OrderPhysicalOperator::next() {
  RC rc = RC::SUCCESS;

  if (index_ == tuples_.size() -1) {
    return RC::RECORD_EOF;
  }
  index_++;
  return RC::SUCCESS;
}

RC OrderPhysicalOperator::close() {
  if (!children_.empty()) {
    children_[0]->close();
  }
  return RC::SUCCESS;
}

Tuple * OrderPhysicalOperator::current_tuple() {
  assert(0 <= index_ < tuples_.size());
  return tuples_[index_];
}