# Single Linked List
## Single Linked List
```c
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

void push_front (node **hp, int data) {
    node *ptr = (node*)malloc(sizeof(node));
    ptr->data = data;

    ptr->next = *hp;
    *hp = ptr;
}

void push_at(node **hp, int data, int pos) {
    node *ptr = (node*)malloc(sizeof(node));
    ptr->next = NULL;
    ptr->data = data;
    node *temp = *hp;


    if (pos == 0) {
         ptr->next = *hp;
        *hp = ptr;
    } else {
        int i = 0;
        while (i < (pos-1) && temp != NULL) {
                temp = temp->next;
                i++;
            }
             
        if (temp == NULL) {
          printf("Error: Desire node is out of range"); 
          return;
        }

        ptr->next = temp->next;
        temp->next = ptr;
    } 
}


void push_back(node **hp, int data) {
    node *ptr = (node*)malloc(sizeof(node));
    ptr->data = data;
    ptr->next = NULL;
    node *temp = *hp;

    if((*hp) != NULL) {
         while (temp->next != NULL) temp = temp->next;
    }
       
    temp->next = ptr;
}

void delete_byVal (node **hp, int val) {

    node *next = (*hp)->next;
    node *prev = *hp;

    if (prev->data == val) {
        *hp = (*hp)->next;
        free(prev);
    } else {
        while(next != NULL) {
            if(next->data == val) break;

            prev = prev->next;
            next = next->next;
        }
            if (next == NULL) {
            printf("Error: Desired node is not in list\n");
            return;
        }
        prev->next = next->next;
        free(next); 
    }
}

void delete_byPos (node **hp, int pos) {

    node *next = (*hp)->next;
    node *prev = *hp;

    if (pos == 0) {
        *hp = (*hp)->next;
        free(prev);
    } else {
        int i = 0;
        while(next != NULL && i++ < (pos-1)) {
            prev = prev->next;
            next = next->next;
        }
            if (next == NULL) {
            printf("Error: Desired node is not in list\n");
            return;
        }
        prev->next = next->next;
        free(next); 
    }
}

void delete_list (node **hp) {
    node *current = *hp;
    node *next = current->next;

    while(current) {
       next = current->next;
       free(current);
       current = next;
    }
    *hp = NULL;
}

void bubble_sort (node *hp) {
    node *temp = hp;
    node *next = temp->next;

    while(temp){
        next = temp->next;
        while (next) {
            if(temp->data > next->data) {
                int udata = temp->data ;
                temp->data = next->data;
                next->data = udata;
            }
            next = next->next;
        } 
        temp = temp->next;
    }

}


void print_list (node *ptr) {
    if (ptr == NULL) {
        printf("Linked list is empty");
        return;
    }
    while (ptr != NULL) {
        printf("%d ", ptr->data); 
        ptr = ptr->next; 
    }
    printf("\n");
}
int main () {
    node *hp = NULL;
    push_front(&hp, 10); push_front(&hp, 5);
    push_front(&hp, 12); print_list(hp); 
    push_back(&hp, 60);push_back(&hp, 80); print_list(hp); 
    push_at(&hp,100,1); print_list(hp); 
    push_at(&hp,500,5); print_list(hp);  

    delete_byVal(&hp, 100); print_list(hp);
    delete_byPos(&hp, 2); print_list(hp);
    bubble_sort(hp); print_list(hp); 
    delete_list(&hp); print_list(hp); 
    return 0;
}
```

## Remove loop

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

void remove_loop(node* hp)
{
    node *slow = hp, *fast = hp;

    // Step: 1 Detect a loop

    while (fast != NULL  && fast->next!= NULL ) {
		
		slow = slow->next;
        fast = fast->next->next;
		
        if(slow == fast) 
		    break;
    }

    // Step: 2 Not loop found 
    if (fast == NULL || fast->next == NULL) {
        printf("Loop not found\n");
        return;
    }

    slow = hp;

    if(slow == fast) { //  Loop starts at head
        while (fast->next != slow) {
            fast = fast->next;
        }

    } else {
        while (slow->next != fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
    }

    // Remove loop

    fast->next = NULL;
    printf("Loop removed successfully\n");
}

void printReverse(node* head) 
{ 
    // Base case   
    if (head == NULL) 
       return; 
  
    // print the list after head node 
    printReverse(head->next); 
  
    // After everything else is printed, print head 
    printf("%d  ", head->data); 
} 

int main () {
   


    node* head = (node*)malloc(sizeof(node*));
    node* one = (node*)malloc(sizeof(node*));
    node* second = (node*)malloc(sizeof(node*));
    node* third = (node*)malloc(sizeof(node*));
    node* fourth = (node*)malloc(sizeof(node*));
    node* fifth = (node*)malloc(sizeof(node*));
    node* sixth = (node*)malloc(sizeof(node*));
    node* seventh = (node*)malloc(sizeof(node*));

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

   remove_loop(head);
    while(head != NULL)
        {
        printf("%d -> ",head->data);
        head = head->next;
        }
    return 0;
}
```

## Single linked list in CPP

```cpp
#include<iostream>

class node
{
    public:
        int data;
        node * next = nullptr;
        node (int udata):data (udata){};
};

class SLinkedList
{
    node* hp = nullptr;
    public:
		
        SLinkedList() noexcept = default;
        
		void add_front (int udata){
           node *ptr = new node(udata);
            
			if (hp == nullptr){
            	hp = ptr;
            }
            else{
                ptr->next = hp;
                hp = ptr;
            }
        }

        void add_end (int udata){
            node *ptr = new node(udata);
            if(hp ==nullptr){
               hp = ptr;
            }
            else{
                node *temp = hp;
                while(temp->next != nullptr){ 
                    temp = temp->next;
                }
                temp->next = ptr; 
            }
        
        }
    
        void add_middle (int udata,int pos){
            if(pos == 0){
                node *ptr = new node(udata);
                ptr->next = hp;
                hp = ptr;
                return;
            }
            else{
                node *temp = hp;
                int cur_pos =0;
                while(cur_pos < (pos-1) && temp != nullptr){
                    temp = temp->next;
                    cur_pos++;
                }
                if(temp == nullptr){
                    std::cout<<"Requested position is out of range\n";
                    return;
                }
                else{
                    node* ptr = new node(udata);
                    ptr->next = temp->next;
                    temp->next = ptr;
                }
            }
        }
        
        void delete_node(int pos){
            node *temp = hp;
            int cnt =0;
            
            while(cnt <(pos -1) && temp != nullptr){
                temp = temp->next;
                cnt++;
            }
            if(temp == nullptr) {
                std::cout<<"requested position is out of range \n";
                return;
            }
            else{
                node *delete_node = temp->next;
                temp->next = temp->next->next;
                std::cout<<"node going to delete has data is:"<<delete_node->data<<std::endl;
                delete delete_node;
            }
        }
        void sort_list(){
            
            std::cout<<"sort_list is called..."<<std::endl;
            node *cur_ptr = hp;
            node *next_ptr = cur_ptr->next;
            while(cur_ptr != nullptr){
                next_ptr = cur_ptr->next;
                while(next_ptr != nullptr){
                    if(cur_ptr->data > next_ptr->data){
                        cur_ptr->data = (next_ptr->data + cur_ptr->data) - (next_ptr->data = cur_ptr->data); 
                    }
                    next_ptr = next_ptr->next;
                }
                cur_ptr = cur_ptr->next;
            }
        }
        void printList (){
        node *temp = hp;
            while(temp != nullptr){
                std::cout<<temp->data<<" ";
                temp = temp->next;
            }
        std::cout<<std::endl;
        }
};

int main (){
  SLinkedList SL;
  SL.add_front(10);
  SL.add_front(20);
  SL.add_front(30);
  SL.add_end(40);
  SL.add_end(50);
  SL.add_middle(100,0);
  SL.printList();
  
  SL.sort_list();
  SL.printList();
  
  SL.delete_node(2);
  SL.printList();
  
  
  std::cout << "End of main..." << std::endl;
  return 0;
}



```

