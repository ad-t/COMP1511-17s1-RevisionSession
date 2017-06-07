#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

int main (int argc, char * argv[]) {

    char * name = "COMP1511";

    char name_copy[15];
    strcpy(name_copy, name);

    return EXIT_SUCCESS;
}
