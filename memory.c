#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// declare some functions and useful constants
#define RAND_SEED 225

// #defines for printArray function
#define PRINT_VALUE 0       // print array values
#define PRINT_MEMORY 1      // print array memory addresses
#define PRINT_RELATIVE 2    // print relative position in terms of bytes

void printSomeCharAddresses(int *ptrFromMain);
void mallocMadness(double value);
void manualArray(void);
void printArray(int size, int array[], int mode);

int main(int argc, char *argv[]) {
    
    // How does memory work in C?
    // figure it out using pointers
    int favNumber = 5;

    // print out the memory address of this int
    // we'll save it as a variable first
    int *favNumberLocation = &favNumber;

    // print the pointer
    printf("Value of favNumber: %d, Location of favNumber: %p\n",
        favNumber, favNumberLocation);

    // Let's do this again
    srand(RAND_SEED);               // set the 'seed' for random
    int randomNumber = rand() % 20; // get a random number
    int *randomNumberLocation = &randomNumber;

    printf("Value of randomNumber: %d, Location of randomNumber: %p\n",
        randomNumber, randomNumberLocation);

    // Let's do this again - now with malloc'd ints
    int *mallocNumber = malloc(sizeof(int));

    printf("Value of mallocNumber: %d, Location of mallocNumber: %p\n",
        *mallocNumber, mallocNumber);

    free(mallocNumber);

    // and now we compare the pointers
    // pointers are just hexadecimal numbers that 'point' to an
    // area of memory - they act as an index
    printf("Size of an int: %d\n", (int)sizeof(int));
    printf("Difference between int pointers: %d\n\n",
        (int)randomNumberLocation - (int)favNumberLocation);

    // Let's see what happens if we repeat this inside of a function...
    printSomeCharAddresses(randomNumberLocation);

    // mess with malloc
    mallocMadness(3.141592);

    // do array things
    manualArray();

    return EXIT_SUCCESS;
}

// declares some integers and prints out those pointers
void printSomeCharAddresses(int *ptrFromMain) {
    char n = 'n';
    char *nLoc = &n;

    printf("Value of n: %c, Location of n: %p\n", n, nLoc);

    char m = 'm';
    char *mLoc = &m;

    printf("Value of m: %c, Location of m: %p\n", m, mLoc);

    printf("Size of a char: %d\n", (int)sizeof(char));
    printf("Difference between char pointers: %d\n\n", (int)mLoc - (int)nLoc);

    // m was declared after n, so is it's memory address larger
    // or smaller?
    printf("m declared after n\n");
    printf("Where are they comparatively in memory?\n");
    printf("Is mLoc > nLoc?: %s\n\n", mLoc > nLoc ? "Yes" : "No");

    printf("Difference between char and ptr from main: %d\n\n", 
        (int)nLoc - (int)ptrFromMain);
}

// malloc magic
void mallocMadness(double value) {
    // let's use malloc to save a chunck of memory the size of double
    printf("Size of a double: %d\n", (int)sizeof(double));
    double *newPtr = malloc(sizeof(double));

    // print this new pointer
    printf("newPtr: %p\n", newPtr);

    // if it's not null that means malloc succeeded, so we can assign
    // a value to that area of memory
    // DEREFERENCE FIRST

    if (newPtr == NULL) {
        printf("Malloc failed :(\n");
        return; 
    }

    printf("Old value: %lf\n", *newPtr);
    *newPtr = value;
    printf("New value: %lf\n", *newPtr);

    // free the memory before we return
    free(newPtr);

    // Note: ptr is still not null!
    printf("NULL ptr: %p, Freed ptr: %p\n", NULL, newPtr);

    // Set ptr to null
    // since we are modifying the PTR and not its VALUE ...
    // we don't dereference
    newPtr = NULL;
    printf("NULL ptr: %p, Freed ptr: %p\n\n", NULL, newPtr);

    return;
}

// arrays and stuff
void manualArray(void) {
    // let's do this the easy way...
    int countToFive[5] = {1, 2, 3, 4, 5};

    // print values and memory addresses
    printf("countToFive:");
    printArray(5, countToFive, PRINT_VALUE);
    printf("countToFive ptrs:");
    printArray(5, countToFive, PRINT_MEMORY);
    printf("countToFive relative position:");
    printArray(5, countToFive, PRINT_RELATIVE);

    printf("\n");

    // Let's MANUALLY make an integer array, using malloc
    // create a ptr to the start of the array
    int *ptrArray = malloc(5 * sizeof(int));
    *ptrArray = 1;

    // but how do we assign the other values???
    // here's the WRONG way
    // *(ptrArray + 1*sizeof(int)) = 2;
    // *(ptrArray + 2*sizeof(int)) = 3;
    // *(ptrArray + 3*sizeof(int)) = 4;
    // *(ptrArray + 4*sizeof(int)) = 5;

    // here's the RIGHT way
    *(ptrArray + 1) = 2;
    *(ptrArray + 2) = 3;
    ptrArray[3] = 4;
    ptrArray[4] = 5;

    // print values and memory addresses
    printf("ptrArray:");
    printArray(5, ptrArray, PRINT_VALUE);
    printf("ptrArray ptrs:");
    printArray(5, ptrArray, PRINT_MEMORY);
    printf("ptrArray relative position:");
    printArray(5, ptrArray, PRINT_RELATIVE);

    // free memory!
    free(ptrArray);
}

// prints out all the values of an array
// OR prints out all the pts to the elements in the array
// OR prints out the number of bytes in memory of the ptr
// position relative to the first element of the array
// see print modes #defined above
void printArray(int size, int array[], int mode) {
    if (mode == PRINT_VALUE || mode == PRINT_RELATIVE) {
        int mem_diff = (int)&array[0] - (int)&array[0];
        int value = array[0];

        int i = 0;
        while (i < size) {
            mem_diff = (int)&array[i] - (int)&array[0];
            value = array[i];

            printf("\n\t%d", (mode == PRINT_VALUE) ? value : mem_diff);
            i++;
        }
        printf("\n\n");
    } else if (mode == PRINT_MEMORY) {
        int i = 0;
        while (i < size) {
            printf("\n\t%p", &array[i]);
            i++;
        }
        printf("\n\n");
    }

    return;
}