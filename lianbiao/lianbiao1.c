/*************************************************************************
    > File Name: lianbiao1.c
    > Author: Tb
    > Mail: i@tbis.me 
    > Created Time: 2016年03月26日 星期六 13时01分58秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

#define debug_num 10

typedef struct tb_node
{
	int data;
	struct tb_node* next;
}tbnode;

void initll(tbnode **h);
void insert(tbnode *h,  int x);
void delete(tbnode *h, int i);
void buildl(tbnode **h);
void printl(tbnode *h);
void compare(tbnode *a, tbnode *b);

int main()
{
	
	tbnode *A;
	tbnode *B;
	initll(&A);
	initll(&B);

	srand((unsigned) time(NULL));
	buildl(&A);
	buildl(&B);
	
	printl(A);
	printl(B);
	compare(A,B);
	printl(A);
	return 0;
}

void initll(tbnode **h)
{
	*h = (tbnode*) malloc (sizeof(tbnode));
	(*h)->next = NULL;
}

void insert(tbnode *h,  int x)
{
	tbnode *p, *t;
	int j;
	p = h;
	j = 0;
	while(p->next)
		p = p->next;
	t = (tbnode*) malloc (sizeof(tbnode));
	t->data = x;
	t->next = p->next;
	p->next = t;
}

void delete(tbnode *h, int i)
{

}

void buildl(tbnode **h)
{
	tbnode *p = *h;
	int i;
	for (i=0;i<debug_num;i++)
		insert(*h, rand() % 101);
}

void printl(tbnode *h)
{
	tbnode *p = h;
	p = p->next;
	while(p)
	{
		printf("%4d", p->data);
		p = p->next;
	}
	printf("\n");
}

void compare(tbnode *a, tbnode *b)
{	
	tbnode *pa = a;
	tbnode *pb = b;
	int i=0;

	if(pb && pb->next)
	{
		pb = pb->next;
		if(pa && pa->next)
		{
			while(pb)
			{
				pa = a;
				pa = pa->next;
				bool flag = true;
				while(pa)
				{
					if (pb->data == pa->data)
						flag = false;
					pa = pa->next;
				}
				if (flag)
				{
					insert(a,  pb->data);
				}
				pb = pb->next;
			}
		}
	}
}
