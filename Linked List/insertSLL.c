//program to insert elements into single linked list
#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct node *next;
}node;
node *head;

void beginsert();
void lastinsert();
void randominsert();
void display();

int main(){
    int choice = 0;
    while(1){
        puts("Menu");
        puts("1.Insert in Beginning");
        puts("2.Insert at last");
        puts("3.Insert anywhere");
        puts("4.Display");
        puts("5.Exit");
        puts("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                beginsert();
                break;
            case 2:
                lastinsert();
                break;
            case 3:
                randominsert();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
                break;

        }
    }
}

void beginsert(){
    node *ptr;
    int newdata;
    ptr=(node*)malloc(sizeof(node));
    if(ptr==NULL){
        puts("Overflow");
    }
    else{
        printf("Enter value: ");
        scanf("%d",&newdata);
        ptr->data=newdata;
        ptr->next=head;
        head=ptr;
        puts("Node inserted at beginning");
    }
}

void lastinsert(){
    node *ptr,*temp;
    int newdata;
    ptr=(node*)malloc(sizeof(node));
    if(ptr==NULL)
        puts("Overflow");
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=ptr;
    ptr->next=NULL;
    puts("Node inserted at last");
}

void randominsert(){
    int i,key,newdata;
    node *ptr,*temp;
    ptr=(node*)malloc(sizeof(node));
    if(ptr==NULL){
        puts("Overflow");
    }
    else{
        puts("Enter element value");
        scanf("%d",&newdata);
        ptr->data=newdata;
        puts("Enter location after which you want to insert: ");
        scanf("%d",&key);
        temp=head;
        for(i=0;i<key;i++){
            temp=temp->next;
            if(temp==NULL){
                puts("Cannot insert");
                return;
            }
        }
        ptr->next=temp->next;
        temp->next=ptr;
        puts("Node inserted");
    }
}

void display(){
    node *ptr;
    ptr=head;
    if(ptr==NULL){
        puts("Underflow");
    }
    else{
        puts("Values: ");
        while(ptr!=NULL){
            printf("%d\n",ptr->data);
            ptr= (node *) ptr->next;
        }
    }
}
