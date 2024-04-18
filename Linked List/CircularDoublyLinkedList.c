//circular doubly linked list using head
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
        newNode->prev = newNode->next = newNode;
    } else {
        struct Node* last = (head->next->prev);

        last->next = newNode;
        newNode->prev = last;
        newNode->next = head->next;
        head->next->prev = newNode;
    }

    return head;
}

struct Node* deleteNode(struct Node* head, int key) {
    if (head->next == NULL)
        return NULL;

    struct Node* curr = head->next, *prev = NULL;
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
            prev = head->next->prev;
            head->next = head->next->next;
            head->next->prev = prev;
            free(curr);
        } else if (curr->next == head->next) {
            prev->next = head->next;
            head->next->prev = prev;
            free(curr);
        } else {
            struct Node* temp = curr->next;
            prev->next = temp;
            temp->prev = prev;
            free(curr);
        }
    }
    return head;
}

void display(struct Node* head) {
    struct Node* temp = head->next;
    while (temp->next != head->next) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d", temp->data);
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
