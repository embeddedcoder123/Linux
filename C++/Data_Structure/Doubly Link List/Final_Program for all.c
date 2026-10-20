#include<stdio.h>
typedef struct node
{
    int data;
    struct node* next;
    struct node* prev;
}ST;
void pushdata (ST** hp ,int data);
void append (ST** hp ,int data);
void print(ST** hp);
void InsertBefore(ST** hp,ST* NextNode,int data);
void DeleteNode(ST** hp,ST* DelNode);
main()
{
    ST* hp;
   // ST* Tp;
    pushdata(&hp,10);
    pushdata(&hp,5);
    pushdata(&hp,2);
    pushdata(&hp,1);
    append(&hp,100);
    append(&hp,200);
    append(&hp,300);
    append(&hp,350);
    
    InsertBefore(&hp,hp->next->next,2000);
    printf("Nodes before deletation \n");
    print(&hp);
    
    
    DeleteNode(&hp,hp->next);
     printf("Nodes AFTER  deletation \n");
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
void append (ST** hp ,int data)
{
    ST* NewNode = (ST*) malloc(sizeof(ST));
  
    ST* last = (*hp);
    
    NewNode->data = data;
    
    NewNode->next = NewNode->prev = 0;
    
    
    if((*hp) == 0)
    {
        (*hp) = NewNode;
        return;
    }
    
    /*traverse last node till end*/
    while(last->next != 0)
    {
        last = last->next;
    }

    last->next = NewNode;
    NewNode->prev = last;
    
   // last = NewNode;

}

void InsertBefore(ST** hp,ST* NextNode,int data)
{
    if(NextNode == 0)
    {
        printf("Next node could not be nulll");
        return;
    }
    //Create memory for new node
    ST* NewNode = (ST*)malloc(sizeof(ST));
    NewNode->data = data;
    
    NewNode->next = NextNode;
    NewNode-> prev = NextNode->prev;
    
    NextNode->prev = NewNode;
    
    if(NewNode->prev != 0)
    {
        NewNode->prev->next = NewNode;
    }
    else
    {
        (*hp) = NewNode;
    }
}
void DeleteNode(ST** hp,ST* DelNode)
{
    
    printf("Deleted Node is %d \n", DelNode->data);
    if((*hp) == 0 || DelNode == 0)
    {
        return;
    }
    
    
    
    if((*hp) == DelNode)
    {
        (*hp) = DelNode->next;
        return;
    }
    
    if(DelNode->next != 0)
    {
        DelNode->prev->next = DelNode->next;
    }
    if(DelNode->prev != 0)
    {
        DelNode->next->prev = DelNode->prev;
    }
    free(DelNode);
}

