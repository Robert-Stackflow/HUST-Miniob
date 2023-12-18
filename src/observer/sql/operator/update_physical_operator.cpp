//
// Created by NieYang on 2023/10/16.
//

#include "sql/operator/update_physical_operator.h"
#include "common/log/log.h"
#include "storage/record/record.h"
#include "storage/table/table.h"
#include "storage/trx/trx.h"
#include "sql/stmt/update_stmt.h"
#include "common/lang/mutex.h"

RC UpdatePhysicalOperator::open(Trx *trx) 
{ 
    if (children_.empty()) {
        return RC::SUCCESS;
    }

    std::unique_ptr<PhysicalOperator> &child = children_[0];
    RC rc = child->open(trx);
    if (rc != RC::SUCCESS) {
        LOG_WARN("failed to open child operator: %s", strrc(rc));
        return rc;
    }

    trx_ = trx;

    return RC::SUCCESS; 
}

RC UpdatePhysicalOperator::next() 
{ 
    RC rc = RC::SUCCESS;
    if (children_.empty()) {
        return RC::RECORD_EOF;
    }

    PhysicalOperator *child = children_[0].get();
    while (RC::SUCCESS == (rc = child->next())) {
        Tuple *tuple = child->current_tuple();
        if (nullptr == tuple) {
            LOG_WARN("failed to get current record: %s", strrc(rc));
            return rc;
        }
        RowTuple *row_tuple = static_cast<RowTuple *>(tuple);
        // 更新
        Record &record = row_tuple->record();
        char * data = record.data();
        const TableMeta table_meta = table_->table_meta();
        const FieldMeta * field_meta = table_meta.field(field_.c_str());
        //上锁
        common::Mutex lock_;
        lock_.lock();
        const char *value_data = value_->data();
        // 根据待更新字段的偏移更新
        memmove(data + field_meta->offset(), value_data, (size_t)value_->length());
        lock_.unlock();
        if (rc != RC::SUCCESS) {
            LOG_WARN("failed to update record: %s", strrc(rc));
            return rc;
        }
    }

    return RC::RECORD_EOF;
}

RC UpdatePhysicalOperator::close() 
{ 
    if (!children_.empty()) {
        children_[0]->close();
    }
    return RC::SUCCESS;
}
