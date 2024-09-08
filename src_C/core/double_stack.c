#include "scientific_calc.h"

void double_init(double_shtuka_t *a) { a->size = 0; }

int double_push(double_shtuka_t *a, double x) {
  int ret = 0;
  if (a->size < 256) {
    a->elements[a->size] = x;
    a->size++;
  } else {
    ret = -1;
  }
  return ret;
}

double double_pop(double_shtuka_t *a) {
  double element;
  if (a->size > 0) {
    a->size--;
    element = a->elements[a->size];
  } else {
    element = 0;
  }
  return element;
}
