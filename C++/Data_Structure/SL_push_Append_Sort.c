// single link list
#include<stdio.h>
#include<stdlib.h>
typedef struct student
{
    int Data;
    struct student *next;
}ST;

void swap_data(int* first,int* second)
{
    *first = *first + *second;
    *second = *first - *second;
    *first = *first - *second;
}

void sort_list(ST** hp)
{
   ST* cur = *hp;
   ST* cur_next = NULL;
   while(cur->next!= 0)
   {
	    cur_next = cur->next;
        while(cur_next->next)
        {
			 if(cur->Data > cur_next->Data)
			 {
				swap_data(&cur->Data,&cur_next->Data);
			 }
			 cur_next = cur_next->next;
        }
        cur = cur->next;
   }
}

void append_data(ST** hp,int data)
{
     ST* new_node = (ST*)malloc(sizeof(ST));
     new_node->Data = data;
     new_node->next = NULL;

     ST* temp = *hp;
     if(*hp == NULL)
     {
       *hp = new_node;
     }
     else
     {
       while(temp->next != 0){temp =temp->next;}
       temp->next = new_node;
     }
}

void push_data(ST** hp,int data)
{
    ST* new_node = (ST*)malloc(sizeof(ST));
    new_node->Data = data;

    new_node->next = *hp;
    *hp = new_node;
}
void print(ST* hp)
{
 while(hp != NULL) {
  printf("%d ",hp->Data);
   hp= hp->next;
  }
}
void main()
{
   ST* head_ptr = NULL;
   push_data(&head_ptr,30);
   push_data(&head_ptr,20);
   push_data(&head_ptr,10);
   append_data(&head_ptr,40);
   append_data(&head_ptr,50);
   append_data(&head_ptr,60);
   push_data(&head_ptr,0);
   push_data(&head_ptr,1);

   print(head_ptr);
   printf("\n");
   sort_list(&head_ptr);
   print(head_ptr);

}
