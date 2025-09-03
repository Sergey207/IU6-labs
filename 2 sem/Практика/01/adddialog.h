#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QDialog>

#include "entrance.h"

#define ADD 1
#define EDIT 2

namespace Ui {
class AddDialog;
}

class AddDialog : public QDialog {
  Q_OBJECT;
  int _mode;

public:
  explicit AddDialog(QWidget *parent = nullptr, int mode = ADD);
  ~AddDialog();

  void setStruct(const entrance &e);
  entrance getStruct();

private:
  Ui::AddDialog *ui;
  void accept() override;
};

#endif // ADDDIALOG_H
