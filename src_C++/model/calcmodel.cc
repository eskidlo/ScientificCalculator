#include "./calcmodel.h"

namespace scientific_calc {

bool Model::IsOperator(size_t i) {
  Lexemes lex;
  bool answer = false;
  std::string op;
  op.push_back(inputLine.at(i));

  if (op == "-") {
    answer = true;
    if (i == 0 || inputLine.at(i - 1) == '(') {
      op = "~";
      lex.add(4, op);
      tokens.push_back(lex);
    } else {
      lex.add(1, op);
      tokens.push_back(lex);
    }
  } else if (op == "+") {
    if (i == 0 || inputLine.at(i - 1) == '(') {
      answer = true;
    } else {
      answer = true;
      lex.add(1, op);
      tokens.push_back(lex);
    }
  } else if (op == "*") {
    answer = true;
    lex.add(2, op);
    tokens.push_back(lex);
  } else if (op == "/") {
    answer = true;
    lex.add(2, op);
    tokens.push_back(lex);
  } else if (op == "^") {
    answer = true;
    lex.add(3, op);
    tokens.push_back(lex);
  }

  return answer;
}

bool Model::isMod(size_t &i) {
  Model::Lexemes lex;
  bool answer = false;
  if (inputLine.at(i) == 'm' && inputLine.at(i + 1) == 'o' &&
      inputLine.at(i + 2) == 'd' &&
      (isdigit(inputLine.at(i + 3)) || inputLine.at(i + 3) == '(') &&
      (isdigit(inputLine.at(i - 1)) || inputLine.at(i + 3) == ')')) {
    answer = true;
    lex.add(3, "mod");
    tokens.push_back(lex);
    i += 2;
  }
  return answer;
}

bool Model::isFunc(size_t &i) {
  Lexemes lex;
  bool answer = false;
  if (inputLine.at(i) == 'c') {
    if (inputLine.at(i + 1) == 'o' && inputLine.at(i + 2) == 's' &&
        inputLine.at(i + 3) == '(') {
      answer = true;
      lex.add(4, "cos");
      tokens.push_back(lex);
      i += 2;
    }
  } else if (inputLine.at(i) == 's') {
    if (inputLine.at(i + 1) == 'i' && inputLine.at(i + 2) == 'n' &&
        inputLine.at(i + 3) == '(') {
      answer = true;

      lex.add(4, "sin");
      tokens.push_back(lex);
      i += 2;
    } else if (inputLine.at(i + 1) == 'q' && inputLine.at(i + 2) == 'r' &&
               inputLine.at(i + 3) == 't' && inputLine.at(i + 4) == '(') {
      answer = true;
      lex.add(4, "sqrt");
      tokens.push_back(lex);
      i += 3;
    }
  } else if (inputLine.at(i) == 'a') {
    if (inputLine.at(i + 1) == 's' && inputLine.at(i + 2) == 'i' &&
        inputLine.at(i + 3) == 'n' && inputLine.at(i + 4) == '(') {
      answer = true;
      lex.add(4, "asin");
      tokens.push_back(lex);
      i += 3;
    } else if (inputLine.at(i + 1) == 'c' && inputLine.at(i + 2) == 'o' &&
               inputLine.at(i + 3) == 's' && inputLine.at(i + 4) == '(') {
      answer = true;
      lex.add(4, "acos");
      tokens.push_back(lex);
      i += 3;
    } else if (inputLine.at(i + 1) == 't' && inputLine.at(i + 2) == 'a' &&
               inputLine.at(i + 3) == 'n' && inputLine.at(i + 4) == '(') {
      answer = true;
      lex.add(4, "atan");
      tokens.push_back(lex);
      i += 3;
    }
  } else if (inputLine.at(i) == 't') {
    if (inputLine.at(i + 1) == 'a' && inputLine.at(i + 2) == 'n' &&
        inputLine.at(i + 3) == '(') {
      answer = true;
      lex.add(4, "tan");
      tokens.push_back(lex);
      i += 2;
    }
  } else if (inputLine.at(i) == 'l') {
    if (inputLine.at(i + 1) == 'o' && inputLine.at(i + 2) == 'g' &&
        inputLine.at(i + 3) == '(') {
      answer = true;
      lex.add(4, "log");
      tokens.push_back(lex);
      i += 2;
    } else if (inputLine.at(i + 1) == 'n' && inputLine.at(i + 2) == '(') {
      answer = true;
      lex.add(4, "ln");
      tokens.push_back(lex);
      i += 1;
    }
  }
  return answer;
}

bool Model::isNum(size_t &i) {
  Lexemes lex;
  bool answer = false;
  std::string num;
  if (isdigit(inputLine.at(i))) {
    for (auto j = i; j < inputLine.size(); j++) {
      if (isdigit(inputLine.at(j))) {
        num.push_back(inputLine.at(j));
        answer = true;
        i = j;
      } else if (inputLine.at(j) == '.') {
        if (isdigit(inputLine.at(j - 1)) && isdigit(inputLine.at(j + 1))) {
          num.push_back(inputLine.at(j));
          answer = true;
          i = j;
        } else {
          throw std::logic_error("invalid argument");
        }
      } else {
        break;
      }
    }
    if (num.back() == '.') {
      throw std::logic_error("invalid argument");
    }
    lex.add(-1, num);
    tokens.push_back(lex);
    num.clear();
  }
  return answer;
}

bool Model::isX(size_t &i) {
  Lexemes lex;
  bool answer = false;
  if (inputLine.at(i) == 'x') {
    lex.add(-1, "x");
    tokens.push_back(lex);
    answer = true;
  }
  return answer;
}

bool Model::CheckOperator(size_t i) {
  bool answer = false;
  if (inputLine.at(i) == '-' || inputLine.at(i) == '+' ||
      inputLine.at(i) == '*' || inputLine.at(i) == '/' ||
      inputLine.at(i) == '^') {
    answer = true;
  }
  if (inputLine.at(i) == 'm' && inputLine.at(i + 1) == 'o' &&
      inputLine.at(i + 2) == 'd') {
    answer = true;
  }
  return answer;
}

void Model::Validator() {
  Lexemes lex;
  int countRightBracket = 0, countLeftBracket = 0;

  for (size_t i = 0; i < inputLine.size(); i++) {
    lex.clear();
    if (isNum(i) || isFunc(i) || isX(i)) {
      continue;
    } else if (IsOperator(i)) {
      if (i == inputLine.size() - 1 || CheckOperator(i + 1)) {
        throw std::logic_error("invalid argument");
      } else if (i == 0 && inputLine.at(i) != '+' && inputLine.at(i) != '-') {
        throw std::logic_error("invalid argument");
      }
      // continue;
    } else if (isMod(i)) {
      if (i == 0 || i == inputLine.size() - 1) {
        throw std::logic_error("invalid argument");
      }
    } else if (inputLine.at(i) == '(') {
      if (i == inputLine.size() - 1 ||
          ((CheckOperator(i + 1) && inputLine.at(i + 1) != '-' &&
            inputLine.at(i + 1) != '+')) ||
          inputLine.at(i + 1) == ')') {
        throw std::logic_error("invalid argument");
      } else {
        lex.add(0, "(");
        tokens.push_back(lex);
        countLeftBracket++;
      }
    } else if (inputLine.at(i) == ')') {
      if (i == 0 || IsOperator(i - 1)) {
        throw std::logic_error("invalid argument");
      } else {
        lex.add(-1, ")");
        tokens.push_back(lex);
        countRightBracket++;
      }
    } else if (inputLine.at(i) == ' ') {
      continue;
    } else {
      throw std::logic_error("invalid argument");
    }
  }
  if (countLeftBracket != countRightBracket) {
    throw std::logic_error("invalid argument");
  }
}

std::vector<std::string> Model::Parcer() {
  std::vector<std::string> out;
  std::stack<Lexemes> temp;
  for (auto it = tokens.begin(); it < tokens.end(); it++) {
    if (isdigit(it->name_.at(0))) {
      out.push_back((*it).name_);
    } else if (it->name_ == "x") {
      out.push_back((*it).name_);
    } else if (it->name_ == "(" || it->priority_ == 4) {
      temp.push(*it);
    } else if (it->name_ == ")") {
      while ((temp.top()).name_ != "(") {
        out.push_back((temp.top()).name_);
        temp.pop();
      }
      temp.pop();
    } else {
      while (temp.size() > 0 && (it->priority_ <= (temp.top()).priority_)) {
        out.push_back((temp.top()).name_);
        temp.pop();
      }
      temp.push(*it);
    }
  }
  while (temp.size() > 0) {
    out.push_back(temp.top().name_);
    temp.pop();
  }
  return out;
}

double Model::Calc(std::vector<std::string> line, double x) {
  double temp, temp2, ret;
  std::stack<double> answer;

  for (auto it = line.begin(); it < line.end(); it++) {
    if (isdigit((*it).at(0))) {
      answer.push(stod(*it));
    } else if (*it == "x") {
      answer.push(x);
    } else if (*it == "~") {
      temp = -answer.top();
      answer.pop();
      answer.push(temp);
    } else if (*it == "cos") {
      temp = cos(answer.top());
      answer.pop();
      answer.push(temp);
    } else if (*it == "sin") {
      temp = sin(answer.top());
      answer.pop();
      answer.push(temp);
    } else if (*it == "tan") {
      temp = tan(answer.top());
      answer.pop();
      answer.push(temp);
    } else if (*it == "acos") {
      temp = acos(answer.top());
      answer.pop();
      answer.push(temp);
    } else if (*it == "asin") {
      temp = asin(answer.top());
      answer.pop();
      answer.push(temp);
    } else if (*it == "atan") {
      temp = atan(answer.top());
      answer.pop();
      answer.push(temp);
    } else if (*it == "sqrt") {
      temp = sqrt(answer.top());
      answer.pop();
      answer.push(temp);
    } else if (*it == "log") {
      temp = log10(answer.top());
      answer.pop();
      answer.push(temp);
    } else if (*it == "ln") {
      temp = log(answer.top());
      answer.pop();
      answer.push(temp);
    } else if (*it == "+") {
      temp = answer.top();
      answer.pop();
      temp2 = answer.top();
      answer.pop();
      answer.push(temp + temp2);
    } else if (*it == "-") {
      temp = answer.top();
      answer.pop();
      temp2 = answer.top();
      answer.pop();
      answer.push(temp2 - temp);
    } else if (*it == "*") {
      temp = answer.top();
      answer.pop();
      temp2 = answer.top();
      answer.pop();
      answer.push(temp2 * temp);
    } else if (*it == "/") {
      temp = answer.top();
      answer.pop();
      temp2 = answer.top();
      answer.pop();
      answer.push(temp2 / temp);
    } else if (*it == "^") {
      temp = answer.top();
      answer.pop();
      temp2 = answer.top();
      answer.pop();
      answer.push(powf(temp2, temp));
    } else if (*it == "mod") {
      temp = answer.top();
      answer.pop();
      temp2 = answer.top();
      answer.pop();
      answer.push(fmod(temp2, temp));
    }
  }

  if (answer.size() == 1) {
    ret = answer.top();
    answer.pop();
  } else {
    throw std::logic_error("invalid argument");
  }
  return ret;
}

}  // namespace scientific_calc
