#include <stdio.h>

void paixu(int b[],int n)
{
	int i,j,k,t;
  	for(i=1; i<=n; i++)
	{
		k=i;
		for(j=i+1; j<=n; j++)
		{
			if(b[j] < b[k])
			{
				k=j;
			}
		}
		if(k != i)
		{
			t=b[i];
			b[i]=b[k];
			b[k]=t;
		}
	}
}		

//c数组存储最长公共子序列的长度
//d数组记录c数组的值是由哪一个子问题的解得到的
void  LCSLength(int n, int a[], int b[], int c[][n], int d[][n])
{
	int i,j;
	for(i = 0; i <= n; i++)
		c[i][0] = 0;
	for(i = 1; i <= n;i++)
		c[0][i] = 0;
	for(j=1;   j<=n; j++)
		for(i=1; i<=n; i++)
		{
			if(a[i] == b[j])
			{
				c[j][i] = c[j-1][i-1]+1;
				d[j][i] = 1;
			}
			else if(c[j-1][i] >= c[j][i-1])
			{
				c[j][i] = c[j-1][i];
				d[j][i] = 2;
			}
			else
			{
				c[j][i] = c[j][i-1];
				d[j][i] = 3;
			}
		}
	printf("%d\n",c[n][n]);
}

int LCS(int i, int j,int a[],int n, int (*d)[n])
{
	if(i == 0 || j == 0)
		return 0;
	if(d[i][j] == 1)
	{
		LCS(i-1,j-1,a,n,d);
		printf("%d ",a[i]);
	}
	else if(d[i][j] == 2)
	{
		LCS(i-1,j,a,n,d);
	}
	else
	{
		LCS(i,j-1,a,n,d);
	}
}
print(int n,int c[][n]){
	int i,j;

	for(i = 1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{

			printf("%d ",c[i][j]);
	}
	printf("\n");
	}
}
		
void main()
{
	int n;
	scanf("%d",&n);
	int a[n+1],b[n+1];
	int c[n+1][n+1];
	int d[n+1][n+1];
	int i;
	for(i=1; i<=n; i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=1; i<=n; i++)
	{
		b[i]=a[i];
	}
	paixu(b,n);
//	print(a,n);
//	print(b,n);
	LCSLength(n,a,b,c,d);
//	print(n,c);
	LCS(n,n,b,n,d);
}
