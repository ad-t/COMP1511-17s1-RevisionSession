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
    assert(listSize(NULL) == 0);
    assert(!listMember(NULL, 0));

    struct node * second = createNode(5);
    assert(listSize(second) == 1);
    assert(!listMember(second, 6));

    printList(list);

    // let's add more tests!

    return EXIT_SUCCESS;
}
