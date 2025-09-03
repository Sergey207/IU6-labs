#ifndef AREA_H
#define AREA_H

#include <QWidget>

#include <vector>

#include "entrance.h"

using namespace std;

class Area : public QWidget {
  vector<entrance> _data;
  QString _name;

public:
  Area(QWidget *parent);
  void setData(vector<entrance> &data, const QString &name);

protected:
  void paintEvent(QPaintEvent *event);
};

#endif // AREA_H
