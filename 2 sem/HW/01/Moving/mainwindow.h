#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QPushButton>
#include <QWidget>

#include "area.h"

class MainWindow : public QWidget {
protected:
  Area *area;

public:
  MainWindow();
};

#endif // MAINWINDOW_H
