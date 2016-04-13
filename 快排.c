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

void main()
{
	int n;
	scanf("%d",&n);
	int a[n],i;
	printf("please input:");
	for(i = 0; i < n; i++)
	{
		scanf("%d",&a[i]);
	}
	quicksort(a,0,n-1);
	for(i = 0; i < n; i++)
	{
		printf("%d",a[i]);
	}
}
