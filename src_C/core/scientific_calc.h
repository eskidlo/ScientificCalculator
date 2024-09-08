#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MINF -1.0 / 0.0
#define INF 1.0 / 0.0

// stack

typedef struct shtuka {
  char elements[256];
  int size;
} shtuka_t;

void init(shtuka_t *a);
int push(shtuka_t *a, char x);
char pop(shtuka_t *a);
int stack_is_full(shtuka_t *a);
char peek(shtuka_t *a);

// double stack

typedef struct double_shtuka {
  double elements[256];
  int size;
} double_shtuka_t;

void double_init(double_shtuka_t *a);
int double_push(double_shtuka_t *a, double x);
double double_pop(double_shtuka_t *a);

// validator
int validator(char *line);
int num_error(char x);
int check_sin(char *line, int i, int size);
int check_cos(char *line, int i, int size);
int check_tan(char *line, int i, int size);
int check_asin(char *line, int i, int size);
int check_acos(char *line, int i, int size);
int check_atan(char *line, int i, int size);
int check_sqrt(char *line, int i, int size);
int check_log(char *line, int i, int size);
int check_ln(char *line, int i, int size);
int check_mod(char *line, int i, int size);

// polish
int priority(char a);
char *parcer(char *line);
double get_element(char *line, int *i, int size_line);
double calc(char *line, double num_to_x);
