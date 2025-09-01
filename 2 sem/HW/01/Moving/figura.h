#ifndef FIGURA_H
#define FIGURA_H

#include <QPainter>

class Figura {
protected:
  int x, y, halflen, dx, dy, r;
  virtual void draw(QPainter *Painter) = 0;

public:
  Figura(int X, int Y, int Halflen) : x(X), y(Y), halflen(Halflen) {}
  void move(float Alpha, QPainter *Painter);
  virtual ~Figura() {} // необходим для полиморфного объекта
};

class MyLine : public Figura {
protected:
  void draw(QPainter *Painter);

public:
  MyLine(int x, int y, int halflen) : Figura(x, y, halflen) {}
};

class MyTriangle : public Figura {
protected:
  void draw(QPainter *Painter);

public:
  MyTriangle(int x, int y, int halflen) : Figura(x, y, halflen) {}
};

class CompassArrow : public Figura {
protected:
  void draw(QPainter *Painter);

public:
  CompassArrow(int x, int y, int halflen) : Figura(x, y, halflen) {}
};

#endif // FIGURA_H
