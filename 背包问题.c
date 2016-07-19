/*************************************************************************
	> File Name: 背包问题.c
	> Author:jiafei 
	> Mail:hjh@xiyoulinux.org 
	> Created Time: 2016年05月30日 星期一 21时42分07秒
 ************************************************************************/

#include<stdio.h>

int n;              //物品数量
double c;           //背包容量
double v[100];      //各个物品的价值
double w[100];      //各个物品的重量
double cw = 0.0；   //当前背包重量
double cp = 0.0;    //当前背包中的物品价值
double bestp = 0.0; //当前最优价值
double perp[100];   //单位物品价值排序后
int order[100];     //物品编号
int put[100];       //设置是否装入


//按单位价值排序
void knapsack(){
    int i,j;
    int temporder  = 0;
    double temp = 0.0;
    for(i = 1; i <= n; i++){
        prep[i] = v[i] / w[i];
    }
    for(i = 1; i <= n-1; i++){
        for(j =i+ 1; j <=n; j++){
            if(perp[i] < perp[j]){
                temp = perp[i];
                perp[i] = perp[j];
                perp[j] = temp;

                temporder = order[i];
                order[i] = order[j];
                order[j] = temporder;
                temp = v[i];
                v[i] = v[j];
                v[j] = temp;
                
            }
        }
    }










int main(){
    int i;
    printf("请输入物品的数量和背包容量：");
    scanf("%d,%d",&n,&c);
    for(i=1; i<=n; i++){
    printf("请输入第%d个物品的重量:",i);
        scanf("%lf",&w[i]);
        printf("请输入该物品的价值:");
        scanf("%lf",&v[i]);
        order[i] = i;

}

