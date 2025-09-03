#ifndef BOOK_H
#define BOOK_H

#include <QString>

class Book {
private:
  QString _name, _autor;

public:
  int BOOK = 1, SCHOOLBOOK = 2;

  Book(const QString &name, const QString &autor)
      : _name(name), _autor(autor) {};

  virtual int type();

  QString getName();
  QString getAutor();
  virtual QString getSubject();
};

#endif // BOOK_H
