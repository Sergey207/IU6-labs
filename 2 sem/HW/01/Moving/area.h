#ifndef AREA_H
#define AREA_H

#include <QWidget>

#include "figura.h"

class Area : public QWidget {
  int myTimer; // идентификатор таймера
  float alpha; // угол поворота
public:
  Area(QWidget *parent = nullptr);
  ~Area();
  MyLine *myLine; // указатели на объекты фигур
  MyTriangle *myTriangle;
  CompassArrow *compassArrow;

protected:
  // обработчики событий
  void paintEvent(QPaintEvent *event);
  void timerEvent(QTimerEvent *event);
  void showEvent(QShowEvent *event);
  void hideEvent(QHideEvent *event);
};

#endif // AREA_H
