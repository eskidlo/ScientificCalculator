#ifndef GRAPH_H
#define GRAPH_H

#include <QWidget>

#include "../controller/controller.h"
#include "../extra/qcustomplot.h"
#include "./ui_graph.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Graph;
}
QT_END_NAMESPACE

namespace scientific_calc {

class Graph : public QDialog {
  Q_OBJECT

 public:
  explicit Graph(QWidget *parent = nullptr);
  ~Graph();
  void SetWindow();
  QString str = "";

 public slots:
  void on_pushButtonGraph_clicked();

 private:
  Ui::Graph *ui;
  scientific_calc::Controller controller_;
};
}  // namespace scientific_calc
#endif  // GRAPH_H
