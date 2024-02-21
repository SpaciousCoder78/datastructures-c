#include<stdio.h>
#include <stdlib.h>
int main(){
    int *parr,*newparr,m,n,i;
    printf("Enter no of elements in array: ");
    scanf("%d",&n);
    parr=(int*)calloc(n,sizeof(int));
    if(parr==NULL){
        printf("Memory allocation failed");
        exit(0);
    }
    printf("Enter the new no of elements in array: ");
    scanf("%d",&m);
    newparr=(int*)realloc(parr,m*sizeof(int));

    printf("Enter the array elements: \n");
    for(i=0;i<m;i++){
        scanf("%d",newparr+i);
    }
    printf("The entered array elements are: ");
    for(i=0;i<m;i++){
        printf("%d ",*(newparr+i));
    }
    free(parr);
    free(newparr);

}
