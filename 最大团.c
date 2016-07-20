/*************************************************************************
	> File Name: 最大团1.c
	> Author:jiafei 
	> Mail:hjh@xiyoulinux.org 
	> Created Time: 2016年06月19日 星期日 23时39分33秒
 ************************************************************************/

#include<stdio.h>

#define N 100

int a[N][N],n,x[N],bestx[N];
int cn=0,bestn=0;

void backtrack(int i){
    if(i > n){
        for(j = 0; j < n; j++){
            bestx[j] = x[j];
        }
        bestn = cn;
        return;
    }
    
    int ok=1;
    for(j = 0; j < i; j++){
        if(!a[i][j] && x[j] == 1){
            ok = 0;
            break;
        }
    }

    if(ok == 1){
        x[i] = 1;
        cn++;
        func(i+1);
        x[i] = 0;
        cn--;
    }
    
    
        if(cn + n-i > bestn){
            x[i] = 0;
            func(i+1);
        }

}

int main()
{
	int i,j;
	printf("请输入顶点个数:");
	scanf("%d",&n);
	printf("请输入顶点的关系矩阵");
	for(i = 1;i <= n;i++)
	{
		for(j = 1;j <= n;j++)
			scanf("%d",&a[i][j]);
	}
        for(i = 1;i <= n;i++)
	{
		x[i] = bestx[i] = 0;
	}
	backtrack(1);
	printf("最大团的结果\n");
	for(i=1;i<=n;i++)
	{
		printf("%d",bestx[i]);
	}
	printf("最大团里的顶点个数:\n");
	printf("%d\n",bestn);
}


