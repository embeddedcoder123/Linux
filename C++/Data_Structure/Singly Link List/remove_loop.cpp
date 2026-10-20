#include <stdio.h>
#include <stdlib.h>
typedef struct st 
{
    int data;
    struct st* next;
}ST;

void remove_loop(ST* head_ref)
{
    int flag;
    
    ST* ptr1 = head_ref;
    ST* ptr2 = head_ref;
    while(ptr1 != 0 || ptr2->next != 0)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next->next;
        
        if(ptr1 == ptr2)
        {
            flag =1;
            break;
        }
    }
    if(flag)
    {
        ptr1 = head_ref;
        while(ptr1->next != ptr2->next)
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        
        ptr2->next = 0;
    }
    else
    {
        printf("data strucure is not lopped\n");
    }
    
}
int main()
{
    ST* head = (ST*)malloc(sizeof(ST*));
    ST* one = (ST*)malloc(sizeof(ST*));
    ST* second = (ST*)malloc(sizeof(ST*));
    ST* third = (ST*)malloc(sizeof(ST*));
    ST* fourth = (ST*)malloc(sizeof(ST*));
    ST* fifth = (ST*)malloc(sizeof(ST*));
    ST* sixth = (ST*)malloc(sizeof(ST*));
    ST* seventh = (ST*)malloc(sizeof(ST*));
    
    head->data = 10;
    head->next = one;
    
    one->data = 20;
    one->next = second;
    
    second->data = 30;
    second->next = third;
    
    third->data = 40;
    third->next = fourth;
    
    fourth->data = 100;
    fourth->next = fifth;
    
    fifth->data = 200;
    fifth->next = sixth;
    
    sixth->data = 300;
    sixth->next = seventh;
    
    seventh->data = 400;
    seventh->next = third;
    
   // remove_loop(head);
     while(head != NULL)
     {
       printf("%d -> ",head->data);
       head = head->next;
     }
       
       
    printf("Hello World");

    return 0;
}
