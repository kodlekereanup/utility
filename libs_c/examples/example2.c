#include "../includes/klibc.h"
#include <stdlib.h>

int main() {
  
  // what happens internally when you malloc(sizeof(int) * x)
  Vector* v = vector_alloc(sizeof(int));
  printf("\n %d %d \n", vector_size(v), vector_capacity(v));

  //vector_init(v, 3, 0); // not a necessary function
  vector_reserve(v, 3);
  printf("\n %d %d \n", vector_size(v), vector_capacity(v));

  for(int i = 0; i < 5; ++i) vector_push_back(v, i + 1);
  vector_display(v);
  
  printf("\n %d %d \n", vector_size(v), vector_capacity(v));

  vector_reserve(v, 0);
  printf("\n %d %d \n", vector_size(v), vector_capacity(v));
  vector_reserve(v, 10);
  printf("\n %d %d \n", vector_size(v), vector_capacity(v));
  vector_dealloc(v);
  printf("\n %d %d \n", vector_size(v), vector_capacity(v));

  return 0;

}
