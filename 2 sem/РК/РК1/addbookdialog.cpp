#include "addbookdialog.h"
#include "ui_addbookdialog.h"

AddBookDialog::AddBookDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::AddBookDialog) {
  ui->setupUi(this);
}

AddBookDialog::~AddBookDialog() { delete ui; }

QString AddBookDialog::getName() { return ui->edtName->text(); }

QString AddBookDialog::getAutor() { return ui->edtAutor->text(); }
