// @file thread1.cpp
#include <iostream>
#include <thread>

void normal_func(int x){
  
    std::cout << __func__ << "Argument: " << x << std::endl;
}

int main(){

    std::thread myThread(normal_func, 100);
    myThread.join();

    std::cout << "hello from my main thread" << std::endl;
    return 0;
}
