//binary search tree recursive
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* lchild;
    struct node* rchild;
} BinTree;

BinTree* root = NULL;

struct node* createNode(int value) {
    struct node* newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->lchild = NULL;
    newNode->rchild = NULL;
    return newNode;
}

struct node* insertNode(struct node* t, int value) {
    if (t == NULL) {
        t = createNode(value);
    } else {
        if (value > t->data) {
            t->rchild = insertNode(t->rchild, value);
        } else if (value < t->data) {
            t->lchild = insertNode(t->lchild, value);
        } else {
            printf("Value already exists\n");
        }
    }
    return t;
}

BinTree* findMin(BinTree* t) {
    while (t->lchild != NULL) {
        t = t->lchild;
    }
    return t;
}

void deleteNode(int item) {
    BinTree* ptr = root;
    BinTree* parent = NULL;
    BinTree* ptr1;
    int flag = 0, option;

    while (ptr != NULL && flag == 0) {
        if (item == ptr->data) {
            flag = 1;
        } else if (item < ptr->data) {
            parent = ptr;
            ptr = ptr->lchild;
        } else {
            parent = ptr;
            ptr = ptr->rchild;
        }
    }

    if (ptr == NULL) {
        printf("Element not found\n");
        return;
    } else {
        if (ptr->lchild == NULL && ptr->rchild == NULL) {
            option = 1;
        } else if (ptr->lchild != NULL && ptr->rchild != NULL) {
            option = 3;
        } else {
            option = 2;
        }
    }

    if (option == 1) {
        if (parent->lchild == ptr) {
            parent->lchild = NULL;
        } else {
            parent->rchild = NULL;
        }
        free(ptr);
    } else if (option == 2) {
        if (parent->lchild == ptr) {
            if (ptr->lchild != NULL) {
                parent->lchild = ptr->lchild;
            } else {
                parent->lchild = ptr->rchild;
            }
        } else if (parent->rchild == ptr) {
            if (ptr->lchild != NULL) {
                parent->rchild = ptr->lchild;
            } else {
                parent->rchild = ptr->rchild;
            }
        }
        free(ptr);
    } else if (option == 3) {
        ptr1 = findMin(ptr->rchild);
        int minValue = ptr1->data;
        deleteNode(minValue);
        ptr->data = minValue;
    }
}

void inorderTraversal(BinTree* t) {
    if (t != NULL) {
        inorderTraversal(t->lchild);
        printf("%d ", t->data);
        inorderTraversal(t->rchild);
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert Node\n");
        printf("2. Delete Node\n");
        printf("3. Inorder Traversal\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
            scanf("%d", &value);
            root = insertNode(root, value);
            break;
            case 2:
                printf("Enter value to delete: ");
            scanf("%d", &value);
            deleteNode(value);
            break;
            case 3:
                printf("Inorder Traversal: ");
            inorderTraversal(root);
            printf("\n");
            break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}
