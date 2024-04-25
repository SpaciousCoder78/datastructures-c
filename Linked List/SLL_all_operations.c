#include <stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}Node;

Node *head;

int insertBeg(){
    Node *temp;
    int newdata;
    temp=(Node*)malloc(sizeof(Node));
    if(temp==NULL){
        printf("Overdlow");
    }
    else{
        printf("enter data");
        scanf("%d",&newdata);
        temp->data=newdata;
        temp->next=head;
        head=temp;
        printf("Node inserted\n");
    }
}

int insertend(){
    Node *ptr,*temp;
    int newdata;
    ptr = (Node*)malloc(sizeof(Node));
    if(ptr==NULL){
        printf("Overflow\n");
    }
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=ptr;
    ptr->next=NULL;
    printf("Node inserted\n");

}

int insertanywhere(){
    int i,key,newdata;
    Node *ptr,*temp;
    ptr=(Node *)malloc(sizeof(Node));
    if(ptr==NULL){
        printf("Overflow");
    }
    else{
        printf("Enter data");
        scanf("%d",&newdata);
        ptr->data=newdata;
        printf("Enter location");
        scanf("%d",&key);
        temp=head;
        for(i=0;i<key;i++){
            temp=temp->next;
            if(temp==NULL){
                printf("Cant insert");
            }

        }
        ptr->next=temp->next;
        temp->next=ptr;
        printf("Node inserted");
    }
}

int display(){
    Node *ptr;
    ptr=head;
    if(ptr==NULL){
        printf("Nothing to print");
    }
    else{
        printf("List: ");
        while(ptr!=NULL){
            printf("%d",ptr->data);
        }
        ptr=ptr->next;
    }
}

int deletefirst(){
    Node *ptr;
    if(head==NULL){
        printf("list empty");
    }
    else{
        ptr=head;
        head=ptr->next;

    }
}

int deleteend(){
    Node *ptr,*ptr1;
    if(head==NULL){
        printf("Empty");
    }
    else if(head->next==NULL) {
        head = NULL;
        free(head);
        printf("only node of list deleted");
    }
    else{
        ptr=head;
        while(ptr->next!=NULL){
            ptr1=ptr;
            ptr=ptr->next;
        }
        ptr1->next=NULL;
        free(ptr);
    }
}
