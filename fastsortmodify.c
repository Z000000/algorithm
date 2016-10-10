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
	s->r[0] = s->r[low + 1];
	int pivotkey = s->r[low + 1].key;
	while (low <hight)
	{
		while (low<hight&&s->r[hight].key >= pivotkey)

			--hight;


		s->r[low + 1] = s->r[hight];
		while (low<hight&& s->r[low + 1].key <= pivotkey)

			++low;


		s->r[hight] = s->r[low + 1];
	}

	s->r[low + 1] = s->r[0];

	return low;

}

void Qsort(SqList *s, int low, int hight)
{
	if (low < hight)
	{
		int pivotkey = sort(s, low, hight);
		Qsort(s, low, pivotkey);
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
		s->r[i + 1].key = a[i];
	}
	// int pivotkey=sort(s, 0, 7);
	Qsort(s, 0, 7);
	for (int i = 1; i < 8; i++)
	{
		printf("%d\n", s->r[i].key);
	}

	system("pause");

}
