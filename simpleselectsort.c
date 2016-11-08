#include <stdio.h>

int selectmin(int a[], int n, int i)
{
	int k =i;
	for (int c = i + 1; c < n; c++)
	{
		if (a[c]<a[i])
		{
			k = c;
		}
	}
	return k;

}

void sort(int a[])
{
	int temp;
	for (int i = 0; i < 6; i++)
	{
		int min = selectmin(a, 6, i);
		if (min != i)
		{
			temp = a[min];
			a[min] = a[i];
			a[i] = temp;


		}
	}

}

void main()
{
	int a[] = { 1, 4, 3, 6, 65, 8 };
	sort(a);

	for (int i = 0; i < 6; i++)
	{
		printf("%d  ", a[i]);
	}

	system("pause");

}