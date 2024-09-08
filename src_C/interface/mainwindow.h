#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <graphwindow.h>
#include <qcustomplot.h>

#include <QMainWindow>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

extern "C" {
#include "./scientific_calc.h"
}

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private slots:
  void on_pushButton_equal_clicked();
  void on_pushButton_graph_clicked();

 private:
  Ui::MainWindow *ui;
  GraphWindow *gWindow;

 private slots:
  void on_pushButton_point_clicked();
  void on_pushButton_left_brace_clicked();
  void on_pushButton_right_brace_clicked();
  void on_pushButton_grade_clicked();
  void on_pushButton_sin_clicked();
  void on_pushButton_cos_clicked();
  void on_pushButton_tan_clicked();
  void on_pushButton_mod_clicked();
  void on_pushButton_asin_clicked();
  void on_pushButton_acos_clicked();
  void on_pushButton_atan_clicked();
  void on_pushButton_sqrt_clicked();
  void on_pushButton_log_clicked();
  void on_pushButton_ln_clicked();
  void on_pushButton_divide_clicked();
  void on_pushButton_multiply_clicked();
  void on_pushButton_minus_clicked();
  void on_pushButton_plus_clicked();
  void on_pushButton_7_clicked();
  void on_pushButton_8_clicked();
  void on_pushButton_9_clicked();
  void on_pushButton_4_clicked();
  void on_pushButton_5_clicked();
  void on_pushButton_6_clicked();
  void on_pushButton_1_clicked();
  void on_pushButton_2_clicked();
  void on_pushButton_3_clicked();
  void on_pushButton_0_clicked();
  void on_pushButton_AC_clicked();
  void on_pushButton_x_clicked();
};
#endif  // MAINWINDOW_H
