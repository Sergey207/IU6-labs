#include "element.h"

QString NumElement::toString() { return QString::number(num); }

int NumElement::type() { return NUM; }

QString StringElement::toString() { return s; }

int StringElement::type() { return STR; }
