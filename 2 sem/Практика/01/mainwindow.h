#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <vector>

#include "entrance.h"

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT;
  vector<entrance> data;

  // search parameters
  bool searchByDate = false;
  QDate startDate;
  QDate endDate;
  QString searchName;
  QString searchCountry;

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private slots:
  void on_btnAdd_clicked();

  void on_btnClearSearch_clicked();

  void on_btnSearch_clicked();

  void on_btnDelete_clicked();

  void on_btnOpen_clicked();

  void on_btnSave_clicked();

  void on_btnChart_clicked();

  void on_btnEdit_clicked();

private:
  Ui::MainWindow *ui;

  void updateTable();
  void updateTable(QString additional_data);
  void readFromFile(const QString &filename);
  void saveToFile(const QString &filename);
};
#endif // MAINWINDOW_H
