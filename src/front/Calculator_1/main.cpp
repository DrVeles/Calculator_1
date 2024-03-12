#include <QApplication>

#include "s21_calc.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  s21_calc w;
  w.show();
  return a.exec();
}
