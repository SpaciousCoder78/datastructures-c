#include <stdio.h>

void readArray(int n,int arr[30]){
    for(int i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }
}

void display(int n,int arr[30]){
    for(int i = 0;i<n;i++){
        printf("%d",arr[i]);
    }
}

void sum(int n,int arr[30]){
    int sum=-0;
    for(int i =0;i<n;i++ ){
        sum = sum + arr[i];
    }
    printf("%d",sum);
}

int main(){
    int n,arr[30];
    puts("Enter no of elements");
    scanf("%d",&n);
    puts("Enter array elements: ");
    readArray(n,arr);
    puts("array elements are:\n");
    display(n,arr);
    puts("Sum is: ");
    sum(n,arr);
}
