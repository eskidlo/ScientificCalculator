#include "scientific_calc.h"

// + - * / ^

int validator(char *line) {
  int size, error = 0, check_point = 0, check_bracket_right = 0,
            check_bracket_left = 0;
  size = strlen(line);
  for (int i = 0; i < size; i++) {
    if (line[i] == '.') {
      if ((i - 1) < 0 || (i + 1) > size) {
        error = 1;
        break;
      } else if (num_error(line[i + 1]) || num_error(line[i - 1])) {
        error = 1;
        break;
      } else if (check_point == 1) {
        error = 1;
        break;
      }
      check_point = 1;
    } else if (line[i] == '(') {
      check_bracket_left++;
      check_point = 0;
      if ((i + 1) > size) {
        error = 2;
        break;
      } else if (num_error(line[i + 1]) && line[i + 1] != 'x' &&
                 line[i + 1] != '-' && line[i + 1] != '(' &&
                 line[i - 1] != ')' && line[i + 1] != 's' &&
                 line[i + 1] != 'c' && line[i + 1] != 't' &&
                 line[i + 1] != 'a' && line[i + 1] != 'l' &&
                 line[i + 1] != '+') {
        error = 2;
        break;
      }
    } else if (line[i] == ')') {
      check_bracket_right++;
      check_point = 0;
      if ((i - 1) < 0) {
        error = 3;
        break;
      } else if (num_error(line[i - 1]) && line[i - 1] != 'x' &&
                 line[i - 1] != ')' && line[i + 1] != '-' &&
                 line[i + 1] != '+' && line[i + 1] != '^' &&
                 line[i + 1] != 'm' && line[i + 1] != '*' &&
                 line[i + 1] != '/' && line[i + 1] != '^') {
        error = 3;
        break;
      }
    } else if (line[i] == 's') {
      check_point = 0;
      if (check_sin(line, i, size)) {
        i += 2;
      } else if (check_sqrt(line, i, size)) {
        i += 3;
      }
    } else if (line[i] == 'c') {
      check_point = 0;
      i += 2;
    } else if (line[i] == 't') {
      check_point = 0;
      i += 2;

    } else if (line[i] == 'a') {
      check_point = 0;
      i += 3;
    } else if (line[i] == 'l') {
      check_point = 0;
      if (check_ln(line, i, size)) {
        i += 1;
      } else if (check_log(line, i, size)) {
        i += 2;
      }
    } else if (line[i] == 'm') {
      check_point = 0;
      i += 2;
      if ((i + 1 > size) || (i - 1 < 0)) {
        error = 4;
        break;
      } else if (num_error(line[i + 1]) && line[i + 1] != '(' &&
                 line[i - 1] != ')' && line[i + 1] != 's' &&
                 line[i + 1] != 'c' && line[i + 1] != 't' &&
                 line[i + 1] != 'a' && line[i + 1] != 'l' &&
                 line[i + 1] != 'x') {
        error = 4;
        break;
      }
    } else if (line[i] == '*' || line[i] == '/' || line[i] == '^') {
      check_point = 0;
      if ((i + 1 > size) || (i - 1 < 0)) {
        error = 51;
        break;
      } else if (num_error(line[i + 1]) && line[i + 1] != 'x' &&
                 line[i - 1] != ')' && line[i - 1] != '(' &&
                 line[i + 1] != '(' && line[i + 1] != ')' &&
                 line[i + 1] != 's' && line[i + 1] != 'c' &&
                 line[i + 1] != 't' && line[i + 1] != 'a' &&
                 line[i + 1] != 'l') {
        error = 52;
        break;
      } else if (line[i] == '/' && line[i + 1] == '0') {
        error = 55;
        break;
      }
    } else if (line[i] == '-') {
      check_point = 0;
      if (i + 1 > size) {
        error = 1;
        break;
      } else if (num_error(line[i + 1]) && line[i + 1] != 'x' &&
                 line[i - 1] != ')' && line[i - 1] != '(' &&
                 line[i + 1] != '(' && line[i + 1] != ')' &&
                 line[i + 1] != 's' && line[i + 1] != 'c' &&
                 line[i + 1] != 't' && line[i + 1] != 'a' &&
                 line[i + 1] != 'l' && line[i + 1] != 'q') {
        error = 50;
        break;
      }
    } else if (line[i] == '+') {
      check_point = 0;
      if (i + 1 > size) {
        error = 1;
        break;
      } else if (num_error(line[i + 1]) && line[i + 1] != 'x' &&
                 line[i - 1] != '(' && line[i - 1] != ')' &&
                 line[i + 1] != '(' && line[i + 1] != ')' &&
                 line[i + 1] != 's' && line[i + 1] != 'c' &&
                 line[i + 1] != 't' && line[i + 1] != 'a' &&
                 line[i + 1] != 'l') {
        error = 500;
        break;
      }
    }
  }
  if (check_bracket_right != check_bracket_left) {
    error = 9;
  }
  return error;
}

int num_error(char x) {
  int error = 0;
  if ((x < '0') || (x > '9')) {
    error = 1;
  }
  return error;
}
