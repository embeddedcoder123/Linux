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

# Double Linked List

```cpp
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *prev;
    struct node *next;
} node;

node *head = NULL;

/* Create a new node */
node *create_node(int data)
{
    node *newnode = malloc(sizeof(node));

    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = NULL;

    return newnode;
}

/* Insert at the beginning */
void insert_begin(int data)
{
    node *newnode = create_node(data);

    if (newnode == NULL)
        return;

    newnode->next = head;

    if (head != NULL)
        head->prev = newnode;

    head = newnode;
}

/* Insert at the end */
void insert_end(int data)
{
    node *newnode = create_node(data);

    if (newnode == NULL)
        return;

    if (head == NULL) {
        head = newnode;
        return;
    }

    node *temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
    newnode->prev = temp;
}

/* Delete a node by value (first occurrence) */
void delete_node(int data)
{
    node *temp = head;

    while (temp != NULL && temp->data != data)
        temp = temp->next;

    if (temp == NULL) {
        printf("Node not found\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
    printf("Node deleted: %d\n", data);
}

/* Display in forward direction */
void display_forward(void)
{
    node *temp = head;

    printf("Forward: ");

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

/* Display in backward direction */
void display_backward(void)
{
    node *temp = head;

    if (temp == NULL) {
        printf("Backward: List is empty\n");
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    printf("Backward: ");

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }

    printf("\n");
}

/* Free all allocated memory */
void free_list(void)
{
    node *temp;

    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void)
{
    insert_begin(20);
    insert_begin(10);
    insert_end(30);
    insert_end(40);

    display_forward();
    display_backward();

    delete_node(30);

    display_forward();
    display_backward();

    free_list();

    return 0;
}
```
# Ring buffer
## Ring buffer in C
```c

#include <stdio.h>

enum {N=10};
int buffer[N];
int writeIndex = 0, readIndex = 0;

int is_ringFull (void) {
    return (((writeIndex + 1) % N) == readIndex);
}

int is_ringEmpty(void) {
    return (writeIndex == readIndex);
}


int put(int item){
    
    if(is_ringFull()){
        printf("Error: buffer is full...\n");
        return 0; 
    }
        
    buffer[writeIndex] = item;
    writeIndex = (writeIndex + 1) % N; 
    
    return 1;
}

int get(int * value){
    //check if buffer is empty or not
    
    if(is_ringEmpty()){
        return 0;
    }
    
    *value = buffer[readIndex];
    readIndex = (readIndex + 1) % N; 
    return 1;
}
int main() {
    // Write C code here
    int val = 100;
    while(put(val)){
        printf("added value: %d\n",val++);
    }
    int get_val;
    while(get(&get_val)){
        printf("read value: %d\n", get_val);
    }
   
    return 0;
}

```
## Ring buffer in C++
```cpp
#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

template <class T>
class circularbuffer {
    vector<T> buf;
    size_t head, tail, capacity;
    size_t count;

public:
    explicit circularbuffer(size_t cap)
        : head(0), tail(0), capacity(cap), count(0)
    {
        if (cap == 0)
            throw invalid_argument("Capacity must be greater than zero");

        buf.resize(capacity);
    }

    void push_back(const T& data) {
        buf[head] = data;
        head = (head + 1) % capacity;

        if (full()) {
            // Move tail so only latest can store
            tail = (tail + 1) % capacity;
        } else {
            count++;
        }
    }

    T pop_front() {
        if (empty())
            throw underflow_error("Buffer is empty!");

        T data = buf[tail];
        tail = (tail + 1) % capacity;
        count--;

        return data;
    }

    bool empty() const {
        return count == 0;
    }

    bool full() const {
        return count == capacity;
    }

    size_t size() const {
        return count;
    }
};

int main() {
    circularbuffer<int> cb(11);

    try {
        for (int i = 0; i < 100; i++) {
            cb.push_back(i * 10);
        }

        while (!cb.empty()) {
            cout << cb.pop_front() << endl;
        }
    }
    catch (const exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}
```
# Stack
## Stack in C
```c
#include <iostream>

using namespace std;
//Stack program
typedef struct
{
    int top;
    unsigned capacity;
    int *arr;
}Stack;

Stack* create_Stack(unsigned int capacity)
{
    Stack* top_ptr = new(Stack);
    top_ptr->top = -1;
    top_ptr->capacity = capacity;
    top_ptr->arr = (int*)calloc(capacity,sizeof(int));
    return top_ptr;
    
}
bool Is_Full(Stack* ptr)
{
    bool flag = false;
    if(ptr->top == ptr->capacity-1){
      flag = true;
    }
    return flag;
}
bool Is_Emmpty(Stack* ptr)
{
    bool flag = false;
    if(ptr->top == -1){
      flag = true;
    }
    return flag;
}
void push(Stack* ptr,int data)
{
    if(Is_Full(ptr)){
        cout<<"stack is full"<<endl;
        return;
    }
    else{
        ptr->arr[++ptr->top] = data;
        cout<<"pushed data at "<<ptr->top<<" is: "<<data<<endl;
    }
}
int pop(Stack* ptr)
{
    if(Is_Emmpty(ptr)){
        cout<<"stack is Empty"<<endl;
        return (-1);
    }
    else{
        return(ptr->arr[ptr->top--]);
    }
}
int peek(Stack* ptr)
{
    if(Is_Emmpty(ptr)){
        cout<<"stack is Empty"<<endl;
        return (-1);
    }
    else{
        return(ptr->arr[ptr->top]);
    }
}
int main() {

    Stack* stack = create_Stack(100);
    push(stack, 10);
	push(stack, 20);
	push(stack, 30);

	printf("%d popped from stack\n", pop(stack));
	printf("%d popped from stack\n", pop(stack));
	printf("%d popped from stack\n", pop(stack));
	printf("%d popped from stack\n", pop(stack));
	printf("%d popped from stack\n", pop(stack));
	push(stack, 10);
	push(stack, 20);
	push(stack, 30);
    return 0;
}
```

## Stack in C++
```cpp
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

template <class T>
class circularbuffer{
    vector<T> buf;
    int head,tail,capacity;
    
    public:
    circularbuffer(int cap){
        head = tail = 0;
        capacity = cap;
        buf.resize(capacity);
    }
    
    void push_back(T data){
        if(full()){
            cout<<"buffer is full"<<endl; return;
        }
        buf[head] = data;
        head = (head +1) % capacity;
        
        if(head == tail){
            tail = (tail+1)%capacity;
        }
    }
    
    T pop_front(){
        if(empty()){
            cout<<"buffer is empty"<<endl; 
            return -1;
        }
        T udata = buf[tail]; 
        tail = (tail+1)%capacity;
        return udata
        
        
    }
    
    bool empty(){
        return(head == tail);
    }
    
    bool full(){
        return(((head+1) % capacity) == tail);
    }
};
int main()
{
    circularbuffer<int> cb(11);
    
    for(int i=0;i<10;i++){
        cb.push_back(i*10);
        cout<<cb.pop_front()<<" ";
    }
    

    return 0;
}
```