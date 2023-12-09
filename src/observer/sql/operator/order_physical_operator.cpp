//
// Created by NieYang on 2023/10/20.
//

#include "sql/operator/order_physical_operator.h"
#include "storage/table/table.h"
#include "event/sql_debug.h"
#include "sql/stmt/order_stmt.h"

RC OrderPhysicalOperator::open(Trx *trx) {
  if (children_.empty()) {
    return RC::SUCCESS;
  }

  // 递归调用open，递归调用的目的就是将trx传给每一个算子
  std::unique_ptr<PhysicalOperator> &child = children_[0];
  RC rc = child->open(trx);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to open child operator: %s", strrc(rc));
    return rc;
  }

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

  // 排序
  for (auto &order: orders_) {
    auto table_name = order->field().table()->name();
    auto field_name = order->field().field_name();
    auto tuple_schema = TupleCellSpec(table_name, field_name);
    auto order_type = order->type();

    // 需要TupleCellSpec参数,但是我保存的是Field，通过Field字段能否拿到TupleCellSpec参数？
    std::sort(tuples_.begin(), tuples_.end(), [&](Tuple *left, Tuple *right) {
      Value left_value;
      left->find_cell(tuple_schema, left_value);
      Value right_value;
      right->find_cell(tuple_schema, right_value);
      int res = left_value.compare(right_value);
      if (order_type == ASC) {
        return res <= 0;
      }
      return res >= 0;
    });
  }

  index_ = -1;
  return RC::SUCCESS;
}

RC OrderPhysicalOperator::next() {
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