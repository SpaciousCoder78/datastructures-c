//concatenating 2 linked lists
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

void concatenate(struct Node* a, struct Node* b) {
    if (a != NULL && b != NULL) {
        if (a->next == NULL)
            a->next = b;
        else
            concatenate(a->next, b);
    } else {
        printf("Either a or b is NULL\n");
    }
}

void printList(struct Node *node) {
    while (node != NULL) {
        printf(" %d ", node->data);
        node = node->next;
    }
}

int main() {
    struct Node* a = NULL;
    struct Node* b = NULL;
    int n, i, item;

    printf("Enter the number of elements in the first list: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &item);
        insert(&a, item);
    }

    printf("Enter the number of elements in the second list: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &item);
        insert(&b, item);
    }

    printf("First list: ");
    printList(a);
    printf("\nSecond list: ");
    printList(b);

    concatenate(a, b);

    printf("\nConcatenated list: ");
    printList(a);

    return 0;
}
