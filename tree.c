#include<stdio.h>
#include<malloc.h>

typedef int datatype;
typedef  struct BT
{
	datatype data;
   struct  BT * lchild;
	struct BT * rchild;
	
} BT;




BT  *create();
void prepare(BT *t);


BT  * create()
{
	BT *t;
	BT  b, c;
	

	int x;
	scanf_s("%d", &x);
	if (x ==0)
	{
		t = NULL;

	}
	else
	{
		t = (BT*)malloc(sizeof(BT));   //design memory
		t->data = x;
		printf("%d left node is:", t->data);
		t->lchild = create();
		printf("%d right node is:", t->data);
		t->rchild = create();

	}
	return t;

}

void prepare(BT *t)
{
	if (t == NULL)
	{
		return;
	}
	else
	{
		printf("%d", t->data);
		prepare(t->lchild);
		prepare(t->rchild);
	}

}


void main()
{
	BT *T = NULL;


	int choice;
	printf("input  1or 2");

	//switch (choice)
	//{
	//case 1:
	//	T = create();
	//	printf("successful");
	//case 2:
	//	printf("preorder");
	//	prepare(T);
	//	break;
	//}
	do{
		scanf_s("%d", &choice);
		if (choice == 1)
		{
				T = create();
				printf("successful");
		}
		else if (choice==2)
		{
			prepare(T);

		}
	
	} while (choice < 8);




	}
