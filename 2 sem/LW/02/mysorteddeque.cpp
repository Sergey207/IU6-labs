#include "mysorteddeque.h"

bool MySortedDeque::compare(entry *e1, entry *e2) {
  if (e1->element->type() != e2->element->type()) {
    return e1->element->type() < e2->element->type();
  }
  if (e1->element->type() == e1->element->NUM)
    return e1->element->toString().toInt() < e2->element->toString().toInt();
  return e1->element->toString() <= e2->element->toString();
}

void MySortedDeque::swap(entry *e1, entry *e2) {
  auto temp = e1->element;
  e1->element = e2->element;
  e2->element = temp;
}

MySortedDeque::~MySortedDeque() { MyDeque::~MyDeque(); }

void MySortedDeque::sort() {
  if (first == nullptr)
    return;
  auto it1 = first;
  while (it1 != last) {
    auto it2 = it1;
    auto mn = it1;
    while (it2 != nullptr) {
      if (!compare(mn, it2))
        mn = it2;
      it2 = it2->next;
    }
    if (mn != it1)
      swap(mn, it1);
    it1 = it1->next;
  }
}
