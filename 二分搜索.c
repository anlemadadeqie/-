#include <stdio.h>
int main()
{
	int n,i,m;
	printf("数组长度:");
	scanf("%d",&n);
	int a[n];
	for(i=0; i<n; i++)
	{
		scanf("%d",&a[i]);
	}
	printf("查找的数字:");
	scanf("%d",&m);
	int left = 0;
	int right = n-1;
	while(left <= right)
	{
		int middle =(left+right)/2;
		if(m == a[middle])
		{	printf("%d",middle);
			break;
		}
		 if(m > a[middle])
			left = middle+1;
		if(m < a[middle])
			right = middle-1;
	}
	return -1;
}
			
		
