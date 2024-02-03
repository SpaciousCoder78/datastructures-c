//array insertion
#include <stdio.h>

void readArray(int n,int arr[30]){
    int i;
    puts("Enter array elements: \n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
}

void dispOrgArr(int n, int arr[30]){
    int i;
    puts("The array you entered is: ");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}

void insertEle(int n,int arr[30]){
    int ele,pos,i;
    puts("\nEnter the number that you want to insert: ");
    scanf("%d",&ele);
    puts("Enter the position: ");
    scanf("%d",&pos);

    n++;

    for(i=n-1;i>=pos;i--){
        arr[i]=arr[i-1];
    }

    arr[pos-1] = ele;

    puts("The new array is: ");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}

int main(){
    int n,arr[30];
    puts("Enter the size of array");
    scanf("%d",&n);
    readArray(n,arr);
    dispOrgArr(n,arr);
    insertEle(n,arr);
}
