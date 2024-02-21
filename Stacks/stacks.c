//stack operations in c

#include <stdio.h>
#include<stdlib.h>
#define SIZE 5
int top = -1;
int arr[SIZE];
void push();
void pop();
void display();

int main() {

    int choice;
    int ch = 1;
    while (ch == 1) {
        puts("Stack operations");
        puts("1.Push");
        puts("2.Pop");
        puts("3.Display");
        puts("4.Exit");
        puts("Enter your choice: ");
        scanf("%d", &choice);

    if (choice == 1) {
        push();
    } else if (choice == 2) {
        pop();
    } else if (choice == 3) {
        display();
    } else {
        exit(0);
    }

    }
}

void push(){
    int x;
    if(top==SIZE-1){
        printf("Overflow");
    }
    else{
        printf("Enter element to be added to stack: ");
        scanf("%d",&x);
        top=top+1;
        arr[top]=x;
    }
}

void pop(){
    if(top==-1){
        printf("Underflow");
    }
    else{
        printf("Popped element: %d",arr[top]);
        top=top-1;
    }
}

void display(){
    if(top==-1){
        printf("Underflow");

    }
    else{
        printf("Elements in the stack: \n");
        for(int i=top;i>=0;i--){
            printf("%d",arr[i]);
        }
    }
