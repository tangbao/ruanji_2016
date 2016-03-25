/*************************************************************************
    > File Name: shunxubiao4.c
    > Author: Tb
    > Mail: i@tbis.me 
    > Created Time: 2016年03月19日 星期六 10时26分55秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

#define MAXLENGTH  6666
#define debug_num  10

typedef struct tb_stu
{
	int member;
	int score;
}tbstu;

typedef struct tb_list
{
	tbstu data[MAXLENGTH];
	int length;
}tblist;

void initlist(tblist *l);	//initial the list
bool insert(tblist *l, int i, int mem, int score);	//insert mem,score into list
bool delete(tblist *l, int i);
void writein(tblist *l, int del_m);

void sort(tblist *l);
void swap(int *a, int *b);

void printl(tblist l);
void buildl(tblist *l);

int main()
{
	tblist A;
	initlist(&A);

	srand((unsigned) time(NULL));	//make rand seed
	buildl(&A);

	printl(A);
	
	sort(&A);
	printl(A);

	int del_member = 2014000 + rand() % 101;
	writein(&A, del_member);

	printl(A);

	return 0;
}

void initlist(tblist *l)
{
	l->length = 0;
}

void buildl(tblist *l)
{
	int i;
	//srand((unsigned) time(NULL));
	l->length = debug_num;
	for(i=0;i<debug_num;i++)
	{
		l->data[i].member = 2014000 + rand() % 101;	
		l->data[i].score = rand() % 101;
	}
}

void printl(tblist l)
{
	int i;
	for(i=0;i<l.length;i++)
	{
		printf("%8d",l.data[i].member);
		printf("%5d",l.data[i].score);
	}
	printf(" end\n");
}

bool insert(tblist *l, int i, int mem, int score)
{
	if(l->length>=MAXLENGTH)
	{
		printf("Error: List is full.");
		return false;
	}

	if((i<0) || (i>l->length))
	{
		printf("Error: i is not a valid value");
		return false;
	}
	
	int j;
	for (j=l->length-1;j>=i;j--)
	{
		l->data[j+1].member = l->data[j].member;
		l->data[j+1].score = l->data[j].score;
	}
	l->data[i].member = mem;
	l->data[i].score  = score;
	l->length++;
	return true;
}

bool delete (tblist *l, int i)
{
	if((i<0) || (i>l->length-1))
	{
		printf("Error: element not exist.");
		return false;
	}

	int j;
	for(j=i+1;j<l->length;j++)
	{
		l->data[j-1].member = l->data[j].member;
	}
	l->length--;
}

void sort(tblist *l)
{
	int i, j;
	for(i=0;i<l->length-1;i++)
		for(j=0;j<l->length-i-1;j++)
			if(l->data[j].member > l->data[j+1].member)
			{
				swap(&l->data[j].member, &l->data[j+1].member);
				swap(&l->data[j].score, &l->data[j+1].score);
			}
}

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a   = *b;
	*b   = temp;

}

void writein(tblist *l,  int del_m)
{
	int i;
	for(i=0;i<l->length;i++)
	{
		if (del_m == l->data[i].member)
		{
			delete(l, i);
			break;
		}
	}
	printf("number %d not found in data\n", del_m);
}
