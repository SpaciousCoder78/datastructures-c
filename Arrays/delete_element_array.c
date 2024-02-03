//array element deletion
#include <stdio.h>

int *readArray(int n, int *arr){
    puts("Enter elements to be entered: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    return arr;
}

void displayOld(int n, int *arr){
    puts("The entered array is: \n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}

int findEle(int n,int key, int arr[]){
    int i;
    for(i=0;i<n;i++){
        if(arr[i]==key){
            return i;
        }
    }
    return -1;
}

int *deleteEle(int n,int key,int arr[]){
    int pos = findEle(n,key,arr);
    if(pos==-1){
        puts("Element not found\n");
    }
    int i;
    for(i=pos;i<n-1;i++){
        arr[i]=arr[i+1];
    }
    return arr;
}

int main(){
    int n,arr[30],*war,key,*newarr;
    puts("Enter the size of array: ");
    scanf("%d",&n);
    war = readArray(n,arr);
    displayOld(n,war);
    puts("Enter element to be deleted: ");
    scanf("%d",&key);
    newarr=deleteEle(n,key,war);
    puts("The new array is: \n");
    for(int i;i<n-1;i++){
        printf("%d ",newarr[i]);
    }


}
