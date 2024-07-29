#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    char data;
    struct node * lchild;
    struct node * rchild;
}BinTree;

BinTree *root;

BinTree *createNode() {
    BinTree* newnode;
    newnode = (BinTree*)malloc(sizeof(BinTree));
    printf("Enter data: ");
    scanf("%c",newnode->data);
    newnode->lchild=NULL;
    newnode->rchild=NULL;
    return newnode;
}

BinTree *create() {
    int ch;
    BinTree *t;
    t=createNode();
    puts("if you want left child press 1");
    scanf("%d",&ch);
    if(ch==1) {
        t->lchild=create();
    }
    puts("for right child press 1: ");
    if(ch==1) {
        t->rchild=create();
    }
    return t;
}

void inorder(BinTree *t) {
    if(t) {
        inorder(t->lchild);
        printf("%d ",t->data);
        inorder(t->rchild);
    }
}

void preorder(BinTree *t) {
    if(t) {
        printf("%d",t->data);
        preorder(t->lchild);
        preorder(t->rchild);
    }
}

void postorder(BinTree *t) {
    if(t) {
        postorder(t->lchild);
        postorder(t->rchild);
        printf("%d",t->data);
    }
}

int main() {
    BinTree *root;
    int choice;
    while(1) {
        puts("1.Create \n 2.Inorder \n 3.preorder \n 4.postorder \n 5.exit");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice) {
            case 1:
                root=create();
                break;
            case 2:
                printf("Inorder traversal\n");
                inorder(root);
                break;
            case 3:
                printf("Preorder traversal\n");
                preorder(root);
                break;
            case 4:
                printf("Post order traversal\n");
                postorder(root);
                break;
            case 5:
                exit(0);
        }
    }
}
