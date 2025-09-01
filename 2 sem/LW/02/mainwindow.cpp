#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDialog>
#include <QDialogButtonBox>
#include <QMessageBox>

#include "adddialog.h"
#include "mysorteddeque.h"

MainWindow::MainWindow(QWidget *parent, const int &mode)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  _mode = mode;
  if (_mode == DEQUE) {
    ui->btnSort->setEnabled(false);
    setWindowTitle("Дек без сортировки");
    deque = new MyDeque();
  } else if (_mode == SORTING_DEQUE) {
    setWindowTitle("Дек с сортировкой");
    deque = new MySortedDeque();
  } else if (_mode == UNIVERSAL_DEQUE) {
    ui->btnAddString->setEnabled(false);
    setWindowTitle("Универсальный дек");
    u_deque = new MyUniversalDeque<double>;
  }
  if (_mode == DEQUE || _mode == SORTING_DEQUE) {
    deque->addElem(1);
    deque->addElem(2);
    deque->addElem("Hello");
    deque->addElem(3);
    deque->addElem("World!");
    deque->addElem(4);
  } else if (_mode == UNIVERSAL_DEQUE) {
    u_deque->addElem(new double(1.1));
    u_deque->addElem(new double(-4.9));
    u_deque->addElem(new double(-8.3));
    u_deque->addElem(new double(8.9));
  }

  updateList();
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::updateList() {
  ui->lst->clear();
  if (_mode == DEQUE || _mode == SORTING_DEQUE) {
    auto en = deque->getFirstElem();
    while (en != nullptr) {
      ui->lst->addItem(en->element->toString());
      en = en->next;
    }
  } else if (_mode == UNIVERSAL_DEQUE) {
    auto en = u_deque->getFistElem();
    while (en != nullptr) {
      ui->lst->addItem(QString::number(*en->element));
      en = en->next;
    }
  }
}

void MainWindow::on_btnAddNum_clicked() {
  auto addDialog = new AddDialog(this, _mode != UNIVERSAL_DEQUE ? NUM : DOUBLE);
  if (addDialog->exec() == QDialog::Accepted) {
    if (_mode != UNIVERSAL_DEQUE) {
      deque->addElem(addDialog->getNum());
    } else {
      u_deque->addElem(new double(addDialog->getDouble()));
    }
  }
  updateList();
}

void MainWindow::on_btnAddString_clicked() {
  auto addDialog = new AddDialog(this, STR);
  if (addDialog->exec() == QDialog::Accepted) {
    deque->addElem(addDialog->getString());
  }
  updateList();
}

void MainWindow::on_btnDelete_clicked() {
  auto row = ui->lst->currentRow();
  if (row == -1) {
    auto msg = new QMessageBox(this);
    msg->setText("Выберите строку для удаления!");
    msg->setWindowTitle("Ошибка!");
    msg->exec();
  } else {
    if (_mode != UNIVERSAL_DEQUE)
      deque->deleteItem(row);
    else
      u_deque->deleteItem(row);

    updateList();
  }
}

void MainWindow::on_btnSort_clicked() {
  if (_mode != UNIVERSAL_DEQUE)
    deque->sort();
  else
    u_deque->sort();
  updateList();
}
