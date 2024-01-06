#include "common/log/log.h"
#include "sql/operator/update_operator.h"
#include "storage/record/record.h"
#include "storage/common/table.h"
#include "sql/stmt/update_stmt.h"

RC UpdateOperator::open()
{
  RC rc = RC::SUCCESS;
  if (children_.size() != 1) {
    LOG_WARN("update operator must has 1 child");
    return RC::INTERNAL;
  }

  Operator *child = children_[0];
  rc = child->open();
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to open child operator: %s", strrc(rc));
    return rc;
  }

  Table *table = update_stmt_->table();
  while (RC::SUCCESS == (rc = child->next())) {
    Tuple *tuple = child->current_tuple();
    if (nullptr == tuple) {
      rc = RC::INTERNAL;
      LOG_WARN("failed to get current record. rc=%s", strrc(rc));
      break;
    }

    RowTuple *row_tuple = static_cast<RowTuple *>(tuple);
    Record &record = row_tuple->record();
    rc = table->update_record(trx_, update_stmt_->attr_name(), &record, update_stmt_->values());
    if (rc != RC::SUCCESS) {
      if (rc == RC::RECORD_DUPLICATE_KEY) {
        LOG_WARN("same value, not need to update");
        continue;
      } else {
        LOG_WARN("failed to update record: %s", strrc(rc));
        return rc;
      }
    }
    row_num_++;
  }
  if (RC::RECORD_EOF != rc) {
    LOG_WARN("update failed!");
    return rc;
  }

  return RC::SUCCESS;
}

RC UpdateOperator::next()
{
  return RC::RECORD_EOF;
}

RC UpdateOperator::close()
{
  children_[0]->close();
  return RC::SUCCESS;
}