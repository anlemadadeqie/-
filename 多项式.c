#include <stdio.h>
#include <stdlib.h>

typedef  struct Polynomial
{

	float coef;		//存储系数
	int   expn;		//存储指数
	struct Polynomial *next;
}*Polyn;

/*创建多项式*/
Polyn CreatePoly()
{
	Polyn head,rear,s;
	int c,e;
	head=(Polyn)malloc(sizeof(struct Polynomial));
	rear = head;
	scanf("%d,%d",&c,&e);
	while(c!=0)
	{
		s=(Polyn)malloc(sizeof(struct Polynomial));
		s->coef=c;
		s->expn=e;
		rear->next=s;
		rear=s;
		scanf("%d,%d",&c,&e);
	}
	rear->next=NULL;
	return head;
}

/*输出多项式*/
void PrintPolyn(Polyn p)
{
	Polyn q=p->next;
	int flag=1;
	if(!q)
	{
		putchar('0');
		printf("\n");
		return;
	}
	while(q)
	{
		if(q->coef>0&&flag!=1)
			putchar('+');
		if(q->coef!=1&&q->coef!=-1)
		{
			printf("%g",q->coef);
			if(q->expn==1)
				putchar('X');
			else if(q->expn)
				printf("X^%d",q->expn);
		}
		else 
		{
			if(q->coef==1)
			{
				if(!q->expn)
					putchar('1');
				else if(q->expn==1)
					putchar('X');
				else
					printf("X^%d",q->expn);
			}
			if(q->coef==-1)
			{
				if(!q->expn)
					printf("-1");
				else if(q->expn==1)
					printf("-X");
				else
					printf("-X^%d",q->expn);
			}
		}
		q=q->next;
		flag++;
	}
	printf("\n");
}

/*多项式相加*/
Polyn AddPolyn(Polyn pa, Polyn pb)
{
	Polyn qa=pa->next;
	Polyn qb=pb->next;
	Polyn headc,pc,qc;
	pc=(Polyn)malloc(sizeof(struct Polynomial));
	pc->next=NULL;
	headc=pc;
	while(qa!=NULL && qb!=NULL)
	{
		qc=(Polyn)malloc(sizeof(struct Polynomial));
		if(qa->expn < qb->expn)
		{
			qc->coef=qa->coef;
			qc->expn=qa->expn;
			qa=qa->next;
		}
		else if(qa->expn == qb->expn)
		{
			qc->coef=qa->coef+qb->coef;
			qc->expn=qa->expn;
			qa=qa->next;
			qb=qb->next;
		}
		else 
		{
			qc->coef=qb->coef;
			qc->expn=qb->expn;
			qb=qb->next;
		}
		if(qc->coef!=0)
		{
			qc->next=pc->next;
			pc->next=qc;
			pc=qc;
		}
		else free(qc);
	}
	while(qa!=NULL)
	{
		qc=(Polyn)malloc(sizeof(struct Polynomial));
		qc->coef=qa->coef;
		qc->expn=qa->expn;
		qa=qa->next;
		qc->next=pc->next;
		pc->next=qc;
		pc=qc;
	}
	while(qb!=NULL)
	{
		qc=(Polyn)malloc(sizeof(struct Polynomial));
		qc->coef=qb->coef;
		qc->expn=qb->expn;
		qb=qb->next;
		qc->next=pc->next;
		pc->next=qc;
		pc=qc;
	}
	return headc;
}

/*多项式相减*/
Polyn SubtractPolyn(Polyn pa, Polyn pb)
{
	Polyn h=pb;
	Polyn p=pb->next;
	Polyn pd;
	while(p)
	{
		p->coef*=-1;
		p=p->next;
	}
	pd=AddPolyn(pa,h);
	for(p=h->next;p;p=p->next)
	p->coef*=-1;
	return pd;
}

void  main()
{
	Polyn pa,pb,pc,pg;
	pa=CreatePoly();
	PrintPolyn(pa);
	pb=CreatePoly();
	PrintPolyn(pb);
	int num;
	do
	{        
		printf("please select your choice:\n");
		printf("若要进行加法运算请输入1!\n");
		printf("若要进行减法运算请输入2!\n");
		setbuf(stdin,NULL);
		scanf("%d",&num);
		setbuf(stdin,NULL);
	}while(num != 1 && num !=2);
	switch(num)
	{
		case 1:	
			pc=AddPolyn(pa,pb);
			PrintPolyn(pc);
			break;
		case 2:
			pg=SubtractPolyn(pa,pb);
			PrintPolyn(pg);
			break;
	}
}	
