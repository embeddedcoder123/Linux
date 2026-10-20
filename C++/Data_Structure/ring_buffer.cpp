/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<bits/stdc++.h>
#include<exception>
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
            throw("buffer is full!");
        }
        buf[head] = data;
        head = (head +1) % capacity;
        
        if(head == tail){
            tail = (tail+1)%capacity;
        }
    }
    
    T pop_front(){
        if(empty()){
           // cout<<"buffer is empty"<<endl; 
           throw("Buffer is empty!");
        }
        T udata = buf[tail]; 
        tail = (tail+1)%capacity;
        return udata;
        
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
    try{
        for(int i=0;i<100;i++){
            cb.push_back(i*10);
            //cout<<cb.pop_front()<<"\n";
        }
        cb.pop_front();
    }
    catch(char const *e){
        cout<<e;
    }
    
    return 0;
}