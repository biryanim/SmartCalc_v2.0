#ifndef MODEL_H
#define MODEL_H

/************************************************************
 * @file Model.h
 * @brief A model containing the business logic of smart claculator
 ************************************************************/

#include <cmath>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>

namespace s21 {

/************************************************************
 * @brief Token types
 *
 * Token types fot definition of operations, functions and numbers
 ************************************************************/
enum Token_type {
  NON,              // 0
  NUMBER,           // 1
  BINARY_OPERATOR,  // 2
  UNARY_OPERATOR,   // 3
  FUNCTION,         // 4
  X_VALUE
};

/************************************************************
 * @brief Types of functions
 *
 * Name of functions supported by the calculator
 ************************************************************/
enum FUNCTIONS { LN = 0, LOG, COS, SIN, TAN, ACOS, ASIN, ATAN, SQRT };

/************************************************************
 * @brief A model containing the business logic of smart claculator
 ************************************************************/
class Model {
  /************************************************************
   * @brief Token struct
   *
   * @param value_ Value of the token
   * @param priority_ Priority of the token
   * @param type_ Type of the token
   ************************************************************/
  struct Token {
    std::string value_{};
    int priority_ = 0;
    Token_type type_ = NON;
  };

  /************************************************************
   * @brief Vector of tokens
   * @param postfix_entry Vector into which the expression is written in the
   *form of inverse Polish notation
   ************************************************************/
  std::vector<Token> postfix_entry;

  /************************************************************
   * @brief Map of binary operators
   * @param binary_operators map containing the keys as chara(binary operation)
   *and the value that is the priority
   ************************************************************/
  std::map<char, int> binary_operators = {
      {'(', 1}, {')', 1}, {'f', 2}, {'^', 3}, {'u', 4},
      {'*', 5}, {'/', 5}, {'m', 5}, {'+', 6}, {'-', 6}};

  /************************************************************
   * @brief Vector with function names
   ************************************************************/
  std::vector<std::string> functions = {"ln(",   "log(",  "cos(",
                                        "sin(",  "tan(",  "acos(",
                                        "asin(", "atan(", "sqrt("};

  /************************************************************
   * @brief Function determining whether an operator is unary
   * @param it String iterator
   * @param support Previous token
   ************************************************************/
  bool IsItUnaryOperator(std::string::iterator it, Token& support);

  /************************************************************
   * @brief Function determining whether an operator is binary
   * @param it String iterator
   * @param support Previous token
   ************************************************************/
  bool IsItBinaryOperator(std::string::iterator& it, Token& support);

  /************************************************************
   * @brief Function determining whether the function
   * @param it String iterator
   * @param support Previous token
   ************************************************************/
  bool IsItFunction(std::string::iterator& it, Token& support);

  /************************************************************
   * @brief Method for constructing inverse Polish notation
   * @param support Current token
   * @param st Stack for operators and functions
   ************************************************************/
  bool StackOfOperators(Token& support, std::stack<Token>& st);

  /************************************************************
   * @brief Compute unary expression
   * @param unary_operator Unary operator
   * @param st Stack for computing expression
   ************************************************************/
  bool computeUnary(char unary_operator, std::stack<Token>& st);

  /************************************************************
   * @brief Compute functions
   * @param func Function
   * @param st Stack for computing expression
   ************************************************************/
  bool computeFunction(char func, std::stack<Token>& st);

  /************************************************************
   * @brief Compute binary
   * @param op Binary operator
   * @param st Stack for computing expression
   ************************************************************/
  bool computeBinary(char op, std::stack<Token>& st);

  /************************************************************
   * @brief Evaluates the expression given in reverse Polish notation and return
   *false if there is an error
   * @param res Result of computing
   ************************************************************/
  bool CalculateRpnExpression(double& res);

 public:
  Model() = default;

  /************************************************************
   * @brief Сonverts infix notation to Polish notation
   * @param expression Expression
   ************************************************************/
  bool parser(std::string expression);

  /************************************************************
   * @brief Main method for calculating
   * @param expression Expression
   * @param x_value X value
   * @param res Result of the computing
   ************************************************************/
  bool Calculate(std::string expression, std::string x_value, double& res);

  /************************************************************
   * @brief Checks the validity of the input data
   * @param cliecked Input token(number, operator, dot, x or function)
   * @param cur_op Current token
   * @param prev_op Previous token
   ************************************************************/
  bool ValidInput(Token_type clicked, char cur_op, char prev_op);
};
}  // namespace s21
#endif
