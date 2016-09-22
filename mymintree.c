#include<stdio.h>
#include<malloc.h>
#include <stdlib.h>
#include<string.h>
#define MaxvertexNum 100
#define MAX  100000
#define VNUM  10+1   
#define MAXCOST 65535
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
	int i, j, k = 0, minvalue,minid, w, flag;
	int lowcost[VNUM];/*权值*/
	int adjecent[VNUM] = { 0 };
	int sumweight = 0;
	int closet[MaxvertexNum];/*最小生成树结点*/
	char va[MaxvertexNum], vb[MaxvertexNum];
	MGraph *G = (MGraph *)malloc(sizeof(MGraph));
	printf("please input data of vertex and edge num with blank \n ");
	scanf_s("%d %d", &G->n, &G->e);

	//for (int d = 0; d < G->n; d++)
	//{
	//	scanf_s("%s",&G->vexs[d]);
	//}
	for (i = 0; i < G->n; i++)
	{
		for (j = 0; j < G->n; j++)
		{
			G->edges[i][j] = MAXCOST;

		}
	}

	//for (k = 0; k < G->e; k++)
	//{
	//	printf("please input data of v-e with weight\n ");
	//	scanf_s("%d%d%d", &i, &j, &w);
	///*	i = LocateVex(G, va);
	//	j= LocateVex(G, vb);*/
	//	G->edges[i][j] = w;
	//	G->edges[j][i] = w;
	//}

	G->edges[0][1] = 6;

	G->edges[1][0] = 6;

	G->edges[0][2] = 1;

	G->edges[2][0] = 1;

	G->edges[0][3] = 5;

	G->edges[3][0] = 5;

	G->edges[1][2] = 5;

	G->edges[2][1] = 5;

	G->edges[1][4] = 3;

	G->edges[4][1] = 3;

	G->edges[2][3] = 5;

	G->edges[3][2] = 5;

	G->edges[2][4] = 6;

	G->edges[4][2] = 6;

	G->edges[2][5] = 4;

	G->edges[5][2] = 4;

	G->edges[3][5] = 2;

	G->edges[5][3] = 2;

	G->edges[4][5] = 6;

	G->edges[5][4] = 6;

	

	int mst[MAX];
	int  min,sum = 0;
	for (i = 1; i <G->n; i++)
	{
		lowcost[i] = G->edges[0][i];
		mst[i] = 0;
	}
	mst[0] = 1;
	for (i = 1; i <G->n; i++)
	{
		min = MAXCOST;
		minid = 0;
		for (j = 1; j <G->n; j++)
		{
			if (lowcost[j] < min && lowcost[j] != 0)
			{
				min = lowcost[j];
				minid = j;
			}
		}

		printf("v%d-%d=%d\n", mst[minid], minid, min);
		sum += min;
		lowcost[minid] = 0;
		for (j = 1; j < G->n; j++)
		{
			if (G->edges[minid][j] < lowcost[j])
			{
				lowcost[j] = G->edges[minid][j];
				mst[j] = minid;
			}
		}
	}
	return sum;
	

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

	MGraph * M = CreateMGraph();
	
	system("pause");
}