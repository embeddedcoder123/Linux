
#include<iostream>
#include<thread>
#include<future>
int factorial(int n){
    int i = 1;
    int res =1;
    std::cout<<"factorial thread ID: "<<std::this_thread::get_id()<<std::endl;
    while(i<(n+1) ){
        res *= i;
        i++;
    }
    //std::cout<<res<<std::endl;
    return res;
}

int main(){
    std::future<int> f = std::async(std::launch::deferred,factorial,4);
    
    int res = f.get();
    std::cout<<"result from thread: "<<res<<std::endl;

    std::cout<<"main thread ID: "<<std::this_thread::get_id()<<std::endl;
    return 0;
}

Output:
factorial thread ID: 1
result from thread: 24
main thread ID: 1 




#include<iostream>
#include<thread>
#include<future>
int factorial(int n){
    int i = 1;
    int res =1;
    std::cout<<"factorial thread ID: "<<std::this_thread::get_id()<<std::endl;
    while(i<(n+1) ){
        res *= i;
        i++;
    }
    //std::cout<<res<<std::endl;
    return res;
}

int main(){
    std::future<int> f = std::async(std::launch::async,factorial,4);
    
    int res = f.get();
    //int res1 = f.get(); it will crash the program
    std::cout<<"result from thread: "<<res<<std::endl;

    std::cout<<"main thread ID: "<<std::this_thread::get_id()<<std::endl;
    return 0;
}

Output:
factorial thread ID: 2
result from thread: 24
main thread ID: 1 

