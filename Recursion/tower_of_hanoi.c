//tower of hanoi
#include <stdio.h>
void towerofhanoi(int,char,char,char);

int main(){
    int n;
    printf("Enter no of disks: ");
    scanf("%d",&n);
    towerofhanoi(n,'A','C','B');
}

void towerofhanoi(int n,char from,char to,char aux){
    if(n==1){
        printf("Move disk 1 from rod %c to rod %c\n",from,to);
        return;
    }
    towerofhanoi(n-1,from,aux,to);
    printf("Move disk %d from rod %c to rod %c\n",n,from,to);
    towerofhanoi(n-1,aux,to,from);
}
