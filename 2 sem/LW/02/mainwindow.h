#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "mydeque.h"
#include "myuniversaldeque.h"

#define DEQUE 1
#define SORTING_DEQUE 2
#define UNIVERSAL_DEQUE 3

#define ADD_NUM 1
#define ADD_STRING 2

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT;
  MyDeque *deque;
  MyUniversalDeque<double> *u_deque;

  int _mode;

public:
  MainWindow(QWidget *parent = nullptr, const int &mode = DEQUE);
  ~MainWindow();

private:
  void updateList();

private slots:
  void on_btnAddNum_clicked();

  void on_btnAddString_clicked();

  void on_btnDelete_clicked();

  void on_btnSort_clicked();

private:
  Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
