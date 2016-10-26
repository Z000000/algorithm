#include<stdio.h>
int arcs[10][10];
int n = 0;
int D[10];
int Used[10];
int v, w;
int shortpath()
{
	
	for (int i = 0; i < n; i++)
	{
		Used[i] = 0; D[i] = arcs[0][i];
	}
	D[0] = 0; Used[0] = 1;
	for (int j = 1; j < n; j++)  //control cycle's count
	{
		int min = 100000;
		for (int w = 0; w < n; w++)
		{
			if (!Used[w])
			{

				if (D[w] < min)
				{
					v = w; min = D[w];
				}
			}
		}


		Used[v] = 1;

		for (int k = 0; k < n; k++)
		{

			if (!Used[k] && (min + arcs[v][k] < D[k]))
			{
				D[k] = min + arcs[v][k];
			}
		}
	}


}



int main()
{
	n = 6;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arcs[i][j] = 100000;
		}
	}

	arcs[0][2] = 10;
	arcs[0][4] = 30;
	arcs[0][5] = 100;
	arcs[1][2] = 5;
	arcs[2][3] = 50;
	arcs[3][5] = 10;
	arcs[4][3] = 20;
	arcs[4][5] = 60;


	shortpath();
	for (int k = 0; k < n; k++)
	{
		printf("D[%d] = %d\n", k, D[k]);
	}
	system("pause");
	
}


