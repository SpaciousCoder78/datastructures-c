//Program for linear search
#include <stdio.h>

int main(){
  int n,num[30],i,key;
  printf("Enter size of array");
  scanf("%d",&n);
  printf("Enter array elements: ");
  for (i=0;i<n;i++){
      scanf("%d",&num[i]);
  }
  printf("Enter key element: ");
  scanf("%d",&key);
  for(i=0;i<n;i++){
      if (num[i]==key){
          printf("Key %d is found at %d position",key,i);
      }
      if(i==n){
          printf("Key not found");
      }
  }
}
