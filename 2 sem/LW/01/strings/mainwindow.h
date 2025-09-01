#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include <QVBoxLayout>

class MainWindow : public QDialog {
  Q_OBJECT

  QLineEdit *inputLine;
  QPushButton *convertBtn;
  QTextEdit *resultField;
  QVBoxLayout *mainLayout;

  bool lower = true;
  QString lastLine;

public:
  MainWindow();
  void setupUI();

private slots:
  void onButtonClick();
  void onEditingFinished();
};

#endif // MAINWINDOW_H
