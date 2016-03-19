/*************************************************************************
    > File Name: shunxubiao3.c
    > Author: Tb
    > Mail: i@tbis.me 
    > Created Time: 2016年03月19日 星期六 09时14分50秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

#define MAXLENGTH  6666
#define debug_num  10

#define insert_member 2014054
#define insert_score  40

typedef struct tb_list
{
	int member[MAXLENGTH];
	int score[MAXLENGTH];
	int length;
}tblist;

void initlist(tblist *l);	//initial the list
bool insert(tblist *l, int i, int mem, int score);	//insert mem,score into list
bool delete(tblist *l, int i);
void writein(tblist *l, int mem, int score);

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

	writein(&A, insert_member, insert_score);

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
		l->member[i] = 2014000 + rand() % 101;	
		l->score[i] = rand() % 101;
	}
}

void printl(tblist l)
{
	int i;
	for(i=0;i<l.length;i++)
	{
		printf("%8d",l.member[i]);
		printf("%5d",l.score[i]);
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
		l->member[j+1] = l->member[j];
		l->score[j+1] = l->score[j];
	}
	l->member[i] = mem;
	l->score[i]  = score;
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

void sort(tblist *l)
{
	int i, j;
	for(i=0;i<l->length-1;i++)
		for(j=0;j<l->length-i-1;j++)
			if(l->member[j] > l->member[j+1])
			{
				swap(&l->member[j], &l->member[j+1]);
				swap(&l->score[j], &l->score[j+1]);
			}
}

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a   = *b;
	*b   = temp;

}

void writein(tblist *l, int mem, int score)
{
	int i;
	for(i=0;i<l->length;i++)
	{
		if (mem >= l->member[i])
		{
			insert(l, i, mem, score);
			break;
		}
	}
}
