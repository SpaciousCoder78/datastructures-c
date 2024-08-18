#include <stdio.h>
#include <stdlib.h>

#define SIZE 20
int top = -1;


typedef struct node {
    int data;
    struct node* lchild;
    struct node* rchild;
} BinTree;

BinTree* Stack[SIZE];
void push(BinTree *t) {
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

void inorder(BinTree *t) {
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

void preorder(BinTree *t) {
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

void postorder(BinTree *t) {
    BinTree *prev = NULL;
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
    // Example usage
    BinTree* root = (BinTree*)malloc(sizeof(BinTree));
    root->data = 1;
    root->lchild = (BinTree*)malloc(sizeof(BinTree));
    root->rchild = (BinTree*)malloc(sizeof(BinTree));
    root->lchild->data = 2;
    root->rchild->data = 3;
    root->lchild->lchild = NULL;
    root->lchild->rchild = NULL;
    root->rchild->lchild = NULL;
    root->rchild->rchild = NULL;

    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");

    return 0;
}
