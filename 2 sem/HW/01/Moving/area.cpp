#include "area.h"
#include <QTimerEvent>

Area::Area(QWidget *parent) : QWidget(parent) {
  setFixedSize(QSize(400, 400)); // фиксируем размер Холста
  myLine = new MyLine(75, 75, 50);
  myTriangle = new MyTriangle(325, 75, 50);
  compassArrow = new CompassArrow(200, 200, 100);
  alpha = 0;
}

Area::~Area() {
  delete myLine;
  delete myTriangle;
}

void Area::showEvent(QShowEvent *) {
  myTimer = startTimer(50); // включаем таймер
}

void Area::paintEvent(QPaintEvent *) {
  QPainter painter(this);        // создаем контент рисования на Холсте
  painter.setPen(Qt::red);       // задаем красное Перо
  myLine->move(alpha, &painter); // рисуем Линию
  myTriangle->move(alpha * (-0.5), &painter); // рисуем Квадрат
  compassArrow->move(alpha * 1.5, &painter);
}

void Area::timerEvent(QTimerEvent *event) {
  if (event->timerId() == myTimer) // если наш таймер
  {
    alpha += 0.2;
    update(); // обновить внешний вид
  } else
    QWidget::timerEvent(event); // иначе событие передать далее
}
void Area::hideEvent(QHideEvent *) {
  killTimer(myTimer); // выключить таймер
}
