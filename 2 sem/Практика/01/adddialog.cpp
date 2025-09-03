#include "adddialog.h"
#include "ui_adddialog.h"

AddDialog::AddDialog(QWidget *parent, int mode)
    : QDialog(parent), ui(new Ui::AddDialog) {
  ui->setupUi(this);
  ui->dateEdit->setDate(QDate::currentDate());
  _mode = mode;
  if (_mode == EDIT) {
    setWindowTitle("Изменить запись");
  }
}

AddDialog::~AddDialog() { delete ui; }

void AddDialog::setStruct(const entrance &e) {
  ui->edtName->setText(e.name);
  ui->dateEdit->setDate(e.date);
  ui->spnAmount->setValue(e.amount);
  ui->edtCountry->setText(e.country);
}

entrance AddDialog::getStruct() {
  return {ui->edtName->text(), ui->dateEdit->date(), ui->spnAmount->value(),
          ui->edtCountry->text()};
}

void AddDialog::accept() {
  if (ui->edtName->text().isEmpty()) {
    ui->edtName->setFocus();
    return;
  }
  if (ui->edtCountry->text().isEmpty()) {
    ui->edtCountry->setFocus();
    return;
  }

  QDialog::accept();
}
