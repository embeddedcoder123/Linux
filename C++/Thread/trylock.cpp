#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>

std::mutex mtx;

void job1(){
    mtx.lock();
        std::cout << "job1 is executed" << std::endl;
    mtx.unlock();
}

void job2(){
    if(mtx.try_lock()){
        std::cout << "job2 is executed" << std::endl;
        mtx.unlock();
    }else{
        using namespace std::chrono_literals;
        std::this_thread::sleep_for(5s);
        if(mtx.try_lock()){
            std::cout << "job2 exected on 2nd try\n";
            mtx.unlock();
        }
    }
}

int main(){

    std::thread thread1(job1);
    std::thread thread2(job2);

    thread1.join();
    thread2.join();

    return 0;
}
