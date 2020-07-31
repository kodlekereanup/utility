#include <stdio.h>
#include "../includes/klibc.h"

int main(void) {

  // Vector vector1;
	// vector_init(&vector1, 3, NULL); // try and make this work
	// vector_display(&vector1);

	// Vector vector2;
	// vector_init(&vector2, 3, 0);
	// vector_display(&vector2);

	// create a vector of size 10 and fill all with 1
  /*
  Vector* vector3 = vector_alloc(sizeof(int));
    vector_init(vector3, 5, 10);
    vector_display(vector3);

    //Vector line = make_vector(2, 4, 6, 8 ...);

    int a2v[3] = { 10, 20, 30 };
    Vector* newvec = vector_alloc(sizeof(int));
    vector_create_from_array(newvec, a2v, 3);
    vector_display(newvec);
    // Vector v2a = make_vector(10, 20, 30);
    // int* arr;
    // arr = extract_array_from_vector(&v2a);

    // Vector scores = make_vector(34, 5, 10);
    // int sum = vector_sum(&scores);

    // Vector* varvec = vector_alloc(NULL);
    // vector_init(varvec); == vector_init(varvec, 0, 0);
    // vector_display(varvec); // should display nothing

    int v2a_size = vector_size(vector3);
    int v2a[v2a_size];
    vector_extract_array(vector3, v2a);

    printf("\n Displaying extracted vector: ");
    for(int i = 0; i < v2a_size; i++) printf("%d ", v2a[i]);
    printf("\n");

    printf("\n Displaying vector3 using the at function: ");
    for(int i = -1; i >= vector_size(vector3) * -1; --i) printf("%d ", vector_at(vector3, i));
    printf("\n");
    */
    Vector* pbtest = vector_alloc(sizeof(int));
    vector_init(pbtest, 3, 0); // try and make vector_init(name) map to this

    for(int i = 0; i < vector_size(pbtest); ++i) vector_push_back(pbtest, i + 1);
    vector_display(pbtest); // in c++ this would print 0 0 0 1 2 3

    vector_dealloc(pbtest);
    //vector_dealloc(vector3);
    //vector_dealloc(newvec);

    return 0;
}
