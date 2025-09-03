#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "addbookdialog.h"
#include "addschoolbookdialog.h"

#include <schoolbook.h>

#include <set>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_btnAddBook_clicked() {
  AddBookDialog dlg{this};
  if (dlg.exec() == QDialog::Accepted) {
    try {
      Book *book = new Book(dlg.getName(), dlg.getAutor());
      shelf.books.push_back(book);
    } catch (...) {
      return;
    }
  }
  updateList();
}

void MainWindow::on_btnAddSchoolbook_clicked() {
  AddSchoolBookDialog dlg{this};
  if (dlg.exec() == QDialog::Accepted) {
    try {
      Book *book =
          new SchoolBook(dlg.getName(), dlg.getAutor(), dlg.getSubject());
      shelf.books.push_back(book);
    } catch (...) {
      return;
    }
  }
  updateList();
  updateCmb();
}

void MainWindow::on_btnDelete_clicked() {}

void MainWindow::on_cmb_currentTextChanged(const QString &arg1) {
  int counter = 0;
  for (auto &i : shelf.books) {
    if (i->type() == i->SCHOOLBOOK && i->getSubject() == ui->cmb->currentText())
      counter++;
  }
  ui->lblResult->setText(QString::number(counter));
}

void MainWindow::updateCmb() {
  set<QString> t;
  for (auto &i : shelf.books) {
    if (i->type() == i->SCHOOLBOOK)
      t.insert(i->getSubject());
  }

  auto selected = ui->cmb->currentText();
  ui->cmb->clear();
  for (auto &i : t) {
    ui->cmb->addItem(i);
  }
  try {
    ui->cmb->setCurrentText(selected);
    on_cmb_currentTextChanged(selected);
  } catch (...) {
    on_cmb_currentTextChanged(ui->cmb->currentText());
    return;
  }
}

void MainWindow::updateList() {
  ui->listWidget->clear();
  for (auto &i : shelf.books) {
    QString newText = i->getName() + " (" + i->getAutor() + ")";
    if (i->type() == i->SCHOOLBOOK)
      newText += (". Предмет: " + i->getSubject());
    ui->listWidget->addItem(newText);
  }
}
