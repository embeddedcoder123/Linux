/******************************************************************************
 print Odd and Even number concurrently

*******************************************************************************/

#include <iostream>
#include<thread>
#include<mutex>
#include<condition_variable>

using namespace std;
std::mutex m;
std::condition_variable cv;
static int num = 0;

void printEven(){
    while(num<20){
        std::unique_lock<std::mutex> ulock(m);
        std::cv.wait(ulock,[&]{
            return (num%2 == 0);
        });
        cout<<"Even: "<<num<<endl;
        num++;
        ulock.unlock();   // unlock is not mandatory it can handled by unique_lock also
        cv.notify_all();  // This is mandatory 
    }
}

void printOdd(){
    while(num<20){
        std::unique_lock<std::mutex> ulock(m);
        std::cv.wait(ulock,[&]{
            return (num%2 == 1);
        });
        std::cout<<"odd : "<<num<<endl;
        num++;
        ulock.unlock(); // unlock is not mandatory it can handled by unique_lock also
        std::cv.notify_all();
    }
}
int main()
{
    jthread th1(printEven);
    jthread th2(printOdd);

    return 0;
}
