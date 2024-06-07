//array element deletion
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

void deleteEle(int n, int arr[30]){
    int pos, i;
    puts("\nEnter the position of the element you want to delete: ");
    scanf("%d", &pos);


    for(i=pos-1; i<n-1; i++){
        arr[i] = arr[i+1];
    }

    n--;

    puts("The new array is: ");
    for(i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
}

int main(){
    int n,arr[30];
    puts("Enter the size of array");
    scanf("%d",&n);
    readArray(n,arr);
    dispOrgArr(n,arr);
    deleteEle(n,arr);
}
