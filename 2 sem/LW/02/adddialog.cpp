#include "adddialog.h"
#include "ui_adddialog.h"

#include <QMessageBox>

AddDialog::AddDialog(QWidget *parent, const int &mode)
    : QDialog(parent), ui(new Ui::AddDialog) {
  ui->setupUi(this);
  _mode = mode;
  if (_mode == NUM) {
    spn = new QSpinBox(this);
    spn->setMinimum(INT_MIN);
    spn->setMaximum(INT_MAX);
    ui->lyt->addWidget(spn);
  } else if (_mode == STR) {
    edt = new QLineEdit(this);
    ui->lyt->addWidget(edt);
  } else if (_mode == DOUBLE) {
    dSpn = new QDoubleSpinBox(this);
    dSpn->setMinimum(-1000);
    dSpn->setMaximum(1000);
    ui->lyt->addWidget(dSpn);
  }
}

AddDialog::~AddDialog() { delete ui; }

int AddDialog::getNum() { return spn->value(); }

QString AddDialog::getString() { return edt->text(); }

double AddDialog::getDouble() { return dSpn->value(); }

void AddDialog::accept() {
  if (_mode == STR && edt->text().isEmpty()) {
    auto msg = new QMessageBox(this);
    msg->setText("Новая строка не может быть пустой!");
    msg->setWindowTitle("Ошибка!");
    msg->exec();
    return;
  }
  QDialog::accept();
}
