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

/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

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