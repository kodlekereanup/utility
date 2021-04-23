#ifndef KLIBC_H
#define KLIBC_H

#include <stdio.h>
#include <stdbool.h>

// ----------------------------------------- MACROS --------------------------------------
#define DEBUG 1
#define debug_print(fmt, ...) \
        do { if (DEBUG) fprintf(stderr, "%s:%d:%s(): " fmt, __FILE__, \
                                __LINE__, __func__, __VA_ARGS__); } while (0)

// ----------------------------------------- VECTOR ---------------------------------------
typedef struct _Vector Vector;

Vector* vector_alloc(const size_t item_size); //TODO: Maybe make the size arg optional?
void    vector_dealloc(Vector* vec);

// ----------------------------- USER INTERFACE --------------------------------------

//TODO: Make these generic (mostly all 'data fields')

void vector_init(Vector* vec, const unsigned int capacity, const int filler);
void vector_reserve(Vector* vec, const unsigned int capacity);

// INSERT functions
void vector_append(Vector* vec, const int data);
void vector_insert(Vector* vec, const unsigned int index, const int data);
void vector_push_back(Vector* vec, const int data); // calls insert

// DELETE functions
void vector_pop_front(Vector* vec);
void vector_pop_back(Vector* vec);
void vector_pop_key(Vector* vec, int key);

// SEARCH
void vector_lsearch_key(const Vector* vec, int key);
void vector_bsearch_key(const Vector* vec, int key); // only works if vec->buffer[] is sorted

// SORT
void vector_bbsort(Vector* vec, bool comparator); // comparator should be a callback or a function pointer
void vector_qsort(Vector* vec, bool comparator);

void vector_display(const Vector* vec);
void vector_display_range(const Vector* vec, int begin, int end);

void vector_create_from_array(Vector* vec, const int* array, const unsigned int array_size);
void vector_extract_array(const Vector* vec, int* array);

// TODO: This should return the type of the element in the vector.
int vector_at(const Vector* vec, const int index);

long long vector_sum(const Vector* vec); // should accept only integer and floating point arrays

size_t vector_size(const Vector* vec);
size_t vector_capacity(const Vector* vec);
size_t vector_item_size(const Vector* vec);
// ----------------------------- LIBRARY CORE ---------------------------------------

/*
 * vector_init can take two optional arguments and since C does not provide us with any functionality
 * for the same, we need to make two different functions, vector_init() and vector_init_core(), with
 * the former being the function accessible to the user.
 * TODO: Find some way to expose only the interface and not the core lbrary fuctions.
 * What I mean by that is, vector_init_core() shouldn't even be visible to the user.
 */
// TODO: Do we need to return an error code if initialization fails?
int vector_init_core(Vector* vec, const unsigned int* capacity, const int* filler);

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
