#include <stdio.h>
#include <stdlib.h>

int main(void) {

    // a void pointer is a pointer to an address
    // but it doesnt have a cooresponding type
    // the pointers point to an address
    // the only thing you can do is assign them to other pointers

    int *p = malloc(sizeof(int) * 10);
    char *q = malloc(sizeof(char) * 10);
    float *r = malloc(sizeof(float) * 10);

}