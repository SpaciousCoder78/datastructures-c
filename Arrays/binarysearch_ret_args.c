//binary search with return with argument
#include <stdio.h>

int binarysearch(int, int, int[]);

int main() {
    int a[30], n, i, key, flag;
    puts("Enter the size of array: ");
    scanf("%d", &n);
    puts("Enter elements into array with ascending order: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("Enter the element to search: ");
    scanf("%d", &key);
    flag = binarysearch(n, key, a);
    if(flag != -1){
        printf("Key is found at %d\n", flag+1);
    }
    else{
        printf("Key element not found in array\n");
    }
}

int binarysearch(int n, int key, int a[30]){
    int low = 0, high = n-1, mid;
    while(low <= high){
        mid = (low + high) / 2;
        if(key == a[mid]){
            return mid;
        }
        else if(key < a[mid]){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return -1;
}
