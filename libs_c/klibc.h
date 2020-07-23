#ifndef KLIBC_H
#define KLIBC_H

// size_t, printf, scanf
#include <stdio.h>

// ----------------------------------------- MACROS --------------------------------------

#define DEBUG 1
#define debug_print(fmt, ...) \
        do { if (DEBUG) fprintf(stderr, "%s:%d:%s(): " fmt, __FILE__, \
                                __LINE__, __func__, __VA_ARGS__); } while (0)



// ----------------------------------------- VECTOR ---------------------------------------
typedef struct {
	unsigned int size; // length of the array
    unsigned int capacity;
	
    unsigned int elemSize; // size of datatype
    void* buffer; 
} Vector;

// ----------------------------- LIBRARY CORE ---------------------------------------

int  vector_init_core(Vector* vec, const unsigned int* init_capacity, const void* filler);

// ----------------------------- USER INTERFACE --------------------------------------
void vector_init(Vector* vec, const unsigned int capacity, const int filler);
void vector_append(Vector* vec, const void* data);
void vector_insert(Vector* vec, const void* data, const unsigned int* index); 
void vector_push_back(Vector* vec, const void* data); // calls insert
void create_vector_from_array(Vector* vector, const void* array, const unsigned int array_size);
void vector_display(const Vector* vec);

void* extract_array_from_vector(const Vector* vector);
void* at(const Vector* vec, const unsigned int index);


// ------------------------------------------ VECTOR STUBS ----------------------------------------
//#define vector_push_back(vec, data, TYPE) vector_push_back(vec, TYPE data)
//#define create_vector_from_array(vec, arr, size, TYPE) create_vector_from_array(vec, arr, size, TYPE)

// ------------------------------------------ STRINGS -------------------------------
// typedef struct {
//     size_t length;
//     char* buffer;
// } String;

// // ------------------------------------------MAP ------------------------------------

// typedef struct {
//     void* key;
//     void* value;
// } SortedMap;

// typedef struct {
//     void* key;
//     void* vaklue;
// } HashMap;

#endif
