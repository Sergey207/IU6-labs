#include "struct_dialog.h"
#include "ui_struct_dialog.h"

#include <QMessageBox>

StructDialog::StructDialog(QWidget *parent, int type)
    : QDialog(parent), ui(new Ui::StructDialog) {
  ui->setupUi(this);
  dialogType = type;
  if (dialogType == SEARCH)
    setWindowTitle("Поиск записей");
  else if (dialogType == DELETE) {
    setWindowTitle("Удаление записей");
  }
}

StructDialog::~StructDialog() { delete ui; }

void StructDialog::setStruct(field &s) {
  ui->edtLastName->setText(s.last_name);
  ui->edtFirstName->setText(s.first_name);
  ui->edtPhone->setText(s.phone_number);
  ui->edtAddress->setText(s.address);
}

field StructDialog::getStruct() {
  return {ui->edtLastName->text(), ui->edtFirstName->text(),
          ui->edtPhone->text(), ui->edtAddress->text()};
}

void StructDialog::showDialog(QString text) {
  auto dlg = QMessageBox(this);
  dlg.setText(text);
  dlg.setWindowTitle("Ошибка!");
  dlg.resize(400, 300);
  dlg.exec();
}

void StructDialog::accept() {
  for (auto c : ui->edtLastName->text()) {
    if (!c.isLetter())
      showDialog(QString("В фамилии должны быть только буквы!"));
  }
  for (auto c : ui->edtFirstName->text()) {
    if (!c.isLetter())
      showDialog(QString("В имени должны быть только буквы!"));
  }

  auto lineEdits = {ui->edtLastName, ui->edtFirstName, ui->edtPhone,
                    ui->edtAddress};
  if (dialogType == ADD) {
    for (auto edt : lineEdits) {
      if (edt->text().isEmpty()) {
        edt->setFocus();
        return;
      }
    }
  } else if (dialogType == DELETE) {
    for (auto edt : lineEdits) {
      if (!edt->text().isEmpty()) {
        QDialog::accept();
        return;
      } else {
        ui->edtLastName->setFocus();
      }
    }
  }
  QDialog::accept();
}
