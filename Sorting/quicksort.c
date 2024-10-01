#include<stdio.h>

void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int partition(int arr[],int low, int high){
    int p = arr[low];
    int i = low;
    int j = high;

    while(i<j){
        while(arr[i]<=p&&i<=high-1){
            i++;
        }
        while(arr[j]>p&&j>=low+1){
            j--;
        }
        if(i<j){
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[low],&arr[j]);
    return j;
}

void quickSort(int arr[],int low,int high){
    if(low<high){
        int pivot = partition(arr,low,high);
        quickSort(arr,low,pivot-1);
        quickSort(arr,pivot+1,high);

    }
}

int main(){
    int arr[30],n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    printf("Enter the elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }   
    quickSort(arr,0,n-1);
    printf("Sorted array: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}