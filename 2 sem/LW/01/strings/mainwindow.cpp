#include "mainwindow.h"

MainWindow::MainWindow() { setupUI(); }

void MainWindow::setupUI() {
  mainLayout = new QVBoxLayout(this);

  inputLine = new QLineEdit();
  mainLayout->addWidget(inputLine);

  convertBtn = new QPushButton();
  convertBtn->setText("Convert");
  convertBtn->setAutoDefault(false);
  mainLayout->addWidget(convertBtn);

  resultField = new QTextEdit();
  resultField->setReadOnly(true);
  mainLayout->addWidget(resultField);

  setLayout(mainLayout);

  connect(convertBtn, SIGNAL(clicked()), this, SLOT(onButtonClick()));
  connect(inputLine, SIGNAL(editingFinished()), this,
          SLOT(onEditingFinished()));
}

void MainWindow::onButtonClick() {
  if (lastLine.isEmpty())
    return;
  if (lower)
    resultField->append("lower: " + lastLine.toLower());
  else
    resultField->append("upper: " + lastLine.toUpper());
  lower = !lower;
}

void MainWindow::onEditingFinished() {
  if (inputLine->text().isEmpty() || lastLine == inputLine->text())
    return;
  lastLine = inputLine->text();

  resultField->append("input: " + lastLine);
  lower = true;
}
