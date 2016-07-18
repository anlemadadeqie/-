#include <stdio.h>
#define max 100
int N;
int q[max][max];
int w[max][max];

int Max_Sum(int r, int j)
{	
	if(r == N)
		return q[r][j];
	if(w[r+1][j] == -1)
	{
		w[r+1][j] = Max_Sum(r+1,j);
	}
	if(w[r+1][j+1] == -1)
	{
		w[r+1][j+1] = Max_Sum(r+1,j+1);
	}
	if(w[r+1][j] > w[r+1][j+1])
		return q[r][j]+w[r+1][j];
	else
		return q[r][j]+w[r+1][j+1];
}


int main()
{	
	int i, j;
	scanf("%d",&N);
	memset(w,-1,sizeof(w));
	for(i = 1; i < N+1; i++)
	{
		for(j = 1; j <= i; j++)
		{
			scanf("%d",&q[i][j]);
		}
	}
	printf("%d",Max_Sum(1,1));
	return 0;
}	
