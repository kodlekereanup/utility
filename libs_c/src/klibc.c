#include "../includes/klibc.h"
#include <stdlib.h>

// --------------------------------- STRUCT DEFS ---------------------------
typedef struct _Vector {
    size_t size; // length of the array
    size_t capacity;
    size_t item_size; // size of datatype
    int* buffer; // or use a flexible array void buffer[0]
} Vector;

// vector_alloc(int s) // should take alloc size cause generic
Vector* vector_alloc(const size_t item_size) {

    Vector* vec = malloc(sizeof(Vector));

    if(!vec) {
      // malloc couldn't allocate. Handle error.
    }

    vec->item_size = item_size;
    vec->size      = 0;
    vec->capacity  = 0;
    vec->buffer    = NULL;

    return vec;
}

void vector_dealloc(Vector* vec) {
    // TODO: use a foreach loop here, possibly make some kind of
    //       iterator functionality like that of C++.

  // for(int i = 0; i < vec->size(); i++) free(vec->buffer[i]);
    free(vec);
    vec->item_size = 0;
    vec->size      = 0;
    vec->capacity  = 0;
    vec->buffer    = NULL;
}

// --------------------------------- FUNCTION DEFS -------------------------
void vector_init(Vector* vec, const unsigned int capacity, const int filler) {
    vector_init_core(vec, &capacity, &filler);
}

// TODO: Very bad code, find a better way to do this
// Probably outdated, we wont need this when variadic macro with
// function dispatch based on the argument count is implemented.
int vector_init_core(Vector* vec, const unsigned int* capacity, const int* filler) {

    if(capacity == NULL && filler != NULL) {
        //error handle
    }

    // By default, capacity and filler are 0.
    //
    // User can choose to mention capacity at call, without choosing filler, in which case the array
    // will be filled with 0's upto 'capacity' length
    //
    // User can choose to not mention either - making an empty vector of size / capacity 0
    //
    // Finally, user can choose to mention both, capacity and filler - in which case the array
    // of length 'capacity' will be filled with 'filler'

    if(capacity == NULL && filler == NULL) {
        vec->size = 0;
        vec->capacity = 0;
    } else if(capacity != NULL && filler != NULL) {
        vec->size = *capacity;
        vec->capacity = *capacity;
        vec->buffer = malloc((vec->item_size) * (*capacity)); // TODO: sizeof(int) should be generic somehow
        if(!vec->buffer) {
            printf("\n Could not malloc \n"); // logger
            return -1;
        }

        for(int i = 0; i < *capacity; ++i) vec->buffer[i] = *filler;
    } else if(capacity != NULL && filler == NULL) {
        vec->size = *capacity;
        vec->capacity = *capacity;
        vec->buffer = malloc((vec->item_size) * (*capacity));
        if(!vec->buffer) {
            printf("\n Could not malloc \n");
            return -1;
        }

        for(int i = 0; i < *capacity; ++i) vec->buffer[i] = 0;
    }
    return 0;
}

void vector_create_from_array(Vector* vec, const int* array, const unsigned int array_size) {
  if(vector_size(vec) != 0) {
    // vec is already allocated, using this function may possibly lead to data loss
  }

  vector_init(vec, array_size, 0);
    // what if I pass an already existing array?
    for(int i = 0; i < array_size; ++i) vector_push_back(vec, array[i]);
}

// FIXME: vector_push_back is not inserting any kind of data in the buffer.
//        my doubt is that it's because we haven't allocated the array
//        inside the struct vector and hence it's always zero?
void vector_push_back(Vector* vec, const int data) {
    static int i = 0;
    // vec->buffer[i] = *(int*)malloc(sizeof(data));
    vec->buffer[i++] = data;
}

//TODO:
// Create a macro that takes in the vector object and the format and type to make a generic
// printf function. Also try to 'init' it at vector_init() to be the type declared at initialization.
void vector_display(const Vector* vec) {
    printf("\n");
    for(int i = 0; i < vector_size(vec); ++i) printf("%d ", vec->buffer[i]);
    printf("\n");
}

size_t vector_size(const Vector* vec) { return vec->size; }

size_t vector_capacity(const Vector* vec) { return vec->capacity; }

void vector_extract_array(const Vector* vec, int* array) {
  for(int i = 0; i < vector_size(vec); ++i) {
    array[i] =  vec->buffer[i]; //vec->at(i);
  }
}

int vector_at(const Vector* vec, const int index) {
  int size = vector_size(vec);
  if(index < 0 && index >= (size * -1)) {
    return vec->buffer[size + index];
    // size - index but we're passing -index from the function, and - of '-' is +
  } else if(index >= 0 && index < size) {
    return vec->buffer[index];
  } else {
    // index out of bounds 
  }
}


