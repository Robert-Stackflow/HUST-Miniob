#include "common/rc.h"
#include "common/log/log.h"
#include "common/lang/string.h"
#include "sql/stmt/group_stmt.h"
#include "storage/db/db.h"
#include "storage/table/table.h"
#include "common/util.h"

GroupStmt::~GroupStmt()
{
  delete group_unit_;
}

RC GroupStmt::create(Db *db, Table *default_table, std::unordered_map<std::string, Table *> *tables,
    const GroupSqlNode &order, GroupStmt *&stmt)
{
  RC rc = RC::SUCCESS;

  GroupUnit* group_unit = new GroupUnit();

  GroupStmt *tmp_stmt = new GroupStmt();

  Table *table = nullptr;
  const FieldMeta *field = nullptr;
  rc = Util::get_table_and_field(db, default_table, tables, order, table, field);
  if (rc != RC::SUCCESS) {
    LOG_WARN("cannot find attr");
    return rc;
  }

  group_unit->set_field(Field(table, field));

  tmp_stmt->set_unit(group_unit);

  stmt=tmp_stmt;

  return rc;
}
