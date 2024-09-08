#include <QApplication>

#include "./calcview.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  scientific_calc::SmartCalc w;
  w.show();
  return a.exec();
}
