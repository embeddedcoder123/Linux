// @file thread5.cpp
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

std::mutex gLock;
static int shared_value= 0;

void shared_value_increment(){
    gLock.lock();
        shared_value = shared_value + 1;
    gLock.unlock();
}
/// @brief 
/// @return 


int main(){

    std::vector<std::thread> vthreads;
    for(int i=0; i < 1000; i++){
        vthreads.push_back(std::thread(shared_value_increment));
    }

    for(int i=0; i < 1000; i++){
        vthreads[i].join(); 
    }

    std::cout << "Shared value:" << shared_value << std::endl;
    return 0;
}
