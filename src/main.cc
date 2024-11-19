/************************************************************
 * @mainpage
 * @author biryanim
 * @version 2.0
 * @file main.cc
 * @brief Entry point
 ************************************************************/

#include <QApplication>

#include "view.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  View w;
  w.show();
  return a.exec();
}
