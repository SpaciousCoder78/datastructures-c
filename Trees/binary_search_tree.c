#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node * lchild;
    struct node * rchild;
}BinTree;

BinTree *root;

struct node * createNode(int value) {
    struct node * newNode;
    newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=value;
    newNode->lchild = NULL;
    newNode ->rchild=NULL;
    return newNode;
}
struct node* insertNode(struct node *t,int value) {
    if(t=NULL) {
        t=createNode(value);

    }
    else {
        if(value>t->data) {
            t->rchild=insertNode(t->rchild,value);
        }
        else if(value < t->data) {
            t->lchild = insertNode(t->lchild,value);
        }
        else {
            printf("Already value exists");
        }
    }
    return t;
}
