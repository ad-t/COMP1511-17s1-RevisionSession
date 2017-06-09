#include <stdio.h>
#include <stdlib.h>

/*
    Sabrina Rispin, Jun 2017
    binSearch, bubbleSort and quickSort modified versions
    of Andrew Taylor's COMP1511 S1 2017 code
*/

int linearSearch(int len, int array[], int find);
int binarySearch(int len, int array[], int find);
void bubblesort(int length, int array[]);
void printBubbleSort(int len, int array[], int pos);
void printArray(int len, int array[]);
void printSubArray(int start, int end, int array[]);
void quicksort(int array[], int length);
void quicksort1(int array[], int lo, int hi, int *skip);
int partition(int array[], int lo, int hi);
void pause(int *skip);

int main(int argc, char *argv[]) {
    
    // a simple search example
    int sortedArray[10] = {13, 21, 32, 47, 50, 61, 66, 85, 90, 99};

    linearSearch(10, sortedArray, 61);
    binarySearch(10, sortedArray, 61);

    // unsorted array
    int unsortedArray[10] = {50, 32, 99, 66, 85, 13, 21, 47, 90, 61};

    linearSearch(10, unsortedArray, 61);    // will work
    binarySearch(10, unsortedArray, 61);    // won't work (why?)
    
    bubblesort(10, unsortedArray);          // sort array   
    binarySearch(10, unsortedArray, 61);    // binary search works!

    int array[10] = {50, 32, 99, 66, 85, 13, 21, 47, 90, 61};

    quicksort(array, 10);   // quicksort example

    return EXIT_SUCCESS;
}

// take in an array + its length as well as a value to search for
// return the index in the array of that value
// returns -1 if not found
int linearSearch(int len, int array[], int find) {
    printf("LINEAR SEARCH for %d in ", find);
    printArray(len, array);
    printf("Press ENTER to step through, enter s to skip: ");
    int skip = getchar() == 's' ? 1 : 0;
    if (skip) {
        getchar();
    }
    char newline = skip ? '\n' : ' ';

    int i = 0;
    while (i < len) {
        printf("ind: %d, val: %d%c", i, array[i], newline);
        if (array[i] == find) {
            if (!skip) {
                printf("\n");
            }
            printf("\n%d was found at index %d!\n\n", find, i);
            return i;
        }

        // wait for user to hit enter
        pause(&skip);

        i++;
    }

    printf("\n%d was not found in the array\n\n", find);
    return -1;
}

int binarySearch(int len, int array[], int find) {
    printf("BINARY SEARCH for %d in ", find);
    printArray(len, array);
    printf("Press ENTER to step through, enter s to (s)kip: ");
    int skip = getchar() == 's' ? 1 : 0;
    if (skip) {
        getchar();
    }
    char newline = skip ? '\n' : ' ';

    int lower = 0;
    int upper = len - 1;
    while (lower <= upper) {
        int mid = (lower + upper)/ 2;
        char compare = array[mid] < find ? '<' : '>';
        if (array[mid] ==  find) {
            compare = '=';
        }
        
        printf("mid ind: %d, val: %d, %d %c %d\t", mid, array[mid], array[mid], compare, find);

        if (array[mid] == find) {
            printf("%d was found at index %d!\n\n", find, mid);
            return mid;
        } else if (array[mid] > find) {
            printf("Searching lower half...%c", newline);
            upper = mid - 1;
        } else {
            printf("Searching upper half...%c", newline);
            lower = mid + 1;
        }

        // wait for user to hit enter
        pause(&skip);
    }

    printf("\n%d was not found in the array\n\n", find);
    return -1;
}

void bubblesort(int length, int array[]) {
    printf("BUBBLE SORT ");
    printArray(length, array);
    printf("Press ENTER to step through, enter s to (s)kip: ");
    int skip = getchar() == 's' ? 1 : 0;
    if (skip) {
        getchar();
    }

    int swapped = 1;
    while (swapped) {
        swapped = 0;
        for (int i = 1; i < length; i = i + 1) {
            printBubbleSort(length, array, i);
            
            if (array[i] < array[i - 1]) {
                int tmp = array[i];
                array[i] = array[i - 1];
                array[i - 1] = tmp;
                swapped = 1;
            }

            // wait for user to hit enter
            pause(&skip);
        }
    }
}

void printBubbleSort(int len, int array[], int pos) {
    printArray(len, array);

    int i = 0;
    while (i < len) {
        if (i == pos) {
            printf(" |%s|  ", array[i] > array[i+1] ? "swap" : "    ");
        } else if (i + 1 != pos) {
            printf("    ");
        }
        
        i++;
    }
    printf("\n\n");
}

void printArray(int len, int array[]) {
    printf("[%d", array[0]);
    int i = 1;
    while (i < len) {
        printf(", %2d", array[i]);
        i++;
    }
    printf("]\n");
}

void printSubArray(int start, int end, int array[]) {
    printf("[%d", array[start]);
    int i = start+1;
    while (i < end+1) {
        printf(", %2d", array[i]);
        i++;
    }
    printf("]\n");
}

void quicksort(int array[], int length) {
    printf("QUICKSORT ");
    printArray(length, array);

    printf("Press ENTER to step through, enter s to (s)kip: ");
    int skip = getchar() == 's' ? 1 : 0;
    if (skip) {
        getchar();
    }

    quicksort1(array, 0, length - 1, &skip);

    printf("\n\nFinal Array: ");
    printArray(length, array);
}

void quicksort1(int array[], int lo, int hi, int *skip) {
    if (lo >= hi) {
        return;
    }
    // rearrange array so that
    // all elements smaller than pivot value are below it and
    // all element larger than pivot value are above it

    printf("\nArray before partition: ");
    printSubArray(lo, hi, array);
    int p = partition(array, lo, hi);
    printf("Array after partition: ");
    printSubArray(lo, hi, array);

    // wait for user to hit enter
    pause(skip);
    
    // sort lower part of array
    printf("\nQuicksort below pivot: ");
    printSubArray(lo, p, array);
    quicksort1(array, lo, p, skip);

    // wait for user to hit enter
    pause(skip);

    // sort upper part of array
    printf("\nQuicksort above pivot: ");
    printSubArray(p+1, hi, array);
    quicksort1(array, p + 1, hi, skip);

    printf("\nCombining sorted halves:\n");
    printSubArray(lo, hi, array);
}


int partition(int array[], int lo, int hi) {
    int i = lo;
    int j = hi;

    // use middle value as pivot
    int pivotValue = array[(lo + hi) / 2];
    printf("Pivot value: %d\n", pivotValue);

    // start from left and right ends
    while (1) {

        // Look for pair to swap

        while (array[i] < pivotValue) {
            i = i + 1;
        }

        while (array[j] > pivotValue) {
            j = j - 1;
        }

        // No pair to swap so return
        if (i >= j) {
            return j;
        }
        // and swap them over
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
        i = i + 1;
        j = j - 1;
    }
}

void pause(int *skip) {
    if (!*skip) {
        char c = getchar();
        while (c != '\n') {
            if (c == 's') {
                *skip = 1;
                c = '\n';
            }
            c = getchar();
        };
    }
}