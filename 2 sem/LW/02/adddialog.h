#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QDialog>
#include <QDoubleSpinBox>
#include <QLineEdit>
#include <QSpinBox>

#define NUM 1
#define STR 2
#define DOUBLE 3

namespace Ui {
class AddDialog;
}

class AddDialog : public QDialog {
  Q_OBJECT;
  int _mode;
  QSpinBox *spn;
  QLineEdit *edt;
  QDoubleSpinBox *dSpn;

public:
  explicit AddDialog(QWidget *parent = nullptr, const int &mode = NUM);
  ~AddDialog();

  int getNum();
  QString getString();
  double getDouble();

private:
  Ui::AddDialog *ui;
  void accept() override;
};

#endif // ADDDIALOG_H
