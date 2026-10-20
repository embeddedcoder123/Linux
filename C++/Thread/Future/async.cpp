// @file async.cpp

// @file datarace.cpp
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

static int shared_value= 0;

void shared_value_increment(){
        shared_value = shared_value + 1;
}

int main(){

    std::vector<std::thread> threads;
    for(int i=0; i < 1000; i++){
        threads.push_back(std::thread(shared_value_increment));
    }

    for(int i=0; i < 1000; i++){
        threads[i].join(); 
    }

    std::cout << "Shared value:" << shared_value << std::endl;
    return 0;
}

#include <iostream>
#include <future>

int square(int x){
    return x*x;
}

int main(){

    std::future<int> asyncFunction = std::async(square,12);
    for(int i=0; i< 10; i++){
        std::cout << square(i) << std::endl;
    }

    // We are blocked at the 'get()' operation, until our
    // result has computed
    int result = asyncFunction.get();

    std::cout << "result is: " << result << std::endl;

    return 0;
}


#include <future>
#include <thread>
#include <iostream>

using namespace std;

int main()
{
    cout << "main thread id " << this_thread::get_id() << endl;

    future<int> f1 = async(launch::deferred, [](){
        cout << "future 1 run on thread " << this_thread::get_id() << endl;
        return 1;
    });

    f1.get(); 

    future<int> f2 = async(launch::async, [](){
        cout << "future 2 run on thread " << this_thread::get_id() << endl;
        return 1;
    });

    f2.get();

    future<int> f3 = async(launch::async, [](){
        cout << "future 3  run on thread " << this_thread::get_id() << endl;
        return 1;
    });

    f3.get();

    cin.ignore();

    return 0;
}
main thread id 140211453515584
future 1 run on thread 140211453515584
future 2 run on thread 140211453511232
future 3 run on thread 140211453511232