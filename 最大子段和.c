#include<stdio.h>
int maxsum(int n, int a[], int *besti, int *bestj)
{
	int i, j,k;
	int sum =0;
	for(i = 0; i<n; i++)
		for(j=i; i<n; j++)
		{
			int sum1 = 0;
			for(k=i; k<=j; k++)
			{
				sum1 = sum1+a[k];
			}
			if(sum1 > sum)
			{
				sum = sum1;
				*besti = i;
				*bestj = j;
			}
		}
	return sum;
}



int main()
{
	int n;
	int i,sum;
	int besti, bestj;
	scanf("%d",&n);
	int a[n];
	for(i=0; i<n; i++)
	{
		scanf("%d",&a[i]);
	}
	sum = maxsum(n,a,&besti,&bestj);
	printf("%d",sum);
	return 0;
}
