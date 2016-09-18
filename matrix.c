#include <stdio.h>
#include <stdlib.h>

typedef float ElemType;
typedef struct Triple
{
	int i, j;
	ElemType e;
}Triple;

typedef struct TSMatrix
{
	Triple data[100];
	int mu, nu, tu;
}TSMatrix;

TSMatrix NewTsMatrix(int m, int n);
void TsMatrixInsert(TSMatrix *M, int row, int col, ElemType e);
void PrintMaxtrix(TSMatrix *M);

void Transpose(TSMatrix *M);

void  TransposeSMatrix( TSMatrix *M, TSMatrix *T);

TSMatrix NewTsMatrix(int m, int n)
{
	TSMatrix *M = (TSMatrix *)malloc(sizeof(TSMatrix));
	M->mu = m;
	M->nu = n;
	M->tu = 0;
	return *M;
}

void TsMatrixInsert(TSMatrix *M, int row, int col, ElemType e)
{
	int p = 1;
	if (M->tu==0)
	{
		M->data[p].i = row;
		M->data[p].j = col;
		M->data[p].e = e;
		M->tu++;
	}
	else
	{
		if (row >= M->data[p].i&&col >= M->data[p].j)
		{
			p++;
		}
		else
		{
			for (int i = M->tu; i >= p; i--)
			{
							M->data[i + 1].i = M->data[i].i;
							M->data[i + 1].j = M->data[i].j;
							M->data[i + 1].e = M->data[i].e;
			}
		}


	}

	M->data[p].i = row;
	M->data[p].j = col;
	M->data[p].e = e;
	M->tu++;




}

void  TransposeSMatrix(TSMatrix *M, TSMatrix *T)
{
	int col, p, q;
	T->mu = M->nu;    T->nu = M->mu; T->tu = M->tu;
	if (T->tu){
		q = 1;
		for (col = 0; col <= M->mu; col++)
		for (p = 1; p <= M->tu; p++)
		if (M->data[p].i== col){
			T->data[q].i = M->data[p].j;
			T->data[q].j = M->data[p].i;
			T->data[q].e = M->data[p].e;
			q++;
		}
	}

}

void PrintMatrix(TSMatrix *M)
{
	int p = 1;
	if (!M->tu)
	{
		printf("%d",0);
		return;
	}
	for (int i = 0; i < M->mu; i++)
	{
		for (int j = 0; j < M->nu; j++)
		{
			if (i == M->data[p].i && j == M->data[p].j){
				printf("%g\t", M->data[p].e);
				p++;
			}
			else
			{
				printf("%g\t", 0.0);
			}
			
		}
		printf("\n");
	}
	printf("\n");
}


void main()
{
	TSMatrix M = NewTsMatrix(3,4);
	TSMatrix T = NewTsMatrix(3, 4);

	TsMatrixInsert(&M, 2, 2, 3.1);
	TsMatrixInsert(&M, 1, 1, 3.1);
	TsMatrixInsert(&M, 0, 1, 3.1);
	TsMatrixInsert(&M, 0, 0, 3.1);
	PrintMatrix(&M);

	TransposeSMatrix(&M,&T);
	PrintMatrix(&T);
	system("pause");

}