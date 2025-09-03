#ifndef ADDSCHOOLBOOKDIALOG_H
#define ADDSCHOOLBOOKDIALOG_H

#include <QDialog>

namespace Ui {
class AddSchoolBookDialog;
}

class AddSchoolBookDialog : public QDialog {
  Q_OBJECT

public:
  explicit AddSchoolBookDialog(QWidget *parent = nullptr);
  ~AddSchoolBookDialog();

  QString getName();
  QString getAutor();
  QString getSubject();

private:
  Ui::AddSchoolBookDialog *ui;
};

#endif // ADDSCHOOLBOOKDIALOG_H
