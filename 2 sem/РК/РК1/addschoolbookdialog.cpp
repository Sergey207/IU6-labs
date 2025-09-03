#include "addschoolbookdialog.h"
#include "ui_addschoolbookdialog.h"

AddSchoolBookDialog::AddSchoolBookDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::AddSchoolBookDialog) {
  ui->setupUi(this);
}

AddSchoolBookDialog::~AddSchoolBookDialog() { delete ui; }

QString AddSchoolBookDialog::getName() { return ui->edtName_2->text(); }
QString AddSchoolBookDialog::getAutor() { return ui->edtAutor_2->text(); }
QString AddSchoolBookDialog::getSubject() { return ui->edtSubject->text(); }
