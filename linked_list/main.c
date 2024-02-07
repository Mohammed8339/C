#include <stdio.h>
#include "linkedList.h"

int addresses[1000];


int main() {

    Spine* list1 = newLinkedList();
    Spine* list2 = newLinkedList();

    size(list1, 100);
    createNode(list1, 100);
    createNode(list1, 200);

    size(list2, 100);
    createNode(list2, 1);
    createNode(list2, 2);

    printNodes(list1);
    printNodes(list2);
}
