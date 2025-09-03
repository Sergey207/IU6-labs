#ifndef ENTRANCE_H
#define ENTRANCE_H

#include <QDate>
#include <QString>

struct entrance {
  QString name;
  QDate date;
  int amount;
  QString country;
};
#endif // ENTRANCE_H
