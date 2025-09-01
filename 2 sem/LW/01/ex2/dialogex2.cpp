#include "dialogex2.h"
#include <QMessageBox>
#include <QString>
#include <QTextCodec>

// Преобразуем входную последовательность символов в кодировку UNICODE
#define RUS(str) QString::fromUtf8(str)
DialogEx2::DialogEx2(QWidget *parent) : QDialog(parent) {
  setupUi(this); // Строим форму, описанную в Ui_DialogEx2
  // связываем сигнал кнопки со слотом onExitClicked
  connect(pushButton, SIGNAL(clicked()), this, SLOT(onExitClicked()));
};
void DialogEx2::onExitClicked() {
  // Спрашиваем, закрывать приложение или нет
  if (QMessageBox::question(this, QString(), RUS("Завершить приложение?"),
                            QMessageBox::Yes | QMessageBox::No) ==
      QMessageBox::Yes)
    exit(0);
  else {
    show();
  }
};
