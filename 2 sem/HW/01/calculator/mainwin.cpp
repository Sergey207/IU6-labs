#include "mainwin.h"
#include "ui_mainwin.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), res(0), oper('@') {
  ui->setupUi(this);
  ui->lineEdit->setFocus();
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_clearButton_clicked() {
  ui->lineEdit->clear();
  ui->lineEdit->setFocus();
  res = 0;
  oper = '@';
}

void MainWindow::on_equalButton_clicked() {
  double r = ui->lineEdit->text().toDouble();
  if (oper == '+')
    res += r;
  else if (oper == '-')
    res -= r;
  else if (oper == '*')
    res *= r;
  else if (oper == '/') {
    if (r == 0) {
      auto messageBox = QMessageBox(this);
      messageBox.setText("Нельзя делить на 0!");
      messageBox.exec();
    } else
      res /= r;
  }
  QString q_str;
  ui->lineEdit->setText(q_str.setNum(res));
  ui->lineEdit->setFocus();
}

void MainWindow::onActionClicked(char action) {
  oper = action;
  res = ui->lineEdit->text().toDouble();
  ui->lineEdit->clear();
  ui->lineEdit->setFocus();
}

void MainWindow::on_plusButton_clicked() { onActionClicked('+'); }

void MainWindow::on_minusButton_clicked() { onActionClicked('-'); }

void MainWindow::on_multiButton_clicked() { onActionClicked('*'); }

void MainWindow::on_divButton_clicked() { onActionClicked('/'); }

void MainWindow::on_exitButton_clicked() { this->close(); }
