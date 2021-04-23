#include <stdio.h>
#include <stdlib.h>
//#include "../includes/klibc.h"

#define TEST_VEC_SIZE 5

// enum { INT, CHAR, FLOAT, DOUBLE, OTHER }

char INT[] = " %d";
char CHAR[] = " %c";
char FLOAT[] = " %f";

typedef struct {
    unsigned size;
    unsigned capacity;
    unsigned item_size;
    int* arr; // should be void** arr;
} Vector;

void push_back(Vector* vec, int data) {
    // check if the vector is sufficiently long to hold new elements, 
    // if not, reallocate it to double the original size.
    if(vec->size == vec->capacity) {
        vec->capacity *= 2;
        if(vec->capacity == 0) vec->capacity = 1;
        vec->arr = realloc(vec->arr, (vec->item_size) * (vec->capacity));
    }
    
    vec->arr[vec->size++] = data;
}

void display(const Vector* vec, char fmt[]) {
    printf("\n");
    for(int i = 0; i < vec->size; ++i) printf(fmt, vec->arr[i]);
    printf("\n");
}

int main() {
    Vector v;

    // this should be handled automatically
    v.capacity = 2;
    v.size = 0;
    v.item_size = sizeof(int);
    v.arr = malloc((v.item_size) * (v.capacity));
    
    for(int i = 0; i < TEST_VEC_SIZE; ++i) {
        push_back(&v, (i + 1) * (i + 1));
        //printf("[%d, (%d:%d)]", i, v.size, v.capacity);
        printf(" %d", sizeof(v.arr));
    }

    display(&v, INT);

    // Alternatively:
    // Vector* v2 = malloc(sizeof(int));

    // v2->capacity = 5;
    // v2->size = 3;
    // v2->item_size = sizeof(int);
    // v2->arr = malloc((v2->item_size) * (v2->capacity));
    
    // for(int i = 0; i < 3; ++i) push_back(v2, i + 1);
    // display(v2);

    return 0;
}

/*
fixed sized array inside stack-struct
fixed sized array inside malloced-struct

dynamic sized array inside stack-struct
dynamic sized array inside malloced-struct

*/