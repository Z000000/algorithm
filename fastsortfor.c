#include<stdio.h>

void test(int *a)
{

    int pivot = 0;
    int key = a[pivot];
    int flag = 0;
    int flag1 = 0;
    for (int i = 5; i >= 0; i--)
    {
        if (i>pivot&&a[i] < key)
        {
            int tmp = a[i];
            a[i] = key;
            a[pivot] = tmp;
            pivot = i;
            flag = i;
            break;
        }
    }
    for (int j = 0; j < 6; j++)
    {
        if (j<pivot&&a[j]>key)
        {
            int tmp = a[j];
            a[j] = key;
            a[pivot] = tmp;
            pivot = j;
            flag1 = j;
            break;
        }
    }
   
    if (flag != flag1)
    {
        test(a);
    }
    else
    {
        return;
    }
}


void main()
{

    int aa[5] = { 1, 2, 3, 4, 5 };
    printf("%x",aa);
    printf("%x", &aa);
    int *ptr = (int *)(&aa+1);
    printf("%d,%d", *(aa + 1), *(ptr-1));//Êä³ö£º2,5
    int a[6] = {6,2,7,3,8,9};
    test(a);
    for (int c = 0; c < 6; c++)
    {
        printf("%d", a[c]);
    }
    getchar();
}