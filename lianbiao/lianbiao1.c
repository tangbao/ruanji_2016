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

void initll(tbnode **h);                //initate linked list
void insert(tbnode *h, int i, int x);   //insert x to location i
void delete(tbnode *h, int i);          //delete location i
void buildl(tbnode **h);				//make a linked list with random numbers
void printl(tbnode *h);					//print the linked list
void compare(tbnode *a, tbnode *b);		//compare two lists to work out numbers both in them

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
	(*h)->data = 0;
}

void insert(tbnode *h,  int i,  int x)
{
	tbnode *p, *t;
	int j = 0;
	p = h;

	while(p && j<i-1)
	{
		p = p->next;
		j++;
	}
	if (j!=i-1)
	{
		printf("invalid i");
		return;
	}
	t = (tbnode*) malloc (sizeof(tbnode));
	t->data = x;
	(*h).data ++;
	t->next = p->next;
	p->next = t;
}

void delete(tbnode *h, int i)
{
	tbnode *p, *s;
	int j = 0;
	p = h;
	while(p->next && j<i-1)
	{
		p = p->next;
		j++;
	}
	if (j!=i-1)
	{
			printf("invalid i");
			return;
	}
	s = p->next;
	p->next = s->next;
	(*h).data--;
	free(s);
}

void buildl(tbnode **h)
{
	tbnode *p = *h;
	int i;
	for (i=0;i<debug_num;i++)
		insert(*h, (*h)->data+1, rand() % 101);
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

	if(pb && pb->next)
	{
		if(pa && pa->next)
		{
			pb = pb->next;
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
					insert(a, (*a).data+1, pb->data);
				}
				pb = pb->next;
			}
		}
	}
}
