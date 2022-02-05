#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int *p = malloc(sizeof(int) * 10);

    // this is saying "whats the size of d reference p"
    // this is the same as "whats the size of p[0]"
    // int *p = malloc(sizeof *p * 10);

    // printf("%ld\n", *p);
    // printf("%zu\n", sizeof(int));
    // printf("%zu\n", sizeof(long int));

    *p = 12;

    //this sets the zeroth index to 12
    *(p + 0) = 12;
    p[0] = 12;

    // goes to the next integer
    *(p + 0) = 24;
    p[1] = 24;


    printf("%d\n", *p);

    free(p);
}