//Program to create and display single linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* link;
};

int main(){
    struct node* first = NULL,*last,*temp;
    char ch='y';
    while(ch=='y'){
        temp=(struct node*)malloc(sizeof(struct node));
        printf("Enter value: ");
        scanf("%d",&temp->data);
        if(first==NULL){
            first=temp;
            last=temp;

        }
        else{
            last->link=temp;
            last=temp;
        }
        printf("Do you want new node: ");
        scanf(" %c",&ch);
    }
    last->link=NULL;
    printf("Linked List is: ");
    temp=first;
    while(temp!=NULL){
        printf("%d,",temp->data);
        temp=temp->link;
    }
    free(temp);
}
