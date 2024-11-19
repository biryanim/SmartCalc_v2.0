#include <iostream>

#include "Model.h"

using namespace s21;

int main() {
  Model model;
  double res = 0;
  // for(double i = -3; i  < 3; i+=0.01){
  //     bool flag = model.Calculate("x", std::to_string(i), res);
  //     if(!flag){
  //         std::cout << "Error" << '\n';
  //         return 1;
  //     }
  //     std::cout << res << '\n';
  // }
  // bool flag = model.Calculate("x*2-32.9", "-2.3", res);
  // if(!flag){
  //         std::cout << "Error" << '\n';
  //         return 1;
  //     }
  // std::cout << res << '\n';
  std::string str;
  double s = 2;
  str = std::to_string(s);
  std::cout << str;
}

/*
sqrt((6^atan())*9)
6 atan ^ 9 * sqrt

atan(6)

6 7 ^ 9 * 8
1 4 2 1 2 4

*/