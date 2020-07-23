#include <stdio.h>
#include "klibc.h"

int main(void) {

	// Vector vector1;
	// vector_init(&vector1, 3, NULL); // try and make this work
	// vector_display(&vector1);

	// Vector vector2;
	// vector_init(&vector2, 3, 0);
	// vector_display(&vector2);

	// // create a vector of size 10 and fill all with 1
 //    Vector vector3;
 //    vector_init(&vector3, 10, 1);
 //    vector_display(&vector3);

    //Vector line = make_vector(2, 4, 6, 8 ...);

    int a2v[3] = { 10, 20, 30 };
    Vector newvec;
    create_vector_from_array(&newvec, a2v, 3);

    Vector v2a = make_vector(10, 20, 30);
    int* arr;
    arr = extract_array_from_vector(&v2a);

    // Vector scores = make_vector(34, 5, 10);
    // int sum = vector_sum(&scores);

    return 0;
}
