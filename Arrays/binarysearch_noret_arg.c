//binary search without return with argument
#include <stdio.h>

int binarysearch(int,int,int,int,int,int[],int);
int main() {


    int mid, a[30], n, i, low, high, key, flag = 0;
    puts("Enter the size of array: ");
    scanf("%d", &n);
    puts("Enter elements into array with ascending order: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("Enter the element to search: ");
    scanf("%d", &key);
    binarysearch(low,high,mid,n,key,a,flag);
}
    int binarysearch(int low,int high,int mid,int n,int key,int a[30],int flag){
    low=0,high=n-1;
    while(low<=high){
        mid=(low+high)/2;
        if(key==a[mid]){
            flag=1;
            break;
        }
        else if(key<a[mid]){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    if(flag==1){
        printf("Key is found at %d",mid+1);
    }
    else{
        printf("Key element not found in array\n");
    }
}
