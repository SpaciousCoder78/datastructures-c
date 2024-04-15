#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}node;

node *top,*top1,*temp;

int peek();
void push(int newdata);
void pop();
void display();
void create();

int count = 0;

int main(){
    puts("Stack operations using linked list");
    puts("1.Push");
    puts("2.Pop");
    puts("3.Peek");
    puts("4.Display");
    puts("5.Exit");
    puts("Enter your choice: ");
    int choice;
    create();
    while(1){
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter data to push: ");
                int data;
                scanf("%d",&data);
                push(data);
                break;
            case 2:
                pop();
                break;
            case 3:
                if(top==NULL)
                    printf("No element found\n");
                else
                    printf("Top element is %d\n",peek());
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
                break;
            default:
                puts("Invalid input");
                break;
        }
    }

}

void create(){
    top = NULL;
}

void push(int newdata){
    if(top==NULL){
        top = (node*)malloc(1*sizeof(node));
        top->next=NULL;
        top->data = newdata;
    }
    else{
        temp=(node*)malloc(1*sizeof(node));
        temp->next=top;
        temp->data = newdata;
        top=temp;
    }
    count++;
}

void display(){
    top1 = top;
    if(top1==NULL){
        puts("Stack is empty");
        return;
    }
    while(top1!=NULL){
        printf("%d ",top1->data);
        top1 = top1->next;
    }
    puts("");
}

void pop(){
    top1 = top;
    if(top1==NULL){
        puts("Underflow");
    }
    else {
        top1=top1->next;
        printf("Popped value: %d",top->data);
        free(top);
        count--;
    }
}

int peek(){
    return top->data;
}
