//radix sort
#include <stdio.h>
int getMax(int a[],int n){
    int max = a[0];
    for(int i=1;i<n;i++){
        if(a[i]>max)
            max=a[i];
    }
    return max;
}
void countSort(int a[],int n,int place){
    int out[n+1],i;
    int count[10]={0};
    for(i=0;i<n;i++)
        count[(a[i]/place)%10]++;
    for(i=1;i<10;i++)
        count[i]+=count[i-1];
    for(i=n-1;i>=0;i--){
        out[count[(a[i]/place)%10]-1]=a[i];
        count[(a[i]/place)%10]--;
    }
    for(i=0;i<n;i++)
        a[i]=out[i];
}
void radixSort(int a[],int n){
    int max = getMax(a,n);
    for(int place = 1; max/place>0;place*=10)
        countSort(a,n,place);
}
void printArray(int a[],int n){
    int i;
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
}
int main() {
    int i,a[30],n;
    printf("Enter no of elements: ");
    scanf("%d",&n);
    printf("Enter elements: ");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    radixSort(a,n);
    printf("Sorted Array is: ");
    printArray(a,n);
}
