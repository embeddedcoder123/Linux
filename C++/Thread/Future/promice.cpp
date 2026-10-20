#include<iostream>
#include<thread>
#include<future>
#include<chrono>
using namespace std;
int factorial(std::future<int> &f){
    int i = 1;
    int res =1;
    int n = f.get();
    while(i<(n+1) ){
        res *= i;
        i++;
    }
    return res;
}

int main(){
    int res;
    std::promise<int> p;
    std::future<int> fu = p.get_future();

    std::future<int> f = std::async(std::launch::async,factorial,std::ref(fu));
    /*
        parent thread need to set value to child thread but now parent doesnot has,
        but in future when it has it will sent to child thread that is promise here to child thread

    */
    // After when package is revieved Do something
    std::this_thread::sleep_for(chrono::milliseconds(500));

    p.set_value(5);  // sending value to child thread as per promise
    /*
    if data not recieved exception need to s
    p.set_exception(std::make_exception_ptr(std::runtime_error("data not recienved")));
    */
    
    res = f.get();

    std::cout<<"result: "<<res<<std::endl;

    return 0;
}