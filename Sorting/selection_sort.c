//selection short
#include<stdio.h>

int main() {
    int arr[10],n,i,j,pos,swap;

    printf("Enter no of elements: ");
    scanf("%d",&n);
    printf("Enter %d elements: ",n);
    for(i=0;i<n;i++) {
        scanf("%d",&arr[i]);
    }
    for(i=0;i<(n-1);i++) {
        pos=i;
        for(j=i+1;j<n;j++) {
            if(arr[pos]>arr[j])
                pos=j;
        }
        if(pos!=i) {
            swap=arr[i];
            arr[i]=arr[pos];
            arr[pos]=swap;
        }
    }
    printf("Sorted List is: ");
    for(i=0;i<n;i++) {
        printf("%d ",arr[i]);
    }
}
