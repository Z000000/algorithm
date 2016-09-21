#include<stdio.h>
#include<malloc.h>
#include <stdlib.h>
#define MaxvertexNum 100
typedef char VertexType;
typedef int EdgeType;
typedef struct MGraph
{
	VertexType vexs[MaxvertexNum];
	EdgeType edges[MaxvertexNum][MaxvertexNum];
	int n, e;

}MGraph;

MGraph *  CreateMGraph()
{
	int i, j, k, w;
	MGraph *G = (MGraph *)malloc(sizeof(MGraph));
	printf("please input data of vertex and edge num with blank \n ");
	scanf_s("%d %d",&G->n,&G->e);
	for (i = 0; i < G->n; i++)
	{
		for (j = 0; j < G->n; j++)
		{
			G->edges[i][j] = 0;
		
		}
	}

	for (k = 0; k < G->e; k++)
	{
		printf("please input data of v-e with weight\n ");
		scanf_s("%d%d%d", &i, &j, &w);
		G->edges[i][j] = w;
		G->edges[j][i] = w;
	}
	return G;
}

void Show(MGraph *G)
{
	for (int i = 0; i < G->n; i++)
	{
		for (int j = 0; j < G->n; j++)
		{
			printf("%d\t", G->edges[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void main()
{
	
	MGraph * M=CreateMGraph();
	Show(M);
	system("pause");
}