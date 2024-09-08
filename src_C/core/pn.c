#include "scientific_calc.h"

// cos = c; sin = s; tan = t; acos = a; asin = b; atan = l; sqrt = q; ln = n;
// log = g; mod = m;
// atof - переводит в цифру

int priority(char a) {
  int ret = -1;
  switch (a) {
    case '(':
      ret = 0;
      break;
    case '+':
    case '-':
      ret = 1;
      break;
    case '*':
    case '/':
      ret = 2;
      break;
    case '^':
    case 'm':
      ret = 3;
      break;
    case '~':
    case 'p':
    case 'c':
    case 's':
    case 't':
    case 'a':
    case 'b':
    case 'l':
    case 'q':
    case 'n':
    case 'g':
      ret = 4;
      break;
    default:
      break;
  }
  return ret;
}

char *parcer(char *line) {
  static char out[512] = {0};
  for (int i = 0; i < 512; i++) {
    out[i] = 0;
  }
  shtuka_t stck = {0};
  char c;
  int size_out = 0, size_line;
  init(&stck);
  size_line = strlen(line);
  for (int i = 0; i < size_line; i++) {
    c = line[i];
    if (c >= '0' && c <= '9') {
      for (int j = i; j < size_line; j++) {
        c = line[j];
        if ((c >= '0' && c <= '9') || (c == '.')) {
          out[size_out++] = c;
        } else {
          j--;
          break;
        }
        i = j;
      }
      out[size_out++] = ' ';
    } else if (c == '(') {
      push(&stck, c);
    } else if (c == ')') {
      while (peek(&stck) != '(') {
        out[size_out++] = pop(&stck);
        out[size_out++] = ' ';
      }
      pop(&stck);
    } else if (c == 'c') {
      if (check_cos(line, i, size_line)) {
        push(&stck, 'c');
        i += 2;
      }
    } else if (c == 's') {
      if (check_sin(line, i, size_line)) {
        push(&stck, 's');
        i += 2;
      } else if (check_sqrt(line, i, size_line)) {
        push(&stck, 'q');
        i += 3;
      }
    } else if (c == 't') {
      if (check_tan(line, i, size_line)) {
        push(&stck, 't');
        i += 2;
      }
    } else if (c == 'a') {
      if (check_asin(line, i, size_line)) {
        push(&stck, 'b');
        i += 3;
      } else if (check_acos(line, i, size_line)) {
        push(&stck, 'a');
        i += 3;
      } else if (check_atan(line, i, size_line)) {
        push(&stck, 'l');
        i += 3;
      }
    } else if (c == 'l') {
      if (check_ln(line, i, size_line)) {
        push(&stck, 'n');
        i += 1;
      } else if (check_log(line, i, size_line)) {
        push(&stck, 'g');
        i += 2;
      }
    } else if (check_mod(line, i, size_line)) {
      push(&stck, 'm');
      i += 2;
    } else if (c == 'x') {
      out[size_out++] = c;
      out[size_out++] = ' ';
    } else {
      char op = c;
      if ((op == '-' && (i == 0 || priority(line[i - 1]) != -1))) {
        op = '~';
      } else if ((op == '+' && (i == 0 || priority(line[i - 1]) != -1))) {
        op = 'p';
      }
      while (stck.size > 0 && (priority(op) <= priority(peek(&stck)))) {
        out[size_out++] = pop(&stck);
        out[size_out++] = ' ';
      }
      push(&stck, op);
    }
  }
  while (stck.size > 0) {
    out[size_out++] = pop(&stck);
    out[size_out++] = ' ';
  }
  return out;
}

double calc(char *line, double num_to_x) {
  double el_0 = 0, el_1 = 0, el_2 = 0, res = 0, the_x = num_to_x;
  double_shtuka_t elements = {0};
  double_init(&elements);
  int size_line;
  size_line = strlen(line);
  char c;
  for (int i = 0; i < size_line; i++) {
    c = line[i];
    if (c >= '0' && c <= '9') {
      el_0 = get_element(line, &i, size_line);
      double_push(&elements, el_0);
    } else if (c == 'x') {
      double_push(&elements, the_x);
    } else {
      switch (c) {
        case '~':
          el_0 = double_pop(&elements);
          el_0 = -el_0;
          double_push(&elements, el_0);
          break;
        case 'p':
          el_0 = double_pop(&elements);
          double_push(&elements, el_0);
          break;
        case 'c':
          el_0 = double_pop(&elements);
          el_0 = cos(el_0);
          double_push(&elements, el_0);
          break;
        case 's':
          el_0 = double_pop(&elements);
          el_0 = sin(el_0);
          double_push(&elements, el_0);
          break;
        case 't':
          el_0 = double_pop(&elements);
          el_0 = tan(el_0);
          double_push(&elements, el_0);
          break;
        case 'a':
          el_0 = double_pop(&elements);
          el_0 = acos(el_0);
          double_push(&elements, el_0);
          break;
        case 'b':
          el_0 = double_pop(&elements);
          el_0 = asin(el_0);
          double_push(&elements, el_0);
          break;
        case 'l':
          el_0 = double_pop(&elements);
          el_0 = atan(el_0);
          double_push(&elements, el_0);
          break;
        case 'q':
          el_0 = double_pop(&elements);
          el_0 = sqrt(el_0);
          double_push(&elements, el_0);
          break;
        case 'n':
          el_0 = double_pop(&elements);
          el_0 = log(el_0);
          double_push(&elements, el_0);
          break;
        case 'g':
          el_0 = double_pop(&elements);
          el_0 = log10(el_0);
          double_push(&elements, el_0);
          break;
        case '-':
          el_2 = double_pop(&elements);
          el_1 = double_pop(&elements);
          el_0 = el_1 - el_2;
          double_push(&elements, el_0);
          break;
        case '+':
          el_2 = double_pop(&elements);
          el_1 = double_pop(&elements);
          el_0 = el_1 + el_2;
          double_push(&elements, el_0);
          break;
        case '*':
          el_2 = double_pop(&elements);
          el_1 = double_pop(&elements);
          el_0 = el_1 * el_2;
          double_push(&elements, el_0);
          break;
        case '/':
          el_2 = double_pop(&elements);
          el_1 = double_pop(&elements);
          el_0 = el_1 / el_2;
          double_push(&elements, el_0);
          break;
        case '^':
          el_2 = double_pop(&elements);
          el_1 = double_pop(&elements);
          el_0 = pow(el_1, el_2);
          double_push(&elements, el_0);
          break;
        case 'm':
          el_2 = double_pop(&elements);
          el_1 = double_pop(&elements);
          el_0 = fmod(el_1, el_2);
          double_push(&elements, el_0);
          break;
        default:
          break;
      }
    }
  }

  res = double_pop(&elements);
  if (elements.size != 0) {
    res = NAN;
  }
  return res;
}

double get_element(char *line, int *i, int size_line) {
  char element[256] = {0};
  int size = 0, j = *i;
  char c;
  for (; j < size_line; j++) {
    c = line[j];
    if (c == ' ') {
      break;
    } else {
      element[size++] = c;
    }
  }
  *i = j;
  return atof(element);
}

int check_sin(char *line, int i, int size) {
  int check = 0;
  if (i + 3 < size) {
    if (line[i + 1] == 'i' && line[i + 2] == 'n' && line[i + 3] == '(') {
      check = 1;
    }
  }
  return check;
}

int check_cos(char *line, int i, int size) {
  int check = 0;
  if (i + 3 < size) {
    if (line[i + 1] == 'o' && line[i + 2] == 's' && line[i + 3] == '(') {
      check = 1;
    }
  }
  return check;
}

int check_tan(char *line, int i, int size) {
  int check = 0;
  if (i + 3 < size) {
    if (line[i + 1] == 'a' && line[i + 2] == 'n' && line[i + 3] == '(') {
      check = 1;
    }
  }
  return check;
}

int check_asin(char *line, int i, int size) {
  int check = 0;
  if (i + 4 < size) {
    if (line[i + 1] == 's' && line[i + 2] == 'i' && line[i + 3] == 'n' &&
        line[i + 4] == '(') {
      check = 1;
    }
  }
  return check;
}

int check_acos(char *line, int i, int size) {
  int check = 0;
  if (i + 4 < size) {
    if (line[i + 1] == 'c' && line[i + 2] == 'o' && line[i + 3] == 's' &&
        line[i + 4] == '(') {
      check = 1;
    }
  }
  return check;
}

int check_atan(char *line, int i, int size) {
  int check = 0;
  if (i + 4 < size) {
    if (line[i + 1] == 't' && line[i + 2] == 'a' && line[i + 3] == 'n' &&
        line[i + 4] == '(') {
      check = 1;
    }
  }
  return check;
}

int check_ln(char *line, int i, int size) {
  int check = 0;
  if (i + 2 < size) {
    if (line[i + 1] == 'n' && line[i + 2] == '(') {
      check = 1;
    }
  }
  return check;
}

int check_log(char *line, int i, int size) {
  int check = 0;
  if (i + 2 < size) {
    if (line[i + 1] == 'o' && line[i + 2] == 'g' && line[i + 3] == '(') {
      check = 1;
    }
  }
  return check;
}

int check_sqrt(char *line, int i, int size) {
  int check = 0;
  if (i + 4 < size) {
    if (line[i + 1] == 'q' && line[i + 2] == 'r' && line[i + 3] == 't' &&
        line[i + 4]) {
      check = 1;
    }
  }
  return check;
}

int check_mod(char *line, int i, int size) {
  int check = 0;
  if (i + 2 < size) {
    if (line[i + 1] == 'o' && line[i + 2] == 'd') {
      check = 1;
    }
  }
  return check;
}
