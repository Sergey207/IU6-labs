#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "bookshelf.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT;
  BookShelf shelf;

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private slots:
  void on_btnAddBook_clicked();

  void on_btnAddSchoolbook_clicked();

  void on_btnDelete_clicked();

  void on_cmb_currentTextChanged(const QString &arg1);

private:
  Ui::MainWindow *ui;

  void updateCmb();
  void updateList();
};
#endif // MAINWINDOW_H
