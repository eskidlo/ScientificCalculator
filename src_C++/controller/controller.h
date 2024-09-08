#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QApplication>
#include <QLabel>

#include "../model/calcmodel.h"

namespace scientific_calc {

class Controller {
 private:
  scientific_calc::Model model;

 public:
  Controller() = default;
  ~Controller() = default;
  Controller(const Controller &) = default;
  Controller(Controller &&) = default;
  Controller &operator=(const Controller &) = default;

  QString str = "";
  QVector<double> x, y;
  double xBegin, xEnd, h = 0.01, X, xRange, yRange;
  int N;

  double Calculate(double x);
  QString showText();
  void dealWithGraph(QString str);
};
}  // namespace scientific_calc
#endif  // CONTROLLER_H
