//queue in c
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define SIZE 5
void enqueue();
void dequeue();
void display();

int items[SIZE],front=-1,rear=-1;
int choice;

int main(){
    while(true) {
        puts("Queue Operations");
        puts("1.Enqueue");
        puts("2.Dequeue");
        puts("3.Display Queue");
        puts("4.Exit");
        puts("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
        }
    }
}
void enqueue(){
    if(rear==SIZE-1)
        printf("\nQueue is Full!!");
    else{
        printf("Enter a value: ");
        int value;
        scanf("%d",&value);
        if(front==-1)
            front=0;
        rear++;
        items[rear]=value;
        printf("Inserted element\n");
    }
}

void dequeue(){
    if(front==-1)
        printf("Queue is empty\n");
    else{
        printf("Deleted: %d\n",items[front]);
        front++;
        if(front>rear)
            front=rear=-1;
    }
}
void display(){
    if(rear==-1)
        printf("Queue is empty\n");
    else{
        int i;
        printf("Queue elements are:\n");
        for(i=front;i<=rear;i++){
            printf("%d ",items[i]);
        }
    }
    printf("\n");
}
