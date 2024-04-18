//circular linked list with head node
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *link;
};

void createNode(struct Node** head,int data){
struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
struct Node *temp=*head;

newNode->data=data;
newNode->link=*head;

if(*head!=NULL){
    while(temp->link!=*head)
        temp=temp->link;
    temp->link=newNode;
}
else
    newNode->link=newNode;

*head=newNode;
}

void printList(struct Node *head){
    struct Node *temp=head;
    if(head!=NULL){
        do{
            printf("%d ",temp->data);
            temp=temp->link;
        }while(temp!=head);
    }
    printf("\n");
}

int main(){
    struct Node *head = NULL;

    createNode(&head,10);
    createNode(&head,20);
    createNode(&head,30);

    printf("Circular linked list is: ");
    printList(head);
}
