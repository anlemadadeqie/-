#include <stdio.h>
#include <stdlib.h>

#define Maxsize 100

typedef struct nodAe 
{
	char data;
	struct node *lchild;
	struct node *rchild;
}Binode, *Bitree;

typedef struct
{
	struct node *data[Maxsize];
	int top;
}Seqstack;

//栈的初始化
Seqstack *Initstack()
{
	Seqstack *s;
	s = malloc(sizeof(Seqstack));
	s->top = -1;
	return s;
}

//入栈
int Push(Seqstack *s, Binode *q)
{
	 if(s->top == Maxsize-1)
		return 0;
	 s->top++;
	 s->data[s->top] = q;
	 return 1;
}


//判空栈
int Isempty(Seqstack *s)
{
	if(s->top == -1)
		return 1;
	else
		return 0;
}


//出栈
int Pop(Seqstack *s, Binode **q)
{
	if(Isempty(s))
		return 0;
	*q=s->data[s->top];
	s->top--;
	return 1;
}


//取栈顶元素
Binode *Top(Seqstack *s)
{
	if(Isempty(s))
		return 0;
	else
		return (s->data[s->top]);
}
	
	
//二叉树的建立
Binode  *creat()
{
	char ch;
	Binode *h;
	ch = getchar();
	if(ch == '#')
		return 0;
	h = (Binode *)malloc(sizeof(Binode));
	h->data = ch;
	h->lchild = creat();
	h->rchild = creat();
	return h;
}


//先序非递归遍历二叉树
void PreOrder(Bitree root)
{
	Bitree	p;
	Seqstack *s;
	s=Initstack();
	p = root;
	while(p != NULL || !Isempty(s))
	{
		while(p != NULL)
		{
			printf("%c",p->data);
			Push(s,p);
			p = p->lchild;
		}
		if(!Isempty(s))
		{
			Pop(s,&p);
			p = p->rchild;
		}
	}
}


//中序非递归遍历二叉树
void PreOrder1(Bitree root)
{
	Seqstack *s;
	Bitree p;
	s=Initstack();
	p = root;
	while(p != NULL || !Isempty(s))
	{
		while(p != NULL)
		{
			Push(s,p);
			p = p->lchild;
		}
		if(!Isempty(s))
		{
			Pop(s,&p);
			printf("%c", p->data);
			p = p->rchild;
		}
	}
}


//后续非递归遍历二叉树
void PreOrder3(Bitree root)
{
	Seqstack *s;
	Bitree p, q;
	s=Initstack();
	p = root;
	q = NULL;
	while( p != NULL || !Isempty(s))
	{
		while(p != NULL)
		{
			Push(s,p);
			p = p->lchild;
		}
		if(!Isempty(s))
		{
			p=Top(s);
			if((p->rchild == NULL) || (p->rchild == q))
			{
				Pop(s,&p);
				printf("%c", p->data);
				q = p;
				p = NULL;
			}
			else
				p = p->rchild;
		}
	}
}
						
void main()
{
				
	Binode *h;
	h=creat();
	PreOrder(h);
	printf("\n");
}					
