#include<stdio.h>
#include<stdlib.h>
#define MaxSize 20
typedef int ElemType;
typedef  struct RedType
{
	ElemType key;

};
typedef struct  SqList
{
	RedType r[MaxSize + 1];

} SqList;

int sort(SqList *s, int low, int hight)
{
	int a = s->r[low].key;
	int pivotkey = s->r[low].key;
	while (low <hight)
	{
		while (low<hight&&s->r[hight].key >= pivotkey)

			--hight;


		s->r[low] = s->r[hight];
		while (low<hight&& s->r[low].key <= pivotkey)

			++low;


		s->r[hight] = s->r[low];
	}

	s->r[low].key =a;

	return low;

}

void Qsort(SqList *s, int low, int hight)
{
	if (low < hight)
	{
		int pivotkey = sort(s, low, hight);
		Qsort(s, low, pivotkey-1);
		Qsort(s, pivotkey + 1, hight);
	}



}

void main()
{
	SqList *s;
	s = (SqList *)malloc(sizeof(SqList));
	int a[] = { 49, 38, 65, 97, 76, 13, 27 };
	for (int i = 0; i < 7; i++)
	{
		s->r[i].key = a[i];
	}
	// int pivotkey=sort(s, 0, 7);
	Qsort(s, 0, 6);
	for (int i = 0; i < 7; i++)
	{
		printf("%d\n", s->r[i].key);
	}

	system("pause");

}
