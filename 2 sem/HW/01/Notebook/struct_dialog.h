#ifndef STRUCT_DIALOG_H
#define STRUCT_DIALOG_H

#include <QDialog>

#include "field.h"

#define ADD 1
#define SEARCH 2
#define DELETE 3

namespace Ui {
class StructDialog;
}
class StructDialog : public QDialog {
  Q_OBJECT;
  int dialogType;

public:
  explicit StructDialog(QWidget *parent = nullptr, int type = ADD);
  ~StructDialog();
  void setStruct(field &s);
  field getStruct();

private:
  Ui::StructDialog *ui;
  void accept() override;
  void showDialog(QString text);
};

#endif // STRUCT_DIALOG_H
