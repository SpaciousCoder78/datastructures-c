// Circular Queue implementation in C

#include <stdio.h>
#include<stdbool.h>
#include<stdlib.h>

#define SIZE 5

int items[SIZE];
int front = -1, rear = -1;


int isFull() {
    if ((front == rear + 1) || (front == 0 && rear == SIZE - 1)) return 1;
    return 0;
}


int isEmpty() {
    if (front == -1) return 1;
    return 0;
}


void enqueue() {
    if (isFull())
        printf("\n Queue is full!! \n");
    else {
        int element;
        printf("Enter element: ");
        scanf("%d",&element);
        if (front == -1) front = 0;
        rear = (rear + 1) % SIZE;
        items[rear] = element;
        printf("\n Inserted -> %d", element);
    }
}

// Removing an element
int dequeue() {
    int element;
    if (isEmpty()) {
        printf("\n Queue is empty !! \n");
        return (-1);
    } else {
        element = items[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        }
            // Q has only one element, so we reset the
            // queue after dequeing it. ?
        else {
            front = (front + 1) % SIZE;
        }
        printf("\n Deleted element -> %d \n", element);
        return (element);
    }
}

// Display the queue
void display() {
    int i;
    if (isEmpty())
        printf(" \n Empty Queue\n");
    else {
        printf("\n Front -> %d ", front);
        printf("\n Items -> ");
        for (i = front; i != rear; i = (i + 1) % SIZE) {
            printf("%d ", items[i]);
        }
        printf("%d ", items[i]);
        printf("\n Rear -> %d \n", rear);
    }
}

int main() {
    int choice;
    while(true) {
        puts("Circular Queue Operations: ");
        puts("1.Enqueue");
        puts("2.Dequeue");
        puts("3.Display");
        puts("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: exit(0);

        }
    }

}
