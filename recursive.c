#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int factorial(int n) {
    if (n == 0) {
        return 1;
    } else if (n < 0) {
        return 0;
    } else {
        return n * factorial(n-1);
    }
}

int main (int argc, char * argv[]) {

    assert(factorial(0) == 1);
    assert(factorial(1) == 1);
    assert(factorial(2) == 2);
    assert(factorial(3) == 6);
    assert(factorial(-1) == 0);
    assert(factorial(10) == 3628800);

    return EXIT_SUCCESS;
}
