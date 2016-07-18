#include <stdio.h>

void  quicksort(int a[], int left, int right){
        if(left < right){
                int key = a[left];
                int low = left;
                int high = right;
                while(low < high){
                        while(low < high && a[high] > key){
                                high--;
                        }
			a[low] = a[high];
                        while(low < high && a[low] < key){
                                low++;
                        }
                        a[high] = a[low];
                }
                a[low] = key;
                quicksort(a,left,low-1);
                quicksort(a,low+1,right);
        }
}


		


 int main(void)
{	
	//num:记录已安排的会场数
	//a[num]:记录该会场所安排的最后一次活动序列号
	int i,j,n,k,num;
	scanf("%d",&n);
 	int s[n+1],f[n+1],a[n+1];  
        for(i = 1; i <= n; i++)
	{
		scanf("%d%d",&s[i],&f[i]);
		a[i] = 0;
	} 
	quicksort(s,1,n); 
    	a[1] = 1;
	num = 1;  
    	for(i = 2; i<= n; i++)
	{  
        	for(j = 1;j <= num; j++)
		{  
            		if(s[i] >= f[a[j]])
			{
				a[j] = i;
				break;
			}  
        	}      
        	if(j > num)
		{
			num++;
			a[num] = i;
		}  
    	}      
    	for(k = 1; k <= num; k++)
		printf("%d ",a[k]); 
    printf("\n");  
    printf("%d\n",num);    
    return 0;  
}          
