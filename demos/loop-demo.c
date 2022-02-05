#include <stdio.h>
#include <stdlib.h>

int loop(int start, int end) {

    printf("\n*** stack frame");

    if (start < end) {
        loopf(start + 1, end);
    } else {
        
    }

}

int main(void) {
    loopf(0,3);
}