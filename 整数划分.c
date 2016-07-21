#include <stdio.h>

int q(int n, int m)
{
	if((n<1) || (m<1))
		return 0;
	if((n == 1) || (m == 1))
		return 1;
	if(n < m)
		return q(n,n);
	if(n == m)
		return q(n,m-1)+1;
	return q(n,m-1)+q(n-m,m);
}
void main()
{	
	int n,m;
	printf("please input n:");
	scanf("%d",&n);
	printf("please input m:");
	scanf("%d",&m);
	int num;
	num = q(n,m);
	printf("%d",num);
}
	
