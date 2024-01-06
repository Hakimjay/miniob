/* Copyright (c) 2021 Xie Meiyi(xiemeiyi@hust.edu.cn) and OceanBase and/or its affiliates. All rights reserved.
miniob is licensed under Mulan PSL v2.
You can use this software according to the terms and conditions of the Mulan PSL v2.
You may obtain a copy of Mulan PSL v2 at:
         http://license.coscl.org.cn/MulanPSL2
THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
See the Mulan PSL v2 for more details. */

//
// Created by Wangyunlai on 2021/5/14.
//

#pragma once

#include <memory>
#include <vector>

#include "common/log/log.h"
#include "sql/parser/parse.h"
#include "sql/expr/tuple_cell.h"
#include "sql/expr/expression.h"
#include "storage/record/record.h"

class Table;

class TupleCellSpec
{
public:
  TupleCellSpec() = default;
  TupleCellSpec(Expression *expr) : expression_(expr)
  {}

  ~TupleCellSpec()
  {
    if (expression_) {
      delete expression_;
      expression_ = nullptr;
    }
  }

  void set_alias(const char *alias)
  {
    alias_ = std::shared_ptr<std::string>(new std::string(alias));
  }

    void set_alias(std::shared_ptr<std::string> ptr)
  {
    alias_ = ptr;
  }

  std::shared_ptr<std::string> get_alias_ptr()
  {
    return alias_;
  }

  const char *alias() const
  {
    return alias_.get()->c_str();
  }

  Expression *expression() const
  {
    return expression_;
  }

private:
  std::shared_ptr<std::string> alias_ = nullptr;
  Expression *expression_ = nullptr;
};

class Tuple
{
public:
  Tuple() = default;
  virtual ~Tuple() = default;

  virtual int cell_num() const = 0; 
  virtual RC  cell_at(int index, TupleCell &cell) const = 0;
  virtual RC  find_cell(const Field &field, TupleCell &cell) const = 0;

  virtual RC  cell_spec_at(int index, const TupleCellSpec *&spec) const = 0;

  // 将元组的记录推送到给定的 CompoundRecord 对象中
  virtual void get_record(CompoundRecord &record) const = 0;

  // 此函数将设置所有与元组相关的记录
  // 调用此函数将擦除参数中的所有记录并替换为元组的记录
  virtual void set_record(CompoundRecord &record) = 0;

  // 此函数不会设置所有记录
  // 调用此函数将擦除参数中的结束部分记录，并将元组的右侧记录替换进去
  virtual void set_right_record(CompoundRecord &record) = 0;

};

class RowTuple : public Tuple
{
public:
  RowTuple() = default;
  virtual ~RowTuple()
  {
    for (TupleCellSpec *spec : speces_) {
      delete spec;
    }
    speces_.clear();
  }
  
  void set_record(Record *record)
  {
    this->record_ = record;
  }

  void set_schema(const Table *table, const std::vector<FieldMeta> *fields)
  {
    table_ = table;
    this->speces_.reserve(fields->size());
    for (const FieldMeta &field : *fields) {
      speces_.push_back(new TupleCellSpec(new FieldExpr(table, &field)));
    }
  }

  int cell_num() const override
  {
    return speces_.size();
  }

  RC cell_at(int index, TupleCell &cell) const override
  {
    if (index < 0 || index >= static_cast<int>(speces_.size())) {
      LOG_WARN("invalid argument. index=%d", index);
      return RC::INVALID_ARGUMENT;
    }

    const TupleCellSpec *spec = speces_[index];
    FieldExpr *field_expr = (FieldExpr *)spec->expression();
    const FieldMeta *field_meta = field_expr->field().meta();
    cell.set_type(field_meta->type());
    cell.set_data(this->record_->data() + field_meta->offset());
    cell.set_length(field_meta->len());
    return RC::SUCCESS;
  }

  RC find_cell(const Field &field, TupleCell &cell) const override
  {
    const char *table_name = field.table_name();
    if (0 != strcmp(table_name, table_->name())) {
      return RC::NOTFOUND;
    }

    const char *field_name = field.field_name();
    for (size_t i = 0; i < speces_.size(); ++i) {
      const FieldExpr * field_expr = (const FieldExpr *)speces_[i]->expression();
      const Field &field = field_expr->field();
      if (0 == strcmp(field_name, field.field_name())) {
	return cell_at(i, cell);
      }
    }
    return RC::NOTFOUND;
  }

  RC cell_spec_at(int index, const TupleCellSpec *&spec) const override
  {
    if (index < 0 || index >= static_cast<int>(speces_.size())) {
      LOG_WARN("invalid argument. index=%d", index);
      return RC::INVALID_ARGUMENT;
    }
    spec = speces_[index];
    return RC::SUCCESS;
  }

  void get_record(CompoundRecord &record) const override
  {
    record.emplace_back(record_);
  }

  void set_record(CompoundRecord &record) override
  {
    assert(record.size() >= 1);
    this->record_ = record.front();
    record.erase(record.begin());
  }

  void set_right_record(CompoundRecord &record) override
  {
    assert(!record.empty());
    set_record(record);
  }

  Record &record()
  {
    return *record_;
  }

  const Record &record() const
  {
    return *record_;
  }
private:
  Record *record_ = nullptr;
  const Table *table_ = nullptr;
  std::vector<TupleCellSpec *> speces_;
};

/*
class CompositeTuple : public Tuple
{
public:
  int cell_num() const override; 
  RC  cell_at(int index, TupleCell &cell) const = 0;
private:
  int cell_num_ = 0;
  std::vector<Tuple *> tuples_;
};
*/

class ProjectTuple : public Tuple
{
public:
  ProjectTuple() = default;
  virtual ~ProjectTuple()
  {
    for (TupleCellSpec *spec : speces_) {
      delete spec;
    }
    speces_.clear();
  }

  void set_tuple(Tuple *tuple)
  {
    this->tuple_ = tuple;
  }

  void add_cell_spec(TupleCellSpec *spec)
  {
    speces_.push_back(spec);
  }
  int cell_num() const override
  {
    return speces_.size();
  }

  RC cell_at(int index, TupleCell &cell) const override
  {
    if (index < 0 || index >= static_cast<int>(speces_.size())) {
      return RC::GENERIC_ERROR;
    }
    if (tuple_ == nullptr) {
      return RC::GENERIC_ERROR;
    }

    const TupleCellSpec *spec = speces_[index];
    return spec->expression()->get_value(*tuple_, cell);
  }

  RC find_cell(const Field &field, TupleCell &cell) const override
  {
    return tuple_->find_cell(field, cell);
  }
  RC cell_spec_at(int index, const TupleCellSpec *&spec) const override
  {
    if (index < 0 || index >= static_cast<int>(speces_.size())) {
      return RC::NOTFOUND;
    }
    spec = speces_[index];
    return RC::SUCCESS;
  }

    void get_record(CompoundRecord &record) const override
  {
    tuple_->get_record(record);
  }

  void set_record(CompoundRecord &record) override
  {
    tuple_->set_record(record);
  }

  void set_right_record(CompoundRecord &record) override
  {
    tuple_->set_right_record(record);
  }

private:
  std::vector<TupleCellSpec *> speces_;
  Tuple *tuple_ = nullptr;
};

class CompoundTuple : public Tuple {
public:
  CompoundTuple() = default;
  CompoundTuple(Tuple *left, Tuple *right) : left_tup_(left), right_tup_(right)
  {}
  virtual ~CompoundTuple() = default;

  void init(Tuple *left, Tuple *right)
  {
    left_tup_ = left;
    right_tup_ = right;
  }

  void set_right_record(CompoundRecord &record) override
  {
    right_tup_->set_right_record(record);
    assert(record.empty());
  }

  void set_record(CompoundRecord &record) override
  {
    left_tup_->set_record(record);
    right_tup_->set_record(record);
  }

  int cell_num() const override
  {
    return left_tup_->cell_num() + right_tup_->cell_num();
    ;
  }

  RC cell_at(int index, TupleCell &cell) const override
  {
    if (index < 0 || index >= cell_num()) {
      return RC::INVALID_ARGUMENT;
    }
    int num = left_tup_->cell_num();
    if (index < num) {
      return left_tup_->cell_at(index, cell);
    }
    return right_tup_->cell_at(index - num, cell);
  }

  RC find_cell(const Field &field, TupleCell &cell) const override
  {
    if (RC::SUCCESS != left_tup_->find_cell(field, cell)) {
      return right_tup_->find_cell(field, cell);
    }
    return RC::SUCCESS;
  }

  RC cell_spec_at(int index, const TupleCellSpec *&spec) const override
  {
    if (index < 0 || index >= cell_num()) {
      return RC::INVALID_ARGUMENT;
    }
    int num = left_tup_->cell_num();
    if (index < num) {
      return left_tup_->cell_spec_at(index, spec);
    }
    return right_tup_->cell_spec_at(index - num, spec);
  }

  void get_record(CompoundRecord &record) const override
  {
    left_tup_->get_record(record);
    right_tup_->get_record(record);
  }

private:
  Tuple *left_tup_;
  Tuple *right_tup_;
};
