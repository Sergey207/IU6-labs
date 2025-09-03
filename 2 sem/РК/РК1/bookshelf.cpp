#include "bookshelf.h"

BookShelf::BookShelf() {}

BookShelf::~BookShelf() {
  for (auto &i : books) {
    delete i;
  }
}
