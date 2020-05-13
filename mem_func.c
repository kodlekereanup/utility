#include <stdio.h>

// Simulates member functions of C++ in C via function pointers //

typedef struct {
  int x;
  int y;
  void (*set)(struct point*, int, int);
} point;

void oset(point* p, int x, int y) {
    p->x = x;
    p->y = y  + 2;
}

void main() {
    point p = { 0, 0, oset };
    p.set(&p, 2, 3);
    printf("%d %d\n", p.x, p.y);
}
