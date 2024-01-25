//sorting array in ascending order
#include <stdio.h>

void swap(int *xp,int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void readArray(int n,int arr[30]){
    puts("Enter array elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
}

void displayNormalArr(int n, int arr[30]){
    puts("The array you entered is: \n");
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
    }
    puts("\n");
}

void arrayAscending(int n,int arr[30]){
    int i,j,min;
    for(i=0;i<n-1;i++){
        min=i;
        for(j=i+1;j<n;j++){
            if(arr[j]<arr[min])
            min=j;
        }
        swap(&arr[min], &arr[i]);
    }
}

void displayAscending(int n, int arr[30]){
    puts("The sorted array is");
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
    }
}



int main(){
    int n,arr[30];
    puts("Enter the number of elements in array");
    scanf("%d",&n);
    readArray(n,arr);
    displayNormalArr(n,arr);
    arrayAscending(n,arr);
    displayAscending(n,arr);

}
