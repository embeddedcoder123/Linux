// @file thread4.cpp
#include <iostream>
#include <thread>
#include <vector>

int main(){

    auto lambda=[](int x){
        std::cout << "Hello from thread!" << std::this_thread::get_id() << std::endl;
        std::cout << "Argument passed in: " << x << std::endl;
    };

    std::vector<std::jthread> jthreads;
    for(int i=0; i < 10; i++){
        jthreads.push_back(std::jthread(lambda, i));
    }


    std::cout << "hello from my main thread" << std::endl;
    return 0;
}
/* 
Hello from thread!140557874837056
Argument passed in: Hello from thread!1405578580516480
Argument passed in: 2

Hello from thread!140557849658944
Argument passed in: 3
Hello from thread!140557770815040
Argument passed in: 4
Hello from thread!140557866444352
Argument passed in: 1
Hello from thread!140557762422336
Argument passed in: 5
Hello from thread!140557737244224
Argument passed in: 8
Hello from thread!140557745636928
Argument passed in: 7
Hello from thread!140557728851520
Argument passed in: 9
Hello from thread!140557754029632
Argument passed in: 6
hello from my main thread */