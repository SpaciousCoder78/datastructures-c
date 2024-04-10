//circular doubly linked list using head
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};

void createNode(struct Node** head, int newData){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=newData;

    if(*head==NULL){
        newNode->next=newNode;
        newNode->prev=newNode;
        *head=newNode;
        return;
    }

    struct Node* last=(*head)->prev;

    newNode->next=*head;
    (*head)->prev=newNode;
    newNode->prev=last;
    last->next=newNode;
}

void printList(struct Node* node){
    struct Node* temp = node;
    do{
        printf("%d ",temp->data);
        temp=temp->next;
    }while(temp!=node);
    printf("\n");
}

int main(){
    struct Node* head = NULL;

    createNode(&head,10);
    createNode(&head,20);
    createNode(&head,30);

    printf("Circular doubly linked list is: ");
    printList(head);
    
}
