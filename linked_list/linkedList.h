#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int index;
    int data;
    struct Node* next;
} Node;

typedef struct {
    int index;
    Node* base_node_address;
    Node* current_node_address;
    Node* previous_node_address;
    int location;
    int MAX_NODES;
    struct Node* current_node;
    struct Spine* next;
} Spine;

Spine* base_spine_address = NULL;
Spine* current_spine_address = NULL;
Spine* previous_spine_address = NULL;

int spineIndex = 0;
bool ran = false;
bool firstSpine = true;

void size(Spine* spine, const int length) {
    spine->MAX_NODES = length;
    ran = true;
}

Spine* newLinkedList() {
    Spine* newSpine = malloc(sizeof(Spine));
    newSpine->index = spineIndex;
    newSpine->base_node_address = NULL;
    newSpine->next = NULL;
    newSpine->location = 0;

    current_spine_address = newSpine;

    if (spineIndex != 0) {
        previous_spine_address->next = newSpine;
    }
    else {
        base_spine_address = newSpine;
        firstSpine = false;
    }
    ++spineIndex;
    previous_spine_address = newSpine;

    return newSpine;
}


Node* createNode(Spine* spine, const int nodeData) {
    int location = spine->location;

    if (firstSpine == true) {
        firstSpine = false; // wtf?
    }

    if (ran == false) {
        printf("You must call the size() function before creating a node\n");
        return NULL;
    }

    if (location >= spine->MAX_NODES) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));

    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    newNode->data = nodeData;
    newNode->index = location;
    newNode->next = NULL;
    spine->current_node_address = newNode; /* Set the current node address to the new node. */

    if (location != 0) {
        spine->previous_node_address->next = spine->current_node_address;
    }
    else {
        spine->base_node_address = newNode; /* Set the base node address to the new node. */
    }
    spine->previous_node_address = spine->current_node_address;
    spine->location = ++location; /* Increment location */
    return newNode;
}

void removeNode(Spine* spine, const int nodeIndex) {
    Node* prev_node_addr = NULL;
    Node* temp = spine->base_node_address;

    if (temp->index == nodeIndex) {
        spine->base_node_address = temp->next;
        free(temp);
        return;
    }

    bool loop = true;
    while (loop) {

        if (temp->index == nodeIndex) {
            prev_node_addr->next = temp->next;
            free(temp);
            loop = false;
            return;
        }

        prev_node_addr = temp;
        temp = temp->next;
    }
}

void printNodes(const Spine* spine) {
    Node* temp = spine->base_node_address;
    while (temp != NULL) {
        printf("spine: %d\n", spine->index);
        printf("pointer: %p\n", temp);
        printf("index: %d\n", temp->index);
        printf("data: %d\n", temp->data);
        printf("next: %p\n", temp->next);
        temp = temp->next;
    }
    printf("\n\n\n");
}