#include "calcDialog.h"
#include <QGridLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QVBoxLayout>
#include <QVector>

#include <cmath>

// Идентификаторы кнопок
// Для цифровых кнопок идентификатор является соответствующая цифра
#define POKAZ -4
#define LOG -3
#define SIN -2
#define COS -1

#define DIV 10
#define MUL 11
#define MINUS 12
#define PLUS 13
#define INVERSE 15
#define DOT 16
#define EQ 20
#define BKSP 30
#define CLR 31
#define CLR_ALL 32

#define NEW_KEYS 4
#define GRID_KEYS 16
// Описатель кнопки
struct BtnDescr {
  QString text;                         // Отображаемый на кнопке текст
  int id;                               // Идентификатор кнопки
  BtnDescr() { id = 0; };               // Конструктор по умолчанию
  BtnDescr(const QString &str, int i) { // Конструктор для инициализации
    text = str;
    id = i;
  };
};
// Динамический массив-вектор элементов описателей кнопок
QVector<BtnDescr> _btnDescr;
// Инициализация массива _btnDescr всеми отображаемыми кнопками
void InitBtnDescrArray() {
  _btnDescr.push_back(BtnDescr("x^y", POKAZ));
  _btnDescr.push_back(BtnDescr("log y (x)", LOG));
  _btnDescr.push_back(BtnDescr("sin(x)", SIN));
  _btnDescr.push_back(BtnDescr("cos(x)", COS));
  _btnDescr.push_back(BtnDescr("7", 7));
  _btnDescr.push_back(BtnDescr("8", 8));
  _btnDescr.push_back(BtnDescr("9", 9));
  _btnDescr.push_back(BtnDescr("/", DIV));
  _btnDescr.push_back(BtnDescr("4", 4));
  _btnDescr.push_back(BtnDescr("5", 5));
  _btnDescr.push_back(BtnDescr("6", 6));
  _btnDescr.push_back(BtnDescr("*", MUL));
  _btnDescr.push_back(BtnDescr("1", 1));
  _btnDescr.push_back(BtnDescr("2", 2));
  _btnDescr.push_back(BtnDescr("3", 3));
  _btnDescr.push_back(BtnDescr("-", MINUS));
  _btnDescr.push_back(BtnDescr("0", 0));
  _btnDescr.push_back(BtnDescr("-/+", INVERSE));
  _btnDescr.push_back(BtnDescr(".", DOT));
  _btnDescr.push_back(BtnDescr("+", PLUS));
  _btnDescr.push_back(BtnDescr("<-", BKSP));
  _btnDescr.push_back(BtnDescr("CE", CLR));
  _btnDescr.push_back(BtnDescr("C", CLR_ALL));
  _btnDescr.push_back(BtnDescr("=", EQ));
}
// Конструктор класса калькулятора
CalcDialog::CalcDialog(QWidget *parent) {
  initNum();           // инициализируем счетные переменные
  InitBtnDescrArray(); // инициализируем массив с описанием кнопок
  // Создаем форму
  m_pLineEdit = new QLineEdit(this);
  // устанавливаем режим только чтения - разрешаем ввод только с нарисованных
  // кнопок
  m_pLineEdit->setReadOnly(true);
  m_pSignalMapper = new QSignalMapper(this);
  // создаем схемы выравнивания
  QGridLayout *gridLayout = new QGridLayout();
  QHBoxLayout *bccKeysLayout = new QHBoxLayout();
  QHBoxLayout *mainKeysLayout = new QHBoxLayout();
  QVBoxLayout *dlgLayout = new QVBoxLayout();
  QVBoxLayout *newKeysLayout = new QVBoxLayout();
  // Заполняем форму кнопками из _btnDescr
  for (int i = 0; i < _btnDescr.size(); i++) {
    // Создаем кнопку с текстом из очередного описателя
    QPushButton *button = new QPushButton(_btnDescr[i].text);
    // если кнопка в основном блоке цифровых или "=" -
    // разрешаем изменение всех размеров
    if (i >= GRID_KEYS + NEW_KEYS + 3 || i < GRID_KEYS + NEW_KEYS)
      button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    // если кнопка не цифровая - увеличиваем шрифт надписи на 4 пункта
    if (_btnDescr[i].id >= 20) {
      QFont fnt = button->font();
      fnt.setPointSize(fnt.pointSize() + 4);
      button->setFont(fnt);
    }
    // связываем сигнал нажатия кнопки с объектом m_pSignalMapper
    connect(button, SIGNAL(clicked()), m_pSignalMapper, SLOT(map()));
    // обеспечиваем соответствие кнопки её идентификатору
    m_pSignalMapper->setMapping(button, _btnDescr[i].id);
    if (i < NEW_KEYS)
      newKeysLayout->addWidget(button, i);
    else if (i < GRID_KEYS + NEW_KEYS) // Если кнопка из центрального блока -
                                       // помещаем в сетку
      gridLayout->addWidget(button, (i - NEW_KEYS) / 4, (i - NEW_KEYS) % 4);
    else if (i < GRID_KEYS + NEW_KEYS +
                     3) // кнопка из верхнего блока - в bccKeysLayout
      bccKeysLayout->addWidget(button);
    else { // кнопка "=" - помещаем в блок mainKeysLayout после gridLayout
      mainKeysLayout->addLayout(newKeysLayout);
      mainKeysLayout->addLayout(gridLayout);
      mainKeysLayout->addWidget(button);
    }
  }
  // связываем сигнал из m_pSignalMapper о нажатии со слотом clicked
  // нашего класса
  connect(m_pSignalMapper, SIGNAL(mapped(int)), this, SLOT(clicked(int)));
  // добавляем блоки кнопок в схему выравнивания всей формы
  dlgLayout->addWidget(m_pLineEdit);
  dlgLayout->addLayout(bccKeysLayout);
  dlgLayout->addLayout(mainKeysLayout);
  // связываем схему выравнивания dlgLayout с формой
  setLayout(dlgLayout);
  // отображаем "0" в поле ввода чисел m_pLineEdit
  setNumEdit(0);
};
// Обработка нажатия клавиш
void CalcDialog::clicked(
    int id) { // по идентификатору кнопки ищем действие для выполнения
  switch (id) {
  case INVERSE: // унарная операция +/-
  {
    setNumEdit(getNumEdit() * -1.0);
    break;
  };
  case DOT:
    // добавление десятичной точки
    {
      // если на экране результат предыдущей операции - сбросить
      checkOpPerf();
      QString str = m_pLineEdit->text();
      str.append("."); // добавляем точку к строке
      bool ok = false;
      // проверяем, является ли результат числом (исключаем 0.1. )
      str.toDouble(&ok);
      // если строка является числом - помещаем резульат в m_pLineEdit
      if (ok)
        m_pLineEdit->setText(str);
      break;
    };
  case SIN:
    setNumEdit(std::sin(getNumEdit()));
    break;
  case COS:
    setNumEdit(std::cos(getNumEdit()));
    break;
  case DIV: // бинарные арифметические операции
  case MUL:
  case PLUS:
  case MINUS:
  case POKAZ:
  case LOG:
  case EQ: {
    calcPrevOp(id);
    break;
  }
  case CLR_ALL:
    initNum(); // удалить всё
  case CLR: {
    setNumEdit(0);
    // записать в m_pLineEdit число 0
    break;
  }
  case BKSP: {
    // удалить последний символ
    // если на экране резульатат предыдущей операции - сбросить
    checkOpPerf();
    QString str = m_pLineEdit->text();
    if (str.length()) {
      // если строка в m_pLineEdit не нулевая - удалить символ
      str.remove(str.length() - 1, 1);
      m_pLineEdit->setText(str);
    }
    break;
  }
  default: {
    // обработка цифровых клавиш
    // если на экране результат предыдущей операции - сбросить
    checkOpPerf();
    QString sId;
    // сформировать строку по идентификатору нажатой клавиши
    sId.setNum(id);
    QString str = m_pLineEdit->text();
    if (str == "0")
      str = sId; // затираем незначащий нуль
    else
      str.append(sId); // добавить в m_pLineEdit нажатую цифру
    m_pLineEdit->setText(str);
  }
  };
};
// Получить число из m_pLineEdit
double CalcDialog::getNumEdit() {
  double result;
  QString str = m_pLineEdit->text();
  result = str.toDouble(); // преобразовать строку в число
  return result;
};
// записать число в m_pLineEdit
void CalcDialog::setNumEdit(double num) {
  QString str;
  str.setNum(num, 'g', 25); // преобразовать вещественное число в строку
  m_pLineEdit->setText(str);
};
// Выполнить предыдущую бинарную операцию
void CalcDialog::calcPrevOp(int curOp) {
  // получить число на экране
  // m_Val хранит число, введенное до нажатия кнопки операции
  double num = getNumEdit();
  switch (m_Op) {
  case DIV: {
    if (num != 0)
      m_Val /= num;
    else
      m_Val = 0;
    break;
  }
  case MUL: {
    m_Val *= num;
    break;
  }
  case PLUS: {
    m_Val += num;
    break;
  }
  case MINUS: {
    m_Val -= num;
    break;
  }
  case EQ: { // если была нажата кнопка "=" - не делать ничего
    m_Val = num;
    break;
  }
  case POKAZ: {
    m_Val = std::pow(m_Val, num);
    break;
  }
  case LOG: {
    if (m_Val > 0 && num > 0 && num != 0)
      m_Val = std::log(m_Val) / std::log(num);
    else
      m_Val = 0;
    break;
  }
  }
  m_Op = curOp;
  // запомнить результат текущей операции
  setNumEdit(m_Val); // отобразить результат
  m_bPerf = true;
  // поставить флаг выполнения операции
};
void CalcDialog::checkOpPerf() {
  if (m_bPerf) {
    // если что-то выполнялось - очистить m_pLineEdit
    m_pLineEdit->clear();
    m_bPerf = false;
  };
};
void CalcDialog::initNum() {
  m_bPerf = false;
  m_Val = 0;
  m_Op = EQ;
};
