#include <stdio.h>
#include <stdlib.h>

int a = 13;

int f(int x) {
  a++;
  return x + a;
}

int main() {
  int *p = malloc(sizeof(int));
  *p = f(1);
  *p = f(2);
  printf("Value of a: %d\n", a);
  printf("Value of p: %d\n", *p);
  return 0;
}
