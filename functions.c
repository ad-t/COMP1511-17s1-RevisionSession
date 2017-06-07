#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int factorial(int n) {
    if (n < 0) {
        return 0;
    }
    int current = n;
    int sum = 1;
    while (current > 0) {
        sum = sum * current;
        current = current - 1;
    }
    return sum;
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
