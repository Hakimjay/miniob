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
// Created by Wangyunlai on 2022/6/5.
//

#pragma once

#include <vector>

#include "rc.h"
#include "sql/stmt/stmt.h"
#include "storage/common/field.h"

class FieldMeta;
class FilterStmt;
class Db;
class Table;
class Expression;
class OrderByStmt;
class GroupByStmt;



class SelectStmt : public Stmt
{
public:

  SelectStmt() = default;
  ~SelectStmt() override;

  StmtType type() const override { return StmtType::SELECT; }
public:
  static RC create(Db *db, const Selects &select_sql, Stmt *&stmt);

public:
  const std::vector<Table *> &tables() const { return tables_; }
  const std::vector<Expression *> &projects() const { return projects_; }
  FilterStmt *filter_stmt() const { return filter_stmt_; }
  OrderByStmt *orderby_stmt() const { return orderby_stmt_; }
  GroupByStmt *groupby_stmt() const { return groupby_stmt_; }
  OrderByStmt *orderby_stmt_for_groupby() const { return orderby_stmt_for_groupby_; }
private:
  std::vector<Expression *> projects_;
  std::vector<Table *> tables_;
  FilterStmt *filter_stmt_ = nullptr;
  OrderByStmt *orderby_stmt_ = nullptr;
  GroupByStmt *groupby_stmt_ = nullptr;
  OrderByStmt *orderby_stmt_for_groupby_ = nullptr;
};

