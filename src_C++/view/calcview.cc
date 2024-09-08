#include "./calcview.h"

namespace scientific_calc {
SmartCalc::SmartCalc(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::SmartCalc) {
  ui->setupUi(this);
  gWindow = new Graph();
}

SmartCalc::~SmartCalc() { delete ui; }

// braces
void SmartCalc::on_pushButtonLeftBrace_clicked() {
  ui->showRes->setText("");
  controller.str += ui->showRes->text() + "(";
  ui->showRes->setText(controller.showText());
}

void SmartCalc::on_pushButtonRightBrace_clicked() {
  ui->showRes->setText("");
  controller.str += ui->showRes->text() + ")";
  ui->showRes->setText(controller.showText());
}

// digits
void SmartCalc::on_pushButton0_clicked() {
  ui->showRes->setText("");
  controller.str += ui->showRes->text() + "0";
  ui->showRes->setText(controller.showText());
}

void SmartCalc::on_pushButton1_clicked() {
  ui->showRes->setText("");
  controller.str += ui->showRes->text() + "1";
  ui->showRes->setText(controller.showText());
}

void SmartCalc::on_pushButton2_clicked() {
  ui->showRes->setText("");
  controller.str += ui->showRes->text() + "2";
  ui->showRes->setText(controller.showText());
}

void SmartCalc::on_pushButton3_clicked() {
  ui->showRes->setText("");
  controller.str += ui->showRes->text() + "3";
  ui->showRes->setText(controller.showText());
}

void SmartCalc::on_pushButton4_clicked() {
  ui->showRes->setText("");
  controller.str += ui->showRes->text() + "4";
  ui->showRes->setText(controller.showText());
}

void SmartCalc::on_pushButton5_clicked() {
  ui->showRes->setText("");
  controller.str += ui->showRes->text() + "5";
  ui->showRes->setText(controller.showText());
}

void SmartCalc::on_pushButton6_clicked() {
  ui->showRes->setText("");
  controller.str += ui->showRes->text() + "6";
  ui->showRes->setText(controller.showText());
}

void SmartCalc::on_pushButton7_clicked() {
  ui->showRes->setText("");
  controller.str += ui->showRes->text() + "7";
  ui->showRes->setText(controller.showText());
}

void SmartCalc::on_pushButton8_clicked() {
  ui->showRes->setText("");
  controller.str += ui->showRes->text() + "8";
  ui->showRes->setText(controller.showText());
}

void SmartCalc::on_pushButton9_clicked() {
  ui->showRes->setText("");
  controller.str += ui->showRes->text() + "9";
  ui->showRes->setText(controller.showText());
}

void SmartCalc::on_pushButtonPlus_clicked() {
  ui->showRes->setText("");
  controller.str += ui->showRes->text() + "+";
  ui->showRes->setText(controller.showText());
}

void SmartCalc::on_pushButtonMinus_clicked() {
  ui->showRes->setText("");
  controller.str += ui->showRes->text() + "-";
  ui->showRes->setText(controller.showText());
}

void SmartCalc::on_pushButtonMult_clicked() {
  ui->showRes->setText("");
  controller.str += ui->showRes->text() + "*";
  ui->showRes->setText(controller.showText());
}

void SmartCalc::on_pushButtonDivide_clicked() {
  ui->showRes->setText("");
  controller.str += ui->showRes->text() + "/";
  ui->showRes->setText(controller.showText());
}

void SmartCalc::on_pushButtonGrade_clicked() {
  ui->showRes->setText("");
  controller.str += ui->showRes->text() + "^";
  ui->showRes->setText(controller.showText());
}

void SmartCalc::on_pushButtonMod_clicked() {
  ui->showRes->setText("");
  controller.str += ui->showRes->text() + "mod";
  ui->showRes->setText(controller.showText());
}

void SmartCalc::on_pushButtonSin_clicked() {
  ui->showRes->setText("");
  controller.str += ui->showRes->text() + "sin(";
  ui->showRes->setText(controller.showText());
}

void SmartCalc::on_pushButtonCos_clicked() {
  ui->showRes->setText("");
  controller.str += ui->showRes->text() + "cos(";
  ui->showRes->setText(controller.showText());
}

void SmartCalc::on_pushButtonTan_clicked() {
  ui->showRes->setText("");
  controller.str += ui->showRes->text() + "tan(";
  ui->showRes->setText(controller.showText());
}

void SmartCalc::on_pushButtonAsin_clicked() {
  ui->showRes->setText("");
  controller.str += ui->showRes->text() + "asin(";
  ui->showRes->setText(controller.showText());
}

void SmartCalc::on_pushButtonAcos_clicked() {
  ui->showRes->setText("");
  controller.str += ui->showRes->text() + "acos(";
  ui->showRes->setText(controller.showText());
}

void SmartCalc::on_pushButtonAtan_clicked() {
  ui->showRes->setText("");
  controller.str += ui->showRes->text() + "atan(";
  ui->showRes->setText(controller.showText());
}

void SmartCalc::on_pushButtonSqrt_clicked() {
  ui->showRes->setText("");
  controller.str += ui->showRes->text() + "sqrt(";
  ui->showRes->setText(controller.showText());
}

void SmartCalc::on_pushButtonLog_clicked() {
  ui->showRes->setText("");
  controller.str += ui->showRes->text() + "log(";
  ui->showRes->setText(controller.showText());
}

void SmartCalc::on_pushButtonLn_clicked() {
  ui->showRes->setText("");
  controller.str += ui->showRes->text() + "ln(";
  ui->showRes->setText(controller.showText());
}

void SmartCalc::on_pushButtonX_clicked() {
  ui->showRes->setText("");
  controller.str += ui->showRes->text() + "x";
  ui->showRes->setText(controller.showText());
}

void SmartCalc::on_pushButtonAC_clicked() {
  gWindow->close();

  ui->showRes->setText("");
  ui->lineX->setText("");
  controller.str.clear();
  ui->showRes->setText(controller.showText());
}

void SmartCalc::on_pushButtonPoint_clicked() {
  ui->showRes->setText("");
  controller.str += ui->showRes->text() + ".";
  ui->showRes->setText(controller.showText());
}

void SmartCalc::on_pushButtonDeleteLast_clicked() {
  ui->showRes->setText("");
  controller.str.chop(1);
  ui->showRes->setText(controller.showText());
}

void SmartCalc::on_pushButtonEqual_clicked() {
  try {
    QString str;
    if (controller.str.contains("x")) {
      this->on_pushButtonGraph_clicked();
      str =
          QString::number(controller.Calculate((ui->lineX->text()).toDouble()));
    } else {
      str = QString::number(controller.Calculate(0), 'g', 8);
    }
    ui->showRes->setText(str);

  } catch (...) {
    ui->showRes->setText("ERROR");
  }
}

void SmartCalc::on_pushButtonGraph_clicked() {
  gWindow->str = ui->showRes->text();
  gWindow->on_pushButtonGraph_clicked();
  gWindow->show();
}

}  // namespace scientific_calc
