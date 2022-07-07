#include <stdio.h>
#include <stdlib.h>

typedef struct personas{
  char name[100];
  int danger_category;
  float attack_prob;
  struct personas *next;
}personas;
