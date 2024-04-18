//doubly linked list with head

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    if (head->next == NULL) {
        head->next = newNode;
        newNode->prev = head;
    } else {
        struct Node* last = head;
        while (last->next != NULL)
            last = last->next;

        last->next = newNode;
        newNode->prev = last;
    }

    return head;
}

struct Node* deleteNode(struct Node* head, int key) {
    if (head->next == NULL)
        return NULL;

    struct Node* curr = head->next;
    while (curr != NULL && curr->data != key)
        curr = curr->next;

    if (curr != NULL) {
        if (curr->next != NULL)
            curr->next->prev = curr->prev;
        if (curr->prev != NULL)
            curr->prev->next = curr->next;

        free(curr);
    } else {
        printf("\nGiven node is not found in the list!!!");
    }

    return head;
}

void display(struct Node* head) {
    struct Node* temp = head->next;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    struct Node* head = createNode(0);  // Creating a head node
    int choice, data;

    while(1) {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter the data to insert: ");
                scanf("%d", &data);
                head = insertEnd(head, data);
                break;
            case 2:
                printf("\nEnter the data to delete: ");
                scanf("%d", &data);
                head = deleteNode(head, data);
                break;
            case 3:
                display(head);
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid choice!");
        }
    }

    return 0;
}
