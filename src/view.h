#ifndef VIEW_H
#define VIEW_H

/************************************************************
 * @file view.h
 * @brief Presentation (form of user interface for interaction with the program)
 ************************************************************/

#include <QChar>
#include <QKeyEvent>
#include <QLineEdit>
#include <QMainWindow>
#include <QString>

#include "Controller.h"

/************************************************************
 * @brief View class
 ************************************************************/
QT_BEGIN_NAMESPACE
namespace Ui {
class View;
}
QT_END_NAMESPACE

class View : public QMainWindow {
  Q_OBJECT

 public:
  View(QWidget *parent = nullptr);
  ~View();

 private:
  Ui::View *ui;
  s21::Controller controller;

 protected:
  void keyPressEvent(QKeyEvent *e) override;

 private slots:
  void input_numbers();
  void input_operators();
  void input_functions();
  QString start(QString button_text);
  void on_lineEdit_textChanged(const QString &arg1);
  void on_pushButton_dot_clicked();
  void on_pushButton_EQ_clicked();
  void on_pushButton_CA_clicked();
  void on_pushButton_x_clicked();
  void on_pushButton_Plot_clicked();
};
#endif  // VIEW_H
