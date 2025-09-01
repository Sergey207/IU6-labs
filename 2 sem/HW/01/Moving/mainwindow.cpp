#include "mainwindow.h"

#include <QString>

MainWindow::MainWindow() {
  setWindowTitle(QString("Движение"));
  setFixedSize(400, 400);
  area = new Area(this);
}
