#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(void) {
    void *p;

    p = sbrk(0);

    printf("%p\n", p);

    p = sbrk(1024);

    printf("%p\n", p);

    char *q = p;

    strcpy(q, "Hello, world!");
    
    printf("%p\n", p);

    printf("%s\n", q);
}