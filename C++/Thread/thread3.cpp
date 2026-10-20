// @file thread3.cpp
#include <iostream>
#include <thread>
#include <vector>

int main(){

    auto lambda=[](int x){
        std::cout << "Hello from thread!" << std::this_thread::get_id() << std::endl;
        std::cout << "Argument passed in: " << x << std::endl;
    };

    std::vector<std::thread> threads;
    for(int i=0; i < 10; i++){
        threads.push_back(std::thread(lambda, i));
    }

    for(int i=0; i < 10; i++){
        threads[i].join(); 
    }

    std::cout << "hello from my main thread" << std::endl;
    return 0;
}

/*
Hello from thread!Hello from thread!Hello from thread!140595815097920140595798312512140595806705216
Argument passed in: 
Argument passed in: 0
Hello from thread!140595764741696
Argument passed in: 6
Hello from thread!140595789919808
Argument passed in: 3

Hello from thread!Argument passed in: 1
Hello from thread!140595678930496
Argument passed in: 8
2Hello from thread!140595781527104
Argument passed in: 4

Hello from thread!140595687323200
Argument passed in: 7
140595670537792
Argument passed in: 9
Hello from thread!140595773134400
Argument passed in: 5
hello from my main thread
*/