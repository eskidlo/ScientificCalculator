#ifndef SMARTCALC_H
#define SMARTCALC_H

#include <QMainWindow>
#include <QString>

#include "../controller/controller.h"
#include "../view/graph.h"
#include "./ui_smartcalc.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class SmartCalc;
}
QT_END_NAMESPACE

namespace scientific_calc {
class SmartCalc : public QMainWindow {
  Q_OBJECT

 public:
  SmartCalc(QWidget *parent = nullptr);
  ~SmartCalc();

 private slots:
  // braces
  void on_pushButtonLeftBrace_clicked();
  void on_pushButtonRightBrace_clicked();

  // digits
  void on_pushButton0_clicked();
  void on_pushButton1_clicked();
  void on_pushButton2_clicked();
  void on_pushButton3_clicked();
  void on_pushButton4_clicked();
  void on_pushButton5_clicked();
  void on_pushButton6_clicked();
  void on_pushButton7_clicked();
  void on_pushButton8_clicked();
  void on_pushButton9_clicked();

  // operations
  void on_pushButtonPlus_clicked();
  void on_pushButtonMinus_clicked();
  void on_pushButtonMult_clicked();
  void on_pushButtonDivide_clicked();
  void on_pushButtonGrade_clicked();
  void on_pushButtonMod_clicked();

  // functions

  void on_pushButtonSin_clicked();
  void on_pushButtonCos_clicked();
  void on_pushButtonTan_clicked();
  void on_pushButtonAsin_clicked();
  void on_pushButtonAcos_clicked();
  void on_pushButtonAtan_clicked();
  void on_pushButtonSqrt_clicked();
  void on_pushButtonLog_clicked();
  void on_pushButtonLn_clicked();

  // extra

  void on_pushButtonX_clicked();
  void on_pushButtonAC_clicked();
  void on_pushButtonPoint_clicked();
  void on_pushButtonDeleteLast_clicked();
  void on_pushButtonEqual_clicked();

  void on_pushButtonGraph_clicked();

 private:
  Ui::SmartCalc *ui;
  scientific_calc::Graph *gWindow;
  scientific_calc::Controller controller;
};
}  // namespace scientific_calc
#endif  // SMARTCALC_H
