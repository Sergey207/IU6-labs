#include "book.h"

int Book::type() { return BOOK; }

QString Book::getName() { return _name; }

QString Book::getAutor() { return _autor; }

QString Book::getSubject() { return ""; }
