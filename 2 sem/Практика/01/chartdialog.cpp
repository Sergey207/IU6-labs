#include "chartdialog.h"
#include "ui_chartdialog.h"

ChartDialog::ChartDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::ChartDialog) {
  ui->setupUi(this);
  area = new Area(this);
  ui->verticalLayout->insertWidget(1, area);
}

ChartDialog::~ChartDialog() {
  delete ui;
  delete area;
}

void ChartDialog::setData(vector<entrance> &data) {
  _data = data;
  _names.clear();
  for (auto &it : _data) {
    _names.insert(it.name);
  }
  ui->comboBox->clear();
  for (auto &it : _names) {
    ui->comboBox->addItem(it);
  }
  area->setData(_data, ui->comboBox->currentText());
}

void ChartDialog::on_comboBox_currentTextChanged(const QString &arg1) {
  area->setData(_data, arg1);
  area->repaint();
}
