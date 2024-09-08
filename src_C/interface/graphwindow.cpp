#include "graphwindow.h"

#include "ui_graphwindow.h"
extern "C" {
#include "../core/scientific_calc.h"
}

GraphWindow::GraphWindow(QWidget *parent)
    : QWidget(parent), ui(new Ui::GraphWindow) {
  ui->setupUi(this);

  ui->widget->addGraph();
  ui->widget->graph(0)->addData(x, y);
  ui->widget->setBackground(QColor(255, 224, 244));

  // yAxis
  ui->widget->yAxis->setBasePen(QPen(QColor(227, 5, 173)));
  ui->widget->yAxis->setTickPen(QPen(QColor(227, 5, 173)));
  ui->widget->yAxis->setSubTickPen(QPen(QColor(227, 5, 173)));
  ui->widget->yAxis->grid()->setSubGridVisible(true);
  ui->widget->yAxis->setTickLabelColor(QColor(227, 5, 173));
  ui->widget->yAxis->setLabelColor(QColor(227, 5, 173));
  // xAxis
  ui->widget->xAxis->setBasePen(QPen(QColor(227, 5, 173)));
  ui->widget->xAxis->setTickPen(QPen(QColor(227, 5, 173)));
  ui->widget->xAxis->setSubTickPen(QPen(QColor(227, 5, 173)));
  ui->widget->xAxis->grid()->setSubGridVisible(true);
  ui->widget->xAxis->setTickLabelColor(QColor(227, 5, 173));
  ui->widget->xAxis->setLabelColor(QColor(227, 5, 173));

  // прикол
  ui->widget->setInteraction(QCP::iRangeZoom, true);
  ui->widget->setInteraction(QCP::iRangeDrag, true);

  // ui->widget->replot();
  // ui->widget->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle,
  // 4));
}

GraphWindow::~GraphWindow() { delete ui; }

void GraphWindow::on_pushButton_graph_clicked(char *line) {
  QPen pen;
  ui->widget->clearGraphs();
  strcpy(temp_str, line);
  double mel, x_range, y_range;

  h = 0.01;
  x_begin = ui->its_x_min->text().toDouble();
  x_end = ui->its_x_max->text().toDouble();
  x_range = ui->its_x_range->text().toDouble();
  y_range = ui->its_y_range->text().toDouble();

  if (x_begin < x_end) {
    ui->widget->xAxis->setRange(-1 * x_range, x_range);
    ui->widget->yAxis->setRange(-1 * y_range, y_range);

    amount_of_points = (x_end - x_begin) / h + 2;

    for (X = x_begin; X <= x_end; X += h) {
      mel = calc(temp_str, X);

      x.push_back(X);
      y.push_back(mel);
    }

    ui->widget->addGraph();
    ui->widget->graph(0)->addData(x, y);

    // line
    pen.setWidth(2);
    pen.setColor(QColor(227, 5, 173));
    ui->widget->graph(0)->setPen(pen);
    ui->widget->graph(0)->setLineStyle(QCPGraph::lsNone);
    ui->widget->graph(0)->setScatterStyle(
        QCPScatterStyle(QCPScatterStyle::ssCircle, 0.5));

    ui->widget->replot();
    x.clear();
    y.clear();
  }
}

void GraphWindow::on_pushButton_graph_clicked() {
  ui->widget->clearGraphs();
  GraphWindow::on_pushButton_graph_clicked(temp_str);
}
