#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "linkedList.h"

Spine* linkedList = NULL;

void displayTasks(Spine* list) {
    for (int i = 0; i < list->location; i++) {
        printf("%s\n", getNode(list, i));
    }
}

void addTask(Spine* list, char task[]) {
    createNode(list, task);
}

int main() {
    linkedList = newLinkedList();
    bool loop = true;
    while (loop) {
        printf("Todo List:\n");
        printf("[1] Add a task\n");
        printf("[2] remove a task\n");
        printf("[3] show all tasks\n");
        printf("[4] exit\n");

        char input[10];
        fgets(input, sizeof(input), stdin);

        switch (atoi(input)) {
            case 1:
                printf("what do you want to add as your task?");

                char task[1000];
                char* buffer;

                fgets(task, sizeof(task), stdin);

                char *newline = strchr(task, '\n');
                if (newline) {
                    *newline = '\0';
                }

                buffer = (char*) malloc((strlen(task) + 1) * sizeof(char));

                if (buffer == NULL) {
                    printf("Memory allocation failed\n");
                    exit(1);
                }

                strcpy(buffer, task);

                addTask(linkedList, buffer);

                break;
            case 2:
                printf("case 2 selected");
                break;
            case 3:
                displayTasks(linkedList);
                break;
            default:
                printf("other case selected");
                break;
        }
    }
    return 0;
}