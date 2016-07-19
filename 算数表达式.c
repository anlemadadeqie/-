#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Maxsize 100

typedef struct 
{
	char data[Maxsize];
	int top;
}SeqStack;

typedef struct 
{
	int data[Maxsize];
	int top;
}SeqStack1;

SeqStack  *fhzhan;
SeqStack1 *szzhan;

/*置空栈**/
int InitStack()
{
	fhzhan = malloc(sizeof(SeqStack));
	szzhan = malloc(sizeof(SeqStack1));
	fhzhan->top = -1;
	szzhan->top = -1;
}

/*入符号栈*/
int Push_SeqStack(char x)
{
	if(fhzhan->top == Maxsize-1)
		return 0;
	else
	{
		fhzhan->top++;
		fhzhan->data[fhzhan->top] = x;
		return 1;
	}
}

/*入数字栈*/
int Push_SeqStack1(int x)
{
	if(szzhan->top == Maxsize-1)
		return 0;
	else
	{
		szzhan->top++;
		szzhan->data[szzhan->top] = x;
		return 1;
	}
}

/*判符号空栈**/
int Empty_SeqStack()
{
	if(fhzhan->top == -1)
		return 1;
	else
		return 0;
}

/*判数字空栈**/
int Empty_SeqStack1()
{
	if(szzhan->top == -1)
		return 1;
	else
		return 0;
}

/*出符号栈*/
int Pop_SeqStack(char *x)
{
	if(Empty_SeqStack(fhzhan))
		return 0;
	else
	{
		*x=fhzhan->data[fhzhan->top];
		fhzhan->top--;
		return 1;
	}
}

/*出数字栈*/
int Pop_SeqStack1(int *x)
{
	if(Empty_SeqStack(szzhan))
		return	0;
	else
	{
		*x=szzhan->data[szzhan->top];
		szzhan->top--;
		return 1;
	}
}

/*取符号栈顶元素**/
int Top_SeqStack()
{
	if(Empty_SeqStack())
		return 0;
	else
		return fhzhan->data[fhzhan->top];
}

/*取数字栈顶元素**/
int Top_SeqStack1()
{
	if(Empty_SeqStack1())
		return 0;
	else
		return szzhan->data[szzhan->top];
}

void main()
{
	char a[100],q[100],b,e,op,x,c;
	int d,n,j = 0,k = 0,o1,o2,val,i = 0,z = 0;
	InitStack();
	Push_SeqStack('#');
	printf("请输入算数表达式：");
	scanf("%s",a);
	n = strlen(a);
	for(i = 0; i < n; i++) 
	{
		if(a[i] >= '0' && a[i] <= '9')
		{		
			q[j]=a[i];
			j++;
			continue;
		}
		else if(a[i] == '(')
		{
			Push_SeqStack1(a[i]);
			continue;
		}
		else
		{
			if(j !=0)
			{
				for(k=0; k<j; k++)
				{
					z=z*10+q[k]-48;
				}
				j=0;
				Push_SeqStack1(z);
				z=0;
				b=Top_SeqStack();
				if(b == '#') 
				{
					Push_SeqStack(a[i]);
				}
				else
				{
						if(a[i] == ')')
						{
							while( Top_SeqStack() != '(')
							{
								Pop_SeqStack(&op);
								Pop_SeqStack1(&o1);
								Pop_SeqStack1(&o2);
								if(op == '+')
									val=o2+o1;
								else if(op == '-')
									val=o2-o1;
								else if(op == '*')
									val=o2*o1;
								else if(op == '/')
									val=o2/o1;
								Push_SeqStack1(val);						
							}
							Pop_SeqStack(&x);
						}
						else if(b == '+' || b == '-') 
						{
							Push_SeqStack(a[i]);
							continue;
						}
						else if((b == '*' || b == '/') && (a[i] == '*' || a[i] == '/'))
						{
							Push_SeqStack(a[i]);
							continue;
						}
						else if((b == '*' || b == '/') && (a[i] == '+' || a[i] == '-'))
						{
							Pop_SeqStack(&op);
				 			Pop_SeqStack1(&o1);
				 			Pop_SeqStack1(&o2);
							if(op == '*')
								val=o2*o1;
							else if(op == '/')
								val=o2/o1;	
							Push_SeqStack1(val);
						//	Push_SeqStack(a[i]);
							e=Top_SeqStack();
							while((e == '*' || e == '/') && (a[i] == '+' || a[i] == '-'))
							{
								Pop_SeqStack(&op);
								Pop_SeqStack1(&o1);
								Pop_SeqStack1(&o2);
								if(op == '*')
									val=o2*o1;
								else if(op == '/')
									val=o2/o1;
								Push_SeqStack1(val);
								e=Top_SeqStack();
							}
								Push_SeqStack(a[i]);
						}


											
				}
			}
			else
				Push_SeqStack(a[i]);
				
		}
	}
	if(j !=0)
	{
		for(k=0; k<j; k++)
		{
			z=z*10+q[k]-48;
		}
		j=0;
	}
	Push_SeqStack1(z);
	Pop_SeqStack1(&o1);
	Pop_SeqStack(&op);
	while (op!='#')
	{
		Pop_SeqStack1(&o2);
		if(op == '+')
			o1=o2+o1;
		else if(op == '-')
			o1=o2-o1;
		else if(op == '*')
			o1=o2*o1;
		else if(op == '/')
			o1=o2/o1;
		Pop_SeqStack(&op);
	}  		
	printf("%d\n",o1);
}
					
						
	
