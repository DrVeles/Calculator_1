#ifndef S21_CALC_H
#define S21_CALC_H

#include <QMainWindow>
#include <QVector>

extern "C" {
#include "../../s21_calc_controller.h"
}

QT_BEGIN_NAMESPACE
namespace Ui {
class s21_calc;
}
QT_END_NAMESPACE

class s21_calc : public QMainWindow {
  Q_OBJECT

 public:
  s21_calc(QWidget *parent = nullptr);
  ~s21_calc();
  bool is_result_clicked_last;

 private:
  Ui::s21_calc *ui;

 private slots:
  void initial_graph();
  void click_to_number();
  void click_to_operator();
  void click_to_bracket();
  void click_to_math_foo();
  void click_to_result();
  void on_pushButton_clear_all_clicked();
  void on_pushButton_x_clicked();
  void on_pushButton_create_graph_clicked();
  double convert_x_to_y(double x, QString text);
};

#endif  // S21_CALC_H
