- [C++11](#c11)
  - [C++11 Language Features](#c11-language-features)
    - [Move semantics](#move-semantics)
    - [Rvalue references](#rvalue-references)
      - [Simple rule:](#simple-rule)
    - [Forwarding references](#forwarding-references)
    - [Variadic templates](#variadic-templates)
      - [Fold Expressions (C++17+)](#fold-expressions-c17)
    - [Initializer lists](#initializer-lists)
    - [Static assertions](#static-assertions)
    - [auto](#auto)
    - [Lambda expressions](#lambda-expressions)
    - [decltype](#decltype)
    - [Type aliases](#type-aliases)
    - [nullptr](#nullptr)
    - [pending](#pending)
    - [Strongly-typed enums](#strongly-typed-enums)
    - [Attributes](#attributes)
    - [constexpr](#constexpr)
    - [Delegating constructors](#delegating-constructors)
      - [Without delegating constructors](#without-delegating-constructors)
      - [With delegating constructors](#with-delegating-constructors)
    - [User-defined literals](#user-defined-literals)
    - [Explicit virtual overrides](#explicit-virtual-overrides)
    - [Final specifier](#final-specifier)
    - [Default functions](#default-functions)
    - [Deleted functions](#deleted-functions)
    - [Range-based for loops](#range-based-for-loops)
    - [Special member functions for move semantics (Move constructor and Move assignment operator)](#special-member-functions-for-move-semantics-move-constructor-and-move-assignment-operator)
    - [Converting constructors](#converting-constructors)
    - [Explicit conversion functions](#explicit-conversion-functions)
      - [Implicit Conversion (No explicit)](#implicit-conversion-no-explicit)
      - [With explicit (C++11)](#with-explicit-c11)
    - [Inline namespaces](#inline-namespaces)
    - [Non-static data member initializers](#non-static-data-member-initializers)
    - [Right angle brackets](#right-angle-brackets)
    - [Ref-qualified member functions](#ref-qualified-member-functions)
      - [Why use them?](#why-use-them)
    - [Trailing return types](#trailing-return-types)
    - [Noexcept specifier](#noexcept-specifier)
    - [char32\_t and char16\_t](#char32_t-and-char16_t)
    - [Raw string literals](#raw-string-literals)
  - [C++11 Library Features](#c11-library-features)
    - [std::move](#stdmove)
    - [std::forward](#stdforward)
    - [std::thread](#stdthread)
    - [std::to\_string](#stdto_string)
    - [Type traits](#type-traits)
    - [Smart pointers](#smart-pointers)
    - [std::chrono](#stdchrono)
    - [Tuples](#tuples)
    - [std::tie](#stdtie)
    - [std::array](#stdarray)
    - [Unordered containers](#unordered-containers)
    - [std::make\_shared](#stdmake_shared)
    - [std::ref](#stdref)
    - [Memory model](#memory-model)
    - [std::async](#stdasync)
    - [std::begin/end](#stdbeginend)
  - [Acknowledgements](#acknowledgements)
  - [Author](#author)
  - [Content Contributors](#content-contributors)
  - [License](#license)
- [C++14](#c14)
  - [C++14 Language Features](#c14-language-features)
    - [Binary literals](#binary-literals)
    - [Return type deduction](#return-type-deduction)
    - [decltype(auto)](#decltypeauto)
    - [Relaxing constraints on constexpr functions](#relaxing-constraints-on-constexpr-functions)
    - [Variable templates](#variable-templates)
    - [\[\[deprecated\]\] attribute](#deprecated-attribute)
  - [C++14 Library Features](#c14-library-features)
    - [User-defined literals for standard library types](#user-defined-literals-for-standard-library-types)
    - [Compile-time integer sequences](#compile-time-integer-sequences)
    - [std::make\_unique](#stdmake_unique)
  - [Acknowledgements](#acknowledgements-1)
  - [Author](#author-1)
- [C++17](#c17)
  - [C++17 Language Features](#c17-language-features)
    - [Template argument deduction for class templates](#template-argument-deduction-for-class-templates)
    - [Declaring non-type template parameters with auto](#declaring-non-type-template-parameters-with-auto)
      - [What is a Non-Type Template Parameter?](#what-is-a-non-type-template-parameter)
    - [Folding expressions](#folding-expressions)
    - [New rules for auto deduction from braced-init-list](#new-rules-for-auto-deduction-from-braced-init-list)
    - [constexpr lambda](#constexpr-lambda)
    - [Lambda capture `this` by value](#lambda-capture-this-by-value)
    - [Inline variables](#inline-variables)
    - [Nested namespaces](#nested-namespaces)
    - [Structured bindings](#structured-bindings)
    - [Selection statements with initializer](#selection-statements-with-initializer)
    - [constexpr if](#constexpr-if)
    - [UTF-8 character literals](#utf-8-character-literals)
    - [Direct list initialization of enums](#direct-list-initialization-of-enums)
    - [\[\[fallthrough\]\], \[\[nodiscard\]\], \[\[maybe\_unused\]\] attributes](#fallthrough-nodiscard-maybe_unused-attributes)
    - [\_\_has\_include](#__has_include)
    - [Class Template Argument Deduction (CTAD)](#class-template-argument-deduction-ctad)
    - [What is CTAD?](#what-is-ctad)
    - [std::vector](#stdvector)
    - [**std::lock\_guard**](#stdlock_guard)
  - [C++17 Library Features](#c17-library-features)
    - [std::variant](#stdvariant)
    - [std::optional](#stdoptional)
    - [std::any](#stdany)
    - [std::string\_view](#stdstring_view)
    - [std::invoke](#stdinvoke)
      - [syntax:](#syntax)
    - [std::apply](#stdapply)
    - [std::filesystem](#stdfilesystem)
    - [std::byte](#stdbyte)
    - [Splicing for maps and sets](#splicing-for-maps-and-sets)
    - [Parallel algorithms](#parallel-algorithms)
    - [std::sample](#stdsample)
    - [std::clamp](#stdclamp)
    - [std::reduce](#stdreduce)
    - [Prefix sum algorithms](#prefix-sum-algorithms)
    - [GCD and LCM](#gcd-and-lcm)
    - [std::not\_fn](#stdnot_fn)
    - [String conversion to/from numbers](#string-conversion-tofrom-numbers)
    - [Rounding functions for chrono durations and timepoints](#rounding-functions-for-chrono-durations-and-timepoints)
  - [Acknowledgements](#acknowledgements-2)
  - [Author](#author-2)
  - [Content Contributors](#content-contributors-1)
  - [License](#license-1)
- [C++20](#c20)
  - [C++20 Language Features](#c20-language-features)
    - [Coroutines](#coroutines)
      - [Coroutine handles](#coroutine-handles)
      - [The coroutine return object](#the-coroutine-return-object)
      - [The promise object](#the-promise-object)
      - [The co\_return operator](#the-co_return-operator)
      - [The co\_return operator](#the-co_return-operator-1)
      - [Generic generator example](#generic-generator-example)
        - [Why use a Generator?](#why-use-a-generator)
        - [Real Code Example: Even Number Generator](#real-code-example-even-number-generator)
    - [Concepts](#concepts)
        - [Why Are Concepts Useful?](#why-are-concepts-useful)
        - [Without concepts:](#without-concepts)
        - [With Concepts:](#with-concepts)
          - [Example 1: Concept to check if + works](#example-1-concept-to-check-if--works)
          - [Example 2: Built-in Concept — Only integers allowed](#example-2-built-in-concept--only-integers-allowed)
          - [Example 3: Use concept with auto (shortcut)](#example-3-use-concept-with-auto-shortcut)
          - [Example 4: Custom Concept — Has size() method](#example-4-custom-concept--has-size-method)
          - [Example 5: Multiple Concepts Together](#example-5-multiple-concepts-together)
    - [Three-way comparison (Spaceship Operator)](#three-way-comparison-spaceship-operator)
    - [Template syntax for lambdas](#template-syntax-for-lambdas)
    - [Range-based for loop with initializer](#range-based-for-loop-with-initializer)
    - [\[\[likely\]\] and \[\[unlikely\]\] attributes](#likely-and-unlikely-attributes)
    - [Deprecate implicit capture of this](#deprecate-implicit-capture-of-this)
    - [Class types in non-type template parameters](#class-types-in-non-type-template-parameters)
    - [constexpr virtual functions](#constexpr-virtual-functions)
    - [explicit(bool)](#explicitbool)
    - [Immediate functions](#immediate-functions)
    - [using enum](#using-enum)
    - [Lambda capture of parameter pack](#lambda-capture-of-parameter-pack)
    - [char8\_t](#char8_t)
    - [constinit](#constinit)
    - [\_\_VA\_OPT\_\_](#__va_opt__)
  - [C++20 Library Features](#c20-library-features)
    - [Concepts library](#concepts-library)
    - [Formatting library](#formatting-library)
    - [Synchronized buffered outputstream](#synchronized-buffered-outputstream)
    - [std::span](#stdspan)
    - [Bit operations](#bit-operations)
    - [Math constants](#math-constants)
    - [std::is\_constant\_evaluated](#stdis_constant_evaluated)
    - [std::make\_shared supports arrays](#stdmake_shared-supports-arrays)
    - [starts\_with and ends\_with on strings](#starts_with-and-ends_with-on-strings)
    - [Check if associative container has element](#check-if-associative-container-has-element)
    - [std::bit\_cast](#stdbit_cast)
    - [std::midpoint](#stdmidpoint)
    - [std::to\_array](#stdto_array)
    - [std::bind\_front](#stdbind_front)
    - [Uniform container erasure](#uniform-container-erasure)
    - [Three-way comparison helpers](#three-way-comparison-helpers)
    - [std::lexicographical\_compare\_three\_way](#stdlexicographical_compare_three_way)
  - [Acknowledgements](#acknowledgements-3)
  - [Author](#author-3)
  - [Content Contributors](#content-contributors-2)
  - [License](#license-2)


# C++11

## C++11 Language Features

### Move semantics
Moving an object means to transfer ownership of some resource it manages to another object.

- The first benefit of move semantics is performance optimization. 
- When an object is about to reach the end of its lifetime, either because it's a temporary or by explicitly calling `std::move`, a move is often a cheaper way to transfer resources. 
For example, moving a `std::vector` is just copying some pointers and internal state over to the new vector -- copying would involve having to copy every single contained element in the vector, which is expensive and unnecessary if the old vector will soon be destroyed.

- Moves also make it possible for non-copyable types such as `std::unique_ptr`s ([smart pointers](#smart-pointers)) to guarantee at the language level that there is only ever one instance of a resource being managed at a time, while being able to transfer an instance between scopes.

See the sections on: [rvalue references](#rvalue-references), [special member functions for move semantics](#special-member-functions-for-move-semantics), [`std::move`](#stdmove), [`std::forward`](#stdforward), [`forwarding references`](#forwarding-references).

### Rvalue references
C++11 introduces a new reference termed the _rvalue reference_. An rvalue reference to `T`, which is a non-template type parameter (such as `int`, or a user-defined type), is created with the syntax `T&&`. Rvalue references only bind to rvalues.
- lvalue: Something you can give a name to and find in memory (you can takeits address).
- rvalue: A temporary value that doesn’t have a name or a fixed place in memory.
For example:
```c++
        int a = 5;     // 'a' is an lvalue (named thing)
        int b = a + 3; // 'a + 3' is an rvalue (temporary value)
```
Type deduction with lvalues and rvalues:
```c++
int x = 0;          // x is an object of type int; the expression 'x' is an lvalue

int& xl = x;        // xl is an lvalue reference to x; binding an lvalue reference to an lvalue is allowed

int&& xr = x;       // ERROR: x is an lvalue expression, and a non-const rvalue reference
                    // cannot bind directly to an lvalue

int&& xr2 = 0;      // OK: 0 is a prvalue (rvalue), so it can bind to an rvalue reference

// Note: although xr2 has type 'int&&', the expression 'xr2' itself is an lvalue
// because it is a named variable.

int&& xr3 = std::move(x); // OK: std::move(x) produces an xvalue, which can bind
                          // to an rvalue reference

void f(int& x) {}
void f(int&& x) {}

f(x);  // calls f(int&)
f(xl); // calls f(int&)
f(3);  // calls f(int&&)
f(std::move(x)); // calls f(int&&)

f(xr2);           // calls f(int&)
f(std::move(xr2)); // calls f(int&& x)
```

#### Simple rule:
> If it has a name, it is an lvalue (even if its type is `T&&`).
> Only unnamed values (like `0`, `temporaries`, `std::move(x)`) are rvalues.

See also: [`std::move`](#stdmove), [`std::forward`](#stdforward), [`forwarding references`](#forwarding-references).

### Forwarding references
- Also known (unofficially) as _universal references_. 
- A forwarding reference is created with the syntax `T&&` where `T` is a template type parameter, or using `auto&&`. 
This enables _perfect forwarding_: the ability to pass arguments while maintaining their value category (e.g. lvalues stay as lvalues, temporaries are forwarded as rvalues).

Forwarding references allow a reference to bind to either an lvalue or rvalue depending on the type. Forwarding references follow the rules of _reference collapsing_:
* `T& &` becomes `T&`
* `T& &&` becomes `T&`
* `T&& &` becomes `T&`
* `T&& &&` becomes `T&&`

`auto` type deduction with lvalues and rvalues:
```c++
int x = 0; // `x` is an lvalue of type `int`
auto&& al = x; // `al` is an lvalue of type `int&` -- binds to the lvalue, `x`
auto&& ar = 0; // `ar` is an lvalue of type `int&&` -- binds to the rvalue temporary, `0`
```

Template type parameter deduction with lvalues and rvalues:
```c++
// Since C++14 or later:
void f(auto&& t) {
  // ...
}

// Since C++11 or later:
template <typename T>
void f(T&& t) {
  // ...
}

#include <iostream>
#include <utility> // for std::forward

// Template function with forwarding reference
template <typename T>
void wrapper(T&& arg) {
    std::cout << "In wrapper, forwarding to process...\n";
    process(std::forward<T>(arg)); // Forward to preserve value category
}

// Overloads of process
void process(int& x) {
    std::cout << "Lvalue processed: " << x << "\n";
}

void process(int&& x) {
    std::cout << "Rvalue processed: " << x << "\n";
}

int main() {
    
int x = 0;
wrapper(0); // rvalue T is int, deduces as f(int &&) => f(int&&)
wrapper(x); // lvalue T is int&, deduces as f(int& &&) => f(int&)

int& y = x;
wrapper(y); lvalue // T is int&, deduces as f(int& &&) => f(int&)

int&& z = 0; // NOTE: `z` is an lvalue with type `int&&`.
wrapper(z); // lvalue T is int&, deduces as f(int& &&) => f(int&)
wrapper(std::move(z)); // rvalue T is int, deduces as f(int &&) => f(int&&)
    
    return 0;
}


```

See also: [`std::move`](#stdmove), [`std::forward`](#stdforward), [`rvalue references`](#rvalue-references).

### Variadic templates
In C++11, variadic templates allow you to define template functions or template classes that take a variable number of template arguments.
```c++
#include <iostream>

// Base case: when there are no arguments left
void print() {
    std::cout << "End of recursion\n";
}

// Variadic template function
template<typename T, typename... Args>
void print(T first, Args... rest) {
    std::cout << first << std::endl;  // Print first argument
    print(rest...);                   // Recursive call with remaining arguments
}

int main() {
    print(1, 2.5, "Hello", 'A');
    return 0;
}
/*
1
2.5
Hello
A
End of recursion
*/

}

```
#### Fold Expressions (C++17+)
From C++17, you can replace recursive expansion with fold expressions for cleaner code:
```c++
template<typename... Args>
auto sum(Args... args) {
    return (args + ...);  // Fold expression
```

### Initializer lists
A lightweight array-like container of elements created using a "braced list" syntax. For example, `{ 1, 2, 3 }` creates a sequences of integers, that has type `std::initializer_list<int>`. Useful as a replacement to passing a vector of objects to a function.
```c++
int sum(const std::initializer_list<int>& list) {
  int total = 0;
  for (auto& e : list) {
    total += e;
  }

  return total;
}

auto list = {1, 2, 3};
sum(list); // == 6
sum({1, 2, 3}); // == 6
sum({}); // == 0
```

### Static assertions
Assertions that are evaluated at compile-time.
```c++
constexpr int x = 0;
constexpr int y = 1;
static_assert(x == y, "x != y");
```

### auto
`auto`-typed variables are deduced by the compiler according to the type of their initializer.
```c++
auto a = 3.14; // double
auto b = 1; // int
auto& c = b; // int&
auto d = { 0 }; // std::initializer_list<int>
auto&& e = 1; // int&&
auto&& f = b; // int&
auto g = new auto(123); // int*
const auto h = 1; // const int
auto i = 1, j = 2, k = 3; // int, int, int
auto l = 1, m = true, n = 1.61; // error -- `l` deduced to be int, `m` is bool
auto o; // error -- `o` requires initializer
```

Extremely useful for readability, especially for complicated types:
```c++
std::vector<int> v = ...;
std::vector<int>::const_iterator cit = v.cbegin();
// vs.
auto cit = v.cbegin();
```

- Functions can also deduce the return type using `auto`. 
- In C++11, a return type must be specified either explicitly, or using `decltype` like so:
```c++
template <typename X, typename Y>
auto add(X x, Y y) -> decltype(x + y) {
  return x + y;
}
add(1, 2); // == 3
add(1, 2.0); // == 3.0
add(1.5, 1.5); // == 3.0
```
The trailing return type in the above example is the _declared type_ (see section on [`decltype`](#decltype)) of the expression `x + y`. For example, if `x` is an integer and `y` is a double, `decltype(x + y)` is a double. Therefore, the above function will deduce the type depending on what type the expression `x + y` yields. 
Notice that the trailing return type has access to its parameters, and `this` when appropriate.

### Lambda expressions
- A `lambda` is an unnamed function object capable of capturing variables in scope.
- It features: a _capture list_; an optional set of parameters with an optional trailing return type; and a body. 
Examples of capture lists:
* `[]` - captures nothing.
* `[=]` - capture local objects (local variables, parameters) in scope by value.
* `[&]` - capture local objects (local variables, parameters) in scope by reference.
* `[this]` - capture `this` by reference.
* `[a, &b]` - capture objects `a` by value, `b` by reference.

```c++
int x = 1;

auto getX = [=] { return x; };
getX(); // == 1

auto addX = [=](int y) { return x + y; };
addX(1); // == 2

auto getXRef = [&]() -> int& { return x; };
getXRef(); // int& to `x`
```
- By default, value-captures cannot be modified inside the lambda because the compiler-generated method is marked as `const`. 
- The `mutable` keyword allows modifying captured variables. The keyword is placed after the parameter-list (which must be present even if it is empty).
```c++
int x = 1;

auto f1 = [&x] { x = 2; }; // OK: x is a reference and modifies the original

auto f2 = [x] { x = 2; }; // ERROR: the lambda can only perform const-operations on the captured value
// vs.
auto f3 = [x]() mutable { x = 2; }; // OK: the lambda can perform any operations on the captured value
```

### decltype
`decltype` is an operator which returns the _declared type_ of an expression passed to it. cv-qualifiers and references are maintained if they are part of the expression. Examples of `decltype`:
```c++
int a = 1; // `a` is declared as type `int`
decltype(a) b = a; // `decltype(a)` is `int`
const int& c = a; // `c` is declared as type `const int&`
decltype(c) d = a; // `decltype(c)` is `const int&`
decltype(123) e = 123; // `decltype(123)` is `int`
int&& f = 1; // `f` is declared as type `int&&`
decltype(f) g = 1; // `decltype(f) is `int&&`
decltype((a)) h = g; // `decltype((a))` is int&
```
```c++
template <typename X, typename Y>
auto add(X x, Y y) -> decltype(x + y) {
  return x + y;
}
add(1, 2.0); // `decltype(x + y)` => `decltype(3.0)` => `double`
```

See also: [`decltype(auto) (C++14)`](README.md#decltypeauto).

### Type aliases
Semantically similar to using a `typedef` however, type aliases with `using` are easier to read and are compatible with templates.
```c++
template <typename T>
using Vec = std::vector<T>;
Vec<int> v; // std::vector<int>

using String = std::string;
String s {"foo"};
```

### nullptr
C++11 introduces a new null pointer type designed to replace C's `NULL` macro. `nullptr` itself is of type `std::nullptr_t` and can be implicitly converted into pointer types, and unlike `NULL`, not convertible to integral types except `bool`.
```c++
void foo(int);
void foo(char*);
foo(NULL); // error -- ambiguous
foo(nullptr); // calls foo(char*)
```

### pending

### Strongly-typed enums 
Type-safe enums that solve a variety of problems with C-style enums including: implicit conversions, inability to specify the underlying type, scope pollution.
```c++
// Specifying underlying type as `unsigned int`
enum class Color : unsigned int { Red = 0xff0000, Green = 0xff00, Blue = 0xff };
// `Red`/`Green` in `Alert` don't conflict with `Color`
enum class Alert : bool { Red, Green };
Color c = Color::Red;
```

### Attributes
Attributes provide a universal syntax over `__attribute__(...)`, `__declspec`, etc.
```c++
// `noreturn` attribute indicates `f` doesn't return.
[[ noreturn ]] void f() {
  throw "error";
}
```

### constexpr
- Constant expressions are expressions that are *possibly* evaluated by       the compiler at compile-time. 
- Only non-complex computations can be carried out in a constant expression (these rules are progressively relaxed in later versions). 
- Use the `constexpr` specifier to indicate the variable, function, etc. is a constant expression.
```c++
constexpr int square(int x) {
  return x * x;
}

int square2(int x) {
  return x * x;
}

int a = square(2);  // mov DWORD PTR [rbp-4], 4

int b = square2(2); // mov edi, 2
                    // call square2(int)
                    // mov DWORD PTR [rbp-8], eax
```
In the previous snippet, notice that the computation when calling `square` is carried out at compile-time, and then the result is embedded in the code generation, while `square2` is called at run-time.

`constexpr` values are those that the compiler can evaluate, but are not guaranteed to, at compile-time:


**`const`** = "cannot change"
**`constexpr`** = "known at compile time"

> **Every constexpr variable is const, but not every const variable is constexpr.**


```c++



const int x = 123;
constexpr const int& y = x; // error -- constexpr variable `y` must be initialized by a constant expression

constexpr int  x1 = 0;
constexpr const int& y = x1; //ok 
```

Constant expressions with classes:
```c++
struct Complex {
  constexpr Complex(double r, double i) : re{r}, im{i} { }
  constexpr double real() { return re; }
  constexpr double imag() { return im; }

private:
  double re;
  double im;
};

constexpr Complex I(0, 1);
```

### Delegating constructors
Delegating constructors in C++11 allow one constructor to call another constructor of the same class. 
This helps avoid code duplication and simplifies constructor implementations.

> **One constructor calls another constructor of the same class to avoid repeating code.**

#### Without delegating constructors
```c++
#include <iostream>
using namespace std;

class Car {
    string brand;
    int speed;

public:
    Car() : brand("Unknown"), speed(0) {}

    Car(string b) : brand(b), speed(0) {}

    Car(string b, int s) : brand(b), speed(s) {}

    void display() {
        cout << brand << " " << speed << endl;
    }
};

int main() {
    Car c1;
    Car c2("BMW");
    Car c3("Audi", 200);
}
```

#### With delegating constructors


```c++
#include <iostream>
using namespace std;

class Car {
    string brand;
    int speed;

public:
    // Delegates to the main constructor
    Car() : Car("Unknown", 0) {
        cout << "Default constructor\n";
    }

    // Delegates to the main constructor
    Car(string b) : Car(b, 0) {
        cout << "One-parameter constructor\n";
    }

    // Main constructor
    Car(string b, int s) : brand(b), speed(s) {
        cout << "Main constructor\n";
    }

    void display() {
        cout << brand << " " << speed << endl;
    }
};

int main() {
    Car c1;
    c1.display();

    Car c2("BMW");
    c2.display();

    Car c3("Audi", 200);
    c3.display();
}
/*
Main constructor
Default constructor
Unknown 0

Main constructor
One-parameter constructor
BMW 0

Main constructor
Audi 200
*/
```

```bash
# Car c1;
Car()
   │
   ▼
Car("Unknown", 0)
   │
   ▼
Initialize brand and speed

----------------------------------------

# Car c2("BMW");
Car("BMW")
    │
    ▼
Car("BMW", 0)
    │
    ▼
Initialize brand and speed

----------------------------------------

# Car c3("Audi", 200);
Car("Audi", 200)
        │
        ▼
Initialize brand and speed
```
### User-defined literals
- User-defined literals allow you to extend the language and add your own syntax. 
- To create a literal, define a `T operator "" X(...) { ... }` function that returns a type `T`, with a name `X`. 
- Note that the name of this function defines the name of the literal. Any literal names not starting with an underscore are reserved and won't be invoked. 
- There are rules on what parameters a user-defined literal function should accept, according to what type the literal is called on.

Converting Celsius to Fahrenheit:
```c++
// `unsigned long long` parameter required for integer literal.
long long operator "" _celsius(unsigned long long tempCelsius) {
  return std::llround(tempCelsius * 1.8 + 32);
}
24_celsius; // == 75
```

String to integer conversion:
```c++
// `const char*` and `std::size_t` required as parameters.
int operator "" _int(const char* str, std::size_t) {
  return std::stoi(str);
}

"123"_int; // == 123, with type `int`
```

### Explicit virtual overrides
Specifies that a virtual function overrides another virtual function. 
If the virtual function does not override a parent's virtual function, throws a compiler error.
```c++
struct A {
  virtual void foo();
  void bar();
};

struct B : A {
  void foo() override; // correct -- B::foo overrides A::foo
  void bar() override; // error -- A::bar is not virtual
  void baz() override; // error -- B::baz does not override A::baz
};
```

### Final specifier
Specifies that a virtual function cannot be overridden in a derived class or that a class cannot be inherited from.
```c++
#include <iostream>

class Base {
public:
    virtual void show() final { // Cannot be overridden
        std::cout << "Base show" << std::endl;
    }
    
    virtual void display() {
        std::cout << "Base display" << std::endl;
    }
};

class Derived : public Base {
public:
    // void show() override { // Error: show is final in Base
    //     std::cout << "Derived show" << std::endl;
    // }

    void display() override {
        std::cout << "Derived display" << std::endl;
    }
};

int main() {
    Derived d;
    d.show();    // Calls Base::show()
    d.display(); // Calls Derived::display()
    return 0;
}

```

Class cannot be inherited from.
```c++
#include <iostream>

class Base {
public:
    virtual void display() {
        std::cout << "Base display" << std::endl;
    }
};

class Derived final : public Base { // 'final' here prevents further inheritance
public:
    void display() override {
        std::cout << "Derived display" << std::endl;
    }
};

// This would be an error:
// class SubDerived : public Derived {}; // Error: cannot inherit from final class

int main() {
    Derived d;
    d.display(); // Derived display
    return 0;
}

```

### Default functions
A more elegant, efficient way to provide a default implementation of a function, such as a constructor.
```c++
struct A {
  A() = default;
  A(int x) : x{x} {}
  int x {1};
};
A a; // a.x == 1
A a2 {123}; // a.x == 123
```

With inheritance:
```c++
struct B {
  B() : x{1} {}
  int x;
};

struct C : B {
  // Calls B::B
  C() = default;
};

C c; // c.x == 1
```

### Deleted functions
A more elegant, efficient way to provide a deleted implementation of a function. Useful for preventing copies on objects.
```c++
class A {
  int x;

public:
  A(int x) : x{x} {};
  A(const A&) = delete;
  A& operator=(const A&) = delete;
};

A x {123};
A y = x; // error -- call to deleted copy constructor
y = x; // error -- operator= deleted
```

### Range-based for loops
Syntactic sugar for iterating over a container's elements.
```c++
std::array<int, 5> a {1, 2, 3, 4, 5};
for (int& x : a) x *= 2;
// a == { 2, 4, 6, 8, 10 }
```

Note the difference when using `int` as opposed to `int&`:
```c++
std::array<int, 5> a {1, 2, 3, 4, 5};
for (int x : a) x *= 2;
// a == { 1, 2, 3, 4, 5 }
```

### Special member functions for move semantics (Move constructor and Move assignment operator)
The copy constructor and copy assignment operator are called when copies are made, and with C++11's introduction of move semantics, 
there is now a move constructor and move assignment operator for moves.
```c++
#include <iostream>
#include <cstring>
#include <utility>

class MyString {
private:
    char* data;

public:
    // Constructor
    MyString(const char* str = "") {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
        std::cout << "Constructor called\n";
    }

    // Copy Constructor
    MyString(const MyString& other) {
        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);
        std::cout << "Copy Constructor called\n";
    }

    // Copy Assignment Operator
    MyString& operator=(const MyString& other) {
        std::cout << "Copy Assignment Operator called\n";

        if (this != &other) {
            delete[] data;
            data = new char[strlen(other.data) + 1];
            strcpy(data, other.data);
        }

        return *this;
    }

    // Move Constructor
    MyString(MyString&& other) noexcept {
        data = other.data;
        other.data = nullptr;
        std::cout << "Move Constructor called\n";
    }

    // Move Assignment Operator
    MyString& operator=(MyString&& other) noexcept {
        std::cout << "Move Assignment Operator called\n";

        if (this != &other) {
            delete[] data;
            data = other.data;
            other.data = nullptr;
        }

        return *this;
    }

    // Destructor
    ~MyString() {
        delete[] data;
        std::cout << "Destructor called\n";
    }

    void print() const {
        std::cout << "String: " << (data ? data : "null") << '\n';
    }
};

int main() {
    MyString a("Hello");

    // Copy constructor
    MyString b(a);

    // Copy assignment
    MyString c;
    c = a;

    // Move constructor
    MyString temp1("World");
    MyString d(std::move(temp1));

    // Move assignment
    MyString temp2("C++11");
    MyString e;
    e = std::move(temp2);

    std::cout << "\nObjects:\n";
    a.print();
    b.print();
    c.print();
    d.print();
    e.print();

    std::cout << "\nMoved-from objects:\n";
    temp1.print();
    temp2.print();

    return 0;
}

/************************
Constructor called
Copy Constructor called
Constructor called
Copy Assignment Operator called
Constructor called
Move Constructor called
Constructor called
Constructor called
Move Assignment Operator called

Objects:
String: Hello
String: Hello
String: Hello
String: World
String: C++11

Moved-from objects:
String: null
String: null

Destructor called
...
*************************/

```

### Converting constructors
A converting constructor is a constructor that can be called with a single argument, allowing implicit conversion of one type to another. 
In C++11, you have more control over them using the explicit keyword.
```c++
#include <iostream>

class MyNumber {
    int value;

public:
    // Converting constructor
    MyNumber(int v) : value(v) {
        std::cout << "Converting constructor called\n";
    }

    void print() const {
        std::cout << "Value: " << value << "\n";
    }
};

void show(MyNumber num) {
    num.print();
}

int main() {
    MyNumber a = 5;  // Implicit conversion (int → MyNumber)
    show(10);        // Implicit conversion via constructor
    return 0;
}
/*
Converting constructor called
Converting constructor called
Value: 10
*/
```

### Explicit conversion functions
In C++11, you can mark a conversion function with explicit to prevent implicit type conversions, just like with constructors.
#### Implicit Conversion (No explicit)
```c++
#include <iostream>
class MyClass {
public:
    operator int() const {  // Implicit conversion allowed
        return 123;
    }
};

void printInt(int x) {
    std::cout << "Value: " << x << "\n";
}

int main() {
    MyClass obj;
    int a = obj;        // ✅ Implicit conversion
    printInt(obj);      // ✅ Implicit conversion
}
```
#### With explicit (C++11)
```c++
#include <iostream>

class MyClass {
public:
    explicit operator int() const {  // Implicit conversion disabled
        return 456;
    }
};

void printInt(int x) {
    std::cout << "Value: " << x << "\n";
}

int main() {
    MyClass obj;
    // int a = obj;       // ❌ Error: explicit conversion required
    // printInt(obj);     // ❌ Error: explicit conversion required

    int a = static_cast<int>(obj);  // ✅ OK with explicit cast
    printInt(static_cast<int>(obj));
}

```
### Inline namespaces
- All members of an inline namespace are treated as if they were part of its parent namespace, allowing specialization of functions and easing the process of versioning. 
- This is a transitive property, if A contains B, which in turn contains C and both B and C are inline namespaces, C's members can be used as if they were on A.

```c++
namespace Program {
  namespace Version1 {
    int getVersion() { return 1; }
    bool isFirstVersion() { return true; }
  }
  inline namespace Version2 {
    int getVersion() { return 2; }
  }
}

int version {Program::getVersion()};              // Uses getVersion() from Version2
int oldVersion {Program::Version1::getVersion()}; // Uses getVersion() from Version1
bool firstVersion {Program::isFirstVersion()};    // Does not compile when Version2 is added
```

### Non-static data member initializers
Allows non-static data members to be initialized where they are declared, potentially cleaning up constructors of default initializations.

```c++
// Default initialization prior to C++11
class Human {
    Human() : age{0} {}
  private:
    unsigned age;
};
// Default initialization on C++11
class Human {
  private:
    unsigned age {0};
};
```

### Right angle brackets
C++11 is now able to infer when a series of right angle brackets is used as an operator or as a closing statement of typedef, without having to add whitespace.

```c++
typedef std::map<int, std::map <int, std::map <int, int> > > cpp98LongTypedef;
typedef std::map<int, std::map <int, std::map <int, int>>>   cpp11LongTypedef;
```

### Ref-qualified member functions
 - Reference-qualified member functions) were introduced to provide overloads based on the value category (lvalue or rvalue) of the object the method is called on.
- They allow you to write different versions of a member function depending on whether *this is an lvalue or rvalue. 
- This is especially useful for classes that manage resources or where the behavior should differ based on whether you're dealing with a temporary object.
```c++
class MyClass {
public:
    void func() &;   // Called only on lvalues
    void func() &&;  // Called only on rvalues
};
```
- void func() &; — only callable on lvalue instances (obj.func();)
- void func() &&; — only callable on rvalue instances 

#### Why use them?
They are most commonly used when:
- Returning resources (like std::move() on rvalues)
- Preventing misuse (like calling methods that invalidate the object on lvalues)
```c++
#include <iostream>
#include <string>
class MyString {
    std::string data;
public:
    MyString(std::string s) : data(std::move(s)) {}

    // Called on lvalues
    std::string& get() & {
        std::cout << "Lvalue version called\n";
        return data;
    }

    // Called on rvalues
    std::string&& get() && {
        std::cout << "Rvalue version called\n";
        return std::move(data);
    }
};

int main() {
    MyString a("Hello");

    std::string x = a.get();           // Lvalue version
    std::string y = std::move(a).get(); // Rvalue version
}
```
### Trailing return types
C++11 allows functions and lambdas an alternative syntax for specifying their return types.
```c++
int f() {
  return 123;
}
// vs.
auto f() -> int {
  return 123;
}
```
```c++
auto g = []() -> int {
  return 123;
};
```
This feature is especially useful when certain return types cannot be resolved:
```c++
// NOTE: This does not compile!
template <typename T, typename U>
decltype(a + b) add(T a, U b) {
    return a + b;
}

// Trailing return types allows this:
template <typename T, typename U>
auto add(T a, U b) -> decltype(a + b) {
    return a + b;
}
```
In C++14, [`decltype(auto) (C++14)`](README.md#decltypeauto) can be used instead.

### Noexcept specifier
The `noexcept` specifier specifies whether a function could throw exceptions. It is an improved version of `throw()`.

```c++
void func1() noexcept;        // does not throw
void func2() noexcept(true);  // does not throw
void func3() throw();         // does not throw

void func4() noexcept(false); // may throw
```

Non-throwing functions are permitted to call potentially-throwing functions. Whenever an exception is thrown and the search for a handler encounters the outermost block of a non-throwing function, the function std::terminate is called.

```c++
extern void f();  // potentially-throwing
void g() noexcept {
    f();          // valid, even if f throws
    throw 42;     // valid, effectively a call to std::terminate
}
```

### char32_t and char16_t
Provides standard types for representing UTF-8 strings.

**UTF = Unicode Transformation Format**

```c++
char32_t utf8_str[] = U"\u0123";
char16_t utf8_str[] = u"\u0123";
```

### Raw string literals
C++11 introduces a new way to declare string literals as "raw string literals". Characters issued from an escape sequence (tabs, line feeds, single backslashes, etc.) can be inputted raw while preserving formatting. This is useful, for example, to write literary text, which might contain a lot of quotes or special formatting. This can make your string literals easier to read and maintain.

A raw string literal is declared using the following syntax:
```
R"delimiter(raw_characters)delimiter"
```
where:
* `delimiter` is an optional sequence of characters made of any source character except parentheses, backslashes and spaces.
* `raw_characters` is any raw character sequence; must not contain the closing sequence `")delimiter"`.

Example:
```cpp
// msg1 and msg2 are equivalent.
const char* msg1 = "\nHello,\n\tworld!\n";
const char* msg2 = R"(
Hello,
	world!
)";
```

## C++11 Library Features

### std::move
`std::move` indicates that the object passed to it may have its resources transferred. Using objects that have been moved from should be used with care, as they can be left in an unspecified state (see: [What can I do with a moved-from object?](http://stackoverflow.com/questions/7027523/what-can-i-do-with-a-moved-from-object)).

A definition of `std::move` (performing a move is nothing more than casting to an rvalue reference):
```c++
template <typename T>
typename remove_reference<T>::type&& move(T&& arg) {
  return static_cast<typename remove_reference<T>::type&&>(arg);
}
```

Transferring `std::unique_ptr`s:
```c++
std::unique_ptr<int> p1 {new int{0}};  // in practice, use std::make_unique
std::unique_ptr<int> p2 = p1; // error -- cannot copy unique pointers
std::unique_ptr<int> p3 = std::move(p1); // move `p1` into `p3`
                                         // now unsafe to dereference object held by `p1`
```

### std::forward
Returns the arguments passed to it while maintaining their value category and cv-qualifiers. Useful for generic code and factories. Used in conjunction with [`forwarding references`](#forwarding-references).

A definition of `std::forward`:
```c++
template <typename T>
T&& forward(typename remove_reference<T>::type& arg) {
  return static_cast<T&&>(arg);
}
```

An example of a function `wrapper` which just forwards other `A` objects to a new `A` object's copy or move constructor:
```c++
struct A {
  A() = default;
  A(const A& o) { std::cout << "copied" << std::endl; }
  A(A&& o) { std::cout << "moved" << std::endl; }
};

template <typename T>
A wrapper(T&& arg) {
  return A{std::forward<T>(arg)};
}

wrapper(A{}); // moved
A a;
wrapper(a); // copied
wrapper(std::move(a)); // moved
```

See also: [`forwarding references`](#forwarding-references), [`rvalue references`](#rvalue-references).

### std::thread
The `std::thread` library provides a standard way to control threads, such as spawning and killing them. In the example below, multiple threads are spawned to do different calculations and then the program waits for all of them to finish.

```c++
void foo(bool clause) { /* do something... */ }

std::vector<std::thread> threadsVector;
threadsVector.emplace_back([]() {
  // Lambda function that will be invoked
});
threadsVector.emplace_back(foo, true);  // thread will run foo(true)
for (auto& thread : threadsVector) {
  thread.join(); // Wait for threads to finish
}
```

### std::to_string
Converts a numeric argument to a `std::string`.
```c++
std::to_string(1.2); // == "1.2"
std::to_string(123); // == "123"
```

### Type traits
Type traits defines a compile-time template-based interface to query or modify the properties of types.
```c++
static_assert(std::is_integral<int>::value);
static_assert(std::is_same<int, int>::value);
static_assert(std::is_same<std::conditional<true, int, double>::type, int>::value);
```

### Smart pointers
C++11 introduces new smart pointers: `std::unique_ptr`, `std::shared_ptr`, `std::weak_ptr`. 
`std::auto_ptr` now becomes deprecated and then eventually removed in C++17.

`std::unique_ptr` is a non-copyable, movable pointer that manages its own heap-allocated memory. 
**Note: Prefer using the `std::make_X` helper functions as opposed to using constructors. 
See the sections for [std::make_unique](https://github.com/AnthonyCalandra/modern-cpp-features/blob/master/CPP14.md#stdmake_unique) and [std::make_shared](#stdmake_shared).**
```c++
std::unique_ptr<Foo> p1 { new Foo{} };  // `p1` owns `Foo`
if (p1) {
  p1->bar();
}

{
  std::unique_ptr<Foo> p2 {std::move(p1)};  // Now `p2` owns `Foo`
  f(*p2);

  p1 = std::move(p2);  // Ownership returns to `p1` -- `p2` gets destroyed
}

if (p1) {
  p1->bar();
}
// `Foo` instance is destroyed when `p1` goes out of scope
```

A `std::shared_ptr` is a smart pointer that manages a resource that is shared across multiple owners. A shared pointer holds a _control block_ which has a few components such as the managed object and a reference counter. All control block access is thread-safe, however, manipulating the managed object itself is *not* thread-safe.
```c++
void foo(std::shared_ptr<T> t) {
  // Do something with `t`...
}

void bar(std::shared_ptr<T> t) {
  // Do something with `t`...
}

void baz(std::shared_ptr<T> t) {
  // Do something with `t`...
}

std::shared_ptr<T> p1 {new T{}};
// Perhaps these take place in another threads?
foo(p1);
bar(p1);
baz(p1);
```

### std::chrono
The chrono library contains a set of utility functions and types that deal with _durations_, _clocks_, and _time points_. One use case of this library is benchmarking code:
```c++
std::chrono::time_point<std::chrono::steady_clock> start, end;
start = std::chrono::steady_clock::now();
// Some computations...
end = std::chrono::steady_clock::now();

std::chrono::duration<double> elapsed_seconds = end - start;
double t = elapsed_seconds.count(); // t number of seconds, represented as a `double`
```

### Tuples
Tuples are a fixed-size collection of heterogeneous values. Access the elements of a `std::tuple` by unpacking using [`std::tie`](#stdtie), or using `std::get`.
```c++
// `playerProfile` has type `std::tuple<int, const char*, const char*>`.
auto playerProfile = std::make_tuple(51, "Frans Nielsen", "NYI");
std::get<0>(playerProfile); // 51
std::get<1>(playerProfile); // "Frans Nielsen"
std::get<2>(playerProfile); // "NYI"
```

### std::tie
Creates a tuple of lvalue references. Useful for unpacking `std::pair` and `std::tuple` objects. Use `std::ignore` as a placeholder for ignored values. In C++17, structured bindings should be used instead.
```c++
#include <iostream>
#include <string>
#include <tuple>
#include <map>

// Function returning multiple values using tuple
std::tuple<int, std::string, std::string> getPlayer()
{
    int id = 91;
    std::string name = "John Tavares";
    std::string team = "NYI";

    return std::make_tuple(id, name, team);
}

// Function returning pair
std::pair<std::string, std::string> getAnswer()
{
    return std::make_pair("yes", "no");
}

int main()
{
    // -------------------------------------------------
    // 1. Using std::tie with tuple
    // -------------------------------------------------

    int playerId;
    std::string playerName;
    std::string teamName;

    std::tie(playerId, playerName, teamName) = getPlayer();

    std::cout << "Player Information\n";
    std::cout << "ID     : " << playerId << "\n";
    std::cout << "Name   : " << playerName << "\n";
    std::cout << "Team   : " << teamName << "\n\n";


    // -------------------------------------------------
    // 2. Using std::ignore (ignore unwanted values)
    // -------------------------------------------------

    std::string onlyName;

    std::tie(std::ignore, onlyName, std::ignore) = getPlayer();

    std::cout << "Only Player Name: "
              << onlyName << "\n\n";


    // -------------------------------------------------
    // 3. Using std::tie with pair
    // -------------------------------------------------

    std::string yes;
    std::string no;

    std::tie(yes, no) = getAnswer();

    std::cout << "Pair Example\n";
    std::cout << "First value  : " << yes << "\n";
    std::cout << "Second value : " << no << "\n\n";


    // -------------------------------------------------
    // 4. Real example: std::map iteration
    // -------------------------------------------------

    std::map<int, std::string> players;

    players[91] = "John Tavares";
    players[97] = "Connor McDavid";
    players[8]  = "Alexander Ovechkin";


    std::cout << "Players List\n";

    for (const auto& player : players)
    {
        int jerseyNumber;
        std::string name;

        // map element is pair<int,string>
        std::tie(jerseyNumber, name) = player;

        std::cout << jerseyNumber
                  << " -> "
                  << name
                  << "\n";
    }


    // -------------------------------------------------
    // 5. Swapping values using std::tie
    // -------------------------------------------------

    int a = 10;
    int b = 20;

    std::tie(a, b) = std::make_tuple(b, a);

    std::cout << "\nAfter swap\n";
    std::cout << "a = " << a << "\n";
    std::cout << "b = " << b << "\n";


    return 0;
}

/************************
Player Information
ID     : 91
Name   : John Tavares
Team   : NYI

Only Player Name: John Tavares

Pair Example
First value  : yes
Second value : no

Players List
8 -> Alexander Ovechkin
91 -> John Tavares
97 -> Connor McDavid

After swap
a = 20
b = 10
*************************/
```

### std::array
`std::array` is a container built on top of a C-style array. Supports common container operations such as sorting.
```c++
std::array<int, 3> a = {2, 1, 3};
std::sort(a.begin(), a.end()); // a == { 1, 2, 3 }
for (int& x : a) x *= 2; // a == { 2, 4, 6 }
```

### Unordered containers
These containers maintain average constant-time complexity for search, insert, and remove operations. In order to achieve constant-time complexity, sacrifices order for speed by hashing elements into buckets. There are four unordered containers:


- An unordered container is a container that stores data using a hash table.

**The main idea:**
> It does not care about the order of elements. It only cares about finding data as fast as possible.

* `unordered_set`
* `unordered_multiset`
* `unordered_map`
* `unordered_multimap`

### std::make_shared
`std::make_shared` is the recommended way to create instances of `std::shared_ptr`s due to the following reasons:
* Avoid having to use the `new` operator.
* Prevents code repetition when specifying the underlying type the pointer shall hold.
* It provides exception-safety. Suppose we were calling a function `foo` like so:
```c++
foo(std::shared_ptr<T>{new T{}}, function_that_throws(), std::shared_ptr<T>{new T{}});
```
The compiler is free to call `new T{}`, then `function_that_throws()`, and so on... Since we have allocated data on the heap in the first construction of a `T`, we have introduced a leak here. With `std::make_shared`, we are given exception-safety:
```c++
foo(std::make_shared<T>(), function_that_throws(), std::make_shared<T>());
```
* Prevents having to do two allocations. When calling `std::shared_ptr{ new T{} }`, we have to allocate memory for `T`, then in the shared pointer we have to allocate memory for the control block within the pointer.

See the section on [smart pointers](#smart-pointers) for more information on `std::unique_ptr` and `std::shared_ptr`.

### std::ref
`std::ref(val)` is used to create object of type `std::reference_wrapper` that holds reference of val. Used in cases when usual reference passing using `&` does not compile or `&` is dropped due to type deduction. `std::cref` is similar but created reference wrapper holds a const reference to val.

```c++
// create a container to store reference of objects.
auto val = 99;
auto _ref = std::ref(val);
_ref++;
auto _cref = std::cref(val);
//_cref++; does not compile
std::vector<std::reference_wrapper<int>>vec; // vector<int&>vec does not compile
vec.push_back(_ref); // vec.push_back(&i) does not compile
cout << val << endl; // prints 100
cout << vec[0] << endl; // prints 100
cout << _cref; // prints 100
```

### Memory model
C++11 introduces a memory model for C++, which means library support for threading and atomic operations. Some of these operations include (but aren't limited to) atomic loads/stores, compare-and-swap, atomic flags, promises, futures, locks, and condition variables.

See the sections on: [std::thread](#stdthread)

### std::async
`std::async` runs the given function either asynchronously or lazily-evaluated, then returns a `std::future` which holds the result of that function call.

The first parameter is the policy which can be:
1. `std::launch::async | std::launch::deferred` It is up to the implementation whether to perform asynchronous execution or lazy evaluation.
1. `std::launch::async` Run the callable object on a new thread.
1. `std::launch::deferred` Perform lazy evaluation on the current thread.

```c++
int foo() {
  /* Do something here, then return the result. */
  return 1000;
}

auto handle = std::async(std::launch::async, foo);  // create an async task
auto result = handle.get();  // wait for the result
```

### std::begin/end
`std::begin` and `std::end` free functions were added to return begin and end iterators of a container generically. These functions also work with raw arrays which do not have `begin` and `end` member functions.

```c++
template <typename T>
int CountTwos(const T& container) {
  return std::count_if(std::begin(container), std::end(container), [](int item) {
    return item == 2;
  });
}

std::vector<int> vec = {2, 2, 43, 435, 4543, 534};
int arr[8] = {2, 43, 45, 435, 32, 32, 32, 32};
auto a = CountTwos(vec); // 2
auto b = CountTwos(arr);  // 1
```

## Acknowledgements
* [cppreference](http://en.cppreference.com/w/cpp) - especially useful for finding examples and documentation of new library features.
* [C++ Rvalue References Explained](http://web.archive.org/web/20240324121501/http://thbecker.net/articles/rvalue_references/section_01.html) - a great introduction I used to understand rvalue references, perfect forwarding, and move semantics.
* [clang](http://clang.llvm.org/cxx_status.html) and [gcc](https://gcc.gnu.org/projects/cxx-status.html)'s standards support pages. Also included here are the proposals for language/library features that I used to help find a description of, what it's meant to fix, and some examples.
* [Compiler explorer](https://godbolt.org/)
* [Scott Meyers' Effective Modern C++](https://www.amazon.com/Effective-Modern-Specific-Ways-Improve/dp/1491903996) - highly recommended book!
* [Jason Turner's C++ Weekly](https://www.youtube.com/channel/UCxHAlbZQNFU2LgEtiqd2Maw) - nice collection of C++-related videos.
* [What can I do with a moved-from object?](http://stackoverflow.com/questions/7027523/what-can-i-do-with-a-moved-from-object)
* [What are some uses of decltype(auto)?](http://stackoverflow.com/questions/24109737/what-are-some-uses-of-decltypeauto)
* And many more SO posts I'm forgetting...

## Author
Haresh Panchal

## Content Contributors
See: https://github.com/AnthonyCalandra/modern-cpp-features/graphs/contributors

## License
MIT


# C++14

## C++14 Language Features

### Binary literals
Binary literals provide a convenient way to represent a base-2 number.
It is possible to separate digits with `'`.
```c++
0b110 // == 6
0b1111'1111 // == 255
```
### Return type deduction
In C++14, functions can automatically deduce their return type, just like lambdas could in C++11.
```c++
// Deduce return type as `int`.
auto f(int i) {
 return i;
}
/*
No need to specify -> decltype(...) or write the return type manually unless you want to.
*/
```

```c++
template <typename T>
auto& f(T& t) {
  return t;
}
```
**What’s Still Not Allowed**
> C++14 does not allow auto as the return type in recursive functions without an explicit return type in certain cases: C++14 does not allow auto as the return type in recursive functions without an explicit return type in certain cases:
ckeck below example
```c++
// May not compile without a forward declaration or trailing return type
//You may need to use a trailing return type or decltype if deduction can’t resolve correctly.
auto factorial(int n) {
    return n <= 1 ? 1 : n * factorial(n - 1);
}

// Correct version

auto factorial(int n) -> int {
    return n <= 1 ? 1 : n * factorial(n - 1);
}
```


### decltype(auto)
**auto makes a copy, while decltype(auto) can keep the reference.**


- **`auto` says: "Give me the value."**
    - It copies the value.
    - While copying, it forgets const and references (`&`, `&&`).
- **`decltype(auto)` says: "Give me the exact same type."**
    - It keeps everything: `const`, `&`, and `&&`.
  
```c++
const int x = 0;
auto x1 = x; // int
decltype(auto) x2 = x; // const int

int y = 0;
int& y1 = y;
auto y2 = y1; // int
decltype(auto) y3 = y1; // int&

int&& z = 0;
auto z1 = std::move(z); // int
decltype(auto) z2 = std::move(z); // int&&
```

```c++
// Note: Especially useful for generic code!


// Return type is `int`.
auto f(const int& i) {
 return i;
}

// Return type is `const int&`.
decltype(auto) g(const int& i) {
 return i;
}
int x = 123;

static_assert(std::is_same<int, decltype(f(x))>::value == 1); 
static_assert(std::is_same<const int&, decltype(f(x))>::value == 0);

static_assert(std::is_same<const int&, decltype(g(x))>::value == 1);
```

See also: [`decltype (C++11)`](README.md#decltype).

### Relaxing constraints on constexpr functions
**C++14 relaxed the rules**
1. Multiple statements
2. Local variables
3. Conditionals and loops

**1. Multiple statements**
- C++11 A `constexpr` function could only contain a single return statement.
```c++

constexpr int square(int x)
{
    return x * x;
}

// This is valid. But below is invalid:

constexpr int square(int x)
{
    int result = x * x;   // Error
    return result;
}

/**********************
Reason:
    - Local variables were not allowed.
    - More than one executable statement was not allowed.
/**********************
```

- C++14 Now multiple statements are permitted.

```c
constexpr int square(int x)
{
    int result = x * x;
    return result;
}
// This is perfectly valid.
```

**2. Local Variables Allowed**
- C++11: You could not declare local variables inside constexpr functions.
- C++14: You can declare and initialize local variables (including mutable ones, if the function is a member function).

- C++11
```cpp
constexpr int add(int a, int b)
{
    int sum = a + b;      // Error
    return sum;
}
// Compiler error because local variables were forbidden.
```

- C++14
```cpp
constexpr int add(int a, int b)
{
    int sum = a + b;
    return sum;
}
// Now allowed.
```
**3. Loops and Conditionals**
- C++11: `for`, `while`, i`f`, etc. were not allowed.
- C++14: You can use `if`, `switch`, `for`, `while`, `do-while`, etc.
```cpp
constexpr int sum_to_n(int n) {
    int sum = 0;
    for (int i = 1; i <= n; ++i)
        sum += i;
    return sum;
}
```
**4. More Flexibility with Return Statements**
- You can now use early returns, which was not allowed in C++11.
```cpp
constexpr bool is_even(int x) {
    if (x % 2 == 0)
        return true;
    else
        return false;
}
```
**Limitations Still Present in C++14**
Even with these improvements, there are still rules:
- constexpr must be deterministic and side-effect-free) means it can not change global variable and IO operation
- Dynamic memory allocation (new, delete) is still not allowed.
- Non-constexpr function can not be called in a constexpr function.
### Variable templates
C++14 allows variables to be templated:

```c++
template<class T>
constexpr T pi = T(3.1415926535897932385);
template<class T>
constexpr T e  = T(2.7182818284590452353);
```

### [[deprecated]] attribute
C++14 introduces the `[[deprecated]]` attribute to indicate that they should not be used in new code, and compilers can warn when they are
```c++
[[deprecated]]
void old_method();
[[deprecated("Use new_method instead")]]
void legacy_method();
```

## C++14 Library Features

### User-defined literals for standard library types
New user-defined literals for standard library types, including new built-in literals for `chrono` and `basic_string`. These can be `constexpr` meaning they can be used at compile-time. Some uses for these literals include compile-time integer parsing, binary literals, and imaginary number literals.
```c++
using namespace std::chrono_literals;
auto day = 24h;
day.count(); // == 24
std::chrono::duration_cast<std::chrono::minutes>(day).count(); // == 1440
```

### Compile-time integer sequences
The class template `std::integer_sequence` represents a compile-time sequence of integers. There are a few helpers built on top:
* `std::make_integer_sequence<T, N>` - creates a sequence of `0, ..., N - 1` with type `T`.
* `std::index_sequence_for<T...>` - converts a template parameter pack into an integer sequence.

Convert an array into a tuple:
```c++
template<typename Array, std::size_t... I>
decltype(auto) a2t_impl(const Array& a, std::integer_sequence<std::size_t, I...>) {
  return std::make_tuple(a[I]...);
}

template<typename T, std::size_t N, typename Indices = std::make_index_sequence<N>>
decltype(auto) a2t(const std::array<T, N>& a) {
  return a2t_impl(a, Indices());
}
```

### std::make_unique
`std::make_unique` is the recommended way to create instances of `std::unique_ptr`s due to the following reasons:
* Avoid having to use the `new` operator.
* Prevents code repetition when specifying the underlying type the pointer shall hold.
* Most importantly, it provides exception-safety. Suppose we were calling a function `foo` like so:
```c++
foo(std::unique_ptr<T>{new T{}}, function_that_throws(), std::unique_ptr<T>{new T{}});
```
The compiler is free to call `new T{}`, then `function_that_throws()`, and so on... Since we have allocated data on the heap in the first construction of a `T`, we have introduced a leak here. With `std::make_unique`, we are given exception-safety:
```c++
foo(std::make_unique<T>(), function_that_throws(), std::make_unique<T>());
```

See the section on [smart pointers (C++11)](README.md#smart-pointers) for more information on `std::unique_ptr` and `std::shared_ptr`.

## Acknowledgements
* [cppreference](http://en.cppreference.com/w/cpp) - especially useful for finding examples and documentation of new library features.
* [C++ Rvalue References Explained](http://web.archive.org/web/20240324121501/http://thbecker.net/articles/rvalue_references/section_01.html) - a great introduction I used to understand rvalue references, perfect forwarding, and move semantics.
* [clang](http://clang.llvm.org/cxx_status.html) and [gcc](https://gcc.gnu.org/projects/cxx-status.html)'s standards support pages. Also included here are the proposals for language/library features that I used to help find a description of, what it's meant to fix, and some examples.
* [Compiler explorer](https://godbolt.org/)
* [Scott Meyers' Effective Modern C++](https://www.amazon.com/Effective-Modern-Specific-Ways-Improve/dp/1491903996) - highly recommended book!
* [Jason Turner's C++ Weekly](https://www.youtube.com/channel/UCxHAlbZQNFU2LgEtiqd2Maw) - nice collection of C++-related videos.
* [What can I do with a moved-from object?](http://stackoverflow.com/questions/7027523/what-can-i-do-with-a-moved-from-object)
* [What are some uses of decltype(auto)?](http://stackoverflow.com/questions/24109737/what-are-some-uses-of-decltypeauto)
* And many more SO posts I'm forgetting...

## Author
**Haresh Panchal**


# C++17
## C++17 Language Features

### Template argument deduction for class templates

Automatic template argument deduction much like how it's done for functions, but now including class constructors.

```c++
template <typename T = float>
struct MyContainer {
  T val;
  MyContainer() : val{} {}
  MyContainer(T val) : val{val} {}
  // ...
};
MyContainer c1 {1}; // OK MyContainer<int>
MyContainer c2; // OK MyContainer<float>
```

### Declaring non-type template parameters with auto

#### What is a Non-Type Template Parameter?

A non-type template parameter is a template parameter that represents a value rather than a type. For example:

```c++
template<int N>
void printN() {
    std::cout << N << std::endl;
}
```

**C++17 Feature: auto in Non-Type Template Parameters**
In C++17, you can now write:

```c++
#include <iostream>
template<auto N>
void print() {
    std::cout << "Value: " << N << std::endl;
}
int main() {
    print<42>();          // int
    print<3.14>();        // double
    print<'A'>();         // char
    print<true>();        // bool

    return 0;
}
```

### Folding expressions

A fold expression performs a fold of a template parameter pack over a binary operator.

* An expression of the form `(... op e)` or `(e op ...)`, where `op` is a fold-operator and `e` is an unexpanded parameter pack, are called *unary folds*.
* An expression of the form `(e1 op ... op e2)`, where `op` are fold-operators, is called a *binary fold*. Either `e1` or `e2` is an unexpanded parameter pack, but not both.

```c++
template <typename... Args>
bool logicalAnd(Args... args) {
    // Binary folding.
    return (true && ... && args);
}
bool b = true;
bool& b2 = b;
logicalAnd(b, b2, true); // == true
```

```c++
template <typename... Args>
auto sum(Args... args) {
    // Unary folding.
    return (... + args);
}
sum(1.0, 2.0f, 3); // == 6.0
```

### New rules for auto deduction from braced-init-list

Changes to `auto` deduction when used with the uniform initialization syntax. Previously, `auto x {3};` deduces a `std::initializer_list<int>`, which now deduces to `int`.

```c++
auto x1 {1, 2, 3}; // error: not a single element
auto x2 = {1, 2, 3}; // x2 is std::initializer_list<int>
auto x3 {3}; // x3 is int
auto x4 {3.0}; // x4 is double
```

### constexpr lambda

Compile-time lambdas using `constexpr`.

```c++
auto identity = [](int n) constexpr { return n; };
static_assert(identity(123) == 123);
```

```c++
constexpr auto add = [](int x, int y) {
  auto L = [=] { return x; };
  auto R = [=] { return y; };
  return [=] { return L() + R(); };
};

static_assert(add(1, 2)() == 3);
```

```c++
constexpr int addOne(int n) {
  return [n] { return n + 1; }();
}

static_assert(addOne(1) == 2);
```

### Lambda capture `this` by value

Capturing `this` in a lambda's environment was previously reference-only. An example of where this is problematic is asynchronous code using callbacks that require an object to be available, potentially past its lifetime. `*this` (C++17) will now make a copy of the current object, while `this` (C++11) continues to capture by reference.

```c++
struct MyObj {
  int value {123};
  auto getValueCopy() {
    return [*this] { return value; };
  }
  auto getValueRef() {
    return [this] { return value; };
  }
};
MyObj mo;
auto valueCopy = mo.getValueCopy();
auto valueRef = mo.getValueRef();
mo.value = 321;
valueCopy(); // 123
valueRef(); // 321
```

### Inline variables

The inline specifier can be applied to variables as well as to functions. A variable declared inline has the same semantics as a function declared inline.

```c++
// Disassembly example using compiler explorer.
struct S { int x; };
inline S x1 = S{321}; // mov esi, dword ptr [x1]
                      // x1: .long 321

S x2 = S{123};        // mov eax, dword ptr [.L_ZZ4mainE2x2]
                      // mov dword ptr [rbp - 8], eax
                      // .L_ZZ4mainE2x2: .long 123
```

It can also be used to declare and define a static member variable, such that it does not need to be initialized in the source file.

```c++
struct S {
  S() : id{count++} {}
  ~S() { count--; }
  int id;
  static inline int count{0}; // declare and initialize count to 0 within the class
};
```

### Nested namespaces

Using the namespace resolution operator to create nested namespace definitions.

```c++
namespace A {
  namespace B {
    namespace C {
      int i;
    }
  }
}
```

The code above can be written like this:

```c++
namespace A::B::C {
  int i;
}
```

### Structured bindings

**What are structured bindings?**
Instead of accessing elements via .first, .second, or .get<>(), you can declare multiple variables at once that correspond to parts of a compound object.

1. Iterating over a map with structured bindings

```c++
#include <iostream>
#include <map>
int main() {
    std::map<int, std::string> myMap = {
        {1, "one"},
        {2, "two"},
        {3, "three"}
    };

    for (const auto& [key, value] : myMap) {
        std::cout << key << " -> " << value << std::endl;
    }
    return 0;
}

```

2. Structured bindings with std::pair
```c++
#include <iostream>
#include <utility>

int main() {
    std::pair<int, std::string> p = {1, "hello"};

    auto [num, text] = p;  // Unpack pair into num and text

    std::cout << num << " " << text << std::endl;  // Output: 1 hello
}
```

3. Structured bindings with std::tuple

```c++
#include <iostream>
#include <tuple>

int main() {
    std::tuple<int, double, std::string> t = {1, 3.14, "pi"};

    auto [i, d, s] = t;

    std::cout << i << ", " << d << ", " << s << std::endl;  // Output: 1, 3.14, pi
}
```

4. Structured bindings with array

```c++
int arr[3] = {10, 20, 30};
auto [x, y, z] = arr;
```

5. Structured bindings with struct

```c++
struct Point {
    int x;
    int y;
};

Point pt{5, 10};
auto [a, b] = pt;
std::cout << a << ", " << b << std::endl;  // Output: 5, 10
```
### Selection statements with initializer
New versions of the `if` and `switch` statements which simplify common code patterns and help users keep scopes tight.
```c++
{
  std::lock_guard<std::mutex> lk(mx);
  if (v.empty()) v.push_back(val);
}
// vs.
if (std::lock_guard<std::mutex> lk(mx); v.empty()) {
  v.push_back(val);
}
```

```c++
Foo gadget(args);
switch (auto s = gadget.status()) {
  case OK: gadget.zip(); break;
  case Bad: throw BadFoo(s.message());
}
// vs.
switch (Foo gadget(args); auto s = gadget.status()) {
  case OK: gadget.zip(); break;
  case Bad: throw BadFoo(s.message());
}
```

### constexpr if

Write code that is instantiated depending on a compile-time condition.

```c++
template <typename T>
constexpr bool isIntegral() {
  if constexpr (std::is_integral<T>::value) {
    return true;
  } else {
    return false;
  }
}
static_assert(isIntegral<int>() == true);
static_assert(isIntegral<char>() == true);
static_assert(isIntegral<double>() == false);
struct S {};
static_assert(isIntegral<S>() == false);
```

### UTF-8 character literals

A character literal that begins with `u8` is a character literal of type `char`. The value of a UTF-8 character literal is equal to its ISO 10646 code point value.
This if some special character

```c++
char x = u8'x';
```

### Direct list initialization of enums

Enums can now be initialized using braced syntax.

```c++
enum byte : unsigned char {};
byte b {0}; // OK
byte c {-1}; // ERROR
byte d = byte{1}; // OK
byte e = byte{256}; // ERROR
```

### [[fallthrough]], [[nodiscard]], [[maybe\_unused]] attributes

C++17 introduces three new attributes: `[[fallthrough]]`, `[[nodiscard]]` and `[[maybe_unused]]`.

* `[[fallthrough]]` indicates that in switch statement to tell the compiler and readers that you're intentionally letting execution fall through from one case to another without a break.

This helps avoid warnings and makes your code clearer.

```c++
switch (n) {
  case 1:
    // ...
    [[fallthrough]];
  case 2:
    // ...
    break;
  case 3:
    // ...
    [[fallthrough]];
  default:
    // ...
}
```

* `[[nodiscard]]` tells the compiler: "If someone calls this function and ignores the return value, give a warning.”
  It's a way to help prevent bugs by making sure important results aren't accidentally ignored..

**Why use it?**
Sometimes, ignoring a return value is dangerous. For example:

* A function returns true or false to tell you if something succeeded.
* You ignore it and assume it worked — bad idea.

```c++
[[nodiscard]] bool do_something() {
  return is_success; // true for success, false for failure
}

do_something(); // warning: ignoring return value of 'bool do_something()',
                // declared with attribute 'nodiscard'
```

```c++
// Only issues a warning when `error_info` is returned by value.
struct [[nodiscard]] error_info {
  // ...
};

error_info do_something() {
  error_info ei;
  // ...
  return ei;
}

do_something(); // warning: ignoring returned value of type 'error_info',
                // declared with attribute 'nodiscard'
```
```c++

* `[[maybe_unused]]` indicates to the compiler that a variable or parameter might be unused and is intended.

```c++
void my_callback(std::string msg, [[maybe_unused]] bool error) {
  // Don't care if `msg` is an error message, just log it.
  log(msg);
}
```

### \_\_has\_include

` What is \_\_has\_include?
\_\_has\_include is a preprocessor feature in C++17.
It lets you check if a header file exists before including it.

It's super useful when your code might run in different environments or with different libraries.

One use case of this would be using two libraries that work the same way, using the backup/experimental one if the preferred one is not found on the system.

```c++
#if __has_include(<header>)
    #include <header>
#endif

```

### Class Template Argument Deduction (CTAD)

### What is CTAD?

Normally, when creating an object of a class template, you must specify the template type:

### std::vector

```cpp
std::vector<int> v{1, 2, 3};
```
With **CTAD (introduced in C++17)**, the compiler can figure out the template type from the constructor arguments:

```cpp
std::vector v{1, 2, 3};
```

### **std::lock_guard**

- Before CTAD:

```cpp
std::mutex mtx;

std::lock_guard<std::mutex> lock(mtx);
```

- With CTAD:

```cpp
std::mutex mtx;

auto lock = std::lock_guard{mtx};
```

## C++17 Library Features

### std::variant

* std::variant : is a type-safe union that can hold a value from a fixed set of
  types.
* It's part of the  header and is useful when a variable might
  hold different types at different times, similar to a tagged union or a
  discriminated union.

**Why use std::variant?** :

* Type safety: Unlike traditional unions, std::variant
* ensures that only one of the specified types is held, and type checking is
  enforced at compile time.

Alternatives: Replaces unsafe union or complex class hierarchies when
polymorphism isn’t necessary.

```c++
#include <iostream>
#include <string>
#include <variant>

int main() {
    std::variant<int, float, std::string> v;
    v = 42;  // holds int
    std::cout << std::get<int>(v) << "\n";

    v = 3.14f;  // holds float
    std::cout << std::get<float>(v) << "\n";

    v = "hello";  // holds std::string
    std::cout << std::get<std::string>(v) << "\n";

    // Accessing Wrong Type : Accessing the wrong type with std::get throws
    // std::bad_variant_access:
    try {
        std::cout << std::get<int>(
            v);  // if v doesn't hold int now its hold string
    } catch (const std::bad_variant_access& e) {
        std::cerr << "Wrong type access!\n";
    }

    // Checking the Held Type
    if (std::holds_alternative<std::string>(v)) {
        std::cout << "v holds string\n";
    }
    // std::visit applies a visitor (functor or lambda) to the value inside the
    // variant:
    auto visitor = [](auto&& arg) { std::cout << "Value: " << arg << '\n'; };

    std::visit(visitor, v);

    return 0;
}
/*
Program stdout
42
3.14
hello
v holds string
Value: hello
Program stderr
Wrong type access!
*/
```

### std::optional

* std::option : is a utility type that represents a value that may or may not be present — similar to Nullable in other languages.
* It's part of the <optional> header and is useful for returning values from functions that may fail or be undefined, without needing special sentinel values or exceptions.

```c++
#include <iostream>
#include <optional>
#include <string>

std::optional<std::string> getName(bool valid) {
    if (valid) {
        return "Alice";
    } else {
        return std::nullopt;  // indicates no value
    }
}

int main() {
    auto name = getName(false);
    if (name) {
        std::cout << "Name: " << *name << "\n";
    } else {
        std::cout << "No name available\n";
    }

    // Accessing

    std::optional<int> x;
    try {
        std::cout << x.value();
    } catch (std::bad_optional_access) {
        std::cerr << "x is not initiated\n";
    }
    std::optional<std::string> str("Yeh dil mange more!");

    std::cout << "first method: " << *str << "\nsecond Methods: " << str.value()
              << std::endl;
}
/*
Program stdout
No name available
first method: Yeh dil mange more!
second Methods: Yeh dil mange more!
Program stderr
x is not initiated
*/
```

### std::any

* std::any is a type-safe container for single values of any copyable type.
* It's part of <any> header and allows storing and retrieving a value without knowing its type at compile time, unlike std::variant (which is limited to a known set of types).

| Function              | Meaning                                                      | Example                   |
| --------------------- | ------------------------------------------------------------ | ------------------------- |
| `std::any_cast<T>(a)` | Retrieves the stored value as type `T`                       | `std::any_cast<int>(a)`   |
| `a.has_value()`       | Checks whether `std::any` currently contains a value         | `if (a.has_value())`      |
| `a.reset()`           | Removes the stored value, making the `any` empty             | `a.reset()`               |
| `a.type()`            | Returns information about the stored type (`std::type_info`) | `a.type() == typeid(int)` |


```cpp
#include <any>
#include <iostream>
#include <string>

int main() {
    std::any a;

    a = 42;
    std::cout << std::any_cast<int>(a) << "\n";

    a = std::string("Hello");
    std::cout << std::any_cast<std::string>(a) << "\n";

    a = 3.14;
    try {
        std::cout << std::any_cast<int>(a);  // wrong type!
    } catch (const std::bad_any_cast& e) {
        std::cerr << "Bad any_cast: " << e.what() << '\n';
    }

    a = 100;
    if (a.type() == typeid(int)) {
        std::cout << "a holds an int: " << std::any_cast<int>(a) << '\n';
    }

    return 0;
}
/*
Program stdout
42
Hello
a holds an int: 100
Program stderr
Bad any_cast: bad any_cast
*/
```

### std::string\_view

* std::string\_view : is a non-owning, lightweight view over a string (i.e. a contiguous sequence of characters).
* It does not allocate memory and is designed for performance when you just need to read from a string without modifying or copying it.
* It's part of <string\_view> header.

```c++
#include <iostream>
#include <string_view>

// Much better than overloading for const char* and const std::string&.
void print(std::string_view sv) { std::cout << "String: " << sv << "\n"; }
int main() {
    std::string str = "Hello, world!";
    print(str);                    // From std::string
    print("Hello, string_view!");  // From C-string

    std::string_view sv = "example text";

    // Length
    std::cout << sv.size() << std::endl;  // 12

    // Access character
    std::cout << sv[0] << std::endl;
    ;  // 'e'

    // Substring
    std::string_view sub = sv.substr(0, 7);  // "example"
    std::cout << "sub: " << sub << " sv: " << sv << std::endl;

    // Prefix/suffix remove
    sv.remove_prefix(2);  // now "ample text"
    std::cout << "sv: " << sv << std::endl;
    sv.remove_suffix(5);  // now "ample"
    std::cout << "sv: " << sv << std::endl;

    std::string_view sv1;  // sv is declared, currently empty
    {
        std::string s =
            "hEllo";  // s is a temporary std::string with dynamic memory
        sv1 = s;      // sv1 now points to the internal buffer of s
    }
    std::cout << "sv1: " << sv1
              << std::endl;  // this is not safe refers to danglisng pointer
}
/*
Program stdout
String: Hello, world!
String: Hello, string_view!
12
e
sub: example sv: example text
sv: ample text
sv: ample
*/
```

### std::invoke

* std::invoke privides a uniform way to call callable objects.
* It's part of the / header and is especially useful for invoking member functions, pointers to members, or callable objects in a consistent and type-safe way.

**The goal of std::invoke is to abstract the details of how to call a callable object.
It handles:**

* Function pointers
* Member function pointers
* Pointers to member data
* Lambdas or function objects (functors)
* Objects or references to objects

#### syntax:

**template <class F, class... Args>
decltype(auto) invoke(F&& f, Args&&... args);**

* F is the callable (function, lambda, member pointer, etc.)
* Args... are the arguments passed to it.
* It returns the result of the invocation, using perfect forwarding.
* Can be constexpr if the underlying callable is constexpr.

```c++
#include <functional> // std::invoke()
#include <iostream>

int regular_function(int a, int b) { return a + b; }

struct MyClass {
    int multiply(int x) { return x * 2; }

    int value = 42;
};

struct Functor {
    int operator()(int x) const { return x + 10; }
};

int main() {
    // --- 1. Regular function ---
    int sum = std::invoke(regular_function, 3, 4);
    std::cout << "Regular function: 3 + 4 = " << sum << '\n';
    // Regular function: 3 + 4 = 7

    // --- 2. Lambda function ---
    auto lambda = [](int a, int b) { return a * b; };
    int product = std::invoke(lambda, 5, 6);
    std::cout << "Lambda: 5 * 6 = " << product << '\n';
    // Lambda: 5 * 6 = 30

    // --- 3. Functor (function object) ---
    Functor func;
    int result = std::invoke(func, 7);
    std::cout << "Functor: 7 + 10 = " << result << '\n';
    // Functor: 7 + 10 = 17

    // --- 4. Member function pointer ---
    MyClass obj;
    int doubled = std::invoke(&MyClass::multiply, obj, 8);
    std::cout << "Member function: 8 * 2 = " << doubled << '\n';
    // Member function: 8 * 2 = 16

    // --- 5. Member function pointer with pointer ---
    MyClass* objPtr = &obj;
    int doubledPtr = std::invoke(&MyClass::multiply, objPtr, 9);
    std::cout << "Member function (via pointer): 9 * 2 = " << doubledPtr
              << '\n';
    // Member function (via pointer): 9 * 2 = 18

    // --- 6. Pointer to member data ---
    int memberValue = std::invoke(&MyClass::value, obj);
    std::cout << "Member data: value = " << memberValue << '\n';
    // Member data: value = 42
    return 0;
}
```

### std::apply

* **std::apply :** allows you to call a callable (like a function, lambda, or function object) with a set of arguments stored in a tuple.
  **Problem It Solves**
* Before std::apply, if you had a std::tuple of arguments, and you wanted to call a function with those arguments, you'd need to manually unpack them using template metaprogramming.
  std::apply simplifies this.
* std::apply takes the callable and unpacks the tuple elements as
  arguments to that callable.

**Syntax**
```cpp
  std::apply(func, std::make_tuple(arg1, arg2, arg3));
  as being similar to => func(arg1, arg2, arg3);
```
```cpp
#include <iostream>
#include <string>
#include <tuple>
#include <utility>  // <= this is for std::apply

int add(int a, int b) { return a + b; }

struct MyClass {
    void print(int x) const {
        std::cout << "MyClass::print called with: " << x << std::endl;
    }
};

int main() {
    // 1️⃣ Using std::apply with a regular function
    auto args1 = std::make_tuple(10, 20);
    int sum = std::apply(add, args1);
    std::cout << "Sum using std::apply with function: " << sum << std::endl;
// Sum using std::apply with function: 30

    // 2️⃣ Using std::apply with a lambda
    auto lambda = [](const std::string& label, int value) {
        std::cout << label << " " << value << std::endl;
    };
    auto args2 = std::make_tuple("Lambda output:", 42);
    std::apply(lambda, args2);
// Lambda output: 42

    // 3️⃣ Using std::apply with a member function
    MyClass obj;
    auto args3 = std::make_tuple(&obj, 99);  // note: object pointer must be first
    std::apply(&MyClass::print, args3);
// MyClass::print called with: 99

    return 0;
}
```

### std::filesystem

std::filesystem Quick Reference
Namespace: std::filesystem
Header: <filesystem>

1. Path Management
    fs::path p("file.txt"); — Represents file/directory paths
    p.filename(), p.extension(), p.parent\_path(), p.replace\_extension(".md")
2. Directory Iteration
    fs::directory\_iterator(dir) — Iterate non-recursively over directory entries
    fs::recursive\_directory\_iterator(dir) — Iterate recursively including
   subdirectories
3. File and Directory Checks
    fs::exists(path) — Check existence
    fs::is\_regular\_file(path) — Check if regular file
    fs::is\_directory(path) — Check if directory
    fs::is\_symlink(path) — Check if symbolic link
4. File Operations
    fs::create\_directory(path) — Create one directory
    fs::create\_directories(path) — Create nested directories
    fs::remove(path) — Remove file or empty directory
    fs::remove\_all(path) — Remove directory and contents recursively
    fs::copy(src, dest) — Copy file or directory
    fs::rename(old, new) — Rename or move file/directory
    fs::file\_size(path) — Get size of file in bytes
5. Error Handling
    Throws std::filesystem::filesystem\_error on failure by default
    Use std::error\_code to avoid exceptions:

   std::error\_code ec;
    fs::remove("file.txt", ec);
    if (ec) { //handle error// }
6. List Current Directory
    for (const auto& entry : fs::directory\_iterator(".")) {
    std::cout << entry.path().filename();
    if (fs::is\_directory(entry)) std::cout << " [DIR]";
    std::cout << '\n';
    }

Here, a big file is copied to a temporary path if there is available space:

```
const auto bigFilePath {"bigFileToCopy"};
if (std::filesystem::exists(bigFilePath)) {
  const auto bigFileSize {std::filesystem::file_size(bigFilePath)};
  std::filesystem::path tmpPath {"/tmp"};
  if (std::filesystem::space(tmpPath).available > bigFileSize) {
    std::filesystem::create_directory(tmpPath.append("example"));
    std::filesystem::copy_file(bigFilePath, tmpPath.append("newFile"));
  }
}
```

### std::byte

**std::byte** :is a strongly typed enumeration (enum class) representing a raw byte of memory, introduced in C++17 in the <cstddef> header.  header.
**Purpose:** Provides a clear, type-safe way to work with raw memory as bytes without character semantics.

**Characteristics:**

* Underlying type: unsigned char
* Size: 1 byte
* No implicit conversion to/from integers or characters.
* Supports only bitwise operations (&, |, ^, ~, <<, >>).

**Usage:**

* Initialize with std::byte b = static\_caststd::byte(0x1F);
* Convert to integer with std::to\_integer(b)

**Use cases:** Safe manipulation of raw memory, binary protocols, serialization,
cryptography, etc.

```c++
std::byte a {0};
std::byte b {0xFF};
int i = std::to_integer<int>(b); // 0xFF
std::byte c = a & b;
int j = std::to_integer<int>(c); // 0
```

Note that `std::byte` is simply an enum, and braced initialization of enums become possible thanks to [direct-list-initialization of enums](https://onlinemarkdown.com/#direct-list-initialization-of-enums).

### Splicing for maps and sets

**What is splicing in this context?**
Splicing means moving elements from one container to another, typically from one std::map or std::set to another of the same type,by "extracting" nodes and then "inserting" them in the target container.
This avoids the overhead of copying or moving the keys and values themselves
 since the underlying node is transferred.

```c++
#include <iostream>
#include <map>
#include <set>

int main() {
    // --- std::map example ---
    std::map<int, std::string> map1 = {{1, "one"}, {2, "two"}, {3, "three"}};
    std::map<int, std::string> map2 = {{4, "four"}};

    std::cout << "Before splicing maps:\n";
    std::cout << "map1 contains:\n";
    for (const auto& p : map1)
        std::cout << p.first << " => " << p.second << "\n";
    std::cout << "map2 contains:\n";
    for (const auto& p : map2)
        std::cout << p.first << " => " << p.second << "\n";

    // Extract element with key 2 from map1
    auto nh_map = map1.extract(2);
    // Insert node handle into map2
    auto result_map = map2.insert(std::move(nh_map));

    if (result_map.inserted) {
        std::cout << "Moved element key " << result_map.position->first
                  << " to map2\n";
    } else {
        std::cout << "Failed to move element key 2 to map2\n";
    }

    std::cout << "\nAfter splicing maps:\n";
    std::cout << "map1 contains:\n";
    for (const auto& p : map1)
        std::cout << p.first << " => " << p.second << "\n";
    std::cout << "map2 contains:\n";
    for (const auto& p : map2)
        std::cout << p.first << " => " << p.second << "\n";
     /*
Before splicing maps:
map1 contains:
1 => one
2 => two
3 => three
map2 contains:
4 => four
Moved element key 2 to map2

After splicing maps:
map1 contains:
1 => one
3 => three
map2 contains:
2 => two
4 => four
*/
    // --- std::set example ---
    std::set<int> set1 = {1, 2, 3};
    std::set<int> set2 = {4, 5};

    std::cout << "\nBefore splicing sets:\n";
    std::cout << "set1 contains:";
    for (auto x : set1) std::cout << " " << x;
    std::cout << "\nset2 contains:";
    for (auto x : set2) std::cout << " " << x;
    std::cout << std::endl;

    // Extract element '2' from set1
    auto nh_set = set1.extract(2);
    // Insert node handle into set2
    auto result_set = set2.insert(std::move(nh_set));

    if (result_set.inserted) {
        std::cout << "Moved element " << *result_set.position << " to set2\n";
    } else {
        std::cout << "Failed to move element 2 to set2\n";
    }

    std::cout << "\nAfter splicing sets:\n";
    std::cout << "set1 contains:";
    for (auto x : set1) std::cout << " " << x;
    std::cout << "\nset2 contains:";
    for (auto x : set2) std::cout << " " << x;
    std::cout << std::endl;
/*
Before splicing sets:
set1 contains: 1 2 3
set2 contains: 4 5
Moved element 2 to set2

After splicing sets:
set1 contains: 1 3
set2 contains: 2 4 5
*/

    return 0;
}
```

### Parallel algorithms

**Parallel algorithms** : are part of the Standard Library and provide a way to run standard algorithms concurrently on multiple threads or execution units, potentially improving performance on multi-core processors.
**Key Concepts**
Execution Policies: C++17 introduces execution policies to specify how an algorithm should execute:

* std::execution::seq — Sequential execution (default).
* std::execution::par — Parallel execution.
* std::execution::par\_unseq — Parallel and vectorized

Parallel Algorithms Many standard algorithms got overloads accepting an
execution policy as the first argument.
**Important Notes:**

* Thread Safety: The algorithm itself manages threading; you don’t create threads manually.
* Exceptions: If an exception occurs in a parallel algorithm, it may be wrapped inside std::exception\_list.
* Performance: Not all algorithms
* benefit from parallelism : it depends on the workload, data size, and hardware.

Supported Algorithms: Many standard algorithms support execution policies in C++17, including:

1. for\_each
2. transform
3. sort
4. reduce (introduced in C++17, but reduction algorithms are in C++20)
5. find, find\_if
6. copy, copy\_if
7. fill, fill\_n
    And others.

```c++
#include <algorithm>
#include <chrono>
#include <cmath>
#include <execution> //std::exceution
#include <iostream>
#include <numeric>
#include <vector>

// Simulate expensive CPU work
int heavy_compute(int n) {
    double result = 0;
    for (int i = 0; i < 1000; ++i) {
        result += std::sqrt(n + i);
    }
    return static_cast<int>(result);
}

template <typename ExecPolicy>
void run_test(const std::string& label, ExecPolicy policy) {
    const size_t SIZE = 1'000'000;
    std::vector<int> data(SIZE);
    std::iota(data.begin(), data.end(), 1);  // Fill with 1...SIZE

    std::vector<int> results(SIZE);

    auto start = std::chrono::high_resolution_clock::now();

    std::transform(policy, data.begin(), data.end(), results.begin(),
                   [](int n) { return heavy_compute(n); });

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    std::cout << "[" << label << "] Time taken: " << elapsed.count()
              << " seconds\n";
}

int main() {
    std::cout << "Testing heavy compute with large dataset:\n\n";

    run_test("Sequential", std::execution::seq);
    run_test("Parallel", std::execution::par);

    return 0;
}
/*
Testing heavy compute with large dataset:
[Sequential] Time taken: 10.7294 seconds
[Parallel] Time taken: 9.24226 seconds
*/
```

### std::sample

**std::sample :** randomly selects n elements from a given input range and writes them to an output iterator using a random number generator.

```c++
#include <algorithm> // std::sample
#include <iostream>
#include <random>
#include <vector>

int main() {
    // Input data
    std::vector<int> data = {10, 20, 30, 40, 50};

    // Vector to store result
    std::vector<int> result = {100, 200, 300};

    // Random number generator
    std::random_device rd;
    std::mt19937 gen(rd());

    // Sample 2 elements from 'data' into 'result'
    std::sample(data.begin(), data.end(),    // input range
                std::back_inserter(result),  // output iterator
                2,                           // number of elements to sample
                gen);                        // random number generator

    // Output the result
    std::cout << "Randomly selected elements: ";
    for (int n : result) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}
/*
Randomly selected elements: 100 200 300 20 30
*/
```

### std::clamp

Clamp given value between a lower and upper bound.
**It returns:**

* lo if the value is less than lo
* hi if the value is greater than hi
* otherwise, the value itself

```c++
#include <algorithm>  // std::clamp
#include <iostream>

int main() {
    int value1 = 5;
    int value2 = 15;
    int value3 = 25;

    int low = 10;
    int high = 20;

    std::cout << std::clamp(value1, low, high) << "\n";  // Output: 10
    std::cout << std::clamp(value2, low, high) << "\n";  // Output: 15
    std::cout << std::clamp(value3, low, high) << "\n";  // Output: 20

    return 0;
}

```

### std::reduce

Fold over a given range of elements. Conceptually similar to `std::accumulate`, but `std::reduce` will perform the fold in parallel. Due to the fold being done in parallel, if you specify a binary operation, it is required to be associative and commutative. A given binary operation also should not change any element or invalidate any iterators within the given range.

The default binary operation is std::plus with an initial value of 0.

```c++
const std::array<int, 3> a{ 1, 2, 3 };
std::reduce(std::cbegin(a), std::cend(a)); // == 6
// Using a custom binary op:
std::reduce(std::cbegin(a), std::cend(a), 1, std::multiplies<>{}); // == 6
```

Additionally you can specify transformations for reducers:

```
std::transform_reduce(std::cbegin(a), std::cend(a), 0, std::plus<>{}, times_ten); // == 60

const std::array<int, 3> b{ 1, 2, 3 };
const auto product_times_ten = [](const auto a, const auto b) { return a * b * 10; };

std::transform_reduce(std::cbegin(a), std::cend(a), std::cbegin(b), 0, std::plus<>{}, product_times_ten); // == 140
```

### Prefix sum algorithms

Prefix sum algorithms :are commonly used to efficiently compute the cumulative sum of elements in a list or array, which allows for quick range queries and other operations.

**What is a Prefix Sum?**
Given an array A of size n, the prefix sum array P is defined as:
P[0] = A[0]
P[1] = A[0] + A[1]
P[2] = A[0] + A[1] + A[2]
...
P[i] = A[0] + A[1] + ... + A[i]

```c++
#include <iostream>
#include <numeric>  // for std::partial_sum
#include <vector>

int main() {
    std::vector<int> A = {1, 2, 3, 4, 5};  // Input array
    std::vector<int> P(A.size());          // Prefix sum array

    // Compute prefix sum using std::partial_sum from <numeric>
    std::partial_sum(A.begin(), A.end(), P.begin());

    // Print result
    std::cout << "Prefix Sum Array: ";
    for (int x : P) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    // Example range query: sum of A[1] to A[3] (2 + 3 + 4 = 9)
    int l = 1, r = 3;
    int range_sum = P[r] - (l > 0 ? P[l - 1] : 0);
    std::cout << "Sum from index " << l << " to " << r << " is " << range_sum
              << "\n";

    return 0;
}
/*
Prefix Sum Array: 1 3 6 10 15
Sum from index 1 to 3 is 9
*/
```

### GCD and LCM

Greatest common divisor (GCD) and least common multiple (LCM).

```c++
#include <iostream>
#include <numeric>  // For std::gcd and std::lcm

int main() {
    int a = 24, b = 36;

    int gcd = std::gcd(a, b);  // Built-in function for GCD
    int lcm = std::lcm(a, b);  // Built-in function for LCM

    std::cout << "GCD of " << a << " and " << b << " is " << gcd << '\n';
    std::cout << "LCM of " << a << " and " << b << " is " << lcm << '\n';

    return 0;
}
/*
GCD of 24 and 36 is 12
LCM of 24 and 36 is 72
*/
```

### std::not\_fn

**std::not\_fn:** is a utility function introduced in C++17 that takes a callable object (like a function, lambda, or function object) and returns a new function object that returns the logical negation (!) of the result of the original callable.

```c++
#include <algorithm>
#include <functional>  // std::not_fn()
#include <iostream>
#include <vector>

bool is_even(int n) { return n % 2 == 0; }

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5, 6};

    // Using std::not_fn to find all odd numbers
    auto is_odd = std::not_fn(is_even);

    for (int n : vec) {
        if (is_odd(n)) {
            std::cout << n << " ";
        }
    }

    return 0;
}
/*
1 3 5
*/
```

### String conversion to/from numbers

1. String → Number

* std::from\_chars
* header: <charconv>

Traditional:

* std::stoi, std::stof, etc. (throws exceptions)
* std::stringstream (flexible, slower)

2. Number → String
   * std::to\_string

Traditional:

* Alternative: std::stringstream

```c++
#include <charconv>  // for from_chars
#include <iostream>
#include <sstream>    // for stringstream
#include <stdexcept>  // for stoi
#include <string>

int main() {
    std::string str_num = "12345";
    std::string str_num1 = "FFABCDE";
    int num1, numHex;

    // === Method 1: from_chars (C++17, no exceptions) ===
    auto result = std::from_chars(str_num.data(), str_num.data() + str_num.size(), num1);  // by  default dec
    auto result2 = std::from_chars( str_num1.data(), str_num1.data() + str_num1.size(), numHex, 16);

    if (result.ec == std::errc()) {  //	No error (conversion succeeded)
        std::cout << "[from_chars] Converted string to number: " << num1 << "\n";
    } else {
        std::cout << "[from_chars] Conversion failed.\n";
    }

    if (result2.ec == std::errc()) {  //	No error (conversion succeeded)
        std::cout << "[from_chars] Converted string to number2: " << std::hex
                  << numHex << "\n";
    } else {
        std::cout << "[from_chars] Conversion failed.\n";
    }

    // === Method 2: stoi (throws exceptions) ===
    try {
        int num2 = std::stoi(str_num);
        std::cout << "[stoi] Converted string to number: " << std::dec<< num2
                  << "\n";
    } catch (const std::exception& e) {
        std::cout << "[stoi] Error: " << e.what() << "\n";
    }

    // === Method 3: stringstream ===
    std::stringstream ss(str_num);
    int num3;
    ss >> num3;
    if (!ss.fail()) {
        std::cout << "[stringstream] Converted string to number: " << num3 << "\n";
    } else {
        std::cout << "[stringstream] Conversion failed.\n";
    }

    // === Number to String (to_string) ===
    std::string str1 = std::to_string(num1);
    std::cout << "[to_string] Converted number to string: " << str1 << "\n";

    // === Number to String (stringstream) ===
    std::stringstream ss2;
    ss2 << num1;
    std::string str2 = ss2.str();
    std::cout << "[stringstream] Converted number to string: " << str2 << "\n";

    return 0;
}
/*
[from_chars] Converted string to number: 12345
[from_chars] Converted string to number2: ffabcde
[stoi] Converted string to number: 12345
[stringstream] Converted string to number: 12345
[to_string] Converted number to string: 12345
[stringstream] Converted number to string: 12345
*/

```

### Rounding functions for chrono durations and timepoints

Provides abs, round, ceil, and floor helper functions for `std::chrono::duration` and `std::chrono::time_point`.

```c++
#include <chrono>
#include <ctime>    // for std::localtime
#include <iomanip>  // for put_time
#include <iostream>

int main() {
    using namespace std::chrono;

    // Example with duration
    milliseconds ms(1234);

    seconds floored = floor<seconds>(ms);
    seconds ceiled = ceil<seconds>(ms);
    seconds rounded = round<seconds>(ms);

    std::cout << "Duration rounding (1234ms):\n";
    std::cout << "  floor  : " << floored.count() << "s\n";
    std::cout << "  ceil   : " << ceiled.count() << "s\n";
    std::cout << "  round  : " << rounded.count() << "s\n";

    // Example with time_point
    system_clock::time_point now = system_clock::now();

    auto floor_tp = floor<seconds>(now);
    auto ceil_tp = ceil<seconds>(now);
    auto round_tp = round<seconds>(now);

    std::time_t floor_time = system_clock::to_time_t(floor_tp);
    std::time_t ceil_time = system_clock::to_time_t(ceil_tp);
    std::time_t round_time = system_clock::to_time_t(round_tp);

    std::cout << "\nTime point rounding (system_clock::now()):\n";
    std::cout << "  floor  : "
              << std::put_time(std::localtime(&floor_time), "%F %T") << '\n';
    std::cout << "  ceil   : "
              << std::put_time(std::localtime(&ceil_time), "%F %T") << '\n';
    std::cout << "  round  : "
              << std::put_time(std::localtime(&round_time), "%F %T") << '\n';

    return 0;
}
/*
Duration rounding (1234ms):
  floor  : 1s
  ceil   : 2s
  round  : 1s

Time point rounding (system_clock::now()):
  floor  : 2025-07-07 09:15:47
  ceil   : 2025-07-07 09:15:48
  round  : 2025-07-07 09:15:48*/
```

## Acknowledgements

* [cppreference](http://en.cppreference.com/w/cpp) - especially useful for finding examples and documentation of new library features.
* [C++ Rvalue References Explained](http://web.archive.org/web/20240324121501/http%3A//thbecker.net/articles/rvalue_references/section_01.html) - a great introduction I used to understand rvalue references, perfect forwarding, and move semantics.
* [clang](http://clang.llvm.org/cxx_status.html) and [gcc](https://gcc.gnu.org/projects/cxx-status.html)'s standards support pages. Also included here are the proposals for language/library features that I used to help find a description of, what it's meant to fix, and some examples.
* [Compiler explorer](https://godbolt.org/)
* [Scott Meyers' Effective Modern C++](https://www.amazon.com/Effective-Modern-Specific-Ways-Improve/dp/1491903996) - highly recommended book!
* [Jason Turner's C++ Weekly](https://www.youtube.com/channel/UCxHAlbZQNFU2LgEtiqd2Maw) - nice collection of C++-related videos.
* [What can I do with a moved-from object?](http://stackoverflow.com/questions/7027523/what-can-i-do-with-a-moved-from-object)
* [What are some uses of decltype(auto)?](http://stackoverflow.com/questions/24109737/what-are-some-uses-of-decltypeauto)
* And many more SO posts I'm forgetting...

## Author

Haresh

## Content Contributors

See: <https://github.com/AnthonyCalandra/modern-cpp-features/graphs/contributors>

## License

MIT

File: C++17

42,301 characters 5,965 words 210 paragraphs

Privacy and cookie settings

Managed by Google. Complies with IAB TCF. CMP ID: 300

Online Markdown Editor - Simple, Fast & Live Preview | OnlineMarkdown.com

# C++20

## C++20 Language Features

### Coroutines
[_Coroutines source Link_](https://www.scs.stanford.edu/~dm/blog/c++-coroutines.html)
> **Note:** Coroutines in C++20 are special functions that can pause and resume their execution. They don’t share a stack, so they can jump between each other easily.

However, using them in C++ is a bit messy:
- The core feature (like co_await) is nice, but it's buried under a lot of boilerplate code you have to write yourself.
- The C++ standard library doesn’t provide the support types you need, so you have to build that "support structure" (called the promise, awaiter, etc.) yourself.
   >❗ **Note on Confusion:**
Terms like promise and future used in coroutine discussions do not refer to std::promise or std::future from <future>. That’s a common source of confusion.

✅**What co_await Does (Simply)**
When you write co_await a; in a coroutine:
- The coroutine’s state (local variables, etc.) is saved on the heap.
- A resumer function is created to continue the coroutine later.
- a is asked to handle the pause and resume logic.
- The coroutine stops here and will only continue if a decides to call the resumer.
  
It’s like giving a the power to resume the function when it's ready.

📚 **When to Use Coroutines**
- Implementing asynchronous I/O (like file or network I/O).
- Creating lazy sequences (generators).
- Replacing complex state machines or callback hell.
- Writing cleaner, more linear async logic.

**In C++20, a coroutine must:**
1. Return a coroutine-compatible type (not just any type).
>    In C++20, a coroutine-compatible type is a special return type (like std::generator or a custom type with a promise_type) that integrates with the coroutine system, enabling co_await, co_yield, or co_return to work correctly.
2. Use at least one of the coroutine keywords:
> - co_await – suspends until an awaitable completes.
> - co_yield – yields a value (used in generators).
> - co_return – returns a final value or signals completion.

**Compiling code using coroutines**
>g++ -fcoroutines -std=c++20
Clang’s support is less far along. You need to install llvm libc++ and compile with:
clang++ -std=c++20 -stdlib=libc++ -fcoroutines-ts

#### Coroutine handles
> - std::coroutine_handle<> is the type used to manage coroutine state.
> - It behaves like a C pointer: easy to copy but must be manually destroyed with destroy() to avoid memory leaks.
> - If you use a handle after it’s destroyed, it leads to undefined behavior.
> - The handle remains valid throughout the coroutine’s life.
> - When you write co_await a, the compiler passes the coroutine handle to a.await_suspend(handle).
> - The object a must implement await_ready(), await_suspend(), and await_resume() — making it an “awaiter.”

Now let’s look at a complete program that uses co_await. For now, ignore the ReturnObject type—it’s just part of the garbage we have to get through to access co_await.
```c++
#include <concepts>
#include <coroutine>
#include <exception>
#include <iostream>

struct ReturnObject { // This is return type, callable function should return
  struct promise_type {
    ReturnObject get_return_object() { return {}; }
    std::suspend_never initial_suspend() { return {}; }
    std::suspend_never final_suspend() noexcept { return {}; }
    void unhandled_exception() {}
  };
};

struct Awaiter {
  std::coroutine_handle<> *hp_;
  constexpr bool await_ready() const noexcept { return false; }
  void await_suspend(std::coroutine_handle<> h) { *hp_ = h; }
  constexpr void await_resume() const noexcept {}
};

ReturnObject counter(std::coroutine_handle<> *continuation_out)
{
  Awaiter a{continuation_out};
  for (unsigned i = 0;; ++i) {
    co_await a;
    std::cout << "counter: " << i << std::endl;
  }
}

int main ()
{
  std::coroutine_handle<> h;
  counter(&h);
  for (int i = 0; i < 3; ++i) {
    std::cout << "In main function\n";
    h();
  }
  h.destroy();
  return 0;
}
/*
In main function
counter: 0
In main function
counter: 1
In main1 function
counter: 2
*/

```
**In C++ coroutines, an awaiter needs three functions:**
- **await_ready**: Tells if the coroutine should suspend or keep going. If it returns true, no suspension happens.
- **await_suspend**: Runs if suspension is needed. It handles how the coroutine pauses.
- **await_resume**: Runs when the coroutine resumes. It gives the result of the co_await.

**C++ provides two built-in awaiters:**
- **std::suspend_always**: Always suspends the coroutine.
- **std::suspend_never**: Never suspends it.


#### The coroutine return object
**1. Coroutines return a special type, not just a simple value.**
> - This return type must have a nested promise_type class.
> - The compiler uses promise_type to manage the coroutine’s internal state.
> 
**2. Inside promise_type, the method get_return_object() tells the compiler what to return from the coroutine.**
> - We want to return a ReturnObject2 that holds a coroutine handle.

1. To get the handle from inside get_return_object(), we use:
    ```c++
    std::coroutine_handle<promise_type>::from_promise(*this)
    ```

Below program illustrate
```c++
#include <coroutine>
#include <iostream>

struct ReturnObject2 {
  struct promise_type {
    // Called when the coroutine starts to set up the return object
    ReturnObject2 get_return_object() {
      return {
        .h_ = std::coroutine_handle<promise_type>::from_promise(*this)
      };
    }

    // Coroutine starts immediately (no suspension at the beginning)
    std::suspend_never initial_suspend() { return {}; }

    // Coroutine ends without suspending (immediately done)
    std::suspend_never final_suspend() noexcept { return {}; }

    // What to do if an exception is thrown
    void unhandled_exception() {}

    // No return value for this coroutine
    void return_void() {}
  };

  // Store the coroutine handle
  std::coroutine_handle<promise_type> h_;

  // Allow implicit conversion to generic coroutine_handle<>
  operator std::coroutine_handle<>() const { return h_; }
};

ReturnObject2 counter2() {
  for (unsigned i = 0;; ++i) {
    co_await std::suspend_always{}; // Suspend after each loop iteration
    std::cout << "counter2: " << i << std::endl;
  }
}

int main() {
  // Start coroutine and get the handle
  std::coroutine_handle<> h = counter2();

  // Resume the coroutine 3 times
  for (int i = 0; i < 3; ++i) {
    std::cout << "In main function\n";
    h(); // Resume coroutine
  }

  // Manually destroy coroutine to avoid memory leak
  h.destroy();

  return 0;
}
/*
In main function
counter2: 0
In main function
counter2: 1
In main function
counter2: 2
*/
```
**Here's a simple and brief explanation:**

> - ReturnObject2 is a special object used to control a coroutine’s lifetime. It stores a coroutine_handle, which is like a pointer to the coroutine’s state.
> - The coroutine function counter2() suspends itself after each number using co_await std::suspend_always{}. This means it pauses and lets the caller decide when to resume it.
> - In main(), we get a handle to the coroutine and call it 3 times. Each call resumes the coroutine, which then prints the next number.
> - The coroutine_handle is just a lightweight pointer, so even though the ReturnObject2 goes out of scope, the handle remains valid.
> - But, because the coroutine allocates memory internally, we must call h.destroy() to free that memory. Otherwise, it causes a memory leak.

#### The promise object
**What’s going on?**
- So far, the coroutine just paused and printed stuff, but didn't send data back to the caller (main function).
- We want the coroutine to send values to main, so main can decide what to do with them.

**How?**
- Every coroutine has a promise object that stores the coroutine’s state.
- We add a variable value_ inside the promise to hold the number the coroutine wants to send.
- To access the promise inside the coroutine, we use a special helper called GetPromise.

- GetPromise is an awaiter that:
    1.  Gives us access to the promise object.
    2.  Does not pause the coroutine when awaited.
- Inside the coroutine (counter3), we write the current number into promise.value_ every loop.
- In main, we get the promise through the coroutine handle, and read the number from promise.value_ and print it.
- We resume the coroutine manually with h().
- When done, we call h.destroy() to clean up memory.
```c++
#include <coroutine>
#include <iostream>

// Awaiter to get promise object inside the coroutine
template<typename PromiseType>
struct GetPromise {
  PromiseType *p_;
  bool await_ready() { return false; } // Will call await_suspend
  bool await_suspend(std::coroutine_handle<PromiseType> h) {
    p_ = &h.promise();   // Save pointer to promise object
    return false;        // Don't suspend coroutine
  }
  PromiseType *await_resume() { return p_; } // Return the promise pointer
};

// Return object holding coroutine handle and promise_type
struct ReturnObject3 {
  struct promise_type {
    unsigned value_;  // Field to pass data from coroutine to main

    ReturnObject3 get_return_object() {
      return ReturnObject3 {
        .h_ = std::coroutine_handle<promise_type>::from_promise(*this)
      };
    }
    std::suspend_never initial_suspend() { return {}; }
    std::suspend_never final_suspend() noexcept { return {}; }
    void unhandled_exception() {}
  };

  std::coroutine_handle<promise_type> h_;
  operator std::coroutine_handle<promise_type>() const { return h_; }
};

// Coroutine function that updates promise.value_ and suspends each step
ReturnObject3 counter3() {
  auto pp = co_await GetPromise<ReturnObject3::promise_type>{}; // Get promise

  for (unsigned i = 0;; ++i) {
    pp->value_ = i;                // Update promise value
    co_await std::suspend_always{}; // Suspend coroutine
  }
}

// Main function to resume coroutine and print values from promise
void main3() {
  std::coroutine_handle<ReturnObject3::promise_type> h = counter3();
  ReturnObject3::promise_type &promise = h.promise();

  for (int i = 0; i < 3; ++i) {
    std::cout << "counter3: " << promise.value_ << std::endl;
    h(); // Resume coroutine
  }
  h.destroy(); // Clean up memory
}

int main() {
  main3();
  return 0;
}
/*
counter3: 0
counter3: 1
counter3: 2
*/
```
#### The co_return operator
**What’s going on?**
- co_yield is a special coroutine keyword designed to make it easier to send values from a coroutine back to the caller.
- Instead of manually getting the promise object like before, you just write co_yield value; inside the coroutine.
- Behind the scenes, co_yield e; calls co_await promise.yield_value(e); on the promise object.
- So, if the promise has a method called yield_value, it’s automatically used to handle the yielded value.
- This simplifies the previous approach because the coroutine itself can just yield values directly.

**How the code works:**
- The promise_type has a yield_value method that:
    1. Stores the yielded value inside value_.
    2. Returns std::suspend_always{} to suspend the coroutine after yielding.
- Inside the coroutine (counter4), we just write co_yield i; to send values out.
- In main4, we get the coroutine handle and access the promise’s value_ field.
- Each time we resume the coroutine by calling h(), it produces the next value.
- We print that value in main4.
- Finally, we clean up with h.destroy().
```c++
#include <coroutine>
#include <iostream>

struct ReturnObject4 {
  struct promise_type {
    unsigned value_;

    ReturnObject4 get_return_object() {
      return {
        .h_ = std::coroutine_handle<promise_type>::from_promise(*this)
      };
    }
    std::suspend_never initial_suspend() { return {}; }
    std::suspend_never final_suspend() noexcept { return {}; }
    void unhandled_exception() {}

    // This is called automatically by co_yield
    std::suspend_always yield_value(unsigned value) {
      value_ = value;       // Store the yielded value
      return {};           // Suspend coroutine after yielding
    }
  };

  std::coroutine_handle<promise_type> h_;
};

ReturnObject4 counter4() {
  for (unsigned i = 0;; ++i)
    co_yield i;    // Yield the current value
}

void main4() {
  auto h = counter4().h_;
  auto &promise = h.promise();

  for (int i = 0; i < 3; ++i) {
    std::cout << "counter4: " << promise.value_ << std::endl;
    h();          // Resume coroutine to get next value
  }
  h.destroy();   // Clean up
}

int main() {
  main4();
  return 0;
}
/*
counter4: 0
counter4: 1
counter4: 2
*/
```
#### The co_return operator
**What’s the idea?**
- So far, the coroutine gave infinite values (kept counting forever).
- But sometimes you want the coroutine to produce a limited number of values and then stop.
- To tell the coroutine is finished, C++ uses co_return.

**How does co_return work?**
- co_return e; calls promise.return_value(e) on the promise object.
- co_return; (or just falling off the end of the function) calls promise.return_void().
- The coroutine is done when handle.done() returns true.
- Important: The promise must have return_void() or return_value() methods if you use co_return, or your code won't compile.
- Also, if your coroutine falls off the end but promise lacks return_void(), it causes undefined behavior (bad stuff like crashes).

**Final suspend**
- When a coroutine ends, it calls final_suspend().
- If final_suspend() returns an awaitable that suspends (like std::suspend_always), the coroutine stays alive (so main can inspect it and clean up).
- If final_suspend() returns std::suspend_never (doesn't suspend), coroutine state is destroyed immediately after finishing.
- Usually, you want to suspend at the end so the main function can safely call destroy() on the coroutine handle.
- If you don't, and main still calls handle after the coroutine is destroyed, you get crashes.
```c++
#include <coroutine>
#include <iostream>

struct ReturnObject5 {
  struct promise_type {
    unsigned value_;

    ~promise_type() {
      std::cout << "promise_type destroyed\n";
    }

    ReturnObject5 get_return_object() {
      return {
        .h_ = std::coroutine_handle<promise_type>::from_promise(*this)
      };
    }

    std::suspend_never initial_suspend() { return {}; }
    std::suspend_always final_suspend() noexcept { return {}; }  // suspend at end

    void unhandled_exception() {}

    std::suspend_always yield_value(unsigned value) {
      value_ = value;
      return {};
    }

    void return_void() {}  // required because we fall off end (no co_return value)
  };

  std::coroutine_handle<promise_type> h_;
};

ReturnObject5 counter5() {
  for (unsigned i = 0; i < 3; ++i)
    co_yield i;

  // falling off end means co_return void
}

void main5() {
  auto h = counter5().h_;
  auto &promise = h.promise();

  while (!h.done()) {       // check if coroutine is finished
    std::cout << "counter5: " << promise.value_ << "\n";
    h();                    // resume coroutine
  }

  h.destroy();              // clean up coroutine state
}

int main() {
  main5();
  return 0;
}
/*
counter5: 0
counter5: 1
counter5: 2
promise_type destroyed
*/
```
**What happens if final_suspend() returns std::suspend_never?**
- Coroutine state is destroyed immediately after finishing.
- But main still tries to use the handle (h.done() and h()).
- This causes undefined behavior like crashes or segmentation faults because the coroutine no longer exists.
#### Generic generator example
> **What is a Generator?**
> A generator is like a special function that can pause and resume while producing a sequence of values one by one.
> You ask for the next value, it gives you one, then pauses until you ask again.

##### Why use a Generator?
**Imagine you want to generate numbers one at a time, for example:**
> * All even numbers.
> * Fibonacci sequence.
> * Reading lines from a file.
> * Generating sensor data.

**Instead of:**
> * Storing everything in memory.
> * Returning a big array or list.
> 
> You can pause after each value and resume when needed — saving memory and processing time. That's what generators help you do!
> 
**Real-World Analogy**
> Think of a YouTube playlist. You don’t download all videos at once. You click "Next" to play one video at a time.
> 
**A generator works similarly:**
> * You get one value.
> * Pause. 
> * Ask for next value.
> * Pause again.

##### Real Code Example: Even Number Generator
**Step 1: The Generator Template (same as before, slightly simplified)**
```c++
#include <coroutine>
#include <iostream>
#include <exception>

template<typename T>
struct Generator {
    struct promise_type {
        T current_value;
        std::exception_ptr exception;

        Generator get_return_object() {
            return Generator{ std::coroutine_handle<promise_type>::from_promise(*this) };
        }

        std::suspend_always initial_suspend() { return {}; }
        std::suspend_always final_suspend() noexcept { return {}; }

        void unhandled_exception() {
            exception = std::current_exception(); // Store any exception
        }

        std::suspend_always yield_value(T value) {
            current_value = value;
            return {};
        }

        void return_void() {}
    };

    using handle_type = std::coroutine_handle<promise_type>;
    handle_type coro;

    Generator(handle_type h) : coro(h) {}
    ~Generator() { if (coro) coro.destroy(); }

    bool move_next() {
        coro.resume();
        if (coro.done()) {
            if (coro.promise().exception)
                std::rethrow_exception(coro.promise().exception);
            return false;
        }
        return true;
    }

    T current_value() {
        return coro.promise().current_value;
    }
};

```
**Step 2: The Coroutine Function (Even Number Generator)**
```c++
Generator<int> generate_evens(int max) {
    for (int i = 0; i <= max; i += 2) {
        co_yield i;
    }
}
//This will yield: 0, 2, 4, 6, ..., up to max
```
Step 3: Using It in main
```c++
int main() {
    auto gen = generate_evens(10); // Generate even numbers up to 10

    while (gen.move_next()) {
        std::cout << "Even number: " << gen.current_value() << '\n';
    }
}
/*
Even number: 0
Even number: 2
Even number: 4
Even number: 6
Even number: 8
Even number: 10
*/
```
### Concepts
> _Concepts are rules you can give to template parameters.
> They help make sure that only correct types are passed to templates._
##### Why Are Concepts Useful?
##### Without concepts:
```c++
template<typename T>
T add(T a, T b) {
    return a + b;  // Error if T doesn't support +
}

int main() {
    add("hello", 5);  // ❌ BAD: string + int doesn't work You get a long, ugly compiler error.
}
```
##### With Concepts:
###### Example 1: Concept to check if + works
```c++
#include <iostream>
#include <concepts>

// This is a concept: it checks if type T can be added (+)
template<typename T>
concept Addable = requires(T a, T b) {
    a + b;
};

// Use the concept in a template
template<Addable T>
T add(T a, T b) {
    return a + b;
}

int main() {
    std::cout << add(2, 3) << "\n";        // ✅ OK: int supports +
    std::cout << add(2.5, 1.5) << "\n";    // ✅ OK: double supports +
    // add("Hi", 3);                       // ❌ ERROR: string + int not allowed
}

```
###### Example 2: Built-in Concept — Only integers allowed
```c++
#include <iostream>
#include <concepts>

// Only allow integer values
void printDouble(std::integral auto value) {
    std::cout << value * 2 << "\n";
}

int main() {
    printDouble(5);      // ✅ OK
    // printDouble(3.14);  // ❌ ERROR: 3.14 is not an integer
}

```
###### Example 3: Use concept with auto (shortcut)
See also: [concepts library](#concepts-library).
```c++
//Instead of writing:
template<std::integral T>
void doSomething(T value);

//You can write:
void doSomething(std::integral auto value);

//Both mean the same!
```
######  Example 4: Custom Concept — Has size() method
What if you only want to accept types that have .size()?
Like std::vector, std::string etc.
```c++
#include <iostream>
#include <concepts>
#include <vector>
#include <string>

// Our own concept: checks if type has size()
template<typename T>
concept HasSize = requires(T a) {
    { a.size() } -> std::convertible_to<std::size_t>;
};

// Use it in a function
template<HasSize T>
void printSize(const T& container) {
    std::cout << "Size: " << container.size() << "\n";
}

int main() {
    std::vector<int> v = {1, 2, 3};
    std::string s = "Hello";

    printSize(v);  // ✅ OK
    printSize(s);  // ✅ OK
    // printSize(5);  // ❌ ERROR: int has no size()
}
```
###### Example 5: Multiple Concepts Together
```c++
#include <concepts>
#include <iostream>

// Accept only values that are both integral and default-initializable
template<typename T>
concept MyConcept = std::integral<T> && std::default_initializable<T>;

template<MyConcept T>
void showDefaultValue() {
    T x{};
    std::cout << "Default value: " << x << "\n";
}

int main() {
    showDefaultValue<int>();  // ✅ OK
    // showDefaultValue<std::string>(); // ❌ ERROR: std::string is not integral
}

```
### Three-way comparison (Spaceship Operator)
Before C++20, when creating your own types (e.g., structs), if you wanted to compare objects, you'd often have to manually define all comparison operators. That’s verbose and error-prone.

With <=>, C++20:
> - Reduces boilerplate code.
> - Enables a single point of definition for all comparisons.
> - Supports total, weak, and partial ordering.

**Basic Syntax**
```c++
auto operator<=>(const T& other) const;
```
- Returns a comparison category type:
    std::strong_ordering, std::weak_ordering, or std::partial_ordering.
- auto can deduce the correct return type.
- Can use = default to auto-generate comparisons.


**⚙ Comparison Category Types**
Category Type | Used For | Allows == | Allows <
--------------|----------|-----------|---------
std::strong_ordering | Most types (e.g. int, char) | ✅ | ✅
std::weak_ordering | Case-insensitive compares | ✅ | ✅
std::partial_ordering | Floating-point with NaN | ✅ | ✅

> _Note: NaN means Not a Number__

**All-in-One Example**
```c++
#include <iostream>
#include <compare>
#include <cmath>

struct Point {
    int x, y;
    auto operator<=>(const Point&) const = default; // auto compare x and y
};

class Box {
    int volume;
public:
    Box(int v) : volume(v) {}
    std::strong_ordering operator<=>(const Box& other) const {
        return volume <=> other.volume;
    }
    bool operator==(const Box& other) const = default; // still needed if not using = default
};

int main() {
    // 🔹 1. Built-in type comparison
    int a = 10, b = 20;
    std::cout << "[int] ";
    if (auto r = a <=> b; r < 0) std::cout << "a < b\n";
    else if (r > 0) std::cout << "a > b\n";
    else std::cout << "a == b\n";

    // 🔹 2. Custom type with = default
    Point p1{1, 2}, p2{1, 3};
    std::cout << "[Point] ";
    if (p1 < p2) std::cout << "p1 < p2\n";
    else if (p1 > p2) std::cout << "p1 > p2\n";
    else std::cout << "p1 == p2\n";

    // 🔹 3. Custom type with manual <=> and strong_ordering
    Box box1(100), box2(200);
    std::cout << "[Box] ";
    if (auto r = box1 <=> box2; r < 0) std::cout << "box1 < box2\n";
    else if (r > 0) std::cout << "box1 > box2\n";
    else std::cout << "box1 == box2\n";

    // 🔹 4. Floating point comparison with NaN (partial ordering)
    double x = NAN, y = 1.0;
    std::cout << "[double] ";
    if (auto r = x <=> y; r == std::partial_ordering::unordered)
        std::cout << "x and y are unordered (NaN involved)\n";
    else if (r < 0) std::cout << "x < y\n";
    else if (r > 0) std::cout << "x > y\n";
    else std::cout << "x == y\n";

    return 0;
}

```

### Template syntax for lambdas
Use familiar template syntax in lambda expressions.
```c++
auto f = []<typename T>(std::vector<T> v) {
  // ...
};
```

### Range-based for loop with initializer
This feature simplifies common code patterns, helps keep scopes tight, and offers an elegant solution to a common lifetime problem.
```c++
for (auto v = std::vector{1, 2, 3}; auto& e : v) {
  std::cout << e;
}
// prints "123"
```

### [\[likely]] and [\[unlikely]] attributes
These attributes give hints to the compiler but do not guarantee behavior. They can potentially improve performance by organizing code to reduce CPU branch mispredictions.
```c++
sif (condition) [[likely]] {
    // More likely branch
} else [[unlikely]] {
    // Less likely branch
}

```

```c++
#include <iostream>

void process(int value) {
    if (value == 0) [[unlikely]] {
        std::cout << "Rare case: value is zero\n";
    } else [[likely]] {
        std::cout << "Common case: value is non-zero\n";
    }
}
/*
When value == 0, the code in the [[unlikely]] block executes.
For all other values, the [[likely]] branch is expected to be taken.
Helps CPU prefetch the correct instructions more often if used properly.*/
```


### Deprecate implicit capture of this
> In C++20, it's deprecated (not recommended) to use [=] to capture this implicitly in lambdas.

**❌ Problem Example (Deprecated):**
```c++
auto lambda = [=]() {
    std::cout << x;  // uses `this` implicitly
};
/*
- [=] means "capture everything by copy"
- But it also captures this silently, which can cause bugs (like accessing a deleted object)
*/
```
**✅ Safer Ways:**
1. Explicitly capture this:
```c++
auto lambda = [this]() {
    std::cout << x;
};
```
2. Capture a copy of the object (safer if used later):

```c++
auto lambda = [*this]() {
    std::cout << x;
};
```

**🔁 Summary of Capture Modes for this:**
Capture | Captures this? | Copy or Reference? | Safe if object is destroyed?
--------|----------------|--------------------|-----------------------------
[=] (deprecated) | Yes (implicitly) | Reference (pointer) | ❌ No
[this] | Yes (explicitly) | Reference (pointer) | ❌ No
[*this] | Yes (by copy) | Copy of object | ✅ Yes (safe)

### Class types in non-type template parameters
**What is a Non-Type Template Parameter?**
In templates, non-type parameters are values, not types.
Example:
```c++
template<int N>
struct Array {
    int data[N];  // N is a value
};
```
Before C++20, only basic types like int, char, bool, or pointers could be used.

**What's New in C++20?**
> You can now use class types (like std::string_view, std::chrono::duration, user-defined struct, etc.) as non-type template parameters — as long as they are constexpr.
> 

```c++
#include <iostream>
#include <string_view>

template<std::string_view msg>
struct Logger {
    void log() const {
        std::cout << msg << "\n";
    }
};

int main() {
    Logger<"Hello from template!"> logger;
    logger.log();
}

```
### constexpr virtual functions
Before C++20, virtual functions couldn’t be constexpr because virtual dispatch requires runtime info, but constexpr means evaluation at compile-time.

C++20 allows constexpr virtual functions, meaning:
You can call virtual functions at compile-time if the call is on an object whose exact type is known at compile-time.

Enables more flexible constexpr polymorphism.

**✅ Key points:**
- The virtual function must be defined as constexpr.
- You can override virtual functions with constexpr.
- Compile-time calls happen if the dynamic type is known at compile time.
- Otherwise, virtual calls behave normally at runtime.

```c++
#include <iostream>

struct Base {
    virtual constexpr int getValue() const { return 1; }
    virtual ~Base() = default;
};

struct Derived : Base {
    constexpr int getValue() const override { return 42; }
};

int main() {
    constexpr Derived d;
    constexpr int val = d.getValue();  // OK: known type at compile-time
    std::cout << val << "\n";          // Outputs: 42

    Base* b = new Derived();
    std::cout << b->getValue() << "\n"; // Runtime call: Outputs 42

    delete b;
}
```
**Summary:**
Feature | Pre-C++20 | C++20
--------|-----------|------
constexpr virtual | ❌ | ✅ Allowed
Compile-time call | ❌ | ✅ If exact type known

### explicit(bool)
Before C++20, constructors could be either:
-  explicit (prevent implicit conversions), or
- non-explicit (allow implicit conversions).

Example before C++20:

```c++
struct A {
    explicit A(int x) { }
};

A a1 = 10;    // Error: can't implicitly convert int to A because constructor is explicit
A a2(10);     // O

```
**copy initialization.**
> ```c++
> A a1 = 10;
> ```
> This is called copy initialization. The compiler tries to convert the value 10 to type A implicitly by calling a constructor of A that can take an int.
**if constructor is explicit then explicit prevents the constructor from being used implicitly during copy initialization.**

**✅ What C++20 introduced:**
You can now write:
```c++
explicit(condition)
```

where condition is a compile-time boolean that controls whether the constructor is explicit or not.

**📌 Simple Example:**
```c++
#include <iostream>
#include <type_traits>

struct Number {
    int value;
    
    // Constructor is explicit **only if** T is integral (int, char, etc.)
    template<typename T>
    explicit(std::is_integral_v<T>)
    Number(T v) : value(v) {
        std::cout << "Constructor called with value: " << value
                  << (std::is_integral_v<T> ? " (explicit)\n" : " (implicit)\n");
    }
};

void printNumber(Number n) {
    std::cout << "Got a Number with value " << n.value << std::endl;
}

int main() {
    printNumber(3.14);     // double → implicit allowed, constructor called implicitly
    // printNumber(10);    // int → explicit constructor, so error if uncommented
    printNumber(Number(10)); // OK: explicit conversion by direct construction
    
    return 0;
}
/*
Constructor called with value: 3 (implicit)
Got a Number with value 3
Constructor called with value: 10 (explicit)
Got a Number with value 10
*/
```
### Immediate functions
**What is an immediate function (consteval)?**
- A function declared with consteval must be evaluated at compile time.
- You cannot call it at runtime; it only works in compile-time contexts.
- Use it when you want to guarantee the function runs during compilation (e.g., for generating constant values, checking conditions early, or metaprogramming).

**How is it different from constexpr?**
- constexpr functions can run at compile time or runtime.
- consteval functions must run at compile time only

```c++
#include <iostream>
consteval int square(int x) {
    return x * x;
}

int main() {
    constexpr int val = square(5);  // OK: compile-time evaluation
    std::cout << val << "\n";

    // int runtime_val = 10;
    // int result = square(runtime_val); // ERROR: cannot call consteval function with runtime value
    
    return 0;
}

```
### using enum
Bring an enum's members into scope to improve readability. Before:
```c++
enum class rgba_color_channel { red, green, blue, alpha };

std::string_view to_string(rgba_color_channel channel) {
  switch (channel) {
    case rgba_color_channel::red:   return "red";
    case rgba_color_channel::green: return "green";
    case rgba_color_channel::blue:  return "blue";
    case rgba_color_channel::alpha: return "alpha";
  }
}
```
After:
```c++
enum class rgba_color_channel { red, green, blue, alpha };

std::string_view to_string(rgba_color_channel my_channel) {
  switch (my_channel) {
    using enum rgba_color_channel;
    case red:   return "red";
    case green: return "green";
    case blue:  return "blue";
    case alpha: return "alpha";
  }
}
```

### Lambda capture of parameter pack
In C++20, you can directly capture a parameter pack in a lambda capture list using the syntax [...args], which wasn't allowed before C++20.

**Example**
```c++
#include <iostream>

template<typename... Args>
void printAll(Args... args) {
    // Capture all args by value in the lambda capture pack
    auto printer = [args...]() {
        // Using fold expression to print each argument
        ((std::cout << args << " "), ...);
        std::cout << "\n";
    };

/*
void printAll(Args&... args) {
    // Capture all args by reference
    auto printer = [&args...]() {
        ((std::cout << args << " "), ...);
        std::cout << "\n";
    };
    printer();
}
*/
int main() {
    printAll(1, 2, 3, 4, 5);
    printAll("hello", "world", 123);
}

```

### char8_t
Provides a standard type for representing UTF-8 strings.
```c++
char8_t utf8_str[] = u8"\u0123";
```

### constinit
The `constinit` specifier requires that a variable must be initialized at compile-time.
```c++
const char* g() { return "dynamic initialization"; }
constexpr const char* f(bool p) { return p ? "constant initializer" : g(); }

constinit const char* c = f(true); // OK
constinit const char* d = g(false); // ERROR: `g` is not constexpr, so `d` cannot be evaluated at compile-time.
```

### __VA\_OPT\_\_
Helps support variadic macros by evaluating to the given argument if the variadic macro is non-empty.

```c++
#include <iostream>

#define COUNT_ARGS(...) (sizeof((int[]){0 __VA_OPT__(, __VA_ARGS__)})/sizeof(int) - 1)

int main() {
    std::cout << COUNT_ARGS() << "\n";           // prints 0 (no arguments)
    std::cout << COUNT_ARGS(10) << "\n";         // prints 1
    std::cout << COUNT_ARGS(1, 2, 3, 4) << "\n"; // prints 4
}

```

## C++20 Library Features

### Concepts library
Concepts are also provided by the standard library for building more complicated concepts. Some of these include:

**Core language concepts:**
- `same_as` - specifies two types are the same.
- `derived_from` - specifies that a type is derived from another type.
- `convertible_to` - specifies that a type is implicitly convertible to another type.
- `common_with` - specifies that two types share a common type.
- `integral` - specifies that a type is an integral type.
- `default_constructible` - specifies that an object of a type can be default-constructed.

 **Comparison concepts:**
- `boolean` - specifies that a type can be used in Boolean contexts.
- `equality_comparable` - specifies that `operator==` is an equivalence relation.

 **Object concepts:**
- `movable` - specifies that an object of a type can be moved and swapped.
- `copyable` - specifies that an object of a type can be copied, moved, and swapped.
- `semiregular` - specifies that an object of a type can be copied, moved, swapped, and default constructed.
- `regular` - specifies that a type is _regular_, that is, it is both `semiregular` and `equality_comparable`.

 **Callable concepts:**
- `invocable` - specifies that a callable type can be invoked with a given set of argument types.
- `predicate` - specifies that a callable type is a Boolean predicate.

See also: [concepts](#concepts).

### Formatting library
Combine the simplicity of `printf` with the type-safety of `iostream`. Uses braces as placeholders, and supports custom formatting similar to printf-style specifiers.
```c++
std::format("{1} {0}", "world", "hello"); // == "hello world"

int x = 123;
std::string str = std::format("x: {}", x); // str == "x: 123"

// Format to an output iterator:
for (auto x : {1, 2, 3}) {
  std::format_to(std::ostream_iterator<char>{std::cout, "\n"}, "{}", x);
}
```

To format custom types:
```c++
#include <format>
#include <iostream>
#include <string>

// Custom type
struct Point {
    int x, y;
};

// Custom formatter for Point
template <>
struct std::formatter<Point> {
    constexpr auto parse(std::format_parse_context& ctx) {
        return ctx.begin(); // No custom format options
    }

    auto format(const Point& p, std::format_context& ctx) {
        return std::format_to(ctx.out(), "Point({}, {})", p.x, p.y);
    }
};

int main() {
    std::string name = "Alice";
    int age = 30;
    double pi = 3.14159;
    int number = 42;
    Point pt{10, 20};

    // Using std::format with various formatting options
    std::string output = std::format(
        "Name (left aligned): {:<10}\n"
        "Age (zero-padded): {:02}\n"
        "Pi (2 decimal places): {:.2f}\n"
        "Hex: {:#x}, Binary: {:#b}\n"
        "Custom Type: {}\n",
        name,        // {:<10} left-align in width 10
        age,         // {:02} pad with 0 to width 2
        pi,          // {:.2f} 2 decimal precision
        number,      // Hex and binary with prefix
        pt           // Custom type formatting
    );

    std::cout << output;

    return 0;
}

```

### Synchronized buffered outputstream
Buffers output operations for the wrapped output stream ensuring synchronization (i.e. no interleaving of output).
```c++
std::osyncstream{std::cout} << "The value of x is:" << x << std::endl;
```

### std::span
std::span is a lightweight, non-owning view over a contiguous sequence of elements (like arrays, std::vector, std::array). It allows you to pass arrays or parts of containers safely without copying data.
```c++
#include <iostream>
#include <span>
#include <vector>
#include <array>

void print(std::span<int> data) {
    for (int val : data) {
        std::cout << val << " ";
    }
    std::cout << "\n";
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    std::vector<int> vec = {10, 20, 30, 40};
    std::array<int, 3> stdarr = {7, 8, 9};

    std::cout << "Array: ";
    print(arr);  // span from C-style array

    std::cout << "Vector: ";
    print(vec);  // span from vector

    std::cout << "std::array: ";
    print(stdarr);  // span from std::array

    // Create a subspan (view of part of the data)
    std::cout << "Subspan of vector (first 2 elements): ";
    print(std::span<int>(vec).subspan(0, 2)); // span over part of vector

    return 0;
}

```

### Bit operations
C++20 provides a new `<bit>` header which provides some bit operations including popcount.
```c++
#include <iostream>
#include <bit>     // C++20
#include <bitset>  // For binary display
#include <cstdint> // For fixed-width integer types

void print(const std::string& label, uint32_t value) {
    std::cout << label << ": " << std::bitset<8>(value) << " (" << value << ")\n";
}

int main() {
    uint32_t x = 0b00011010; // 26 in decimal

    print("Original      ", x);

    // Bit rotation
    print("rotl(x, 2)    ", std::rotl(x, 2));   // Rotate left by 2 bits
    print("rotr(x, 2)    ", std::rotr(x, 2));   // Rotate right by 2 bits

    // Bit counting
    std::cout << "countl_zero  : " << std::countl_zero(x) << '\n';
    std::cout << "countl_one   : " << std::countl_one(x) << '\n';
    std::cout << "countr_zero  : " << std::countr_zero(x) << '\n';
    std::cout << "countr_one   : " << std::countr_one(x) << '\n';
    std::cout << "popcount     : " << std::popcount(x) << " (number of 1s)\n";

    // Bit utility functions
    uint32_t y = 70;
    std::cout << "\nFor value y = " << y << ":\n";
    std::cout << "bit_ceil     : " << std::bit_ceil(y) << " (next power of 2)\n";
    std::cout << "bit_floor    : " << std::bit_floor(y) << " (previous power of 2)\n";
    std::cout << "bit_width    : " << std::bit_width(y) << " (min bits to represent)\n";

    return 0;
}
/*
Original      : 00011010 (26)
rotl(x, 2)    : 01101000 (104)
rotr(x, 2)    : 10000110 (134)
countl_zero  : 3
countl_one   : 0
countr_zero  : 1
countr_one   : 0
popcount     : 4 (number of 1s)

For value y = 70:
bit_ceil     : 128 (next power of 2)
bit_floor    : 64 (previous power of 2)
bit_width    : 7 (min bits to represent)
*/
```

### Math constants
Mathematical constants including PI, Euler's number, etc. defined in the `<numbers>` header.
```c++
std::numbers::pi; // 3.14159...
std::numbers::e; // 2.71828...
```

### std::is_constant_evaluated
std::is_constant_evaluated() is a C++20 feature that tells you at runtime whether the current code is being evaluated at compile time (constexpr) or runtime.

📌 Useful when writing functions that behave differently depending on whether they are used in a constexpr context.


```c++
#include <iostream>
#include <type_traits> // std::is_constant_evaluated()

constexpr int compute() {
    if (std::is_constant_evaluated()) {
        return 42; // Used at compile time
    } else {
        return -1; // Used at runtime
    }
}

int main() {
    // Case 1: constexpr usage (evaluated at compile time)
    constexpr int a = compute(); 
    std::cout << "Compile-time result: " << a << "\n";

    // Case 2: runtime usage
    int b = compute(); 
    std::cout << "Runtime result: " << b << "\n";

    return 0;
}
/*
Compile-time result: 42
Runtime result: -1
*/
```

### std::make_shared supports arrays
```c++
auto p = std::make_shared<int[]>(5); // pointer to `int[5]`
// OR
auto p = std::make_shared<int[5]>(); // pointer to `int[5]`
```

### starts_with and ends_with on strings
Strings (and string views) now have the `starts_with` and `ends_with` member functions to check if a string starts or ends with the given string.
```c++
std::string str = "foobar";
str.starts_with("foo"); // true
str.ends_with("baz"); // false
```

### Check if associative container has element
Associative containers such as sets and maps have a `contains` member function, which can be used instead of the "find and check end of iterator" idiom.
```c++
std::map<int, char> map {{1, 'a'}, {2, 'b'}};
map.contains(2); // true
map.contains(123); // false

std::set<int> set {1, 2, 3};
set.contains(2); // true
```

### std::bit_cast
A safer way to reinterpret an object from one type to another.
```c++
#include <iostream>
#include <bit>
#include <bitset>
#include <cstdint>

// Define a simple color struct
struct Color {
    uint8_t r, g, b, a;
};

static_assert(std::is_trivially_copyable_v<Color>, "Color must be trivially copyable");
static_assert(sizeof(Color) == 4, "Color must be 4 bytes");

void print_bits(const std::string& label, uint32_t bits) {
    std::cout << label << ": 0x" << std::hex << bits << " (" << std::bitset<32>(bits) << ")" << std::dec << "\n";
}

int main() {
    // ========================================
    // 1. Float to uint32_t using bit_cast
    // ========================================
    float pi = 3.14f;
    uint32_t floatBits = std::bit_cast<uint32_t>(pi);
    std::cout << "1️⃣  Float → Bits:\n";
    std::cout << "Float: " << pi << "\n";
    print_bits("Bits ", floatBits);
    std::cout << "\n";

    // ========================================
    // 2. uint32_t to float using bit_cast
    // ========================================
    uint32_t piRaw = 0x4048F5C3;  // Bit pattern for 3.14f
    float piRecovered = std::bit_cast<float>(piRaw);
    std::cout << "2️⃣  Bits → Float:\n";
    print_bits("Raw bits", piRaw);
    std::cout << "Recovered float: " << piRecovered << "\n\n";

    // ========================================
    // 3. Struct to uint32_t (pack color)
    // ========================================
    Color color = {255, 128, 64, 32};
    uint32_t packedColor = std::bit_cast<uint32_t>(color);
    std::cout << "3️⃣  Struct → Packed Bits:\n";
    std::cout << "Color RGBA = (" << (int)color.r << ", " << (int)color.g << ", "
              << (int)color.b << ", " << (int)color.a << ")\n";
    print_bits("Packed color", packedColor);
    std::cout << "\n";

    // ========================================
    // 4. uint32_t to Struct (unpack color)
    // ========================================
    uint32_t rawColor = 0x204080FF;
    Color unpackedColor = std::bit_cast<Color>(rawColor);
    std::cout << "4️⃣  Bits → Struct:\n";
    print_bits("Raw color bits", rawColor);
    std::cout << "Unpacked RGBA = (" << (int)unpackedColor.r << ", "
              << (int)unpackedColor.g << ", " << (int)unpackedColor.b << ", "
              << (int)unpackedColor.a << ")\n\n";

    // ========================================
    // 5. Constexpr bit_cast
    // ========================================
    constexpr float constVal = 1.0f;
    constexpr uint32_t constBits = std::bit_cast<uint32_t>(constVal);
    static_assert(std::bit_cast<float>(constBits) == 1.0f, "bit_cast failed at compile-time");

    std::cout << "5️⃣  Constexpr Float → Bits:\n";
    std::cout << "Constexpr float: " << constVal << "\n";
    print_bits("Constexpr bits", constBits);

    return 0;
}
/*
1️⃣  Float → Bits:
Float: 3.14
Bits : 0x4048f5c3 (01000000010010001111010111000011)

2️⃣  Bits → Float:
Raw bits: 0x4048f5c3 (01000000010010001111010111000011)
Recovered float: 3.14

3️⃣  Struct → Packed Bits:
Color RGBA = (255, 128, 64, 32)
Packed color: 0x204080ff (00100000010000001000000011111111)

4️⃣  Bits → Struct:
Raw color bits: 0x204080ff (00100000010000001000000011111111)
Unpacked RGBA = (255, 128, 64, 32)

5️⃣  Constexpr Float → Bits:
Constexpr float: 1
Constexpr bits: 0x3f800000 (00111111100000000000000000000000)
*/
```

### std::midpoint
Calculate the midpoint of two integers safely (without overflow).
```c++
std::midpoint(1, 3); // == 2
```

### std::to_array
Converts the given array/"array-like" object to a `std::array`.
```c++
#include <iostream>
#include <array>
#include <string_view>

// A simple struct to demonstrate with to_array
struct Point {
    int x, y;
};

int main() {
    // 1️⃣ Integer initializer list
    auto int_array = std::to_array({10, 20, 30, 40});
    std::cout << "1. Integer array:\n";
    for (int v : int_array) {
        std::cout << v << " ";
    }
    std::cout << "\nSize: " << int_array.size() << "\n\n";

    // 2️⃣ String literal to std::array<char, N>
    auto char_array = std::to_array("Hello");
    std::cout << "2. Char array from string literal:\n";
    for (char c : char_array) {
        std::cout << (c == '\0' ? '\\' : c) << " ";
    }
    std::cout << "\nSize: " << char_array.size() << " (includes null terminator)\n\n";

    // 3️⃣ C-style array to std::array
    constexpr int c_array[] = {1, 2, 3, 4, 5};
    auto std_array = std::to_array(c_array); // Automatically deduces size and type
    std::cout << "3. Converted from C-style array:\n";
    for (int v : std_array) {
        std::cout << v << " ";
    }
    std::cout << "\nSize: " << std_array.size() << "\n\n";

    // 4️⃣ Custom struct array
    auto point_array = std::to_array({Point{1, 2}, Point{3, 4}});
    std::cout << "4. Struct array (Points):\n";
    for (const auto& p : point_array) {
        std::cout << "(" << p.x << ", " << p.y << ") ";
    }
    std::cout << "\nSize: " << point_array.size() << "\n";

    return 0;
}
/*
1. Integer array:
10 20 30 40 
Size: 4

2. Char array from string literal:
H e l l o \ 
Size: 6 (includes null terminator)

3. Converted from C-style array:
1 2 3 4 5 
Size: 5

4. Struct array (Points):
(1, 2) (3, 4) 
Size: 2
*/
```

### std::bind_front
Binds the first N arguments (where N is the number of arguments after the given function to `std::bind_front`) to a given free function, lambda, or member function.
```c++
#include <iostream>
#include <functional>

void greet(const std::string& prefix, const std::string& name) {
    std::cout << prefix << " " << name << "!\n";
}

int main() {
    // Bind the first argument ("Hello") permanently
    auto say_hello = std::bind_front(greet, "Hello");

    say_hello("Alice");  // Output: Hello Alice!
    say_hello("Bob");    // Output: Hello Bob!

    return 0;
}
/*
Hello Alice!
Hello Bob!
*/
```

### Uniform container erasure
Provides `std::erase` and/or `std::erase_if` for a variety of STL containers such as string, list, vector, map, etc.

For erasing by value use `std::erase`, or to specify a predicate when to erase elements use `std::erase_if`. Both functions return the number of erased elements.

```c++
std::vector v{0, 1, 0, 2, 0, 3};
std::erase(v, 0); // v == {1, 2, 3}
std::erase_if(v, [](int n) { return n == 0; }); // v == {1, 2, 3}
```

### Three-way comparison helpers
Helper functions for giving names to comparison results:
```c++
std::is_eq(0 <=> 0); // == true
std::is_lteq(0 <=> 1); // == true
std::is_gt(0 <=> 1); // == false
```

See also: [three-way comparison](#three-way-comparison).

### std::lexicographical_compare_three_way
std::lexicographical_compare_three_way is a C++20 function that compares two sequences (like strings or arrays) element by element, using the spaceship operator (<=>), and returns the result of the comparison.

It's like a 3-way version of std::lexicographical_compare, but returns a strong/weak/partial ordering instead of just true/false.
```c++
#include <iostream>
#include <compare>   // for comparison categories
#include <algorithm> // for std::lexicographical_compare_three_way
#include <string>

int main() {
    std::string a = "apple";
    std::string b = "apricot";

    auto result = std::lexicographical_compare_three_way(
        a.begin(), a.end(),
        b.begin(), b.end()
    );

    if (result < 0)
        std::cout << a << " < " << b << "\n";
    else if (result > 0)
        std::cout << a << " > " << b << "\n";
    else
        std::cout << a << " == " << b << "\n";

    return 0;
}
// apple < apricot
```

See also: [three-way comparison](#three-way-comparison), [three-way comparison helpers](#three-way-comparison-helpers).

## Acknowledgements
* [cppreference](http://en.cppreference.com/w/cpp) - especially useful for finding examples and documentation of new library features.
* [C++ Rvalue References Explained](http://web.archive.org/web/20240324121501/http://thbecker.net/articles/rvalue_references/section_01.html) - a great introduction I used to understand rvalue references, perfect forwarding, and move semantics.
* [clang](http://clang.llvm.org/cxx_status.html) and [gcc](https://gcc.gnu.org/projects/cxx-status.html)'s standards support pages. Also included here are the proposals for language/library features that I used to help find a description of, what it's meant to fix, and some examples.
* [Compiler explorer](https://godbolt.org/)
* [Scott Meyers' Effective Modern C++](https://www.amazon.com/Effective-Modern-Specific-Ways-Improve/dp/1491903996) - highly recommended book!
* [Jason Turner's C++ Weekly](https://www.youtube.com/channel/UCxHAlbZQNFU2LgEtiqd2Maw) - nice collection of C++-related videos.
* [What can I do with a moved-from object?](http://stackoverflow.com/questions/7027523/what-can-i-do-with-a-moved-from-object)
* [What are some uses of decltype(auto)?](http://stackoverflow.com/questions/24109737/what-are-some-uses-of-decltypeauto)
* And many more SO posts I'm forgetting...

## Author
Haresh Panchal

## Content Contributors
See: https://github.com/AnthonyCalandra/modern-cpp-features/graphs/contributors

## License
MIT