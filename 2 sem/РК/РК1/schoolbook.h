#ifndef SCHOOLBOOK_H
#define SCHOOLBOOK_H

#include "book.h"

class SchoolBook : public Book {
private:
  QString _subject;

public:
  SchoolBook(const QString &name, const QString &autor, const QString &subject)
      : Book(name, autor), _subject(subject) {};

  int type() override;

  QString getSubject() override;
};

#endif // SCHOOLBOOK_H
