#include <stdio.h>
#include <string.h>
void main()
{
	int n;
	int length=0;
	char ch[256];
	int i,m,k,count;
	scanf("%s",ch);
	n=strlen(ch);
	for(i=1; i<n; i++)
	{
		count=0;
		if(ch[i]!=ch[i+1])
		{
			count++;
			m=k=i;
			while(m>=0 && k<n)
			{
				if(ch[m-1] == ch[k+1])
				{
					m--;
					k++;
					count=count+2;
				}
				else
					break;
			}
			if(length < count)
				length=count;
		}
		else
		{
			m=i-1;
			k=i+1+1;
			count=2;
			while(m>=0 && k<n)
			{
				if(ch[m] == ch[k])
				{
					m--;
					k++;
					count=count+2;
				}
				else
					break;
			}
			if(length < count)
				length=count;
		}
	}
	if(length != 0)
	{
		printf("最大的回文子串的长度为:%d\n",length);
	}
	else
	{
		printf("不存在回文子串!\n");
	}
}
