/************************************************************
 * @file Controller.cc
 * @brief A controller that modifies the model based on the user's action.
 ************************************************************/

#include "Controller.h"

using namespace s21;

bool Controller::Calculate(std::string expression, std::string x_value,
                           double& res) {
  return model.Calculate(expression, x_value, res);
}

bool Controller::ValidToken(Token_type clicked, char cur_token,
                            char prev_token) {
  return model.ValidInput(clicked, cur_token, prev_token);
}