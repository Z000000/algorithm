<<<<<<< HEAD
#include<stdio.h>

void main()
{
	int a[6] = { 1, 5, 4, 3, 96, 10 };
	int min;
	for (int i = 0; i < 6; i++)
	{
		min = i;
		for (int j = i + 1; j < 6; j++)
		{
			if (a[min]>a[j])
			{
				min = j;

			}
		}
		if (min != i)
		{
			int temp = a[i];
			a[i] = a[min];
			a[min] = temp;
		}
	}

	for (int m = 0; m < 6; m++)
	{
		printf_s("%d\n",a[m]);
	
	}



=======
#include<stdio.h>

void main()
{
	int a[6] = { 1, 5, 4, 3, 96, 10 };
	int min;
	for (int i = 0; i < 6; i++)
	{
		min = i;
		for (int j = i + 1; j < 6; j++)
		{
			if (a[min]>a[j])
			{
				min = j;

			}
		}
		if (min != i)
		{
			int temp = a[i];
			a[i] = a[min];
			a[min] = temp;
		}
	}

	for (int m = 0; m < 6; m++)
	{
		printf_s("%d\n",a[m]);
	
	}



>>>>>>> 503b21f805d2bc277112298c8f0d928abe4cdc0a
}