#ifndef MYDEQUE_H
#define MYDEQUE_H

#include "element.h"

class MyDeque {
protected:
  struct entry {
    Element *element;
    entry *previous = nullptr;
    entry *next = nullptr;
  };
  entry *first = nullptr;
  entry *last = nullptr;
  int length = 0;

public:
  MyDeque();
  virtual ~MyDeque();

  void addElem(const int &num);
  void addElem(const QString &s);
  void addElem(Element *new_elem);
  void deleteItem(const int &index);
  entry *getFirstElem();

  virtual void sort();
};

#endif // MYDEQUE_H
