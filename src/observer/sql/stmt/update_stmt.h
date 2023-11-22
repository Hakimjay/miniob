

#pragma once

#include "rc.h"
#include "sql/stmt/stmt.h"
#include "sql/parser/parse_defs.h"

class Table;
class FilterStmt;

class UpdateStmt : public Stmt
{
public:

  UpdateStmt(Table *table, FilterStmt *filter_stmt ,const char *attribute_name, const Value *value);
  ~UpdateStmt() override;

  Table *table() const { return table_; }
  FilterStmt *filter_stmt() const { return filter_stmt_; }
  const char *attr_name() const{return attribute_name_; }
  const Value *value() const {return value_;}

  StmtType type() const override { return StmtType::UPDATE; }
public:
  static RC create(Db *db, const Updates &update_sql, Stmt *&stmt);

private:
  Table *table_ = nullptr;
  FilterStmt *filter_stmt_ = nullptr;
  const char *attribute_name_;
  const Value *value_;
};

