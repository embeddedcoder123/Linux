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

## async
```cpp

 // @file async.cpp
#include <iostream>
#include <future>

// Function that calculates the square of a number
int square(int x) {
    return x * x;
}

int main() {
    // Start a task using std::async to calculate square(12).
    // std::future<int> stores the result that will be available later.
    // By default, std::async may execute asynchronously or defer execution.
    std::future<int> asyncFunction = std::async(square, 12);

    // The main thread continues executing while the async task may run
    // concurrently. Calculate and print squares from 0 to 9.
    for (int i = 0; i < 10; i++) {
        std::cout << square(i) << std::endl;
    }

    // Retrieve the result of square(12).
    // If the task is still running, get() blocks until it completes.
    // Calling get() also consumes the future's shared state.
    int result = asyncFunction.get();

    // Print the result returned by the asynchronous task (144).
    std::cout << "result is: " << result << std::endl;

    return 0;
}
```
**Key point:** 
- `std::async()` schedules the task, `std::future` holds its eventual result, and `get()` waits if necessary and retrieves that result. 
- To explicitly request asynchronous execution, use `std::async(std::launch::async, square, 12)`.

### async launch policy
```cpp
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

`std::launch::async | std::launch::deferred ` =>indicates that implementation may choose. This is the default option (when you don't specify one yourself). 
It can decide to run synchronously.


### `wait_for`
```cpp
#include <iostream>
#include <future>
#include <thread>
#include <chrono>

bool bufferedFileLoader() {

    size_t bytesLoaded = 0;

    // This function runs on the background thread.
    // The main thread does NOT wait for each loading step.

    while (bytesLoaded < 4) {

        std::cout << "Background thread: loading file...\n";

        // Simulate loading data for 250 milliseconds.
        std::this_thread::sleep_for(
            std::chrono::milliseconds(250)
        );

        bytesLoaded++;
    }

    // The return value is stored in the shared state
    // associated with the future when the task completes.
    return true;
}

int main() {

    // 1. START BACKGROUND TASK
    //
    // std::launch::async requests asynchronous execution.
    // bufferedFileLoader() runs concurrently with main().
    //
    // backgroundThread represents the eventual result.
    // It does NOT contain the result immediately.

    std::future<bool> backgroundThread =
        std::async(
            std::launch::async,
            bufferedFileLoader
        );

    std::future_status status;

    // 2. MAIN THREAD CONTINUES WORKING
    while (true) {

        std::cout << "Main thread is running\n";

        // Simulate other work in the main thread.
        std::this_thread::sleep_for(
            std::chrono::milliseconds(50)
        );

        // 3. CHECK TASK COMPLETION
        //
        // wait_for(1ms) waits AT MOST 1 millisecond.
        //
        // ready   -> background task has completed.
        // timeout -> background task is still running.
        //
        // This is a synchronization operation: it checks
        // the task's completion state without waiting
        // indefinitely.

        status = backgroundThread.wait_for(
            std::chrono::milliseconds(1)
        );

        if (status == std::future_status::ready) {

            // 4. SYNCHRONIZATION POINT
            //
            // The background function has finished.
            // Its result is now available through the future.
            //
            // Completion synchronization also ensures that
            // effects of the background task happen-before
            // the successful return from wait_for().

            std::cout << "Our data is ready...\n";

            // Retrieve the result. get() returns true.
            // It can be called only once on this future.
            bool success = backgroundThread.get();

            std::cout << "Loading success: "
                      << std::boolalpha << success << '\n';

            break;
        }

        // If status is timeout, the loop repeats.
        // Main keeps working while the background task loads.
    }

    std::cout << "Program is complete\n";

    return 0;
}
```

## `std::future` with `std::launch::deferred`

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
/*
Output:
factorial thread ID: 1
result from thread: 24
main thread ID: 1 
*/

```

## `std::future` with `std::launch::async`

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
    std::future<int> f = std::async(std::launch::async,factorial,4);
    
    int res = f.get();
    //int res1 = f.get(); it will crash the program
    std::cout<<"result from thread: "<<res<<std::endl;

    std::cout<<"main thread ID: "<<std::this_thread::get_id()<<std::endl;
    return 0;
}
/*
Output:
factorial thread ID: 2
result from thread: 24
main thread ID: 1 
*/
```

## std::promice

```text
        MAIN THREAD (Parent)
                |
                | 1. Create promise<int> p
                | 2. Get future<int> fu
                |
                v
        std::async() starts
                |
                v
      BACKGROUND THREAD (Child)
                |
                | 3. fu.get()
                |    Waits for data...
                |
                |        BLOCKED
                |           |
                |           |  Main sends data
                |           v
                |    p.set_value(5)
                |           |
                |           v
                |    Receives n = 5
                |
                | 4. Calculate factorial(5)
                |    5 * 4 * 3 * 2 * 1
                |
                | 5. Return 120
                v
        future f receives result
                |
                | 6. f.get()
                v
        MAIN THREAD receives 120
```

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

    std::future<int> f = std::async(std::launch::async, factorial, std::ref(fu));
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

    std::future<int> f1 = std::async(std::launch::async, factorial, sf);
    std::future<int> f2 = std::async(std::launch::async, factorial, sf);
    std::future<int> f3 = std::async(std::launch::async, factorial, sf);
    std::future<int> f4 = std::async(std::launch::async, factorial, sf);
    
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


| Lock / Function | Prefer It When... | Example Use Case |
|---|---|---|
| `std::lock_guard` | You need simple, automatic locking for a scope. | Protecting a shared counter |
| `std::unique_lock` | You need to lock, unlock, relock, defer locking, or transfer ownership. | Waiting on a condition variable |
| `std::scoped_lock` | You need to lock multiple mutexes safely together (C++17+). | Transferring money between two accounts |
| `std::shared_lock` | Multiple threads need to read shared data simultaneously. | Reading a shared cache |
| `std::mutex::try_lock()` | You want to attempt a lock without waiting. | Skipping work if a resource is busy |
| `std::lock()` | You need to acquire multiple mutexes while avoiding the usual deadlock risk. | Coordinating two mutexes in C++11/14 |
| `std::try_lock()` | You want to try acquiring several mutexes without blocking. | Attempting a multi-resource operation |
| `std::condition_variable` + `std::unique_lock` | A thread must wait until a condition or notification occurs. | Producer-consumer queue |


### 1. `std::lock_guard`
**`std::lock_guard` — most common for simple locking**
```c
#include <mutex>
using namespace std;

mutex m;
int counter = 0;

void increment() {
    lock_guard<mutex> lock(m);
    counter++;
} // Automatically unlocks here
```
- Locks when created.

- Unlocks when the block ends.

- Cannot manually unlock it.

- Best when you need a lock for the entire block.


### 2. `std::unique_lock`
-----------------
- Can unlock and relock.

- Supports deferred locking and try-locking.

- Automatically unlocks when destroyed if it still owns the mutex.

- Best for condition variables and situations requiring flexible locking.

```cpp
#include <iostream>
#include <mutex>
#include <thread>
#include <condition_variable>
#include <chrono>
using namespace std;

mutex m1, m2;           // Normal mutexes
timed_mutex tm;         // Mutex supporting timed locking

condition_variable cv;
bool ready = false;

void work() {

    // 1. BASIC LOCK
    // Locks m1 immediately.
    // Automatically unlocks when 'lock' is destroyed.
    unique_lock<mutex> lock(m1);

    // 2. UNLOCK AND RELOCK
    lock.unlock();      // Release m1 so another thread can use it
    lock.lock();        // Acquire m1 again (waits if it is busy)

    // 3. CHECK OWNERSHIP
    // owns_lock() returns true if this object owns the mutex.
    cout << boolalpha << lock.owns_lock() << '\n'; // true

    // 4. GET THE ASSOCIATED MUTEX
    // Returns a pointer to m1; it does not lock or unlock it.
    mutex* ptr = lock.mutex();

    lock.unlock();      // Release m1 before the next example

    // 5. DEFERRED LOCKING
    // Creates a lock object without locking m1 immediately.
    unique_lock<mutex> defer(m1, defer_lock);
    // Not locked still
    defer.lock();       // Lock m1 later when needed

    defer.unlock();     // Release m1

    // 6. TRY LOCKING
    // Attempts to lock m1 once without waiting.
    unique_lock<mutex> attempt(m1, try_to_lock);

    if (attempt.owns_lock()) {
        cout << "Mutex acquired!\n";
        // Do protected work here
    } else {
        cout << "Mutex is busy!\n";
        // Do something else instead of waiting
    }
    // If acquired, attempt unlocks m1 automatically on destruction.

    // 7. ADOPT AN ALREADY-LOCKED MUTEX
    m2.lock();  // Manually lock m2 first

    // adopt_lock tells unique_lock that we already own m2.
    // Do not lock m2 again before adopting it.
    unique_lock<mutex> adopted(m2, adopt_lock);

    // adopted now manages m2 and will unlock it automatically.

    // 8. MOVE OWNERSHIP
    // Transfers ownership from adopted to moved.
    unique_lock<mutex> moved = move(adopted);

    // moved owns m2; adopted no longer owns it.
    // Do not use adopted to unlock m2.

    // 9. LOCK TWO MUTEXES SAFELY
    // defer_lock creates both lock objects without locking.
    unique_lock<mutex> a(m1, defer_lock);
    unique_lock<mutex> b(m2, defer_lock);

    // Acquires both mutexes using a deadlock-avoiding algorithm.
    lock(a, b);

    // Both mutexes are now locked.
    // a and b automatically unlock them when destroyed.

    // 10. TRY TO LOCK MULTIPLE MUTEXES
    a.unlock();
    b.unlock();

    // Attempts to acquire both locks without waiting indefinitely.
    int result = try_lock(a, b);

    if (result == -1) {
        cout << "Both mutexes acquired!\n";
        // a and b own their mutexes.
    } else {
        cout << "Could not acquire mutex index: "
             << result << '\n';
        // The failed attempt releases any locks it acquired.
    }

    // 11. TIMED LOCKING
    // timed_mutex supports try_lock_for(); ordinary mutex does not.
    unique_lock<timed_mutex> timed(tm, defer_lock);

    // Waits up to one second to acquire tm.
    if (timed.try_lock_for(chrono::seconds(1))) {
        cout << "Timed lock acquired!\n";
    } else {
        cout << "Timed lock failed!\n";
    }

    // 12. RELEASE OWNERSHIP
    // release() stops managing the mutex but DOES NOT unlock it.
    //
    // mutex* raw = lock.release();
    // raw->unlock(); // You must unlock it manually.
    //
    // Only use release() when you deliberately need manual control.

    // 13. CONDITION VARIABLE
    // Example usage (normally in a separate consumer function):
    //
     unique_lock<mutex> lk(m1);
     cv.wait(lk, [] { return ready; });
    // critical section 

      cv.notify_one();  // now critical section will be called
    // wait() temporarily unlocks m1 while waiting.
    // After notification, it reacquires m1 before returning.
    // The predicate handles spurious wakeups.

} // All remaining owned locks automatically unlock here

int main() {
    work();
    return 0;
}
```

##### deadlock.cpp
```cpp
#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

mutex m1, m2;

void thread1() {
    m1.lock();  // Thread 1 locks m1
    cout << "Thread 1 locked m1\n";

    this_thread::sleep_for(chrono::milliseconds(100));

    m2.lock();  // Waits for m2, held by Thread 2

    cout << "Thread 1 locked m2\n";

    m2.unlock();
    m1.unlock();
}

void thread2() {
    m2.lock();  // Thread 2 locks m2
    cout << "Thread 2 locked m2\n";

    this_thread::sleep_for(chrono::milliseconds(100));

    m1.lock();  // Waits for m1, held by Thread 1

    cout << "Thread 2 locked m1\n";

    m1.unlock();
    m2.unlock();
}

int main() {
    thread t1(thread1);
    thread t2(thread2);

    t1.join();
    t2.join();
}
get the first mutex
get the first mutex

```
Thread 1 -> Owns m1 -> Waits for m2
Thread 2 -> Owns m2 -> Waits for m1

#### deadlockResolved.cpp using unique_lock
```cpp
#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>
using namespace std;

mutex m1, m2;

void thread1() {
    // Create locks without locking the mutexes yet
    unique_lock<mutex> lock1(m1, defer_lock);
    unique_lock<mutex> lock2(m2, defer_lock);

    // Lock both mutexes safely without deadlock
    lock(lock1, lock2);

    cout << "Thread 1 acquired both mutexes\n";

    // Do protected work here

} // Both unique_lock objects unlock automatically

void thread2() {
    // Same locking strategy and order-independent acquisition
    unique_lock<mutex> lock1(m2, defer_lock);
    unique_lock<mutex> lock2(m1, defer_lock);

    // Safely acquire both mutexes
    lock(lock1, lock2);

    cout << "Thread 2 acquired both mutexes\n";

    // Do protected work here

} // Both unique_lock objects unlock automatically

int main() {
    thread t1(thread1);
    thread t2(thread2);

    t1.join();
    t2.join();

    return 0;
}
```
#### deadlockResolved.cpp Use std::scoped_lock (C++17)
```cpp
#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

mutex m1, m2;

void thread1() {
    scoped_lock lock(m1, m2);

    cout << "Thread 1 acquired both\n";
}

void thread2() {
    scoped_lock lock(m1, m2);

    cout << "Thread 2 acquired both\n";
}

int main() {
    thread t1(thread1);
    thread t2(thread2);

    t1.join();
    t2.join();
}
```

### 3. `std::scoped_lock` — locking multiple mutexes
```cpp
#include <mutex>
using namespace std;

mutex m1, m2;

void work() {
    scoped_lock lock(m1, m2);

    // Both mutexes are locked
} // Both unlock automatically
```

- Locks multiple mutexes together.

- Helps avoid deadlocks caused by inconsistent lock ordering.

- Available since C++17.

### 4. `std::shared_lock` — multiple readers

```cpp
#include <shared_mutex>
using namespace std;

shared_mutex m;

void readData() {
    shared_lock<shared_mutex> lock(m);
    // Multiple readers can enter together
}

void writeData() {
    unique_lock<shared_mutex> lock(m);
    // Only one exclusive owner at a time
}
```

- Multiple threads can read simultaneously.

- A writer needs exclusive access.

- Best for read-heavy applications.

### 5. try_lock() — don't wait

```cpp
if (m.try_lock()) {
    // Successfully locked
    m.unlock();
} else {
    // Someone else holds the mutex
}
```

- Returns immediately.

- Useful when your thread can do something else if the mutex is busy.

- Prefer RAII locking where possible to avoid forgetting unlock().