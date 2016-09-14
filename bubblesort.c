#include <stdio.h>
void main()
{
	int a[6] = {8,4,5,6,9,10};

	int i, j,temp;
	for (i = 0; i < 6; i++)
	{
		for (j = i;j<6; j++)
		{
			if (a[j]>a[i])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
				
			}
		}
	}
	for (int k = 0; k < 6; k++)
	{
		printf_s("%d\n", a[k]);
	}


}