#include "./controller.h"

#include <QDebug>

namespace scientific_calc {

double Controller::Calculate(double x) {
  model.inputLine = str.toStdString();
  double answer = 0;
  std::vector<std::string> notation;

  model.Validator();
  notation = model.Parcer();
  answer = model.Calc(notation, x);

  model.inputLine.clear();
  str.clear();
  model.tokens.clear();

  return answer;
}

QString Controller::showText() { return str; }

void Controller::dealWithGraph(QString strTemp) {
  QString temp = strTemp;
  for (X = xBegin; X <= xEnd; X += h) {
    str = temp;

    x.push_back(X);
    y.push_back(Calculate(X));
  }
}

}  // namespace scientific_calc
