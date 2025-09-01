#include "figura.h"

#include <cmath>

void Figura::move(float Alpha, QPainter *Painter) {
  dx = static_cast<int>(halflen * cos(Alpha));
  dy = static_cast<int>(halflen * sin(Alpha));
  draw(Painter);
}

void MyLine::draw(QPainter *Painter) {
  Painter->drawLine(x + dx, y + dy, x - dx, y - dy);
}

void MyTriangle::draw(QPainter *Painter) {
  const float sqrt3_2 = 0.8660254f; // sqrt(3)/2

  // Преобразуем в float для точности вычислений
  float fx = x;
  float fy = y;
  float fdx = dx;
  float fdy = dy;

  // Вычисляем координаты трёх вершин
  float x1 = fx + fdx;
  float y1 = fy + fdy;

  float x2 = fx + (-0.5f * fdx - sqrt3_2 * fdy);
  float y2 = fy + (-0.5f * fdy + sqrt3_2 * fdx);

  float x3 = fx + (-0.5f * fdx + sqrt3_2 * fdy);
  float y3 = fy + (-0.5f * fdy - sqrt3_2 * fdx);

  // Создаём массив точек и рисуем треугольник
  QPoint points[3] = {QPoint(static_cast<int>(x1), static_cast<int>(y1)),
                      QPoint(static_cast<int>(x2), static_cast<int>(y2)),
                      QPoint(static_cast<int>(x3), static_cast<int>(y3))};
  Painter->drawPolygon(points, 3);
}

void CompassArrow::draw(QPainter *Painter) {
  const float wingScale = 0.3f; // Отношение длины крыльев к основной диагонали

  // Преобразование в float для точных вычислений
  float fx = x;
  float fy = y;
  float fdx = dx;
  float fdy = dy;

  // Вычисляем перпендикулярное направление (поворот на 90°) и масштабируем
  float wingX = -fdy * wingScale;
  float wingY = fdx * wingScale;

  // Создаем 4 вершины ромба
  QPoint points[4] = {
      QPoint(static_cast<int>(fx + fdx),
             static_cast<int>(fy + fdy)), // Острие стрелки
      QPoint(static_cast<int>(fx + wingX),
             static_cast<int>(fy + wingY)), // Правое крыло
      QPoint(static_cast<int>(fx - fdx), static_cast<int>(fy - fdy)), // Хвост
      QPoint(static_cast<int>(fx - wingX),
             static_cast<int>(fy - wingY)) // Левое крыло
  };

  Painter->drawPolygon(points, 4);
}
