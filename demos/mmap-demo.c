#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/mman.h>
#include <stdlib.h>

// mmap(void *addr, size_t len, int prot, int flags, int fd, off_t offset);

int main(void) {

    void *p;

    void *q = sbrk(65536);

    // p = mmap(NULL, 1023, PROT_READ|PROT_WRITE, MAP_ANON|MAP_PRIVATE, -1, 0);
    p = mmap(NULL, 1024*1024, PROT_READ|PROT_WRITE, MAP_ANON|MAP_SHARED, -1, 0);

    if (p == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }

    // void *q = sbrk(0);

    printf("Mmap: %p\n", p);
    printf("Heap: %p\n", q);

    // printf("%p\n", p);

    // char *q = p;

    // strcpy(q, "HELLO, world!");

    // if(fork() == 0) {
    //     strcpy(q, "hello from the child!");
    //     printf("Child: %s\n", q);
    //     exit(0);
    // }

    // wait(NULL);

    // printf("Parent: %s\n", q);

    // printf("%s\n", q);

    // if(munmap(p, 1024)==-1) {
    //     perror("munmap");
    //     exit(1);
    // }
}