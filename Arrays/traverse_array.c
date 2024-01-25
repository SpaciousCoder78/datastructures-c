//program for traversing an array

#include <stdio.h>

void traversearray(int n,int arr[]){
    printf("Enter elements");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
}
void display(int n,int arr[30]){
    printf("Elements are: ")
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
    }
}

int main() {
    int n,arr[30];
    printf("Enter no of elements in array");
    scanf("%d",&n);
    traversearray(n, arr);
    display(n,arr);

}
