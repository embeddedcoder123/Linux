#include <stdio.h>
#include <stdlib.h>

typedef struct MyStruct
{
	int Data;
	struct MyStruct* Next;
}ST;

void push(ST** hp, int data)
{
	ST* NewNode = (ST*)malloc(sizeof(ST));
	NewNode->Data = data;

	NewNode->Next = *hp;
	*hp = NewNode;
	
}
void append(ST** hp,int data)
{
	ST* NewNode = (ST*)malloc(sizeof(ST));
	NewNode->Data = data;
	NewNode->Next = NULL;

	ST* last = *hp;


	if ((*hp) == NULL)
	{
		*hp = NewNode;
	}
	else
	{
		while (last->Next != NULL)
		{
			last = last->Next;
		}
		last->Next = NewNode;
	}
}
void print(ST* hp)
{
	while (hp)
	{
		printf("%d ", hp->Data);
		hp = hp->Next;
	}
}

void reverse_print(ST* hp)
{
	if (hp == NULL) //most important;
		return;
	reverse_print(hp->Next);
    printf("%d ", hp->Data);
}

void Del_Aftr_Pos(ST** hp, int pos)
{
	ST* temp = *hp;
	/*case1: if head pointer is zero*/
	if (hp == NULL)
		return;
	/*Delete head pointer*/
	if (pos == 0)
	{
		*hp = temp->Next;
		//hp = NULL;
		temp = 0;
		free(temp);
		return;
	}
	/*case 3: travel to Posion*/

	for (int I_ = 0; temp &&I_< pos-1;I_++)
	{
		//hp = hp->Next;
		temp = temp->Next;
	}
	/*Grater posion return*/
	if (temp == 0) return;

	ST* link = temp->Next->Next;
	temp->Next = 0;
	free(temp->Next);
	temp->Next = link;
}
void DelBykey(ST** hp, int Key)
{
	// Store head node
	ST* temp = *hp, * prev = NULL;

	// If head node itself holds the key to be deleted
	if (*hp != NULL && *hp->Data == Key)
	{
		*hp = *hp->Next;   // Changed head
		free(*hp);          // free old head
		return;
	}
	// Search for the key to be deleted, keep track of the
// previous node as we need to change 'prev->next'
	while (temp != NULL && temp->Data != Key)
	{
		prev = temp;
		temp = temp->Next;
	}
	// If key was not present in linked list
	if (temp == NULL) return;

	// Unlink the node from linked list
	prev->Next = temp->Next;

	free(temp);  // Free memory
}
void swap(ST* first, ST* second)
{
	int temp = first->Data;
	first->Data = second->Data;
	second->Data = temp;
}
void bubble_sort(ST* hp)
{
	ST* temp = hp,*NextNode = NULL;
	if (hp == NULL) return;
	int temp1;
	while (temp)
	{
		NextNode = temp->Next;
		while (NextNode)
		{	
			if (temp->Data > NextNode->Data)
			{
				//swap(temp, NextNode);
				 temp1 = temp->Data;
				 temp->Data = NextNode->Data;
				 NextNode->Data = temp1;
			}
			NextNode = NextNode->Next;
		}
		
		temp = temp->Next;
	}

}
void add_at_middlde(ST** hp,int pos,int data)
{
	ST* temp = *hp;
	ST* NewNode = (ST*)malloc(sizeof(ST));
	NewNode->Data = data;
	NewNode->Next = NULL;
	/*hp is null*/
	if ((*hp) == NULL) return;
	if (pos == 0)
	{
		NewNode->Next = *hp;//Important
		*hp = NewNode;
	}
	else
	{
		for (int I_ = 0;I_ < pos - 1 && temp;I_++)
		{
			temp = temp->Next;
		}
		if (temp == NULL){
			printf(" Desire node is out of range\n");
			return;
		}
		NewNode->Next = temp->Next;
		temp->Next = NewNode;;
	}
}

 void main()
{
	ST* hp1 = NULL;
	int ans, d;
	//do
	//{
	//	printf("Enter data to insetrt into node\n");
	//	scanf_s("%d", &d);
	//	push(&hp1,d);
	//	printf("Hit 1 to continue or 0 to terminate\n");
	//	scanf_s("%d",&ans);

	//} while (ans == 1);
	append(&hp1, 20);
	append(&hp1,10);
	append(&hp1, 15);
	append(&hp1, 7);
	append(&hp1, 21);
	append(&hp1, 4);
	add_at_middlde(&hp1, 0, 500);
	add_at_middlde(&hp1, 2, 500);
	add_at_middlde(&hp1, 4, 500);
	add_at_middlde(&hp1, 6, 500);
	add_at_middlde(&hp1, 8, 500);
	add_at_middlde(&hp1, 10, 500);
	add_at_middlde(&hp1, 12, 500);
	Del_Aftr_Pos(&hp1, 12);
	Del_Aftr_Pos(&hp1, 10);
	Del_Aftr_Pos(&hp1, 8);
	Del_Aftr_Pos(&hp1, 6);
	Del_Aftr_Pos(&hp1, 4);
	Del_Aftr_Pos(&hp1, 2);
    Del_Aftr_Pos(&hp1, 0);

	//reverse_print(hp1);;
	//Del_Aftr_Pos(&hp1,0);
	//DelBykey(&hp1, 10);
	//bubble_sort(hp1);
	print(hp1);
	
}

