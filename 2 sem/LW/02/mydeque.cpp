#include "mydeque.h"
#include <QMessageBox>
MyDeque::MyDeque() {}

MyDeque::~MyDeque() {
  for (int i = 0; i < length; i++) {
    last = first;
    last = last->next;
    delete first->element;
    delete first;
    first = last;
  }
}

void MyDeque::addElem(const int &num) { addElem(new NumElement(num)); }
void MyDeque::addElem(const QString &s) { addElem(new StringElement(s)); }
void MyDeque::addElem(Element *new_elem) {
  entry *new_entry = new entry();
  new_entry->element = new_elem;
  try {
    if (first == nullptr) {
      first = new_entry;
      last = new_entry;
    } else {
      new_entry->previous = last;
      last->next = new_entry;
      last = new_entry;
    }
    length++;
  } catch (...) {
  }
}

void MyDeque::deleteItem(const int &index) {
  auto t = first;
  try {
    for (int i = 0; i < index; ++i) {
      t = t->next;
    }
  } catch (...) {
    return;
  }
  if (t == nullptr)
    return;

  if (t == first) {
    first = first->next;
    if (first == nullptr)
      last = nullptr;
    else
      first->previous = nullptr;
  } else if (t == last) {
    last = last->previous;
    last->next = nullptr;
  } else {
    t->previous->next = t->next;
    t->next->previous = t->previous;
  }

  delete t->element;
  delete t;
  length--;
}

MyDeque::entry *MyDeque::getFirstElem() { return first; }

void MyDeque::sort() {}
