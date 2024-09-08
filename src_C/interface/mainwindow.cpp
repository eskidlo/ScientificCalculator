#include "mainwindow.h"

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  gWindow = new GraphWindow();
  // connect(gWindow, &::GraphWindow::firstWindow, this, &MainWindow::show);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_pushButton_point_clicked() {
  ui->show_result->setText(ui->show_result->text() + ".");
}

void MainWindow::on_pushButton_left_brace_clicked() {
  ui->show_result->setText(ui->show_result->text() + "(");
}

void MainWindow::on_pushButton_right_brace_clicked() {
  ui->show_result->setText(ui->show_result->text() + ")");
}

void MainWindow::on_pushButton_grade_clicked() {
  ui->show_result->setText(ui->show_result->text() + "^");
}

void MainWindow::on_pushButton_sin_clicked() {
  ui->show_result->setText(ui->show_result->text() + "sin(");
}

void MainWindow::on_pushButton_cos_clicked() {
  ui->show_result->setText(ui->show_result->text() + "cos(");
}

void MainWindow::on_pushButton_tan_clicked() {
  ui->show_result->setText(ui->show_result->text() + "tan(");
}

void MainWindow::on_pushButton_mod_clicked() {
  ui->show_result->setText(ui->show_result->text() + "mod");
}

void MainWindow::on_pushButton_asin_clicked() {
  ui->show_result->setText(ui->show_result->text() + "asin(");
}

void MainWindow::on_pushButton_acos_clicked() {
  ui->show_result->setText(ui->show_result->text() + "acos(");
}

void MainWindow::on_pushButton_atan_clicked() {
  ui->show_result->setText(ui->show_result->text() + "atan(");
}

void MainWindow::on_pushButton_sqrt_clicked() {
  ui->show_result->setText(ui->show_result->text() + "sqrt(");
}

void MainWindow::on_pushButton_log_clicked() {
  ui->show_result->setText(ui->show_result->text() + "log(");
}

void MainWindow::on_pushButton_ln_clicked() {
  ui->show_result->setText(ui->show_result->text() + "ln(");
}

void MainWindow::on_pushButton_divide_clicked() {
  ui->show_result->setText(ui->show_result->text() + "/");
}

void MainWindow::on_pushButton_multiply_clicked() {
  ui->show_result->setText(ui->show_result->text() + "*");
}

void MainWindow::on_pushButton_minus_clicked() {
  ui->show_result->setText(ui->show_result->text() + "-");
}

void MainWindow::on_pushButton_plus_clicked() {
  ui->show_result->setText(ui->show_result->text() + "+");
}

void MainWindow::on_pushButton_7_clicked() {
  ui->show_result->setText(ui->show_result->text() + "7");
}

void MainWindow::on_pushButton_8_clicked() {
  ui->show_result->setText(ui->show_result->text() + "8");
}

void MainWindow::on_pushButton_9_clicked() {
  ui->show_result->setText(ui->show_result->text() + "9");
}

void MainWindow::on_pushButton_4_clicked() {
  ui->show_result->setText(ui->show_result->text() + "4");
}

void MainWindow::on_pushButton_5_clicked() {
  ui->show_result->setText(ui->show_result->text() + "5");
}

void MainWindow::on_pushButton_6_clicked() {
  ui->show_result->setText(ui->show_result->text() + "6");
}

void MainWindow::on_pushButton_1_clicked() {
  ui->show_result->setText(ui->show_result->text() + "1");
}

void MainWindow::on_pushButton_2_clicked() {
  ui->show_result->setText(ui->show_result->text() + "2");
}

void MainWindow::on_pushButton_3_clicked() {
  ui->show_result->setText(ui->show_result->text() + "3");
}

void MainWindow::on_pushButton_0_clicked() {
  ui->show_result->setText(ui->show_result->text() + "0");
}

void MainWindow::on_pushButton_AC_clicked() {
  ui->show_result->clear();
  ui->show_result->setText("");
}

void MainWindow::on_pushButton_equal_clicked() {
  QString meow = ui->show_result->text();
  QByteArray ba = meow.toLocal8Bit();
  char *line = ba.data();
  char *result;
  double res, double_x = 0;
  if (meow.length() < 256) {
    if (!validator(line)) {
      result = parcer(line);
      if (ui->show_result->text().contains("x")) {
        double_x = ui->lineEdit_x->text().toDouble();
        res = calc(result, double_x);
        ui->show_result->clear();
        ui->show_result->setText("");
        QString textRes = QString::number(res, 'g', 8);
        ui->show_result->setText(textRes);
        gWindow->on_pushButton_graph_clicked(result);
        gWindow->show();
      } else {
        res = calc(result, 0.0);
        ui->show_result->clear();
        ui->show_result->setText("");
        QString textRes = QString::number(res, 'g', 8);
        ui->show_result->setText(textRes);
      }
    } else {
      ui->show_result->setText("ERROR INPUT");
    }
  } else {
    ui->show_result->setText("ERROR INPUT");
  }
}

void MainWindow::on_pushButton_x_clicked() {
  if (!(ui->show_result->text().endsWith("x")))
    ui->show_result->setText(ui->show_result->text() + "x");
}

void MainWindow::on_pushButton_graph_clicked() {
  QString meow = ui->show_result->text();
  if (meow.length() < 256) {
    QByteArray ba = meow.toLocal8Bit();
    char *line = ba.data();
    char *result;
    if (!validator(line)) {
      result = parcer(line);
      gWindow->on_pushButton_graph_clicked(result);
      gWindow->show();
    } else {
      ui->show_result->setText("ERROR INPUT");
    }
  } else {
    ui->show_result->setText("ERROR INPUT");
  }
}
