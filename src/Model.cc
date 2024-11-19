/************************************************************
 * @file Model.cc
 * @brief A model containing the business logic of smart claculator
 ************************************************************/

#include "Model.h"

using namespace s21;

bool Model::ValidInput(Token_type clicked, char cur_op, char prev_op) {
  switch (clicked) {
    case NUMBER:
      if (prev_op != 'x' && prev_op != ')') return true;
      return false;
      std::cout << "PREV_TOKEN: " << prev_op << "End\n";
      break;
    case BINARY_OPERATOR:
      if (prev_op == ')') {
        if (prev_op == '(') return false;
        return true;
      }
      if (binary_operators.find(prev_op) != binary_operators.end() ||
          prev_op == 'd') {
        if (prev_op != '-' && prev_op != '+') {
          if (cur_op == '+' || cur_op == '-' || cur_op == '(') return true;
          return false;
        }
        if (prev_op == '-' || prev_op == '+') {
          if (cur_op != '(') return false;
          return true;
        }
      }
      if (std::isdigit(prev_op) || prev_op == 'x' || prev_op == '.') {
        if (cur_op == '(') return false;
        return true;
      }
      return true;
    case FUNCTION:
      if (prev_op != 'x' && prev_op != '.' && !std::isdigit(prev_op) &&
          prev_op != ')')
        return true;
      return false;
    case X_VALUE:
      if (cur_op == 's' && prev_op == '0') return true;
      if (prev_op == '0' || (!std::isdigit(prev_op) && prev_op != '.' &&
                             prev_op != ')' && prev_op != 'x'))
        return true;
      return false;
      break;
    default:
      return true;
  }
  return true;
}

bool Model::IsItUnaryOperator(std::string::iterator it, Token& support) {
  if (*it == '+' || *it == '-') {
    if (support.type_ == NON ||
        (support.type_ == BINARY_OPERATOR && *(it - 1) != ')')) {
      support.priority_ = 4;
      support.type_ = UNARY_OPERATOR;
      support.value_.push_back(*it);
      return true;
    }
  }
  return false;
}

bool Model::IsItBinaryOperator(std::string::iterator& it, Token& support) {
  if (binary_operators.find(*it) != binary_operators.end()) {
    support.priority_ = binary_operators[*it];
    support.value_.push_back(*it);
    support.type_ = BINARY_OPERATOR;
    if (*it == 'm') {
      if (*(it + 1) != 'o' && *(it + 2) != 'd') return false;
      if (*(it + 1) == 'o' && *(it + 2) == 'd') it += 2;
    }
    return true;
  }
  return false;
}

bool Model::IsItFunction(std::string::iterator& it, Token& support) {
  std::string str = &(*it);
  std::size_t k = 3;
  for (std::size_t i = 0; i < functions.size(); i++) {
    if (i == 1)
      k++;
    else if (i == 5)
      k++;
    if (str.compare(0, k, functions[i]) == 0) {
      support.value_.push_back(i);
      support.type_ = FUNCTION;
      support.priority_ = 2;
      it += k - 2;
      return true;
    }
  }
  return false;
}

bool Model::StackOfOperators(Token& support, std::stack<Token>& st) {
  if ((st.empty() || support.value_[0] == '(') && support.value_[0] != ')')
    st.push(support);
  else if (support.value_[0] == ')') {
    if (!st.empty()) {
      Token cur = st.top();
      while (!st.empty() && cur.value_[0] != '(') {
        postfix_entry.push_back(cur);
        st.pop();
        cur = st.top();
      }
      if (cur.value_[0] == '(')
        st.pop();
      else
        return false;
    } else
      return false;
  } else {
    if (!st.empty()) {
      Token cur = st.top();
      while (!st.empty() && cur.value_[0] != '(' &&
             cur.priority_ <= support.priority_) {
        postfix_entry.push_back(cur);
        st.pop();
        if (!st.empty()) cur = st.top();
      }
    }
    st.push(support);
  }
  return true;
}

bool Model::parser(std::string expression) {
  std::stack<Token> st;
  std::string cur;
  int count_of_dots = 0;
  Token support;
  for (std::string::iterator it = expression.begin(); it != expression.end();
       ++it, count_of_dots = 0) {
    if (std::isdigit(*it) || *it == '.') {
      support.type_ = NUMBER;
      while ((std::isdigit(*it) || *it == '.' || *it == 'e') &&
             it != expression.end()) {
        support.value_.push_back(*it);
        if (*it == '.') count_of_dots++;
        if (*it == 'e' && (*(it + 1) != '-' || *(it + 1) != '+')) return false;
        ++it;
      }
      it--;
      if (count_of_dots > 1) return false;
      postfix_entry.push_back(support);
    } else if (IsItUnaryOperator(it, support) ||
               IsItBinaryOperator(it, support) || IsItFunction(it, support)) {
      if (!StackOfOperators(support, st)) {
        return false;
      }
    } else {
      return false;
    }
    support.value_.clear();
  }
  while (!st.empty()) {
    postfix_entry.push_back(st.top());
    st.pop();
  }
  return true;
}

bool Model::computeUnary(char unary_operator, std::stack<Token>& st) {
  Token a = st.top();
  if (a.type_ == NUMBER) {
    if (unary_operator == '-') {
      st.pop();
      double res = std::stod(a.value_);
      res *= -1;
      a.value_ = std::to_string(res);
      st.push(a);
    }
    return true;
  }
  return false;
}

bool Model::computeFunction(char func, std::stack<Token>& st) {
  Token a = st.top();
  st.pop();
  if (a.type_ != NUMBER) return false;
  double num = std::stod(a.value_);
  if (func == LN)
    num = log(num);
  else if (func == LOG)
    num = log10(num);
  else if (func == COS)
    num = cos(num);
  else if (func == SIN)
    num = sin(num);
  else if (func == TAN)
    num = tan(num);
  else if (func == ACOS)
    num = acos(num);
  else if (func == ASIN)
    num = asin(num);
  else if (func == ATAN)
    num = atan(num);
  else if (func == SQRT)
    num = sqrt(num);
  a.value_ = std::to_string(num);
  st.push(a);
  return true;
}

bool Model::computeBinary(char op, std::stack<Token>& st) {
  Token second = st.top();
  st.pop();
  Token first = st.top();
  st.pop();
  if (first.type_ != NUMBER || second.type_ != NUMBER) return false;
  double s = std::stod(second.value_);
  double f = std::stod(first.value_);
  double res = 0;
  switch (op) {
    case '^':
      res = pow(f, s);
      break;
    case '*':
      res = f * s;
      break;
    case '/':
      res = f / s;
      break;
    case 'm':
      res = fmod(f, s);
      break;
    case '+':
      res = f + s;
      break;
    case '-':
      res = f - s;
      break;
  }
  first.value_ = std::to_string(res);
  st.push(first);
  return true;
}

bool Model::CalculateRpnExpression(double& res) {
  std::stack<Token> st;
  bool flag = true;
  for (std::size_t i = 0; i < postfix_entry.size() && flag; i++) {
    if (postfix_entry[i].type_ == NUMBER)
      st.push(postfix_entry[i]);
    else if (!st.empty()) {
      if (postfix_entry[i].type_ == UNARY_OPERATOR) {
        flag = computeUnary(postfix_entry[i].value_[0], st);
      } else if (postfix_entry[i].type_ == FUNCTION) {
        flag = computeFunction(postfix_entry[i].value_[0], st);
      } else if (postfix_entry[i].type_ == BINARY_OPERATOR && st.size() >= 2)
        flag = computeBinary(postfix_entry[i].value_[0], st);
      else
        flag = false;
    } else
      flag = false;
  }
  if (st.size() > 1)
    flag = false;
  else if (flag) {
    Token a = st.top();
    res = std::stod(a.value_);
  }
  return flag;
}

bool Model::Calculate(std::string expression, std::string x_value,
                      double& res) {
  setlocale(LC_NUMERIC, "C");
  if (expression.size() == 0 || expression.size() > 255) {
    postfix_entry.clear();
    return false;
  }
  std::size_t pos;
  while ((pos = expression.find('x')) != std::string::npos) {
    expression.replace(pos, 1, x_value);
  }
  if (!parser(expression)) {
    postfix_entry.clear();
    return false;
  }
  if (!CalculateRpnExpression(res)) {
    postfix_entry.clear();
    return false;
  }
  postfix_entry.clear();
  return true;
}
