//shell short
#include <stdio.h>

int shell(int a[],int n) {
    int inter,i,temp,j;
    for(inter=n/2;inter>0;inter/=2) {
        for(i=inter;i<n;i++) {
            temp=a[i];
            for(j=i;j>=inter&&a[j-inter]>temp;j-=inter)
                a[j]=a[j-inter];
            a[j]=temp;
        }
    }
}

void arrayPrinter(int arr[],int n) {
    int i;
    for(i=0;i<n;i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[10],n,i;
    printf("Enter size: ");
    scanf("%d",&n);
    printf("Enter elements: ");
    for(i=0;i<n;i++) {
        scanf("%d",&arr[i]);
    }
    shell(arr,n);
    printf("Sorted array is: ");
    arrayPrinter(arr,n);
}
