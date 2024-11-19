/************************************************************
 * @file view.cc
 * @brief Presentation (form of user interface for interaction with the program)
 ************************************************************/

#include "view.h"

#include "ui_view.h"

View::View(QWidget *parent) : QMainWindow(parent), ui(new Ui::View) {
  ui->setupUi(this);
  ui->lineEdit->setReadOnly((true));

  ui->widget->setBackground(QColor("#5f6368"));
  ui->widget->yAxis->setTickLabelColor(QColor(Qt::white));
  ui->widget->xAxis->setTickLabelColor(QColor(Qt::white));
  ui->widget->xAxis->setLabelColor("white");
  ui->widget->yAxis->setLabelColor("white");
  ui->widget->xAxis->setLabel("x");
  ui->widget->yAxis->setLabel("y");

  connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(input_numbers()));
  connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(input_numbers()));
  connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(input_numbers()));
  connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(input_numbers()));
  connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(input_numbers()));
  connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(input_numbers()));
  connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(input_numbers()));
  connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(input_numbers()));
  connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(input_numbers()));
  connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(input_numbers()));

  connect(ui->pushButton_minus, SIGNAL(clicked()), this,
          SLOT(input_operators()));
  connect(ui->pushButton_plus, SIGNAL(clicked()), this,
          SLOT(input_operators()));
  connect(ui->pushButton_mul, SIGNAL(clicked()), this, SLOT(input_operators()));
  connect(ui->pushButton_div, SIGNAL(clicked()), this, SLOT(input_operators()));
  connect(ui->pushButton_pow, SIGNAL(clicked()), this, SLOT(input_operators()));
  connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(input_operators()));
  connect(ui->pushButton_OB, SIGNAL(clicked()), this, SLOT(input_operators()));
  connect(ui->pushButton_CB, SIGNAL(clicked()), this, SLOT(input_operators()));

  connect(ui->pushButton_cos, SIGNAL(clicked()), this, SLOT(input_functions()));
  connect(ui->pushButton_sin, SIGNAL(clicked()), this, SLOT(input_functions()));
  connect(ui->pushButton_tan, SIGNAL(clicked()), this, SLOT(input_functions()));
  connect(ui->pushButton_acos, SIGNAL(clicked()), this,
          SLOT(input_functions()));
  connect(ui->pushButton_asin, SIGNAL(clicked()), this,
          SLOT(input_functions()));
  connect(ui->pushButton_atan, SIGNAL(clicked()), this,
          SLOT(input_functions()));
  connect(ui->pushButton_sqrt, SIGNAL(clicked()), this,
          SLOT(input_functions()));
  connect(ui->pushButton_log, SIGNAL(clicked()), this, SLOT(input_functions()));
  connect(ui->pushButton_ln, SIGNAL(clicked()), this, SLOT(input_functions()));
}

QString View::start(QString button_text) {
  if (ui->lineEdit->text().compare("Error") == 0 ||
      ui->lineEdit->text().compare("inf") == 0 ||
      ui->lineEdit->text().compare("-inf") == 0 ||
      ui->lineEdit->text().compare("nan") == 0)
    ui->lineEdit->setText("0");
  return (ui->lineEdit->text() == "0") ? button_text
                                       : ui->lineEdit->text() + button_text;
}

void View::input_numbers() {
  if (controller.ValidToken(s21::NUMBER, '\0',
                            ui->lineEdit->text().length() <= 1
                                ? '\0'
                                : (ui->lineEdit->text())
                                      .at(ui->lineEdit->text().length() - 1)
                                      .toLatin1())) {
    QPushButton *button = (QPushButton *)sender();
    ui->lineEdit->setText(start(button->text()));
  }
}

void View::input_operators() {
  QPushButton *button = (QPushButton *)sender();

  if (controller.ValidToken(s21::BINARY_OPERATOR,
                            (button->text()).at(0).toLatin1(),
                            ui->lineEdit->text().length() <= 1
                                ? '\0'
                                : (ui->lineEdit->text())
                                      .at(ui->lineEdit->text().length() - 1)
                                      .toLatin1())) {
    ui->lineEdit->setText(ui->lineEdit->text() + button->text());
  }
}

void View::input_functions() {
  if (controller.ValidToken(s21::FUNCTION, '\0',
                            ui->lineEdit->text().length() <= 1
                                ? '\0'
                                : (ui->lineEdit->text())
                                      .at(ui->lineEdit->text().length() - 1)
                                      .toLatin1())) {
    QPushButton *button = (QPushButton *)sender();
    ui->lineEdit->setText(start(button->text()) + "(");
  }
}

void View::keyPressEvent(QKeyEvent *e) {
  if (e->key() >= Qt::Key_0 && e->key() <= Qt::Key_9)
    ui->lineEdit->setText(start(e->text()));
  else if (e->key() == (Qt::Key_Plus))
    ui->pushButton_plus->clicked(true);
  else if (e->key() == (Qt::Key_Minus))
    ui->pushButton_minus->clicked();
  else if (e->key() == (Qt::Key_Asterisk))
    ui->pushButton_mul->clicked();
  else if (e->key() == (Qt::Key_Slash))
    ui->pushButton_div->clicked();
  else if (e->key() == (Qt::Key_Percent))
    ui->pushButton_mod->clicked();
  else if (e->key() == (Qt::Key_AsciiCircum))
    ui->pushButton_pow->clicked();
  else if (e->key() == (Qt::Key_ParenLeft))
    ui->pushButton_OB->clicked();
  else if (e->key() == (Qt::Key_ParenRight))
    ui->pushButton_CB->clicked();
  else if (e->key() == Qt::Key_C && (e->modifiers() & Qt::ShiftModifier))
    ui->pushButton_acos->clicked();
  else if (e->key() == Qt::Key_C)
    ui->pushButton_cos->clicked();
  else if (e->key() == Qt::Key_S && (e->modifiers() & Qt::ShiftModifier))
    ui->pushButton_asin->clicked();
  else if (e->key() == Qt::Key_S)
    ui->pushButton_sin->clicked();
  else if (e->key() == Qt::Key_T && (e->modifiers() & Qt::ShiftModifier))
    ui->pushButton_atan->clicked();
  else if (e->key() == Qt::Key_T)
    ui->pushButton_tan->clicked();
  else if (e->key() == Qt::Key_L && (e->modifiers() & Qt::ShiftModifier))
    ui->pushButton_log->clicked();
  else if (e->key() == Qt::Key_L)
    ui->pushButton_ln->clicked();
  else if (e->key() == Qt::Key_R)
    ui->pushButton_sqrt->clicked();
  else if (e->key() == Qt::Key_Period)
    ui->pushButton_dot->clicked();
  else if (e->key() == Qt::Key_Equal)
    ui->pushButton_EQ->clicked();
  else if (e->key() == Qt::Key_Backspace)
    ui->pushButton_CA->clicked();
  else if (e->key() == Qt::Key_X)
    ui->pushButton_x->clicked();
}

void View::on_lineEdit_textChanged(const QString &arg1) {
  ui->lineEdit->setCursorPosition(arg1.length());
}

void View::on_pushButton_x_clicked() {
  if (controller.ValidToken(s21::X_VALUE,
                            ui->lineEdit->text().length() == 1 ? 's' : '\0',
                            ui->lineEdit->text().length() < 1
                                ? '\0'
                                : (ui->lineEdit->text())
                                      .at(ui->lineEdit->text().length() - 1)
                                      .toLatin1())) {
    QPushButton *button = (QPushButton *)sender();
    ui->lineEdit->setText(start(button->text()));
  }
}

void View::on_pushButton_dot_clicked() {
  if (ui->lineEdit->text().compare("Error") == 0 ||
      ui->lineEdit->text().compare("Infinity") == 0)
    ui->lineEdit->setText("0");
  ui->lineEdit->setText(ui->lineEdit->text() + ".");
}

void View::on_pushButton_EQ_clicked() {
  double res;
  if (!controller.Calculate(ui->lineEdit->text().toStdString(),
                            ui->lineEdit_x_value->text().toStdString(), res)) {
    ui->lineEdit->setText("Error");
    return;
  }
  ui->lineEdit->setText(QString::number(res));
}

void View::on_pushButton_CA_clicked() { ui->lineEdit->setText("0"); }

void View::on_pushButton_Plot_clicked() {
  ui->widget->clearGraphs();
  QVector<double> x, y;
  int xBegin, xEnd, yBegin, yEnd;
  xBegin = ui->lineEdit_x_min->text().toInt();
  xEnd = ui->lineEdit_x_max->text().toInt();
  yBegin = ui->lineEdit_y_min->text().toInt();
  yEnd = ui->lineEdit_y_max->text().toInt();
  ui->widget->xAxis->setRange(xBegin, xEnd);
  ui->widget->yAxis->setRange(yBegin, yEnd);
  double frequency = 1.0;
  if (xBegin <= 1000 && xEnd <= 1000) frequency = 0.1;
  if (xBegin <= 10 && xEnd <= 10) frequency = 0.01;
  double res;
  for (double i = xBegin; i <= xEnd; i += frequency) {
    x.push_back(i);
    if (!controller.Calculate(ui->lineEdit->text().toStdString(),
                              std::to_string(i), res))
      return;
    y.push_back(res);
  }
  ui->widget->addGraph();
  ui->widget->graph(0)->setPen(QPen(QColor("#8ab4f8")));
  ui->widget->graph(0)->addData(x, y);
  ui->widget->graph(0)->setLineStyle(QCPGraph::lsNone);
  ui->widget->graph(0)->setScatterStyle(
      QCPScatterStyle(QCPScatterStyle::ssDisc, 2));
  ui->widget->replot();
  x.clear();
  y.clear();
}

View::~View() { delete ui; }
