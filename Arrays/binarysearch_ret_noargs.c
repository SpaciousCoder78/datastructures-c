#include <stdio.h>

int binarysearch();
int main() {
    int flag;

    flag = binarysearch();
    if(flag != -1){
        printf("Key is found at %d\n",flag+1);
    }
    else{
        printf("Key element not found in array\n");
    }
}
int binarysearch(){
    int mid,a[10],n,i,low,high,key;
    puts("Enter the size of array: ");
    scanf("%d",&n);
    puts("Enter elements into array with ascending order: ");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter the element to search: ");
    scanf("%d",&key);

    low=0,high=n-1;
    while(low<=high) {
        mid = (low + high) / 2;
        if (key == a[mid]) {
            return mid;
        } else if (key < a[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}
