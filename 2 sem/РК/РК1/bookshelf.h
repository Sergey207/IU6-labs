#ifndef BOOKSHELF_H
#define BOOKSHELF_H

#include <vector>

#include "book.h"

using namespace std;

class BookShelf {
public:
  vector<Book *> books;
  BookShelf();
  ~BookShelf();
};

#endif // BOOKSHELF_H
