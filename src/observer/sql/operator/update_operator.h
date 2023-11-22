

#pragma once

#include "sql/operator/operator.h"
#include "sql/parser/parse_defs.h"
#include "rc.h"

class Trx;
class UpdateStmt;

class UpdateOperator : public Operator
{
public:
  UpdateOperator(UpdateStmt *update_stmt, Trx *trx,const char* attr_name,const Value* value)
    : update_stmt_(update_stmt), trx_(trx),attr_name_(attr_name),value_(value)
  {}

  virtual ~UpdateOperator() = default;

  RC open() override;
  RC next() override;
  RC close() override;

  Tuple * current_tuple() override {
    return nullptr;
  }
  //int tuple_cell_num() const override
  //RC tuple_cell_spec_at(int index, TupleCellSpec &spec) const override
private:
  UpdateStmt *update_stmt_ = nullptr;
  Trx *trx_ = nullptr;
  const char *attr_name_;
  const Value *value_;
};
