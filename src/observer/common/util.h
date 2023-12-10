#pragma once

#include "common/rc.h"
#include "sql/parser/parse_defs.h"


class Util{
public:
    static RC get_table_and_field(Db *db, Table *default_table, std::unordered_map<std::string, Table *> *tables,
        const RelAttrSqlNode &attr, Table *&table, const FieldMeta *&field);
};
