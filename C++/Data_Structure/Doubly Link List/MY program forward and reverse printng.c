#include<stdio.h>
typedef struct node
{
    int data;
    struct node* next;
    struct node* prev;
}ST;
void pushdata (ST** hp ,int data);
void print(ST** hp);
main()
{
    ST* hp;
   // ST* Tp;
    pushdata(&hp,10);
    pushdata(&hp,20);
    pushdata(&hp,5);
    pushdata(&hp,2);
    pushdata(&hp,1);
    
    
    print(&hp);
    
}
void pushdata(ST** hp,int data)
{
    ST* NewNode = (ST*) malloc(sizeof(ST));
    NewNode->next = 0;
    NewNode->prev = 0;
    NewNode->data   = data;
    
    if((*hp) != 0) (*hp)->prev = NewNode;
    
    NewNode->next = *hp;
    
    *hp = NewNode;
}
void print(ST** hp)
{
   // ST * last;
   int count = 0;
    while(((*hp)->next != 0))
    {
        
        printf("Forward printing ");
        printf("%d  \n", (*hp)->data);
        (*hp) = (*hp)->next;
        //last = (*hp);
        count++;
    }
   printf("%d \n",count);
    while(count)
    {
        printf("Revrse printing ");
        (*hp) = (*hp)->prev;
        printf("%d  \n", (*hp)->data);
        //(*hp) = (*hp)->prev;
        count--;
    }
    
}