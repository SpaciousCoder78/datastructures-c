//binary tree non recursive
#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

typedef struct node {
    int data;
    struct node* lchild;
    struct node* rchild;
} BinTree;

BinTree* Stack[SIZE];
int top = -1;

BinTree* createNode() {
    BinTree* newnode;
    newnode = (BinTree*)malloc(sizeof(BinTree));
    printf("Enter data: ");
    scanf(" %d", &newnode->data);
    newnode->lchild = NULL;
    newnode->rchild = NULL;
    return newnode;
}

BinTree* create() {
    int ch;
    BinTree* t;
    t = createNode();
    puts("If you want left child press 1");
    scanf("%d", &ch);
    if (ch == 1) {
        t->lchild = create();
    }
    puts("For right child press 1: ");
    scanf("%d", &ch);
    if (ch == 1) {
        t->rchild = create();
    }
    return t;
}

void push(BinTree* t) {
    if (top == SIZE - 1) {
        printf("Overflow\n");
    } else {
        top = top + 1;
        Stack[top] = t;
    }
}

BinTree* pop() {
    if (top == -1) {
        printf("Underflow\n");
        return NULL;
    } else {
        return Stack[top--];
    }
}

void inorder(BinTree* t) {
    while (1) {
        if (t != NULL) {
            push(t);
            t = t->lchild;
        } else if (top != -1) {
            t = pop();
            printf("%d ", t->data);
            t = t->rchild;
        } else {
            break;
        }
    }
}

void preorder(BinTree* t) {
    while (1) {
        if (t != NULL) {
            printf("%d ", t->data);
            push(t);
            t = t->lchild;
        } else if (top != -1) {
            t = pop();
            t = t->rchild;
        } else {
            break;
        }
    }
}

void postorder(BinTree* t) {
    BinTree* prev = NULL;
    while (t != NULL || top != -1) {
        if (t != NULL) {
            push(t);
            t = t->lchild;
        } else {
            t = Stack[top];
            if (t->rchild == NULL || t->rchild == prev) {
                printf("%d ", t->data);
                prev = pop();
                t = NULL;
            } else {
                t = t->rchild;
            }
        }
    }
}

int main() {
    BinTree* root = NULL;
    int choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create Binary Tree\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                root = create();
                break;
            case 2:
                if (root == NULL) {
                    printf("Tree is empty\n");
                } else {
                    printf("Inorder Traversal: ");
                    inorder(root);
                    printf("\n");
                }
                break;
            case 3:
                if (root == NULL) {
                    printf("Tree is empty\n");
                } else {
                    printf("Preorder Traversal: ");
                    preorder(root);
                    printf("\n");
                }
                break;
            case 4:
                if (root == NULL) {
                    printf("Tree is empty\n");
                } else {
                    printf("Postorder Traversal: ");
                    postorder(root);
                    printf("\n");
                }
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
