#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

#define N 100
#define M 2*N-1

typedef struct
{
	char	data;
	int	weight;
	int	parent, lchild, rchild;
}HTNode,Hfmtree[M+1];

typedef struct		//从文件读取统计权值
{
	char	data;
	int	weight;
}sjgk[N+1];

typedef struct		//编码时存储字符和编码
{
	char	data;		//存储字符
	char	zfbm[N+1];	//存储编码
}Hfmcode,Hfmcodetree[N+1];
					

/*选出双亲为0且权值最小的两个结点*/
void Telect(Hfmtree ht, int c, int *s1, int *s2)
{
        int min1;		//表示最小
	int min2;		//表示次小
	int i,j;
	for(i = 1; i <= c; i++)
	{
		if(ht[i].parent == 0)
		{
		
			min1 = ht[i].weight;        //最小
       			*s1 = i;
		}
		
	}
	for(i = 1; i<= c; i++)
	{
		if(ht[i].parent == 0 && i != *s1)
		{
			min2 = ht[i].weight;		//次小
			*s2 = i;
		}
	}
			
	for(j = 1; j <= c; j++)
        {
   		if(ht[j].weight < min1 && ht[j].parent == 0)
                {
			min2 = min1;
                       	*s2 = *s1;
                        min1 = ht[j].weight;
                        *s1 = j;
                }
                
         }
	for(j = 1; j <= c; j++)
	{
		if(ht[j].weight < min2 && ht[j].weight != min1 && ht[j].parent == 0)
		{
			min2 = ht[j].weight;
			*s2 = j;
		}
	}
}	
        		


/*创建哈夫曼树*/
void Crthuffmantree(Hfmtree ht, sjgk sj,  int n)
{
	int i,j;
	int a, b;
	int m = 2*n-1;
	for(i = 1; i <= n; i++)
	{
		ht[i].data = sj[i].data;
		ht[i].weight = sj[i].weight;
		ht[i].parent = 0;
		ht[i].lchild = 0;
		ht[i].rchild = 0;
	}
	for(i = n+1; i <= m; i++)
	{
		ht[i].data = 0;
		ht[i].weight = 0;
		ht[i].parent = 0;
		ht[i].lchild = 0;
		ht[i].rchild = 0;
	}
	for(i = n+1; i <= m; i++)
	{
		Telect(ht,i-1,&a,&b);
		ht[i].weight = ht[a].weight + ht[b].weight;
		ht[i].lchild = a;
		ht[i].rchild = b;
		ht[a].parent = i;
		ht[b].parent = i;

	}
}

	
/*哈夫曼编码*/
void CrthuffmanCode1(Hfmtree ht, Hfmcodetree hc, int n)
{
	char	*cd, ch;
	char	filename1[50], filename2[50];
	int	start, c, p, i;
	FILE 	*fp1, *fp2;
	printf("请输入要存储编码的文件名:\n");
	gets(filename1);
	fp1 = fopen(filename1, "wt");
	printf("请输入要进行编译的文件名:\n");
	gets(filename2);
	fp2 = fopen(filename2, "rt");
	if(fp1 == NULL || fp2 == NULL)
	{
		printf("打开文件失败!\n");
		exit(1);
	}
	cd = (char *)malloc(n * sizeof(char));			//临时编码数组
	cd[n-1] = '\0';						//从后向前逐位求编码,首先放编码结束符
	for(i = 1; i <= n; i++)					//从每个叶子开始,求相应的哈夫曼编码
	{
		start = n-1;
		c = i;						//C为当前结点
		p = ht[i].parent;				//P为其双亲
		while(p != 0)
		{
			start--;
			if(ht[p].lchild == c)
				cd[start] = '0';
			else
				cd[start] = '1';
			c = p;
			p = ht[p].parent;
		}
		strcpy(hc[i].zfbm, &cd[start]);			//复制存储编码
		hc[i].data = ht[i].data;
	}
	while((ch = fgetc(fp2)) != EOF)
	{
		for(i = 1; i <= n; i++)
		{
			if(ch == hc[i].data)
			{
				fputs(hc[i].zfbm, fp1);
				break;
			}
		}
	}
	free(cd);
	fclose(fp1);
	fclose(fp2);
	printf("所得哈夫曼编码为:\n");
	for(i = 1; i<= n; i++)
	{
		printf("%c  的哈夫曼编码为: %s\n",hc[i].data,hc[i].zfbm);
	}
	getchar();
}


/*哈夫曼译码*/
void Crthuffmancode2(Hfmtree ht, Hfmcodetree hc, int n)
{
	int m, i;
	FILE *fp1, *fp2;
	char	filename1[50];
	char	filename2[50];
	char	ch;
	m = 2*n-1;
	printf("请输入存储编码的文件名:\n");
	gets(filename1);
	printf("请输入存储译码结果的文件名:\n");
	gets(filename2);
	fp1 = fopen(filename1,"rt");
	fp2 = fopen(filename2,"wt");
	if(fp1 == NULL  || fp2 == NULL)
	{
		printf("打开文件失败!\n");
		exit(1);
	}
	while((ch = fgetc(fp1)) != EOF)
	{
		if(ch == '0')
		{
			if(ht[m].lchild > 0)
			{
				m = ht[m].lchild;
			}
			if(ht[m].lchild == 0)
			{
				fputc(ht[m].data, fp2);
				printf("%c",ht[m].data);
				m = 2*n-1;
			}
		}
		else
		{
			if(ht[m].rchild > 0)
			{
				m = ht[m].rchild;
			}
			if(ht[m].rchild == 0)
			{
				fputc(ht[m].data,fp2);
				printf("%c",ht[m].data);
				m= 2*n-1;
			}
		}
	}
	fclose(fp1);
	fclose(fp2);
	getchar();
}
		

/*主页目录*/
void menu(sjgk sj, int count)
{
	int number;
	 Hfmtree ht; 
         Hfmcodetree hc;
	do
	{
		system("clear");
		printf("----------哈夫曼编译码器----------\n");
		printf("	  1.创建哈夫曼树	  \n");
		printf("	  2.编码		  \n");
		printf("	  3.译码		  \n");
		printf("	  4.退出		  \n");
		printf("----------------------------------\n");
		printf("请输入你要选择的序号:\n");
		setbuf(stdin,NULL);
		scanf("%d",&number);
		setbuf(stdin,NULL);
		switch(number)
		{
			case 1:Crthuffmantree(ht, sj,  count);		break;
			case 2:CrthuffmanCode1(ht, hc, count);		break;
			case 3:Crthuffmancode2(ht, hc, count);		break;
		}
	 }while(number == 1 || number == 2 || number == 3);

}

void main(int argc, char *argv[])
{
	char	buf[50], ch;
	FILE	*fp;
	int 	w[N+1];
	int	i, number,count = 0;
	sjgk 	sj;
	if(argc != 2)
	{
		printf("请输入要编译的文件名:\n");
		exit(1);
	}
	strcpy(buf, argv[1]);
	fp = fopen(buf,"rt");
	if(fp == NULL)
	{
		printf("打开文件失败!\n");
		exit(1);
	}
	for(i = 0; i <= N; i++)
	{
		w[i] = 0;
	}
	while((ch = fgetc(fp)) != EOF)	
	{
		w[ch-32]++;
	}
	fclose(fp);
	for(i = 0; i <= N; i++)
	{	
		if(w[i] != 0)
		{
			count++;
			sj[count].data = i+32;
			sj[count].weight = w[i];
		}
	}
	menu(sj,count);

}
	 	
