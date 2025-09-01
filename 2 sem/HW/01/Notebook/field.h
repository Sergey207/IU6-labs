#ifndef FIELD_H
#define FIELD_H

#include <QString>

struct field {
  QString last_name;
  QString first_name;
  QString phone_number;
  QString address;

  bool contains(field &other) {
    return last_name.contains(other.last_name) &&
           first_name.contains(other.first_name) &&
           phone_number.contains(other.phone_number) &&
           address.contains(other.address);
  }
};

#endif // FIELD_H
