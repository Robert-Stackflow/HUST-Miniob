// created by NieYang on 2023/20/19

#include "common/rc.h"
#include "common/log/log.h"
#include "common/lang/string.h"
#include "aggregation_stmt.h"
#include "storage/db/db.h"
#include "storage/table/table.h"
#include "common/util.h"

RC AggrFuncItem::add_field(Field *&field) 
{
    if (all_field_) {
      return RC::INTERNAL;
    } else if (aggr_field_ == nullptr) {
      if (check_all_field(field)) {
        if (type_ != COUNT_AGGR_T)
          return RC::INTERNAL;
        all_field_ = true;
      }
      aggr_field_ = field;
      return RC::SUCCESS;
    } else {
      bool field_exist = exist(field);
      if (field_exist && (type_ == SUM_AGGR_T || type_ == AVG_AGGR_T))
        return RC::SUCCESS;
      else 
        return RC::INTERNAL;
    }
}

bool AggrFuncItem::check_all_field(Field *field) 
{ 
  return 0==strcmp(field->meta()->name(), "*"); 
}

RC AggrStmt::create_aggr_func_item(Db *db, Table *default_table, std::unordered_map<std::string, Table *> *tables,
    AggrFuncSqlNode &aggr_func_sql_node, AggrFuncItem *&aggr_func_item)
{
    RC rc = RC::SUCCESS;

    AggrFuncItem *tmp_aggr_func_item = new AggrFuncItem();
    tmp_aggr_func_item->setType(aggr_func_sql_node.type);
    Table *table = nullptr;
    const FieldMeta *field_meta = nullptr;
    for (RelAttrSqlNode &attr : aggr_func_sql_node.attributes) {
        rc = Util::get_table_and_field(db, default_table, tables, attr, table, field_meta);
        if (rc != RC::SUCCESS) {
            return rc;
        }
        Field *new_field = new Field(table, field_meta);
        rc = tmp_aggr_func_item->add_field(new_field);
        if (rc != RC::SUCCESS) {
            return rc;
        }
    }

    aggr_func_item = tmp_aggr_func_item;

    return rc;
}