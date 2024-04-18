//program to reverse linked list
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insert(struct Node** head, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head);
    (*head) = new_node;
}

void reverse(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

void printList(struct Node *node) {
    while (node != NULL) {
        printf(" %d ", node->data);
        node = node->next;
    }
}

int main() {
    struct Node* head = NULL;
    int n, i, item;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &item);
        insert(&head, item);
    }

    printf("Original list: ");
    printList(head);

    reverse(&head);

    printf("\nReversed list: ");
    printList(head);

    return 0;
}
