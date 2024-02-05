#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int index;
    int data;
    struct Node* next;
} Node;

Node* base_node_address = NULL;
Node* current_node_address = NULL;
Node* previous_node_address = NULL;


int defaultSize = 10;
int MAX_NODES= 10;
Node** pointer = NULL;
bool ran = false;

void size(int size) {
    MAX_NODES = size;
    pointer = (Node**)malloc(MAX_NODES * sizeof(Node*));
    ran = true;
}

int location = 0;


Node* createNode(int nodeData) {

    if (ran == false) {
        pointer[defaultSize];
        return NULL;
    }
    else {
        pointer[MAX_NODES];
    }

    if (location >= MAX_NODES) {
        printf("Max size reached\n");
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
    current_node_address = newNode;
    // pointer[location] = newNode; /* Stores the memory address of the struct. */

    if (location != 0) {
        previous_node_address->next = current_node_address;
        // pointer[location - 1]->next = newNode; /* Set the next pointer of the previous node to the new node */
    }
    else {
        base_node_address = newNode; /* Set the base node address to the new node. */
    }
    previous_node_address = current_node_address;
    location++; /* Increment location */
    return newNode;
}

void removeNode(int nodeIndex) {
    Node* prev_node_addr = NULL;
    Node* temp = base_node_address;

    if (temp->index == nodeIndex) {
        base_node_address = temp->next;
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
        else {
            prev_node_addr = temp;
            temp = temp->next;
        }
    }
}

void printNodes() {
    Node* temp = base_node_address;
    while (temp != NULL) {
        printf("pointer: %p\n", temp);
        printf("index: %d\n", temp->index);
        printf("data: %d\n", temp->data);
        printf("next: %p\n", temp->next);
        temp = temp->next;
    }
}