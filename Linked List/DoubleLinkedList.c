//doubly linked list with head

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;

};

void createNode(struct Node** head,int newData){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=newData;
    newNode->next=(*head);
    newNode->prev=NULL;

    if((*head)!=NULL)
        (*head)->prev=newNode;
    (*head)=newNode;
}
void printList(struct Node* node){
    while(node!=NULL){
        printf("%d ",node->data);
        node=node->next;
    }
    printf("\n");
}
int main(){
    struct Node* head=NULL;

    createNode(&head,10);
    createNode(&head,20);
    createNode(&head,30);

    printf("Doubly linked list is: ");
    printList(head);
}
