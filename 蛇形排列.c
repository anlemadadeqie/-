#include<stdio.h>
#include<string.h>

#define MAXN 100

int a[MAXN][MAXN];

int main()
{
    int n,x = 0,y ,tot = 0, i = 0;
    printf("please input:\n");
    scanf("%d",&n);
    y = n-1;
    tot = 1;
    a[x][y] = 1;
    while(tot < n*n)
    {
        while(x+1 < n-i)
		a[++x][y] = ++tot;
        while(y-1 >= 0+i)
		a[x][--y] = ++tot;
        while(x-1 >= 0+i)
		a[--x][y] = ++tot;
		i++;
        while(y+1 < n-i)
		a[x][++y] = ++tot;
    }
    for(x = 0; x < n; x++)
    {
        for(y = 0; y < n; y++)
	{
		printf("%3d",a[x][y]);
        }
	printf("\n");
    }
    return 0;
}
