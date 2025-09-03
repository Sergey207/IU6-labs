#include "area.h"

#include <QPainter>

Area::Area(QWidget *parent) {}

void Area::setData(vector<entrance> &data, const QString &name) {
  _data = data;
  _name = name;
}

void Area::paintEvent(QPaintEvent *) {
  QPainter painter(this);
  auto size = this->size();
  // painter.drawLine(0, 0, size.width(), size.height());
  // painter.drawText(100, 100, _name);

  int minAmount = INT_MAX;
  int maxAmount = INT_MIN;
  vector<entrance> toShow;
  for (const auto &it : _data) {
    if (it.name == _name) {
      toShow.push_back(it);
      minAmount = min(minAmount, it.amount);
      maxAmount = max(maxAmount, it.amount);
    }
  }

  QDate startDate = toShow.begin()->date;
  QDate endDate = toShow.begin()->date;
  for (const auto &it : toShow) {
    startDate = min(startDate, it.date);
    endDate = max(endDate, it.date);
  }

  sort(
      toShow.begin(), toShow.end(),
      [](const entrance &e1, const entrance &e2) { return e1.date < e2.date; });

  const int PADDING = 20;
  int chart_width = size.width() - 2 * PADDING;
  int chart_height = size.height() - 2 * PADDING;
  int xPerEn = chart_width / (toShow.size() + 1);

  // Оси системы координат
  painter.drawLine(PADDING * 2, size.height() - PADDING,
                   size.width() - PADDING / 3, size.height() - PADDING);
  painter.drawLine(PADDING * 2, size.height() - PADDING, PADDING * 2,
                   PADDING / 3);

  if (startDate == endDate) {
    painter.drawText(PADDING + chart_width / 2 - PADDING, size.height() - 7,
                     startDate.toString());
  } else {
    painter.drawText(PADDING * 2, size.height() - 7, startDate.toString());
    painter.drawText(PADDING + chart_width - 70, size.height() - 7,
                     endDate.toString());
  }

  int i = 0;
  int last_x, last_y;
  painter.setBrush(Qt::red);
  for (auto &it : toShow) {
    int x = PADDING + xPerEn * (++i);
    int y = PADDING + chart_height -
            chart_height * (static_cast<float>(it.amount) / maxAmount);
    painter.setPen(Qt::white);
    painter.drawText(10, y, QString::number(it.amount));

    if (i > 1) {
      painter.drawLine(last_x + 3, last_y + 3, x + 3, y + 3);
    }

    painter.setPen(Qt::red);
    if (i > 1)
      painter.drawEllipse(last_x, last_y, 6, 6);
    painter.drawEllipse(x, y, 6, 6);

    last_x = x;
    last_y = y;
  }
}
