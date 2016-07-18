#include <stdio.h>
#include <stdlib.h>

void martixChain(int c[],int n,int m[][100],int s[][100])
{
	int i,j,r,k;
	for(i=1;i<=n;i++)
	{
		m[i][i]=0;
		s[i][i]=0;
	}
	for(r=2;r<=n;r++)					
		for(i=1;i<=n-r+1;i++)			
		{
			j=i+r-1;						 
			m[i][j]=m[i+1][j]+c[i-1]*c[i]*c[j];   
			s[i][j]=i;							
			for(k=i+1;k<j;k++)
			{
				int t=m[i][k]+m[k+1][j]+c[i-1]*c[k]*c[j];	
				if(t<m[i][j])
				{
					m[i][j]=t;
					s[i][j]=k;
				}
			} 
		}
		printf("矩阵相乘的次数:%d\n",m[1][n]);
}

void TraceBook(int i,int j,int s[][100]) 
{
	if(i==j)
	{
		printf("A%d",i);
		return ;
}
	printf("(");
	TraceBook(i,s[i][j],s);
	printf(",");
	TraceBook(s[i][j]+1,j,s);
	printf(")");
}
int main(void)
{
	int a[100][100],b[100][100];
	int n,i;
	printf("矩阵个数：");
	scanf("%d",&n);
	int c[n+1];
	printf("每个矩阵的维数:"); 
	for(i=0;i<=n;i++)
		scanf("%d",&c[i]);
	martixChain(c,n,a,b);
	printf("矩阵相乘方式:");
	TraceBook(1,n,b); 
	return 0; 
}
