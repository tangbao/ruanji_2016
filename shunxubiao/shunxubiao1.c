/*************************************************************************
    > File Name: shunxubiao1.c
    > Author: Tb
    > Mail: i@tbis.me 
    > Created Time: 2016年03月18日 星期五 23时41分19秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

#define MAXLENGTH  6666
#define debug_num  10

typedef struct tb_list
{
	int member[MAXLENGTH];
	int length;
}tblist;

void initlist(tblist *l);	//initial the list
bool insert(tblist *l, int i, int x);	//insert x into list
bool delete(tblist *l, int i);
void compare(tblist *a, tblist b);	//compare listA, B

void printl(tblist l);
void buildl(tblist *l);

int main()
{
	tblist A;
	tblist B;
	initlist(&A);
	initlist(&B);

	srand((unsigned) time(NULL));	//make rand seed
	buildl(&A);
	buildl(&B);

	printl(A);
	printl(B);

	compare(&A,B);

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
		l->member[i] = rand() % 101;
}

void printl(tblist l)
{
	int i;
	for(i=0;i<l.length;i++)
		printf("%5d",l.member[i]);
	printf("\n");
}

bool insert(tblist *l, int i, int x)
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
		l->member[j+1] = l->member[j];
	l->member[i] = x;
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
		l->member[j-1] = l->member[j];
	}
	l->length--;
}

void compare(tblist *a, tblist b)
{
	int i, j;
	bool flag;
	for(i=0;i<b.length;i++)
	{
		flag = true;
		for(j=0;j<a->length;j++)
		{
			if(b.member[i] == a->member[j])
				flag = false;
		}
		if (flag)
		{
			insert(a, a->length, b.member[i]);
		}
	}
}
