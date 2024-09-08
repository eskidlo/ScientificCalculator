#include "./graph.h"

namespace scientific_calc {

Graph::Graph(QWidget *parent) : QDialog(parent), ui(new Ui::Graph) {
  ui->setupUi(this);

  ui->widget->addGraph();
  ui->widget->graph(0)->addData(controller_.x, controller_.y);
  ui->widget->setBackground(QColor(255, 224, 244));
  SetWindow();
}

Graph::~Graph() { delete ui; }

void Graph::on_pushButtonGraph_clicked() {
  ui->widget->clearGraphs();
  try {
    QPen pen;

    controller_.xBegin = ui->xMin->text().toDouble();
    controller_.xEnd = ui->xMax->text().toDouble();
    controller_.xRange = ui->xRange->text().toDouble();
    controller_.yRange = ui->yRange->text().toDouble();

    if (controller_.xBegin < controller_.xEnd) {
      ui->widget->xAxis->setRange(-1 * controller_.xRange, controller_.xRange);
      ui->widget->yAxis->setRange(-1 * controller_.yRange, controller_.yRange);
      controller_.N =
          (controller_.xEnd - controller_.xBegin) / controller_.h + 2;

      controller_.dealWithGraph(str);

      ui->widget->addGraph();
      ui->widget->graph(0)->addData(controller_.x, controller_.y);

      pen.setWidth(2);
      pen.setColor(QColor(227, 5, 173));
      ui->widget->graph(0)->setPen(pen);
      ui->widget->graph(0)->setLineStyle(QCPGraph::lsNone);
      ui->widget->graph(0)->setScatterStyle(
          QCPScatterStyle(QCPScatterStyle::ssCircle, 0.5));

      ui->widget->replot();
      controller_.x.clear();
      controller_.y.clear();
    }
  } catch (...) {
    controller_.x.clear();
    controller_.y.clear();
  }
}

void Graph::SetWindow() {
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

  // Extra
  ui->widget->setInteraction(QCP::iRangeZoom, true);
  ui->widget->setInteraction(QCP::iRangeDrag, true);
}

}  // namespace scientific_calc
