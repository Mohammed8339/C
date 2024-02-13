#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef UNTITLED_LINKED_LIST
#define UNTITLED_LINKED_LIST
typedef struct {
    int index;
    char* data;
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

// Function declarations
void size(Spine* spine, const int length);
Spine* newLinkedList();
Node* createNode(Spine* spine, const char* nodeData);
void printNodes(const Spine* spine);
char* getNode(const Spine* spine, const int index);

// Variable declarations
extern Spine* base_spine_address;
extern Spine* current_spine_address;
extern Spine* previous_spine_address;
extern int spineIndex;
extern int ran;
extern int firstSpine;

#endif