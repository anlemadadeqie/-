#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	char data;
	struct	node *lchild;
	struct	node *rchild;
	int ltag;
	int rtag;
}Binode, *Bitree;
#if 0
/*线索二叉树的建立*/
void Creat(Bitree *root) //创建二叉树
{
	char ch;
	ch = getchar();
	if (ch == '^')
		*root = NULL;
	else
	{
		*root = (Bitree)malloc(sizeof(Binode));
		(*root)->data =ch;
		Creat(&((*root)->lchild));
		Creat(&((*root)->rchild));
	}
}
#endif
/*线索二叉树的建立*/
Binode *creat()
{
	char ch;
	Binode *h;
	ch = getchar();
	if( ch == '#' )
		return 0;
	h=( Binode * )malloc( sizeof( Binode ) );
	h->data = ch;
	h->lchild = creat();
	h->rchild = creat();
	return h;
}

#if 0
Bitree pre = NULL;
/*二叉树的线索化1*/
void Inthread(Bitree root)
{
	if( root != NULL ) 
	{
		Inthread(root->lchild);
		if( root->lchild == NULL )
		{
			root->ltag = 1;
		}
		else
		{
			root->ltag = 0;
		}
		if(root->rchild == NULL )
		{
			root->rtag = 1;
		}
		else
		{
			root->rtag = 0;
		}
		if (pre!=NULL)
		{
			if(pre->rtag == 1)
			{
				pre->rchild = root;
			}
			if(root->ltag == 1)
				root->lchild = pre;
		}
		pre = root;
		Inthread(root->rchild);
	}
}
#endif

Bitree pre = NULL;
/*二叉树的线索化2*/
void Inthread(Bitree root)
{
	if(root != NULL)
	{
		Inthread(root->lchild);
		if(root->lchild == NULL)
		{
			root->lchild = pre;
			root->ltag = 1;
		}
		if(root->rchild == NULL)
		{
			root->rtag = 1;
		}
		if(pre != NULL && pre->rchild == NULL)
		{
			pre->rchild = root;
			pre->rtag = 1;
		}
		pre = root;
		Inthread(root->rchild);
	}
}

/*在线索二叉树中查找遍历的第一个结点*/
Bitree InFirst(Bitree root)
{
	Bitree p = root;
	if( p == NULL)
		return NULL;
	while( p->ltag == 0 )
		p = p->lchild;
	return p;
}

/*在线索二叉树中查找结点的后继*/
Bitree InNext( Bitree root )
{
//	int i =0;
	Bitree next;
	Bitree q;
	if( root->rtag == 1)
	{
		next = root->rchild;
	}
	else
	{
		next = root->rchild;
		for(q = root->rchild; q->ltag == 0;q=q->lchild )
		{
			next = q->lchild;
		}
	}
	return next;
}

/*遍历中序二叉线索树*/
void TinOrder( Bitree root )
{
	Bitree p;
	p = InFirst(root);
	while( p != NULL ) 
	{
		printf("%c", p->data);
		p = InNext( p );
	}
}

void main()
{
	Binode *s;
	s=creat();
	Inthread(s);
	TinOrder(s);
	printf("\n");
}
