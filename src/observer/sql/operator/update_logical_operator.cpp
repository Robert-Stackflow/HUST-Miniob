/// created by NieYang 2023/10/16

#include "update_logical_operator.h"

UpdateLogicalOperator::UpdateLogicalOperator(Table *table, Value *value, std::string field_name) 
    : table_(table), value_(value), field_name_(field_name)
{}