#include "common/rc.h"
#include "common/log/log.h"
#include "common/lang/string.h"
#include "sql/stmt/order_stmt.h"
#include "storage/db/db.h"
#include "storage/table/table.h"

OrderStmt::~OrderStmt()
{
  delete order_unit_;
}

RC get_table_and_field3(Db *db, Table *default_table, std::unordered_map<std::string, Table *> *tables,
    const RelAttrSqlNode &attr, Table *&table, const FieldMeta *&field)
{
  if (common::is_blank
  (attr.relation_name.c_str())) {
    table = default_table;
  } else if (nullptr != tables) {
    auto iter = tables->find(attr.relation_name);
    if (iter != tables->end()) {
      table = iter->second;
    }
  } else {
    table = db->find_table(attr.relation_name.c_str());
  }
  if (nullptr == table) {
    LOG_WARN("No such table: attr.relation_name: %s", attr.relation_name.c_str());
    return RC::SCHEMA_TABLE_NOT_EXIST;
  }

  field = table->table_meta().field(attr.attribute_name.c_str());
  if (nullptr == field) {
    LOG_WARN("no such field in table: table %s, field %s", table->name(), attr.attribute_name.c_str());
    table = nullptr;
    return RC::SCHEMA_FIELD_NOT_EXIST;
  }

  return RC::SUCCESS;
}

RC OrderStmt::create(Db *db, Table *default_table, std::unordered_map<std::string, Table *> *tables,
    const OrderSqlNode &order, OrderStmt *&stmt)
{
  RC rc = RC::SUCCESS;

  OrderUnit* order_unit = new OrderUnit();

  OrderStmt *tmp_stmt = new OrderStmt();

  Table *table = nullptr;
  const FieldMeta *field = nullptr;
  rc = get_table_and_field3(db, default_table, tables, order.attribute, table, field);
  if (rc != RC::SUCCESS) {
    LOG_WARN("cannot find attr");
    return rc;
  }

  order_unit->set_field(Field(table, field));
  order_unit->set_type(order.type);

  tmp_stmt->set_unit(order_unit);

  stmt=tmp_stmt;

  return rc;
}
