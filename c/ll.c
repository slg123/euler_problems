#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int length(struct node *head);

int main() {

    struct node *curr;
    struct node *head;

    head = NULL;

    for (int i=1; i<=20; i++) {
        curr = (struct node *) malloc(sizeof *curr);
        curr->data = i;
        curr->next = head;
        head = curr;
    }

    while (curr) {
        printf(" %d ", curr->data); 
        curr = curr->next;
    }
    printf("\n\n"); 

    for (curr = head; curr != NULL; curr = curr->next) {
        printf(" %d ", curr->data); 
    }

    printf("\nlength: %d\n", length(head)); 

    return 0;
}

int length(struct node *head) {
    int count = 0; 
    struct node *current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}




