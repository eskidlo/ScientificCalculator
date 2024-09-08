#include "scientific_calc.h"

void init(shtuka_t *a) { a->size = 0; }

int push(shtuka_t *a, char x) {
  int ret = 0;
  if (a->size < 256) {
    a->elements[a->size] = x;
    a->size++;
  } else {
    ret = -1;
  }
  return ret;
}

char pop(shtuka_t *a) {
  char element;
  if (a->size > 0) {
    a->size--;
    element = a->elements[a->size];
  } else {
    element = 0;
  }
  return element;
}

char peek(shtuka_t *a) {
  char element;
  if (a->size == 255) {
    element = 0;
  } else {
    element = a->elements[a->size - 1];
  }
  return element;
}
