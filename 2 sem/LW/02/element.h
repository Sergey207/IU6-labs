#ifndef ELEMENT_H
#define ELEMENT_H

#include <QString>

class Element {
public:
  const int NUM = 1;
  const int STR = 2;
  Element() {};
  virtual ~Element() {};
  virtual QString toString() = 0;
  virtual int type() = 0;
};

class NumElement : public Element {
public:
  NumElement(const int &n) : num(n) {};
  int num;
  QString toString() override;
  int type() override;
};

class StringElement : public Element {
public:
  StringElement(const QString &str) : s(str) {};
  QString s;
  QString toString() override;
  int type() override;
};

#endif // ELEMENT_H
