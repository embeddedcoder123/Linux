// Online C compiler to run C program online
#include <stdio.h>
enum {N=10};
int buffer[N];
int writeIndex = 0, readIndex = 0;

int put(int item){
    
    // check buffer is full or not
    if(((writeIndex + 1) % N) == readIndex){
        return 0; // buffer is full
    }
        
    buffer[writeIndex] = item;
    writeIndex = (writeIndex + 1) % N; 
    
    return 1;
}

int get(int * value){
    //check if buffer is empty or not
    
    if(writeIndex == readIndex){
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
