#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "adddialog.h"
#include "chartdialog.h"
#include "searchdialog.h"

#include <QFile>

#define MESSAGE_TIME 5000

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  ui->tableWidget->setColumnCount(4);
  ui->tableWidget->setHorizontalHeaderLabels({"Наименование",
                                              "Дата поступления", "Количество",
                                              "Страна-производитель"});
  ui->tableWidget->horizontalHeader()->setSectionResizeMode(
      QHeaderView::ResizeToContents);
  readFromFile("data.dat");
  updateTable();
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::updateTable() { updateTable(""); }

void MainWindow::updateTable(QString additional_data) {
  ui->tableWidget->setRowCount(0);
  int i = 0;
  for (auto &e : data) {
    if (e.name.contains(searchName, Qt::CaseInsensitive) &&
        e.country.contains(searchCountry, Qt::CaseInsensitive) &&
        (!searchByDate || (startDate <= e.date && e.date <= endDate))) {
      ui->tableWidget->setRowCount(i + 1);
      ui->tableWidget->setItem(i, 0, new QTableWidgetItem(e.name));
      ui->tableWidget->setItem(i, 1, new QTableWidgetItem(e.date.toString()));
      ui->tableWidget->setItem(i, 2,
                               new QTableWidgetItem(QString::number(e.amount)));
      ui->tableWidget->setItem(i, 3, new QTableWidgetItem(e.country));
      i++;
    }
  }
  statusBar()->showMessage(additional_data +
                               "Отображено элементов: " + QString::number(i),
                           MESSAGE_TIME);
}

void MainWindow::readFromFile(const QString &filename) {
  data.clear();
  QFile file(filename);
  if (file.open(QIODevice::ReadOnly)) {
    QDataStream in(&file);
    entrance e;
    while (!in.atEnd()) {
      in >> e.name >> e.date >> e.amount >> e.country;
      data.push_back(e);
    }
    statusBar()->showMessage("Успешно прочитано!", MESSAGE_TIME);
  } else {
    statusBar()->showMessage("Ошибка при чтении!", MESSAGE_TIME);
  }
}

void MainWindow::saveToFile(const QString &filename) {
  QFile file(filename);
  if (file.open(QIODevice::WriteOnly)) {
    QDataStream out(&file);
    for (auto &i : data) {
      out << i.name << i.date << i.amount << i.country;
    }
    file.close();
    statusBar()->showMessage("Успешно записано!", MESSAGE_TIME);
  } else {
    statusBar()->showMessage("Ошибка при записи!", MESSAGE_TIME);
  }
}

void MainWindow::on_btnAdd_clicked() {
  AddDialog addDialog(this, ADD);
  if (addDialog.exec() == QDialog::Accepted) {
    data.push_back(addDialog.getStruct());
    updateTable("Добавлена одна запись. ");
  }
}

void MainWindow::on_btnClearSearch_clicked() {
  searchByDate = false;
  searchName.clear();
  searchCountry.clear();
  updateTable();
}

void MainWindow::on_btnSearch_clicked() {
  SearchDialog searchDialog(this);
  searchDialog.setSearchName(searchName);
  searchDialog.setSearchCountry(searchCountry);
  if (searchByDate)
    searchDialog.setupDate(startDate, endDate);

  if (searchDialog.exec() == QDialog::Accepted) {
    searchName = searchDialog.getSearchName();
    searchCountry = searchDialog.getSearchCountry();
    searchByDate = searchDialog.isSearchByDate();
    if (searchByDate) {
      startDate = searchDialog.getBeginDate();
      endDate = searchDialog.getEndDate();
    }
    updateTable();
  }
}

void MainWindow::on_btnDelete_clicked() {
  if (ui->tableWidget->selectedItems().isEmpty())
    statusBar()->showMessage("Не выбрана ни одна строка!", MESSAGE_TIME);
  else {
    auto row = ui->tableWidget->selectedItems().first()->row();
    data.erase(data.begin() + row);
    updateTable("Удалена 1 строка. ");
  }
}

void MainWindow::on_btnOpen_clicked() {
  readFromFile("data.dat");
  updateTable();
}

void MainWindow::on_btnSave_clicked() { saveToFile("data.dat"); }

void MainWindow::on_btnChart_clicked() {
  ChartDialog chartDialog(this);
  chartDialog.setData(data);
  chartDialog.exec();
}

void MainWindow::on_btnEdit_clicked() {
  if (ui->tableWidget->selectedItems().isEmpty())
    statusBar()->showMessage("Не выбрана ни одна строка!", MESSAGE_TIME);
  else {
    auto row = ui->tableWidget->selectedItems().first()->row();
    AddDialog editDialog(this, EDIT);
    editDialog.setStruct(data[row]);
    if (editDialog.exec() == QDialog::Accepted) {
      data[row] = editDialog.getStruct();
    }
    updateTable("Обновлена одна запись! ");
  }
}
