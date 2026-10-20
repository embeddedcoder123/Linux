# Thread in C++

## Normal thrad
```cpp
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
```
## thrad with lamda function

```cpp
// @file thread2.cpp
#include <iostream>
#include <thread>
int main(){

    auto lambda=[](int x){
        std::cout << "Hello from thread!" << std::endl;
        std::cout << "Argument passed in: " << x << std::endl;
    };

    std::thread myThread(lambda, 100);
    myThread.join();

    std::cout << "hello from my main thread" << std::endl;
    return 0;
}

/*
 Hello from thread!
Argument passed in: 100
hello from my main thread 
*/
```
```cpp
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
```
## Data race and atomic

### Data race
```cpp
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
```

### Atomic

```cpp
// @file atomics.cpp


#include <iostream>
#include <thread>
#include <atomic>
#include <vector>

static std::atomic<int> shared_value= 0;

void shared_value_increment(){
    shared_value+=1;
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

```
## Mutex

```cpp
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
```

## try_lock
```cpp
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
```
## condition variable

```cpp
// @file cv.cpp
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <condition_variable>

std::mutex gLock;
std::condition_variable gConditionVariable;



int main(){

    int result = 0;
    bool notified = false;

    // Reporting thread
    // Must wait on work, done by the working thread
    std::thread reporter([&]{
        std::unique_lock<std::mutex> lock(gLock);
        if(!notified){
            gConditionVariable.wait(lock);
        }
        std::cout << "Reporter, result is: " << result << std::endl;
    });

    // Working thread
    std::thread worker([&]{
        std::unique_lock<std::mutex> lock(gLock);
        // Do our work, because we have the lock
        result = 42 + 1 + 7;
        // Our work is done
        notified = true;
        std::this_thread::sleep_for(std::chrono::seconds(5));
        std::cout << "Work complete\n";
        // Wake up a thread, that is waiting, for some
        // condition to be true
        gConditionVariable.notify_one();
    });

    reporter.join();
    worker.join();

    std::cout << "Program complete" << std::endl;
    return 0;
}
```

## print odd and even number one by one
```cpp
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
```

## asyn
```cpp
// @file async.cpp
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
/*
main thread id 140211453515584
future 1 run on thread 140211453515584
future 2 run on thread 140211453511232
future 3 run on thread 140211453511232
*/
```



- `std::launch::async`    =>indicates that the function call must be run on its own (new) thread. 
					
- `std::launch::deferred` =>indicates that the function call is to be deferred until either wait() or get() is called on the future. 
- Ownership of the future can be transferred to another thread before this happens.

`std::launch::async | std::launch::deferred ` =>indicates that timplementation may choose. This is the default option (when you don't specify one yourself). 
It can decide to run synchronously.

```cpp
#include <iostream>
#include <future>
#include <thread>
#include <chrono>

bool bufferedFileLoader(){
    size_t bytesLoaded = 0;
    while(bytesLoaded < 4000){
        std::cout << "thread: loading file..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(250));
        bytesLoaded += 1000;
    }
    return true;
}

int main(){

    std::future<bool> backgroundThread = std::async(std::launch::async,
                                                    bufferedFileLoader);

    std::future_status status;
    // Our main program loop
    while(true){
        std::cout << "Main thread is running" << std::endl;
        // artificial sleep for our program
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        status = backgroundThread.wait_for(std::chrono::milliseconds(1));
        // If our data is ready, that is, our background
        // thread has completed
        if(status == std::future_status::ready){
            std::cout << "Our data is ready..." << std::endl;
            break;
        }

    }

    std::cout << "Program is complete" << std::endl;

    return 0;
}
```

## std::future

```cpp

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

```

## std::promice
```cpp
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
```
## std::shared_future

```cpp
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
```

## Lock in CPP

- Locks take care of their resource following the `RAII` idiom.  
- A lock automatically binds its mutex in the constructor and releases it in the destructor. 
- This considerably reduces the risk of a deadlock because the runtime takes care of the mutex.

- Locks are available in two flavors in `C++11`. `std::lock_guard` for the simple,  
and `std::unique-lock` for the advanced use case.

### 1. `std::lock_guard`

```c
mutex m;
m.lock();
sharedVariable= getVar();
m.unlock();
```
- With so little code, `mutex m` ensures access to the critical section s`haredVariable= getVar()` is sequential. 
- Sequential means  – in this particular case –  that each thread gains access to the critical section in order. 
- The code is simple but prone to deadlocks. Deadlock appears if the critical section throws an exception or the programmer 
- forgets to unlock the mutex. With `std::lock_guard` we can do this more elegant:

```cpp
{
  std::mutex m,
  std::lock_guard<std::mutex> lockGuard(m);
  sharedVariable= getVar();
}
```

- That was easy. But what about the opening and closing brackets? The lifetime of `std::lock_guard` is limited by the brackets
- That means its lifetime ends when it leaves the critical section. 
- At that time, the destructor of `std::lock_guard` is called, and – I guess you know it – the mutex is released. It happens automatically, and, in addition, it happens if `getVar()` in` sharedVariable = getVar() `throws an exception. Of course, function body scope or loop scope also limits the lifetime of an object.


### 2. std::unique_lock
-----------------
- `std::unique_lock` is mightier but more expansive than its small brother `std::lock_guard`.

- A std::unique_lock enables you in addition to std::lock_guard

- create it without an associated mutex
- create it without a locked associated mutex
- explicitly and repeatedly set or release the lock of the associated mutex
    1. move the mutex
    2. try to lock the mutex
    3. delayed lock the associated mutex


##### deadlock.cpp
```cpp
#include <iostream>
#include <chrono>
#include <mutex>
#include <thread>

struct CriticalData{
  std::mutex mut;
};

void deadLock(CriticalData& a, CriticalData& b){

  a.mut.lock();
  std::cout << "get the first mutex" << std::endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(1));
  b.mut.lock();
  std::cout << "get the second mutex" << std::endl;
  // do something with a and b
  a.mut.unlock();
  b.mut.unlock();
  
}

int main(){

  CriticalData c1;
  CriticalData c2;

  std::thread t1([&]{deadLock(c1,c2);});
  std::thread t2([&]{deadLock(c2,c1);});

  t1.join();
  t2.join();

}

get the first mutex
get the first mutex

```

#### deadlockResolved.cpp
```cpp
#include <iostream>
#include <chrono>
#include <mutex>
#include <thread>

struct CriticalData{
  std::mutex mut;
};

void deadLock(CriticalData& a, CriticalData& b){

  std::unique_lock<std::mutex>guard1(a.mut,std::defer_lock);
  std::cout << "Thread: " << std::this_thread::get_id() << " first mutex" <<  std::endl;

  std::this_thread::sleep_for(std::chrono::milliseconds(1));

  std::unique_lock<std::mutex>guard2(b.mut,std::defer_lock);
  std::cout << "    Thread: " << std::this_thread::get_id() << " second mutex" <<  std::endl;

  std::cout << "        Thread: " << std::this_thread::get_id() << " get both mutex" << std::endl;
  std::lock(guard1,guard2);
  // do something with a and b
}

int main(){

  std::cout << std::endl;

  CriticalData c1;
  CriticalData c2;

  std::thread t1([&]{deadLock(c1,c2);});
  std::thread t2([&]{deadLock(c2,c1);});

  t1.join();
  t2.join();

  std::cout << std::endl;

}
```
 deadlockResolved.cpp

#include <iostream>
#include <chrono>
#include <mutex>
#include <thread>

struct CriticalData{
  std::mutex mut;
};

void deadLock(CriticalData& a, CriticalData& b){

  std::unique_lock<std::mutex>guard1(a.mut,std::defer_lock);
  std::cout << "Thread: " << std::this_thread::get_id() << " first mutex" <<  std::endl;

  std::this_thread::sleep_for(std::chrono::milliseconds(1));

  std::unique_lock<std::mutex>guard2(b.mut,std::defer_lock);
  std::cout << "    Thread: " << std::this_thread::get_id() << " second mutex" <<  std::endl;

  std::cout << "        Thread: " << std::this_thread::get_id() << " get both mutex" << std::endl;
  std::lock(guard1,guard2);
  // do something with a and b
}

int main(){

  std::cout << std::endl;

  CriticalData c1;
  CriticalData c2;

  std::thread t1([&]{deadLock(c1,c2);});
  std::thread t2([&]{deadLock(c2,c1);});

  t1.join();
  t2.join();

  std::cout << std::endl;

}

Thread: 140512068126272 first mutex
Thread: 140512076518976 first mutex
Thread: 140512068126272 second mutex
Thread: 140512068126272 get both mutex
Thread: 140512076518976 second mutex
Thread: 140512076518976 get both mutex



If you call the constructor of std::unique_lock with the argument std::defer_lock, 
the lock will not be locked automatically. 
A variadic template is a template that can accept an arbitrary number of arguments. 
Here, the arguments are locks. std::lock tries to get all locks in an atomic step. So, he fails or gets all of them.

In this example, std::unique_lock takes care of the lifetime of the resources, std::lock locks the associated mutex. 
But you can do it the other way around. In the first step, you lock the mutexes; 
in the second std::unique_lock takes care of the lifetime of resources. Here is a sketch of the second approach.



std::lock_guard:
----------------
std::lock_guard is a lightweight locking mechanism in C++.
It provides exclusive ownership of a mutex for a scoped duration.
The lock is acquired upon construction and automatically released when the std::lock_guard object goes out of scope.
It does not support manual unlocking or relocking of the mutex.
Ideal for simple, short-duration locks that guarantee automatic release upon scope exit without the need for advanced features.
-------------------------------------------------------------------------------------------------------------------------------

std::unique_lock:
-----------------
std::unique_lock is a versatile locking mechanism with more features than std::lock_guard.
It supports both exclusive ownership and shared ownership of a mutex.
Allows manual unlocking, relocking, and transferring of ownership between different scopes or threads.
Provides advanced functionalities like timed locking, condition variables, and deadlock avoidance.
Offers more flexibility and control over locking behavior compared to std::lock_guard.
Suitable when you require advanced locking features, manual unlocking, or transferring ownership.
std::shared_lock:
-------------------------------------------------------------------------------------------------------------------------------

std::shared_lock 
----------------
is designed for shared ownership of a mutex, enabling multiple readers.
Allows multiple threads to acquire the lock concurrently for shared access.
Similar to std::lock_guard, it does not support manual unlocking or relocking.
Ensures thread-safety when multiple threads read shared resources.
Useful when you need to allow concurrent shared access to a resource while maintaining synchronization.
Conclusion: Choosing the appropriate locking mechanism is crucial for effective concurrency management in C++. Understanding the differences between std::lock_guard, std::unique_lock, and std::shared_lock helps determine which mechanism suits your specific requirements. Use std::lock_guard for simple exclusive locks, std::unique_lock for advanced features and flexibility, and std::shared_lock for enabling shared access. By employing the right locking mechanism, you can ensure thread-safety, prevent data races, and build efficient multi-threaded programs.

Remember to consider the specific needs of your program and choose the locking mechanism that best aligns with your synchronization
