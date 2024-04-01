//program to create a single linked list using headnode
#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node * link;
};
struct Node *createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode==NULL){
        printf("Memory allocation failed");
        exit(1);
    }
    newNode->data=data;
    newNode->link=NULL;
    return newNode;
}
void insertNode(struct Node* header,int data){
    struct Node* newNode = createNode(data);
    struct Node* temp = header;
    while(temp->link!=NULL){
        temp=temp->link;
    }
    temp->link=newNode;
}
void search(struct Node* header){
    int key;
    struct Node* temp=header->link;
    printf("Enter node value to be searched: ");
    scanf("%d",&key);
    while(temp!=NULL){
        printf("%d->",temp->data);
        if(temp->data==key){
            printf("Element found");
            break;
        }
        temp=temp->link;
    }
    if(temp==NULL){
        printf("Node not found");
    }
}
void displayList(struct Node* header){
    struct Node* temp=header->link;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->link;
    }
    printf("Null\n");
}
int main(){
    struct Node* temp,*header;
    int choice,value;
    header= createNode(-1);
    while(1){
        printf("1.Insert node 2.display 3.search\n");
        printf("Enter your choice:\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter value: ");
                scanf("%d",&value);
                insertNode(header,value);
                break;
            case 2:
                printf("Linked List: \n");
                displayList(header);
                break;
            case 3:
                search(header);
                break;
            case 4:
                exit(0);
        }
    }
    while(header!=NULL){
        temp=header;
        header=header->link;
        free(temp);
    }
}
