#include <stdio.h>
#include <stdlib.h>


char *foo(void) {

    // this pointer is not initialized. it has some 
    // value in it but we don't know what it is.
    // we dont know where its pointing and thats not useful to us
    // char *p; 

    // lets point it at something. this is not normal but now it is pointing at something
    // char *p = 1239;

    // now lets call malloc with 10 bytes. we have allocated space
    // on the heap
    // p is avariable on the stack. it goes away from foo is done. 
    // this creates a memory leak because we loose reference to p
    char *p = malloc(10);
    
    // both of these valiables are automatically freed when the funtion 
    // returns, but mallor is not
    char q[10];

    return p;

}

int main(void) {

    // pick up pointer p in q and now we can use p without loosing it
    // q is a copy of p, but it wont be lost when the stack clears
    char *q = foo();

    q[0] = 'A';
    q[9] = 'Z';

    free(q);
    // DONT do anything with the memory once you've freed it!!

}