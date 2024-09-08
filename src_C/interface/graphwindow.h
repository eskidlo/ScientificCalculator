#ifndef GRAPHWINDOW_H
#define GRAPHWINDOW_H

#include <qcustomplot.h>

#include <QVector>
#include <QWidget>

namespace Ui {
class GraphWindow;
}

class GraphWindow : public QWidget {
  Q_OBJECT

 public:
  explicit GraphWindow(QWidget *parent = nullptr);
  void on_pushButton_graph_clicked(char *line);
  ~GraphWindow();
 signals:
  void firstWindow();

 public slots:
  void on_pushButton_graph_clicked();

 private:
  Ui::GraphWindow *ui;
  double x_begin, x_end, h, X;
  int amount_of_points;
  QVector<double> x, y;
  char temp_str[256];
};

#endif  // GRAPHWINDOW_H
