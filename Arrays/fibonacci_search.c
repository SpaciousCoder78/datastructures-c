#include <stdio.h>
int a[20], n, f[20], k, s;
int min(int x, int y)
{
	if (x<y)
		return x;
	else 
		return y;
}
void read()
{
	printf("Enter the value n");
	scanf("%d", &n);
	printf("enter %d values", n);
	for(int i=0; i<n; i++)
	{
		scanf("%d", &a[i]);
	}
	printf("enter target element");
	scanf("%d", &s);
}
int fibonacciseries()
{   k=1;
	f[0]=0;
	f[1]=1;
	while (f[k]<n)
	{
		k++; 
		f[k] = f[k-1] + f[k-2];
	}
}
int fibonacciSearch()
{
	int offset=-1;
	while(1)
	{
		if (f[k-2]==0) break;     
		int i = min(offset + f[k-2], n-1);
		if (s == a[i])
			return i; 
		else if (s > a[i])
		{
			k = k-1;
			offset = i;
		}
		else k = k-2;  
	}
	return -1;
}

int main(void)
{
	read();
	fibonacciseries();
	int ind = fibonacciSearch();
	if(ind>=0)
		printf("Found at index: %d",ind);
	else
		printf("%d isn't present in the array",s);
	return 0;
}
