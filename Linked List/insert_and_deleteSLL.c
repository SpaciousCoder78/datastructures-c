//insert and delete operations in single linked list
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertAtBeginning(struct Node** head, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head);
    (*head) = new_node;
}

void insertAtEnd(struct Node** head, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    struct Node *last = *head;
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
}

void insertAtPosition(struct Node** head, int new_data, int position) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;

    if (position == 1) {
        new_node->next = *head;
        *head = new_node;
        return;
    }

    struct Node* previous = *head;
    for (int i = 1; i < position - 1; i++) {
        if (previous != NULL) {
            previous = previous->next;
        }
    }

    if (previous != NULL) {
        new_node->next = previous->next;
        previous->next = new_node;
    }
}

void delete(struct Node **head, int key) {
    struct Node* temp = *head, *prev;

    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}

void printList(struct Node *node) {
    while (node != NULL) {
        printf(" %d ", node->data);
        node = node->next;
    }
}

int main() {
    struct Node* head = NULL;
    int choice, data, position;

    while(1) {
        printf("\nMenu:\n1. Insert at Beginning\n2. Insert at End\n3. Insert at Position\n4. Delete\n5. Display\n6. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter the data to insert at beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("\nEnter the data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                printf("\nEnter the data to insert: ");
                scanf("%d", &data);
                printf("\nEnter the position to insert at: ");
                scanf("%d", &position);
                insertAtPosition(&head, data, position);
                break;
            case 4:
                printf("\nEnter the data to delete: ");
                scanf("%d", &data);
                delete(&head, data);
                break;
            case 5:
                printList(head);
                break;
            case 6:
                exit(0);
            default:
                printf("\nInvalid choice!");
        }
    }

    return 0;
}
