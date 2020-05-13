#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// THE WORST CODE I'VE EVER WRITTEN //
char* conc(char* a, char* b) {
    char* t = (char*) malloc(1 + strlen(a) + strlen(b));
    strcpy(t, b);
    strcat(t, a);
    return t;
}

void print(void* ptr, char* fmt) {
    char ori = fmt[0];
    char* t = "%";
    fmt = conc(fmt, t);

    char i = 'd';
    char f = 'f';
    char c = 'c';
    char s = 's';
    char l = 'l';

    if      (ori == i) printf(fmt, *(int*)ptr);
    else if (ori == f) printf(fmt, *(float*)ptr);
    else if (ori == c || ori == s) printf(fmt, *(char*)ptr);
    else if (ori == l) printf(fmt, *(long*)ptr);
    else               printf("\nType Not Supported Yet\n");

}

void main() {
    int a = 2;
    print(&a, "d");
    float b = 1.2;
    print(&b, "f");

    char c = 'a';
    printf("\n");
    print(&c, "c");

    // char src = 'd';
    // char* nsr = &src;
    // char* des = "imp\0";
    // strncat(nsr, des, 3);
    // printf("%s", nsr);
