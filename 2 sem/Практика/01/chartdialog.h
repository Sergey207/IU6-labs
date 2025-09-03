#ifndef CHARTDIALOG_H
#define CHARTDIALOG_H

#include <QDialog>

#include <set>
#include <vector>

#include "area.h"
#include "entrance.h"

using namespace std;

namespace Ui {
class ChartDialog;
}

class ChartDialog : public QDialog {
  Q_OBJECT;
  vector<entrance> _data;
  set<QString> _names;
  Area *area;

public:
  explicit ChartDialog(QWidget *parent = nullptr);
  ~ChartDialog();

  void setData(vector<entrance> &data);

private slots:
  void on_comboBox_currentTextChanged(const QString &arg1);

private:
  Ui::ChartDialog *ui;
};

#endif // CHARTDIALOG_H
