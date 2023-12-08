#include "sql/stmt/join_stmt.h"

RC JoinStmt::create(Db *db, Table *default_table, std::unordered_map<std::string, Table *> *table_map,
    const JoinSqlNode &sql_node, JoinStmt *&stmt)
{
  RC rc = RC::SUCCESS;
  stmt = nullptr;

  // 检查比较连接条件
  if (sql_node.conditions.size() == 0) {
    return RC::INVALID_ARGUMENT;
  }
  JoinStmt *tmp_stmt = new JoinStmt();
  // 创建过滤语句
  rc = FilterStmt::create(db, default_table, table_map, sql_node.conditions.data(), 
    sql_node.conditions.size(), tmp_stmt->filter_);
  if (rc != RC::SUCCESS) {
    LOG_WARN("cannot construct filter stmt");
    return rc;
  }
  stmt = tmp_stmt;
  return rc;
}