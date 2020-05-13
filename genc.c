#include <stdio.h>
#include <string.h>

void print(char p, int d) {
    char* percent = "%";
    //char* fmt = percent + p;
    strncat(percent, p, 1);
    printf("%s", percent);
}

void main() {
    print('d', 2);
}
