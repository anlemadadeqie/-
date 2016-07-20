#include <stdio.h>

#define SIZE 100

/*对数组进行扫描进行自然分组*/
int fenzu(int a[], int b[], int n)
{
	int i;
	int num = 0;
	b[num++] = 0;
	for(i=1; i<n; i++)
	{
			if(a[i] >= a[i-1])
			continue;
		else
			b[num++] = i;
	}
	b[num++] = n;
	return num;
}


void ziranhebing(int fir, int end, int mid, int a[])    //end:the end of the second array
{
         int tempArr[SIZE];
         int i;
         int fir1 = fir;	//the start index of the first array
	 int fir2 = mid+1;	//the start index of the second array
 	
	//the start and end of two array
        for(i = fir;i <= end; i++){
          if(fir1 > mid)			//scan the first array
              tempArr[i] = a[fir2++];
         else if(fir2 > end)			//scan the second array
              tempArr[i] = a[fir1++];
         else if(a[fir1] > a[fir2])		//compare first of the the first array to first of the second array
             tempArr[i] = a[fir2++];
         else
             tempArr[i] = a[fir1++];
    }
     	for(i = fir;i <= end; i++)		//finishing ranked array
         a[i] = tempArr[i];
 }

void hebing(int a[], int b[], int n)
{
	int number = fenzu(a,b,n);
 	while(number != 2)
	{
		int i = 0;
		for(i = 0; i < number; i+=2)
		{

            		ziranhebing(b[i],b[i+2]-1,b[i+1]-1,a);
        		number = fenzu(a,b,n);
		}
	}
}


void main()
{
	int n,i;
	scanf("%d",&n);	
	int a[n];
	int b[n];
	for(i=0; i<n; i++)
	{
		scanf("%d",&a[i]);
	}
	hebing(a,b,n);
	for(i = 0; i<n; i++)
		printf("%d",a[i]);
}	
