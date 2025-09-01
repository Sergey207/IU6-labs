#ifndef MYUNIVERSALDEQUE_H
#define MYUNIVERSALDEQUE_H

template <class T> class MyUniversalDeque {
protected:
  struct entry {
    T *element;
    entry *previous = nullptr;
    entry *next = nullptr;
  };
  entry *first = nullptr;
  entry *last = nullptr;
  int length = 0;

  void swap(entry *e1, entry *e2) {
    auto temp = e1->element;
    e1->element = e2->element;
    e2->element = temp;
  }

public:
  MyUniversalDeque() {}
  ~MyUniversalDeque() {
    for (int i = 0; i < length; i++) {
      last = first;
      last = last->next;
      delete first->element;
      delete first;
      first = last;
    }
  }

  void addElem(T *new_elem) {
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
  void deleteItem(const int &index) {
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
  entry *getFistElem() { return first; }
  void sort() {
    if (first == nullptr)
      return;
    auto it1 = first;
    while (it1 != last) {
      auto it2 = it1;
      auto mn = it1;
      while (it2 != nullptr) {
        if (*(mn->element) > *(it2->element))
          mn = it2;
        it2 = it2->next;
      }
      if (mn != it1)
        swap(mn, it1);
      it1 = it1->next;
    }
  }
};

#endif // MYUNIVERSALDEQUE_H
