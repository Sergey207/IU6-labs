#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDialog>

#include "struct_dialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  updateList();
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::updateList() {
  ui->txtNotebook->clear();
  for (auto &i : data) {
    if (i.contains(searchBy)) {
      ui->txtNotebook->append(i.last_name + " " + i.first_name);
      ui->txtNotebook->append(i.phone_number);
      ui->txtNotebook->append(i.address);
      ui->txtNotebook->append("");
    }
  }
}

void MainWindow::on_btnAdd_clicked() {
  StructDialog addDialog{this, ADD};
  if (addDialog.exec() == QDialog::Accepted) {
    data.push_back(addDialog.getStruct());
    updateList();
  }
}

void MainWindow::on_btnSearch_clicked() {
  StructDialog searchDialog{this, SEARCH};
  searchDialog.setStruct(searchBy);
  if (searchDialog.exec() == QDialog::Accepted) {
    searchBy = searchDialog.getStruct();
    updateList();
  }
}

void MainWindow::on_btnDelete_clicked() {
  StructDialog deleteDialog(this, DELETE);
  if (deleteDialog.exec() == QDialog::Accepted) {
    auto toDelete = deleteDialog.getStruct();
    auto i = data.begin();
    while (i != data.end()) {
      if ((*i).contains(toDelete))
        i = data.erase(i);
      else
        i++;
    }
    updateList();
  }
}
void MainWindow::on_btnExit_clicked() { this->close(); }
