#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  MainWindow w(nullptr, UNIVERSAL_DEQUE);
  w.show();
  return a.exec();
}
