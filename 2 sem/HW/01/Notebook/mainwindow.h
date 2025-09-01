#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <vector>

#include "field.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT
  std::vector<field> data = {{"Iozhitsa", "Sergey", "+79036148809", "Moscow"},
                             {"Bauman", "Nikolai", "Not invented", "BMSTU"}};
  field searchBy;

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private slots:
  void updateList();

  void on_btnAdd_clicked();

  void on_btnSearch_clicked();

  void on_btnExit_clicked();

  void on_btnDelete_clicked();

private:
  Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
