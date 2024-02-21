#include<stdio.h>
#include <stdlib.h>
int main(){
    int *parr,m,n,i;
    printf("Enter no of elements in array: ");
    scanf("%d",&n);
    parr=(int*)malloc(n*sizeof(int));

    printf("Enter the new no of elements in array: ");
    scanf("%d",&m);


    printf("Enter the array elements: \n");
    for(i=0;i<m;i++){
        scanf("%d",parr+i);
    }
    printf("The entered array elements are: ");
    for(i=0;i<m;i++){
        printf("%d ",*(parr+i));
    }
    free(parr);


}
