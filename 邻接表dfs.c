#include <stdio.h>
#include <malloc.h>

#define MAXVEX 20
typedef struct ArcNode
{
	int adjvex;		//邻接点序号
//	int weight;		//邻接点边上的权值
	struct ArcNode *next;
}ArcNode;

typedef struct VertexNode
{
	char vexdata;		//存储节点信息
	ArcNode *head;		//边表头指针
}VertexNode;

typedef struct
{
	VertexNode vertex[MAXVEX];	//顶点数组
	int vexnum;			//顶点数
	int arcnum;			//弧数
}AdjList;

/*创建邻接表*/
void create(AdjList *G)
{
	int i, j, k;
	ArcNode *e;
	printf("请输入顶点数:\n");
	scanf("%d",&G->vexnum);
	printf("请输入弧数:\n");
	scanf("%d",&G->arcnum);
	for(i = 0; i <= G->vexnum; i++)
	{
		printf("请输入顶点信息:\n");
		scanf("%c",&G->vertex[i].vexdata);
		G->vertex[i].head = NULL;
	}
	for(k = 0; k <= G->arcnum; k++)
	{
		printf("请输入该边的两个顶点序号:\n");
		scanf("%d,%d",&i,&j);
		
		e = (ArcNode *)malloc(sizeof(ArcNode));
		e->adjvex = j;
		e->next =  G->vertex[i].head;
		G->vertex[i].head = e;

		e = (ArcNode *)malloc(sizeof(ArcNode));
		e->adjvex = i;
		e->next = G->vertex[j].head;
		G->vertex[j].head = e;
	}
}

int visited[MAXVEX];

void DFS(AdjList *G, int v)
{
	ArcNode *p;
	printf("%c",G->vertex[v].vexdata);
	visited[v] = 1;
	for(p = G->vertex[v].head; p; p = p->next)
	{
		if(visited[p->adjvex] == 0)
			DFS(G,p->adjvex);
	}
}


void DFS_Traverse(AdjList *G)
{
	int i ;
	for(i = 0; i <= G->vexnum; i++)
		visited[i] = 0;
	for(i = 0; i <= G->vexnum; i++)
	{
		if(visited[i] == 0)
			DFS(G,i);
	}
}
	
	
void main()
{
	AdjList *h;
	h = (AdjList *)malloc(sizeof(AdjList));
	create(h);
	DFS_Traverse(h);
}	
