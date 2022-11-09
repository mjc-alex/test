#include "mytest.h"
typedef struct watchpoint {
  int NO;
  struct watchpoint *next;

  /* TODO: Add more members if necessary */
  bool isfree;
  word_t val;
  char *expr;
} WP;

