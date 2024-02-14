#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "linkedList.h"

Spine* base_spine_address = NULL;
Spine* current_spine_address = NULL;
Spine* previous_spine_address = NULL;
int spineIndex = 0;
//int ran = 0;
int firstSpine = 0;

//void size(Spine* spine, const int length) {
//    spine->MAX_NODES = length;
//    ran = true;
//}

Spine* newLinkedList() {
    Spine* newSpine = malloc(sizeof(Spine));
    newSpine->index = spineIndex;
    newSpine->base_node_address = NULL;
    newSpine->next = NULL;
    newSpine->location = 0;

    current_spine_address = newSpine;

    if (spineIndex != 0) {
        previous_spine_address->next = (struct Spine *) newSpine;
    }
    else {
        base_spine_address = newSpine;
        firstSpine = false;
    }
    ++spineIndex;
    previous_spine_address = newSpine;

    return newSpine;
}


Node* createNode(Spine* spine, const char* nodeData) {
    int location = spine->location;

    if (firstSpine == true) {
        firstSpine = false;
        // if the first spine is created,
        // set the firstSpine to false will eventually be used for something
    }

//    if (ran == false) {
//        printf("You must create a spine before creating a node\n");
//        return NULL;
//    }

//    if (location >= spine->MAX_NODES) {
//        printf("Memory allocation failed\n");
//        return NULL;
//    }

    Node* newNode = (Node*)malloc(sizeof(Node));

    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    newNode->data = malloc(strlen(nodeData) + 1);

    if (newNode->data == NULL) {
        printf("Memory allocation failed\n");
        free(newNode->data);
        return NULL;
    }
    strcpy(newNode->data, nodeData);

    newNode->index = location;
    newNode->next = NULL;
    spine->current_node_address = newNode; /* Set the current node address to the new node. */

    if (location != 0) {
        spine->previous_node_address->next = (struct Node *) spine->current_node_address;
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
        spine->base_node_address = (Node *) temp->next;
        free(temp->data);  // Free the memory allocated for the character array
        free(temp);
        return;
    }

    while (temp != NULL) {
        if (temp->index == nodeIndex) {
            prev_node_addr->next = temp->next;
            free(temp->data);  // Free the memory allocated for the character array
            free(temp);
            return;
        }

        prev_node_addr = temp;
        temp = (Node *) temp->next;
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
        temp = (Node *) temp->next;
    }
    printf("\n\n\n");
}

char* getNode(const Spine* spine, const int nodeIndex) {
    Node* temp = spine->base_node_address;
    while (temp != NULL) {
        if (temp->index == nodeIndex) {
            return temp->data;
        }
        temp = (Node *) temp->next;
    }
    return NULL;
}

int getSize(const Spine* spine) {
    return (int) spine->location;
}