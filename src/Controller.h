#ifndef CONTROLLER_H
#define CONTROLLER_H

/************************************************************
 * @file Controller.h
 * @brief A controller that modifies the model based on the user's action.
 ************************************************************/

#include "Model.h"

namespace s21 {

/************************************************************
 * @brief Controller class that modifies the model based on the user's action.
 ************************************************************/
class Controller {
 public:
  /************************************************************
   * @brief Method calling method from Model.h calculating expression
   * @param expression Expression
   * @param x_value X value
   * @param res Result of computing
   ************************************************************/
  bool Calculate(std::string expression, std::string x_value, double& res);

  /************************************************************
   * @brief Method calling method from Model.h checking input validate
   ************************************************************/
  bool ValidToken(Token_type clicked, char cur_token, char prev_token);

 private:
  Model model;
};
}  // namespace s21

#endif