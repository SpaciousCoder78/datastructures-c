//factorial using recursion
#include<stdio.h>
#define SIZEA 5
#define SIZEB 5
int topa=-1;
int topb=10;


void pusha(int *stack)
{
    int ele;

    if(topa>=(SIZEA-1))
    {	printf("\n\nStack OverFlow");
        return;
    }
    else
    {	printf("\n\nEnter The element To Push");
        scanf("%d",&ele);
        topa++;
        stack[topa]=ele;
    }}

void pushb(int *stack)
{
    int ele;

    if(topb<=(SIZEB))
    {
        printf("\n\nStack OverFlow");
        return;
    }
    else
    {
        printf("\n\nEnter The element To Push");
        scanf("%d",&ele);
        topa--;
        stack[topa]=ele;
    }
}

void popa(int *stack)
{	if(topa==-1)
    {
        printf("Stack A is Underflow");
        return;
    }
    else
    {
        printf("Item Popped from stack A is:%d\n",stack[topa]);

        topa--;
    }
}

void popb(int *stack)
{	if(topb==10)
    {printf("Stack B is Underflow");
        return;
    }
    else
    { printf("Item Popped from stack B is:%d\n",stack[topb]);
        topb++;
    }}

void displaya(int *stack)
{
    int i;
    if(topa==-1)
    {
        printf("Stack A is Empty");
        return;
    }
    else
    { for(i=topa;i>=0;i--)
        {printf("%d,",stack[i]);}
        printf("\n");
    }}

void displayb(int *stack)
{
    int i;
    if(topb==10)
    {printf("Stack Y is Empty");
        return;}
    else
    {for(i=topb;i<=9;i++)
        {
            printf("%d,",stack[i]);
        }
        printf("\n");
    }	}
/*End of display_y*/
/*Begin of main*/
int main()
{	int choice;
    char ch;
    int stack[SIZEA+SIZEB];
    do
    {   printf("1.Push A\n2.Push B\n");
        printf("3.Pop A\n4.Pop B\n");
        printf("5.Display A\n6.Display B\n");
        printf("7.Exit");
        printf("\nEnter Choice");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: pusha(stack);break;
            case 2: pushb(stack);break;

            case 3: popa(stack);break;
            case 4: popb(stack);break;

            case 5: displaya(stack);break;
            case 6: displayb(stack);break;
            case 7: break;
            default: printf("Wrong Option...");
        }
    }while(choice!=7);
}
