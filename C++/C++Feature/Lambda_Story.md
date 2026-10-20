# C++ Lambda Evolution with Full Examples (C++03 → C++20)

---

# 1. C++03: Before Lambda

## Problem

STL algorithms require a callable object.

Example:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

struct PrintFunctor
{
    void operator()(int x) const
    {
        std::cout << x << '\n';
    }
};

int main()
{
    std::vector<int> numbers;

    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);

    std::for_each(
        numbers.begin(),
        numbers.end(),
        PrintFunctor()
    );
}
```

Output:

```
10
20
30
```

---

## Problem with This Approach

For printing only three numbers, we created a complete class.

```cpp
struct PrintFunctor
{
    void operator()(int x) const
    {
        std::cout << x;
    }
};
```

More code:

* Class declaration
* `operator()`
* Separate location

Lambda was introduced to solve this.

---

# 2. C++11: Basic Lambda

## Old Functor Style

```cpp
struct Print
{
    void operator()(int x) const
    {
        std::cout << x << '\n';
    }
};
```

---

## Lambda Style

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> numbers = {10,20,30};

    std::for_each(
        numbers.begin(),
        numbers.end(),
        [](int x)
        {
            std::cout << x << '\n';
        }
    );
}
```

Output:

```
10
20
30
```

---

## Internal Compiler Conversion

Compiler treats:

```cpp
[](int x)
{
    std::cout << x;
}
```

similar to:

```cpp
class Lambda
{
public:

    void operator()(int x) const
    {
        std::cout << x;
    }
};
```

So lambda is not magic.

It is a compiler-generated function object.

---

# 3. Lambda Capture

## Problem

Lambda cannot access local variables directly.

Example:

```cpp
#include <iostream>

int main()
{
    int multiplier = 10;

    auto multiply =
    [](int x)
    {
        return x * multiplier;
    };

    std::cout << multiply(5);
}
```

Compilation error:

```
multiplier is not captured
```

---

# Solution: Capture by Value

```cpp
#include <iostream>

int main()
{
    int multiplier = 10;

    auto multiply =
    [multiplier](int x)
    {
        return x * multiplier;
    };

    std::cout << multiply(5);
}
```

Output:

```
50
```

Lambda stores a copy:

```
Lambda object
-------------
multiplier = 10
```

---

# Capture by Reference

## Problem

Need to modify original variable.

Example:

```cpp
#include <iostream>

int main()
{
    int count = 0;

    auto increment =
    [&count]()
    {
        count++;
    };

    increment();
    increment();

    std::cout << count;
}
```

Output:

```
2
```

The lambda modifies the original variable.

---

# 4. Default Capture

## Capture Everything by Value

```cpp
#include <iostream>

int main()
{
    int a = 10;
    int b = 20;

    auto sum =
    [=]()
    {
        return a+b;
    };

    std::cout << sum();
}
```

Output:

```
30
```

---

## Capture Everything by Reference

```cpp
#include <iostream>

int main()
{
    int value = 10;

    auto change =
    [&]()
    {
        value = 100;
    };

    change();

    std::cout << value;
}
```

Output:

```
100
```

---

# 5. mutable Lambda

## Problem

Value captures are read-only.

Example:

```cpp
#include <iostream>

int main()
{
    int x = 10;

    auto change =
    [x]() // captured by value not referance
    {
        x++;
    };

    change();
}
```

Error:

```
cannot modify captured variable
```

---

## Solution

```cpp
#include <iostream>

int main()
{
    int x = 10;

    auto change =
    [x]() mutable
    {
        x++;
        std::cout << x;
    };

    change();

    std::cout << "\nOriginal x = " << x;
}
```

Output:

```
11
Original x = 10
```

Important:

Lambda changed its own copy.

---

# 6. Capturing Class Members Problem

## Wrong Code

```cpp
#include <iostream>
#include <functional>

struct Person
{
    std::string name;

    std::function<void()> getPrinter()
    {
        return [=]()
        {
            std::cout << name;
        };
    }
};


int main()
{
    auto printer =
        Person{"John"}.getPrinter();

    printer();
}
```

---

## What Happens Internally?

You wrote:

```cpp
[=]
{
    std::cout << name;
}
```

Compiler creates:

```cpp
[this]
{
    std::cout << this->name;
}
```

The lambda stores:

```
Person*
```

not:

```
std::string name
```

---

## Problem

Flow:

```
Create temporary Person
          |
          |
       getPrinter()
          |
          |
    lambda stores this pointer
          |
          |
    Person destroyed
          |
          |
    printer() called
```

Now pointer is invalid.

Result:

```
Undefined Behaviour
```

---

# 7. C++14 Init Capture

## Solution for Class Member

```cpp
#include <iostream>
#include <functional>

struct Person
{
    std::string name;


    std::function<void()> getPrinter()
    {
        return [nameCopy = name]()
        {
            std::cout << nameCopy;
        };
    }
};


int main()
{
    auto printer =
        Person{"John"}.getPrinter();

    printer();
}
```

Output:

```
John
```

Now lambda owns:

```
nameCopy
```

No dangling pointer.

---

# 8. Move Capture (C++14)

## Problem

`unique_ptr` cannot copy.

Wrong:

```cpp
std::unique_ptr<int> ptr(new int(10));

auto lambda =
[ptr]()
{
};
```

Error:

```
unique_ptr copy constructor deleted
```

---

## Solution

```cpp
#include <iostream>
#include <memory>


int main()
{
    auto ptr =
        std::make_unique<int>(100);


    auto lambda =
    [p = std::move(ptr)]()
    {
        std::cout << *p;
    };


    lambda();
}
```

Output:

```
100
```

Ownership moved into lambda.

---

# 9. Generic Lambda (C++14)

## Before

Need multiple functions:

```cpp
void print(int x);
void print(double x);
void print(std::string x);
```

---

## After

```cpp
#include <iostream>

int main()
{
    auto print =
    [](auto value)
    {
        std::cout << value << '\n';
    };


    print(10);
    print(3.14);
    print("hello");
}
```

Output:

```
10
3.14
hello
```

Compiler creates:

```cpp
template<typename T>
void operator()(T value)
```

---

# 10. constexpr Lambda (C++17)

## Purpose

Execute lambda during compilation.

Example:

```cpp
constexpr auto square =
[](int x)
{
    return x*x;
};


static_assert(square(5)==25);
```

If result is wrong:

```
Compilation error
```

---

# 11. Capture *this (C++17)

## Problem

Old:

```cpp
[this]
```

stores pointer.

---

## New

```cpp
[*this]
```

copies complete object.

Example:

```cpp
#include <iostream>


struct Data
{
    int value;


    auto get()
    {
        return [*this]()
        {
            std::cout << value;
        };
    }
};


int main()
{
    auto f =
        Data{100}.get();


    f();
}
```

Output:

```
100
```

Safe because lambda owns a copy.

---

# 12. Template Lambda (C++20)

Before:

```cpp
[](auto a)
```

Generic but limited.

---

C++20:

```cpp
#include <iostream>


int main()
{
    auto add =
    []<typename T>(T a,T b)
    {
        return a+b;
    };


    std::cout << add(10,20);

    std::cout << add(1.5,2.5);
}
```

Output:

```
30
4
```

---

# Complete Lambda Evolution

| Version | Feature          | Why Added                       |
| ------- | ---------------- | ------------------------------- |
| C++11   | Lambda           | Replace small functor classes   |
| C++11   | Capture          | Access external variables       |
| C++11   | mutable          | Modify lambda state             |
| C++14   | Init capture     | Safe ownership and move support |
| C++14   | Generic lambda   | Work with multiple types        |
| C++17   | constexpr lambda | Compile-time execution          |
| C++17   | `[*this]`        | Safe object copy                |
| C++20   | Template lambda  | Advanced generic programming    |

---

# Final Concept

Lambda evolution followed one goal:

```
Less code
    +
Safer lifetime management
    +
More generic programming
    +
Better compile-time optimization
```

Modern C++ uses lambdas everywhere:

* STL algorithms
* Threads
* Callbacks
* Ranges
* Async programming
* Functional programming
