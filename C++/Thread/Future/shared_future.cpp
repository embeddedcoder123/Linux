#include<iostream>
#include<thread>
#include<future>
#include<chrono>
using namespace std;
int factorial(std::shared_future<int> f){
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
    int res1,res2,res3,res4;
    std::promise<int> p;
    std::future<int> fu = p.get_future();

    std::shared_future<int> sf = fu.share();

    std::future<int> f1 = std::async(std::launch::async,factorial,sf);
    std::future<int> f2 = std::async(std::launch::async,factorial,sf);
    std::future<int> f3 = std::async(std::launch::async,factorial,sf);
    std::future<int> f4 = std::async(std::launch::async,factorial,sf);
    
    std::this_thread::sleep_for(chrono::milliseconds(500));

    p.set_value(5);  // sending value to all future thread here broadcast type is used

    res1 = f1.get();
    res2 = f2.get();
    res3 = f3.get();
    res4 = f4.get();

    std::cout<<"res1: "<<res1<<std::endl;
    std::cout<<"res2: "<<res2<<std::endl;
    std::cout<<"res3: "<<res3<<std::endl;
    std::cout<<"res4: "<<res4<<std::endl;
    return 0;
}