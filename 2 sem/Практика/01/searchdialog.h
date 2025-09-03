#ifndef SEARCHDIALOG_H
#define SEARCHDIALOG_H

#include <QDialog>

namespace Ui {
class SearchDialog;
}

class SearchDialog : public QDialog {
  Q_OBJECT

public:
  explicit SearchDialog(QWidget *parent = nullptr);
  ~SearchDialog();

  void setSearchName(QString &s);
  void setSearchCountry(QString &s);
  void setupDate(QDate &begin, QDate &end);

  QString getSearchName();
  QString getSearchCountry();
  bool isSearchByDate();
  QDate getBeginDate();
  QDate getEndDate();

private slots:
  void on_chkSearchByDate_stateChanged(int arg1);

private:
  Ui::SearchDialog *ui;
  void accept() override;
};

#endif // SEARCHDIALOG_H
