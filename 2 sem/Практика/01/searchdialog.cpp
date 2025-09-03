#include "searchdialog.h"
#include "ui_searchdialog.h"

#include <QMessageBox>

SearchDialog::SearchDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::SearchDialog) {
  ui->setupUi(this);
}

SearchDialog::~SearchDialog() { delete ui; }

void SearchDialog::setSearchName(QString &s) { ui->edtSearchName->setText(s); }

void SearchDialog::setSearchCountry(QString &s) {
  ui->edtCountryName->setText(s);
}

void SearchDialog::setupDate(QDate &begin, QDate &end) {
  ui->chkSearchByDate->setCheckState(Qt::Checked);
  ui->datBegin->setEnabled(true);
  ui->datEnd->setEnabled(true);
  ui->datBegin->setDate(begin);
  ui->datEnd->setDate(end);
}

QString SearchDialog::getSearchName() { return ui->edtSearchName->text(); }
QString SearchDialog::getSearchCountry() { return ui->edtCountryName->text(); }
bool SearchDialog::isSearchByDate() {
  return ui->chkSearchByDate->checkState() == Qt::Checked;
}
QDate SearchDialog::getBeginDate() { return ui->datBegin->date(); }
QDate SearchDialog::getEndDate() { return ui->datEnd->date(); }

void SearchDialog::accept() {
  if (ui->datBegin->date() > ui->datEnd->date()) {
    QMessageBox msg;
    msg.setText("Начальная дата поиска не может быть больше конечной!");
    msg.setWindowTitle("Ошибка!");
    msg.resize(400, 300);
    msg.exec();
    return;
  }
  QDialog::accept();
}

void SearchDialog::on_chkSearchByDate_stateChanged(int arg1) {
  ui->datBegin->setEnabled(arg1 == Qt::Checked);
  ui->datEnd->setEnabled(arg1 == Qt::Checked);
}
