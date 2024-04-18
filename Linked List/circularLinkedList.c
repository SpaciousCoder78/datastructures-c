//circular linked list with head node
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    if (head->next == NULL) {
        head->next = newNode;
        newNode->next = newNode;
    } else {
        struct Node* last = head->next;
        while (last->next != head->next)
            last = last->next;

        last->next = newNode;
        newNode->next = head->next;
    }

    return head;
}

struct Node* deleteNode(struct Node* head, int key) {
    if (head->next == NULL)
        return NULL;

    struct Node* curr = head->next, *prev = head;
    while (curr->data != key) {
        if (curr->next == head->next) {
            printf("\nGiven node is not found in the list!!!");
            break;
        }

        prev = curr;
        curr = curr->next;
    }

    if (curr->next != head->next || curr->data == key) {
        if (curr == head->next) {
            head->next = head->next->next;
            free(curr);
        } else {
            prev->next = curr->next;
            free(curr);
        }
    }
    return head;
}

void display(struct Node* head) {
    struct Node* temp = head->next;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head->next);
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
