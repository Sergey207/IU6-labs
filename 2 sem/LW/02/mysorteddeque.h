#ifndef MYSORTEDDEQUE_H
#define MYSORTEDDEQUE_H

#include <mydeque.h>

class MySortedDeque : public MyDeque {
private:
  bool compare(entry *e1, entry *e2);
  void swap(entry *e1, entry *e2);

public:
  ~MySortedDeque();
  void sort();
};

#endif // MYSORTEDDEQUE_H
