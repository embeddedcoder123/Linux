# Top 20 Advanced C++ Interview Questions     

## 1. Explain `std::move()`. Does it actually move an object?
- No. std::move() does not actually move an object.
- `std::move()` is just a cast that converts an object into an rvalue reference, allowing move operations instead of copy operations. It does not move the object by itself.


## 2. What is the difference between `push_back()` and `emplace_back()`?
- `push_back()` inserts an object, while `emplace_back()` constructs the object directly inside the container.

## 3. Explain `lvalues`, `rvalues`, `xvalues`, `prvalues`, and `forwarding references`.
| Type                     | Meaning                                          | Example                             | Quick Trick                    |
| ------------------------ | ------------------------------------------------ | ----------------------------------- | ------------------------------ |
| **lvalue**               | Named object with memory address                 | `int x = 10;` → `x`                 | **L = Location** (has address) |
| **rvalue**               | Temporary value                                  | `x + 5`, `100`                      | **R = Ready to discard**       |
| **prvalue**              | Pure temporary value that creates an object      | `10`, `string("Hi")`                | **P = Pure temporary**         |
| **xvalue**               | Existing object whose resources can be moved     | `std::move(x)`                      | **X = eXpiring (move it)**     |
| **Forwarding Reference** | `T&&` in template that accepts lvalue and rvalue | `template<class T> void fun(T&& x)` | **T&& = Takes both**           |


## 4. What is perfect forwarding? Why do we need `std::forward()`?
> Perfect Forwarding means passing an argument to another function without changing whether it is an lvalue or rvalue
## 5. When does the compiler generate, suppress, or delete copy and move constructors?

> The compiler automatically generates copy and move constructors when possible. User-defined copy operations or destructors may suppress move generation, and constructors are automatically deleted when class members themselves cannot be copied or moved. This behavior forms the basis of the Rule of Three and Rule of Fiv
> 
## 6. Explain the Rule of Three, Rule of Five, and Rule of Zero.

| Rule | What you manage | Functions |
|---|---|---|
| **Rule of 3** | Resource manually | Destructor + Copy Constructor + Copy Assignment |
| **Rule of 5** | Resource manually + move semantics | Above 3 + Move Constructor + Move Assignment |
| **Rule of 0** | Resource managed by RAII types | Define none manually |


## 7. Why should a base class destructor be virtual? What happens if it isn't?
> A virtual destructor ensures that when an object is deleted through a base class pointer, the correct derived class destructor is called first, followed by the base destructor. This is essential for proper cleanup in polymorphic class hierarchie

### Technical Reason
- When a class contains virtual functions, objects are typically accessed through a base pointer:

```c++
Base *ptr = new Derived();
delete ptr;

// If the base destructor is not virtual:
class Base {
public:
~Base() {} // Non-virtual
};

// delete ptr calls only: 
Base::~Base()
```
- The Derived::~Derived() destructor is skipped, resulting in:
    - Resource leaks
    - File handles not closed
    - Memory not freed
    - Incomplete object destruction
    - Undefined behavior according to the C++ standard

### How Virtual Destructor Works
- When the destructor is declared virtual:
```c++
class Base {
public:
    virtual ~Base() {}
};
```
- the compiler places the destructor entry in the object's **vtable**.

During:
```c++
delete ptr;
```

- the runtime:

    - Looks up the actual object type through the vtable.
    - Calls the most-derived destructor.
    - Unwinds the inheritance chain.

- Destruction order:
```c++
Derived::~Derived()
Base::~Base()
```
## 8. Explain virtual functions, vtables, and vptrs. How does dynamic dispatch work?
## 9. Why are virtual function calls inside constructors and destructors discouraged?

- Virtual function calls inside constructors and destructors are discouraged because runtime polymorphism does not work during object construction and destruction.
-  During construction, the derived part is not yet created, and during destruction, the derived part has already been destroyed. 
-  Therefore, virtual calls resolve to the current class implementation instead of the derived implementation, which can lead to unexpected behavior.
- Ath this time `vtable` and `vptr` is not created.

## 10. What is object slicing? How can it be avoided?
## 11. What is copy elision? What are RVO and NRVO? Is copy elision mandatory in C++17?
## 12. Explain iterator invalidation rules for STL containers.
## 13. How does `std::vector` manage memory and grow its capacity internally?

`std::vector `works like a dynamic array.
- It stores elements in a continuous block of memory.
- It has
  - **Size** = number of elements currently stored.
  - **Capacity** = total space allocated.
```c++
std::vector<int> v;

v.push_back(10);
v.push_back(20);
v.push_back(30);

/*
Size = 3
Capacity = 4

When the vector becomes full:

[10][20][30][40]

v.push_back(50);
*/
```
- the vector:
    - Allocates a larger memory block (usually double the size).
    - Copies/Moves old elements to the new block.
    - Frees the old memory.
    - Inserts the new element
- Doubling the capacity reduces the number of memory allocations and makes:
``` c++ 
push_back() 
```
- very fast on average.

Important Point

After reallocation: 

```c++
int* p = &v[0]; // may become invalid because the vector has moved to a new memory location.
 ```
## 14. How does `std::shared_ptr` work internally? Why is `std::weak_ptr` needed?
## 15. What is Undefined Behavior (UB)? Give examples and explain why it is dangerous.
## 16. What is the difference between `const int*`, `int* const`, and `const int* const`?
## 17. Explain `constexpr`, `consteval`, and `constinit`. When should each be used?
## 18. Why is `nullptr` preferred over `NULL`? Explain with overload resolution.
## 19. Explain memory alignment, structure padding, and their impact on performance.

### 1. What is Memory Alignment?
- Processors access memory faster when data is stored at certain addresses.

### 2. What is Structure Padding?

- The compiler automatically inserts unused bytes (padding) inside a structure to maintain proper alignment.

### 3. How to Reduce Padding?
- Reorder members from largest to smallest.
  
```c
- Bad:
struct Test {
    char c;
    int i;
    char d;
};

// size: 12 bytes


// Better

struct Test {
    int i;
    char c;
    char d;
};

// Size 8 bytes
```
- Faster memory access
- Fewer CPU cycles
- Better cache utilization

## 20. What is RAII? Why is it considered one of the most important design principles in C++?
