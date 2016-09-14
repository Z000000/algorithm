#include<stdlib.h>
#include<stdio.h>
typedef int elemtype;
typedef struct node
{
	 elemtype num;
	 struct   node * next;
}node;
node *create(node * head);
void print();

node *create(node * head)
{
	node * p1, *p2;
	int i = 1;
	p1 = p2 = (node *)malloc(sizeof(node));
	scanf_s("%d", &p1->num);
	p1->next = NULL;
	while (p1->num>0)
	{
		if (head == NULL)
		{
			head = p1;
		}
		else
		{
			p2->next = p1;
		}
		p2 = p1;  //cover memory  
		p1  = (node *)malloc(sizeof(node));
		i = i + 1;
		printf("p%d_addr=%d", i, p1);
		printf("%d", head->num);
		scanf_s("%d", &p1->num);

	}
	free(p1);
	p1= NULL;
	p2->next = NULL;
	printf("over");
	
	return head;
}

void insert(node * c, int i, int e)
{
	node *p = c;
	int j = 0;
	while (p&&j < i - 1)
	{
		p = p->next; ++j;
	}
	node * s = (node*)malloc(sizeof(node));
	s->num = e;
	s->next = p->next;//consider the linklist is ok 
	p->next = s;

	

}

void delete(node * c, int i)
{
	node * p = c;
	int j=0;
	while (p->next&&j<i-1)  //before linklist
	{
		p = p->next; ++j;

	}

	node *q;

	q = p->next;
	p->next = q->next;
	free(q);

}

  


void print(node * head)
{
	node * temp;
	temp = head;
	while (temp!=NULL)
	{
		printf("%6d\n", temp->num);
		temp = temp->next;
	}

	printf("end");
	

}

void main()
{
	struct node *head;
	head = NULL;    //②建一个空表  
	head = create(head);/*创建单链表*/
	print(head);/*打印单链表*/
	insert(head, 2, 3222);
	print(head);
	delete(head, 3);
	print(head);
}
