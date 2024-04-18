//search operations in linked list
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
    } else {
        struct Node* last = head;
        while (last->next != NULL)
            last = last->next;

        last->next = newNode;
    }

    return head;
}

struct Node* searchNode(struct Node* head, int key) {
    struct Node* current = head->next;
    while (current != NULL) {
        if (current->data == key)
            return current;
        current = current->next;
    }
    return NULL;
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
        printf("\n1.Insert\n2.Search\n3.Display\n4.Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter the data to insert: ");
                scanf("%d", &data);
                head = insertEnd(head, data);
                break;
            case 2:
                printf("\nEnter the data to search: ");
                scanf("%d", &data);
                struct Node* result = searchNode(head, data);
                if (result != NULL)
                    printf("\nData found in the list.");
                else
                    printf("\nData not found in the list.");
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
