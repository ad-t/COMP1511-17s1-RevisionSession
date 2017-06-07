#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "linked_list.h"

int main (int argc, char * argv[]) {
    
    // create a new linked list
    struct node * list = createNode(0);
    // check if it is null
    assert(list != NULL);
    // add 30 items
    for (int i = 1; i <= 30; i++) {
        append(list, i);
    }
    assert(listSize(list) == 31);
    assert(listRemove(list, 24));
    assert(listSize(list) == 30);
    assert(listMember(list, 21));

    // let's add more tests!

    return EXIT_SUCCESS;
}
