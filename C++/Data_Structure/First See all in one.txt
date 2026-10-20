#include<stdio.h>
#include<malloc.h>

typedef struct MyStruct
{
	int Data;//4
	struct MyStruct* next;//4
	struct MyStruct* prev;//4
	int data1;////4
	char ch;//1

}ST;

void add_begin(ST** hp, int data)
{
	ST* newnode = (ST*)malloc(sizeof(ST));
	newnode->Data = data;
	newnode->next = newnode->prev = NULL;
	if ((*hp) == NULL)
	{
		*hp = newnode;
	}
	else
	{
		newnode->next = (*hp);
		(*hp)->prev = newnode;
		(*hp) = newnode;
	}
}

void add_end(ST ** hp ,int data)
{
	ST* newnode = (ST*)malloc(sizeof(ST));
	ST* last = *hp;
	newnode->Data = data;
	newnode->next = newnode->prev = NULL;
	if ((*hp) == NULL)
	{
		*hp = newnode;
	}
	else
	{
		while (last->next)
		{
			last = last->next;
		}

		last->next = newnode;
		newnode->prev = last;
		//last = newnode;
	}
}
void print(ST* hp)
{
	while (hp)
	{
		printf("%d ", hp->Data);
		hp = hp->next;
	}
}
void print_reverse(ST* hp)
{
	if (hp == NULL) return;

	print_reverse(hp->next);
	printf("%d ", hp->Data);
}
void main()
{
	ST* hp = 0;
	add_begin(&hp, 10);
	add_begin(&hp, 2);
	add_begin(&hp, 50);
	add_begin(&hp, 1);
	add_end(&hp, 15);
	add_end(&hp, 31);
	add_end(&hp, 17);
	
	print_reverse(hp);
	printf("\n");
	print(hp);

}