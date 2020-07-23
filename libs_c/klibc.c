#include "klibc.h"
#include <stdlib.h>

int vector_init(Vector* vec, unsigned int init_capacity, const int filler) {
    return vector_init_core(vec, &init_capacity, &filler);
}

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
        vec->buffer = malloc(sizeof(int) * (*capacity)); // TODO: sizeof(int) should be generic somehow
        if(!vec->buffer) {
            printf("\n Could not malloc \n"); // logger
            return -1;
        }

        for(int i = 0; i < *capacity; ++i) vec->buffer[i] = *filler;
    } else if(capacity != NULL && filler == NULL) {
        vec->size = *capacity;
        vec->capacity = *capacity;
        vec->buffer = malloc(sizeof(int) * (*capacity));
        if(!vec->buffer) {
            printf("\n Could not malloc \n");
            return -1;
        }

        for(int i = 0; i < *capacity; ++i) vec->buffer[i] = 0;
    }

    return 0;
}

void create_vector_from_array(Vector* vector, void* array, int array_size) {
    vector_init(vector, array_size, 0);
    // what if I pass an already existing array?
    for(int i = 0; i < array_size; ++i) vector_push_back(vector, array);
}

void vector_push_back(Vector* vec, const void* data) {

}

void vector_display(const Vector* vec) {
    printf("\n");
    for(int i = 0; i < vec->size; ++i) printf("%d ", vec->buffer[i]);
    printf("\n");
}
