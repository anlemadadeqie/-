#include <stdio.h>
#include <stdlib.h>
#define Max 100

typedef struct NodeType
{
	int id;
	struct NodeType *next;
}NodeType;

void CreatList(NodeType **, int);		// 创建单向循环链表
NodeType *GetNode(int);				//得到一个结点
void PrntList(NodeType *);			//打印循环链表
int IsEmptyList(NodeType *);			//测试链表是否为空
void JosephusOperate(NodeType **, int);		//运行约瑟夫环问题

void CreatList(NodeType **pphead, int n)
{
	int i=0;
	NodeType *pcur=NULL;
	NodeType *pnew=NULL;
	for(i=1; i<=n; i++)
	{
		pnew=GetNode(i);
		if(*pphead == NULL)
		{
			*pphead=pcur=pnew;
			pcur->next=*pphead;
		}
		else
		{
			pnew->next=pcur->next;
			pcur->next=pnew;
			pcur=pnew;
		}
	}
	printf("完成了单向链表的创建!\n");
}

NodeType *GetNode(int id)
{
	NodeType *pnew=NULL;
	pnew=(NodeType *)malloc(sizeof(NodeType));
	if(!pnew)
	{
		printf("存储空间不足!\n");
		exit(-1);
	}
	pnew->id=id;
	pnew->next=NULL;
	return pnew;
}

void PrntList(NodeType *phead)
{
	NodeType *pcur=phead;
	if(!IsEmptyList(phead))
	{
		printf("--ID--\n");
		do
		{
			printf("%3d\n",pcur->id);
			pcur=pcur->next;
		}while(pcur!=phead);
	}
}

int IsEmptyList(NodeType *phead)
{
	if(!phead)
	{
		printf("该链表为空!\n");
		return 1;
	} 
	return 0;
}

void JosephusOperate(NodeType **pphead, int password)
{
	int icounter=0;
	int iFlag=1;
	NodeType *pprv=NULL;
	NodeType *pcur=NULL;
	NodeType *pdel=NULL;
	pprv=pcur=*pphead;
	while(pprv->next != *pphead)
	{
		pprv=pprv->next;
	}
	while(iFlag)
	{
		for(icounter=1; icounter<password; icounter++)
		{
			pprv = pcur;
			pcur = pcur->next;
		}
		if(pprv == pcur)
			iFlag=0;
		pdel=pcur;
		pprv->next=pcur->next;
		pcur = pcur->next;
		printf("第%d个人出列!\n", pdel->id);
		free(pdel);
	}
	*pphead=NULL;
	getchar();
}
		
int main(void)
{
	int n=0;
	int m=0;
	NodeType *phead=NULL;
	do
	{
		if(n > Max)
		{
			printf("人数太多,请重新输入!\n");
		}
		printf("请输入人数:\n");
		scanf("%d",&n);
	}while(n > Max);
	printf("请输入初始密码:\n");
	scanf("%d",&m);
	CreatList(&phead, n);
	printf("-------------打印循环链表-------------\n");
	PrntList(phead);
	printf("-------------打印出队情况-------------\n");
	JosephusOperate(&phead, m);
	return 1;
}

