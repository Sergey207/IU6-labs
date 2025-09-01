#ifndef MAINWIN_H
#define MAINWIN_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private slots:
  void onActionClicked(char action);

  void on_minusButton_clicked();

  void on_clearButton_clicked();

  void on_equalButton_clicked();

  void on_plusButton_clicked();

  void on_multiButton_clicked();

  void on_divButton_clicked();

  void on_exitButton_clicked();

private:
  Ui::MainWindow *ui;
  double res;
  QChar oper;
};
#endif // MAINWIN_H
