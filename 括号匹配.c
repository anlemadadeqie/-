#include <stdio.h>
#include <string.h>
int main()
{
	int n,x,i,len;
	char a[1000],b[1000];
	scanf("%d",&n);
	while(n--)
	{
		x=1;
		scanf("%s",a);
		len=strlen(a);
		b[1]=a[0];
		x=2;
		for(i=1;i<len;)
		{
			b[x++]=a[i++];
			while(x>1 && (b[x-2]-b[x-1]==-1 || b[x-2]-b[x-1]==-2))
			{
				x=x-2;
			}
		}
		if(x==1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
