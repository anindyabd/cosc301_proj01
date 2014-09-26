#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/* your list function definitions */

void list_print(const Node *list) {
    int i = 0;
    printf("In list_print\n");
    while (list != NULL) {
        printf("List item %d: %d\n", i++, list->data);
        list = list->next;
    }
}

void sorted_insert(int data, Node **head) {
    if ((*head) == NULL) {
        Node *newnode = malloc(sizeof(Node));
        newnode->data = data;
        *head = newnode; 
    }
    else if ((*head)->data >= data) {
        Node *newnode = malloc(sizeof(Node));
        newnode->data = data;
        newnode->next = *head;
        *head = newnode;
    }
    else {
        Node *curr = *head;
        while (curr->next != NULL) {
            if ((curr->next)->data >= data) {
                Node *newnode = malloc(sizeof(Node));
                newnode->data = data;
                Node *tmp = curr->next;
                curr->next = newnode;
                newnode->next = tmp;
                return;
            }  
            curr = curr->next;
        }
        Node *newnode = malloc(sizeof(Node));
        newnode->next = NULL;
        newnode->data = data;
        curr->next = newnode;
    }


}

/*int main(int argc, char **argv) {
    char buffer[128];

    Node *head = NULL;

    printf("Next string to add: ");
    fflush(stdout);
    while (fgets(buffer, 128, stdin) != NULL) {
        // fgets includes the newline character at
        // the end of a string as the last character.
        // let's squash it.
        int slen = strlen(buffer);
        buffer[slen-1] = '\0';
        int myint = atoi(buffer);
        printf("Where does it crash\n");
        sorted_insert(myint, &head);
        printf("Adding %s\n", buffer);

        printf("Next string to add (or ctrl+d to exit): ");
        fflush(stdout);
    }
    list_print(head);
}*/