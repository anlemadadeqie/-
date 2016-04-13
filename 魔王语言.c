#include <stdio.h>
#include<malloc.h>
#include<string.h>
struct stack
{
    char ch[1024];
    int top;
};
struct queue{
    char data[1024];
    int rear;
    int front;
};
void chushi(struct stack *zhan)
{
	zhan->top = -1;
}
void ruzhan(struct stack *zhan,char x)
{
	zhan->top++;
	zhan->ch[zhan->top] = x;
}
void chuzhan(struct stack *zhan,char *x)
{
	 *x = zhan->ch[zhan->top];
	 zhan->top--;
}
struct queue *dcs()
{
	struct queue *sq;
	sq = malloc(sizeof(struct queue));
	sq->rear = sq->front = -1;
	return sq;
}
void rudui(struct queue *lie,char x)
{
	lie->rear++;
	lie->data[lie->rear] = x;
}
void chudui(struct queue *lie,char *x)
{
	lie->front++;
	*x = lie->data[lie->front];
}
int main()
{
	 char a[100],x,c;
	 int n,i,j,k,flag = 0;
	 struct stack *zhan;
	 struct queue *lie;
	 zhan = malloc(sizeof(struct stack));
	 lie = dcs();
	 chushi(zhan);
	 scanf("%s",a);
	 n = strlen(a);
	 for(i = 0;i < n;i++)
	 {
		  if(a[i]=='(')
		  {
			   j=i;
			   c=a[i+1];
		  }
		  if(a[i]==')')
		  {
			    k=i;
		  }
	 }
	 for (i=j+2;i<k;i++)
	 {
		  ruzhan(zhan,c);
		  ruzhan(zhan,a[i]);
	 }
	 ruzhan(zhan,c);
	  for (i=0;i<n;i++)
	  {
		   if (a[i]=='B')
		   {
				flag = 1;
				rudui(lie,'t');
				rudui(lie,'s');
				rudui(lie,'a');
				rudui(lie,'e');
				rudui(lie,'d');
				rudui(lie,'s');
				rudui(lie,'a');
				rudui(lie,'e');
		   }
		   if (a[i] == 'A')
		   {
				flag = 1;
				rudui(lie,'s');
				rudui(lie,'a');
				rudui(lie,'e');
		   }
		   if (a[i] == '(')
		   {
			   while (zhan->top!=0)
			   {
				   chuzhan(zhan,&x);
				   rudui(lie,x);
			   }
			   while(a[i]!=')')
			   {
				   i++;
			   }
		   }
		}
	 i = 0;
	 while (lie->front != lie->rear)
	 {
		 chudui(lie,&a[i]);
		 i++;
	 }
	 a[i] = '\0';
	 printf("%s\n",a);
	 return 0;

}