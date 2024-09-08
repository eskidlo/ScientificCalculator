#ifndef MODEL_H
#define MODEL_H

#include <cmath>
#include <functional>
#include <iostream>
#include <stack>

namespace scientific_calc {
class Model {
 private:
  struct Lexemes {
   public:
    int priority_;
    std::string name_;

    Lexemes() {
      priority_ = 0;
      name_ = "";
    }
    Lexemes(int prior, std::string name) : priority_(prior), name_(name) {}
    Lexemes(const Lexemes &) = default;
    Lexemes(Lexemes &&) = default;
    Lexemes &operator=(const Lexemes &) = default;
    ~Lexemes() = default;

    void add(int prior, std::string name) {
      priority_ = prior;
      name_ = name;
    };
    void clear() {
      priority_ = 0;
      name_ = "";
    }
  };

  bool IsOperator(size_t i);
  bool isMod(size_t &i);
  bool isFunc(size_t &i);
  bool isNum(size_t &i);
  bool CheckOperator(size_t i);
  bool isX(size_t &i);

 public:
  Model() = default;
  ~Model() = default;
  Model(std::string line) : inputLine(line) {}
  Model(const Model &) = default;
  Model(Model &&) = default;
  Model &operator=(const Model &) = default;

  std::string inputLine;
  std::vector<Lexemes> tokens;
  void Validator();
  std::vector<std::string> Parcer();
  double Calc(std::vector<std::string> line, double x);
};
}  // namespace scientific_calc

#endif  // MODEL_H
