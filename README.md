<p align="center">
  <img src="https://cdn-icons-png.flaticon.com/512/6132/6132222.png" width="60" alt="C++ Logo">
</p>

<h1 align="center">CPP Module 08</h1>

## Overview

CPP Module 08 introduces the **Standard Template Library (STL)**, focusing on containers, iterators, algorithms, and container adapters.

The STL provides reusable classes and functions for storing, accessing, searching, sorting, and manipulating collections of data.

Each exercise focuses on a different part of the STL:

* **ex00:** Implement `easyfind`, a function template that searches for an integer inside a container.
* **ex01:** Implement a `Span` class that stores integers and calculates the shortest and longest distance between them.
* **ex02:** Implement `MutantStack`, an iterable version of `std::stack`.

---

## Concepts Learned

<details>
<summary>Standard Template Library (STL)</summary>

---

The **Standard Template Library**, or STL, is a collection of reusable C++ components.

It mainly consists of:

* **Containers** for storing data.
* **Iterators** for navigating through containers.
* **Algorithms** for searching, sorting, and manipulating data.
* **Container adapters** that provide specialized interfaces.

Example:

```cpp
std::vector<int> numbers;

numbers.push_back(10);
numbers.push_back(20);
numbers.push_back(30);
```

The vector stores several integers and automatically manages its own memory.

Common STL headers include:

```cpp
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <algorithm>
#include <iterator>
```

</details>

---

<details>
<summary>Containers</summary>

---

A **container** is a class that stores a collection of objects.

```cpp
std::vector<int> numbers;
std::list<int> values;
std::deque<int> queue;
```

Different containers are designed for different operations.

| Container     | Description                                          |
| ------------- | ---------------------------------------------------- |
| `std::vector` | Dynamic array with fast random access.               |
| `std::list`   | Doubly linked list with fast insertion and deletion. |
| `std::deque`  | Double-ended queue with fast insertion at both ends. |
| `std::set`    | Stores unique values in sorted order.                |
| `std::map`    | Stores sorted key-value pairs.                       |
| `std::stack`  | Last-in, first-out container adapter.                |

For example:

```cpp
std::vector<int> numbers;

numbers.push_back(10);
numbers.push_back(20);
numbers.push_back(30);
```

The resulting vector contains:

```text
10 20 30
```

</details>

---

<details>
<summary>Sequential Containers</summary>

---

Sequential containers store elements in a specific order.

Examples include:

```cpp
std::vector<int>
std::list<int>
std::deque<int>
```

They provide iterator functions such as:

```cpp
container.begin();
container.end();
```

In `easyfind`, the container is assumed to contain integers:

```cpp
template <typename T>
typename T::iterator easyfind(T& container, int value);
```

The function can therefore work with several sequential container types without duplicating code.

</details>

---

<details>
<summary>std::vector</summary>

---

`std::vector` is a dynamic array whose size can grow or shrink at runtime.

```cpp
std::vector<int> numbers;

numbers.push_back(10);
numbers.push_back(20);
numbers.push_back(30);
```

Its elements are stored next to each other in memory:

```text
+----+----+----+
| 10 | 20 | 30 |
+----+----+----+
```

Common member functions:

```cpp
numbers.push_back(42);
numbers.size();
numbers.begin();
numbers.end();
numbers.empty();
```

Elements can also be accessed by index:

```cpp
std::cout << numbers[0] << std::endl;
```

`std::vector` is used in the `Span` class because it:

* grows dynamically,
* supports fast insertion at the end,
* provides random-access iterators,
* works with algorithms such as `std::sort`,
* supports iterator ranges.

</details>

---

<details>
<summary>Iterators</summary>

---

An **iterator** is an object used to navigate through a container.

It behaves similarly to a pointer.

```cpp
std::vector<int>::iterator it;
```

An iterator can point to the beginning of a container:

```cpp
it = numbers.begin();
```

The value can be accessed by dereferencing the iterator:

```cpp
std::cout << *it << std::endl;
```

The iterator can be moved forward:

```cpp
++it;
```

Example:

```cpp
std::vector<int>::iterator it = numbers.begin();

while (it != numbers.end())
{
    std::cout << *it << std::endl;
    ++it;
}
```

Important iterator operations:

| Operation     | Meaning                                                |
| ------------- | ------------------------------------------------------ |
| `begin()`     | Iterator pointing to the first element.                |
| `end()`       | Iterator pointing one position after the last element. |
| `*it`         | Access the value pointed to by the iterator.           |
| `++it`        | Move to the next element.                              |
| `it != end()` | Check whether the iterator reached the end.            |

</details>

---

<details>
<summary>begin() and end()</summary>

---

STL containers define a range using two iterators:

```cpp
container.begin();
container.end();
```

`begin()` points to the first element.

`end()` points one position after the last element.

```text
begin()
   │
   ▼
+----+----+----+      end()
| 10 | 20 | 30 |        │
+----+----+----+         ▼
```

`end()` does not point to a valid element and must not be dereferenced.

A common loop is:

```cpp
std::vector<int>::iterator it = numbers.begin();

while (it != numbers.end())
{
    std::cout << *it << std::endl;
    ++it;
}
```

</details>

---

<details>
<summary>STL Algorithms</summary>

---

STL algorithms are reusable functions that operate on iterator ranges.

Common algorithms used in CPP08 include:

```cpp
std::find();
std::sort();
std::min_element();
std::max_element();
std::distance();
```

Most algorithms receive two iterators:

```cpp
algorithm(container.begin(), container.end());
```

This represents the range:

```text
[first element, one position after the last element)
```

Example:

```cpp
std::sort(numbers.begin(), numbers.end());
```

This sorts every element inside the vector.

Algorithms are defined in:

```cpp
#include <algorithm>
```

</details>

---

<details>
<summary>std::find</summary>

---

`std::find` searches for the first occurrence of a value inside an iterator range.

```cpp
std::find(container.begin(), container.end(), value);
```

It returns:

* an iterator pointing to the first matching element, or
* `container.end()` if the value is not found.

Example:

```cpp
std::vector<int>::iterator result;

result = std::find(numbers.begin(), numbers.end(), 20);

if (result != numbers.end())
    std::cout << "Found: " << *result << std::endl;
```

In `easyfind`:

```cpp
template <typename T>
typename T::iterator easyfind(T& container, int value)
{
    typename T::iterator result;

    result = std::find(container.begin(), container.end(), value);

    if (result == container.end())
        throw std::runtime_error("Value not found");

    return (result);
}
```

</details>

---

<details>
<summary>typename T::iterator</summary>

---

Inside a template, the container type is not known until compilation.

```cpp
template <typename T>
typename T::iterator easyfind(T& container, int value);
```

If `T` becomes:

```cpp
std::vector<int>
```

then:

```cpp
T::iterator
```

becomes:

```cpp
std::vector<int>::iterator
```

The `typename` keyword tells the compiler that `T::iterator` represents a type.

Without `typename`, the compiler cannot know whether `iterator` is a type, variable, or static member.

</details>

---

<details>
<summary>Function Templates</summary>

---

A function template allows one function to work with different types.

```cpp
template <typename T>
typename T::iterator easyfind(T& container, int value)
{
    // ...
}
```

The compiler generates the correct version depending on the container passed to the function.

Examples:

```cpp
std::vector<int> vectorValues;
std::list<int> listValues;
std::deque<int> dequeValues;

easyfind(vectorValues, 42);
easyfind(listValues, 42);
easyfind(dequeValues, 42);
```

The same function works with all three container types.

</details>

---

<details>
<summary>Why easyfind Returns an Iterator</summary>

---

`easyfind` returns an iterator instead of returning the integer itself.

```cpp
typename T::iterator easyfind(T& container, int value);
```

This follows the behavior of standard algorithms such as `std::find`.

The iterator provides access to:

* the matching value,
* its position inside the container,
* the remaining elements after it.

Example:

```cpp
std::vector<int>::iterator result;

result = easyfind(numbers, 20);

std::cout << *result << std::endl;
```

Dereferencing the iterator returns the stored integer.

</details>

---

<details>
<summary>Container Ranges</summary>

---

A range is represented by two iterators:

```cpp
begin
end
```

The first iterator points to the beginning of the range.

The second iterator points one position after its final element.

```cpp
sp.addRange(values.begin(), values.end());
```

This means:

```text
Add every element from values.begin()
up to, but not including, values.end()
```

The same range pattern is used throughout the STL:

```cpp
std::find(begin, end, value);
std::sort(begin, end);
std::copy(begin, end, destination);
```

</details>

---

<details>
<summary>Adding a Range of Iterators</summary>

---

The `Span` class can add multiple numbers using an iterator range.

```cpp
template <typename Iterator>
void Span::addRange(Iterator begin, Iterator end)
{
    while (begin != end)
    {
        addNumber(*begin);
        ++begin;
    }
}
```

Example:

```cpp
std::vector<int> values;

values.push_back(6);
values.push_back(3);
values.push_back(17);
values.push_back(9);
values.push_back(11);

Span sp(5);

sp.addRange(values.begin(), values.end());
```

This avoids making thousands of separate calls to `addNumber()`.

Because `addRange()` is a function template, its implementation must remain visible to the compiler.

It can be implemented:

* directly inside `Span.hpp`, or
* inside a `.tpp` file included by `Span.hpp`.

</details>

---

<details>
<summary>std::sort</summary>

---

`std::sort` arranges elements from smallest to largest by default.

```cpp
std::sort(numbers.begin(), numbers.end());
```

Before sorting:

```text
6 3 17 9 11
```

After sorting:

```text
3 6 9 11 17
```

In `shortestSpan()`, sorting makes it possible to compare only neighboring values.

```text
6 - 3   = 3
9 - 6   = 3
11 - 9  = 2
17 - 11 = 6
```

The shortest span is:

```text
2
```

`std::sort` requires random-access iterators, which are provided by containers such as `std::vector` and `std::deque`.

</details>

---

<details>
<summary>Shortest Span</summary>

---

The shortest span is the smallest distance between any two stored numbers.

Example:

```text
6 3 17 9 11
```

First, copy and sort the numbers:

```text
3 6 9 11 17
```

Then compare neighboring elements:

```text
6 - 3   = 3
9 - 6   = 3
11 - 9  = 2
17 - 11 = 6
```

Implementation:

```cpp
int Span::shortestSpan() const
{
    if (numbers.size() < 2)
        throw std::runtime_error("Not enough numbers");

    std::vector<int> sortedNumbers = numbers;

    std::sort(sortedNumbers.begin(), sortedNumbers.end());

    int shortest = sortedNumbers[1] - sortedNumbers[0];

    for (unsigned int i = 1; i < sortedNumbers.size(); i++)
    {
        int difference;

        difference = sortedNumbers[i] - sortedNumbers[i - 1];

        if (difference < shortest)
            shortest = difference;
    }

    return (shortest);
}
```

The original vector is copied so its order remains unchanged.

</details>

---

<details>
<summary>Longest Span</summary>

---

The longest span is the distance between the smallest and largest stored numbers.

Example:

```text
6 3 17 9 11
```

The smallest value is:

```text
3
```

The largest value is:

```text
17
```

Therefore:

```text
17 - 3 = 14
```

Implementation:

```cpp
int Span::longestSpan() const
{
    if (numbers.size() < 2)
        throw std::runtime_error("Not enough numbers");

    int minimum;
    int maximum;

    minimum = *std::min_element(numbers.begin(), numbers.end());
    maximum = *std::max_element(numbers.begin(), numbers.end());

    return (maximum - minimum);
}
```

</details>

---

<details>
<summary>std::min_element and std::max_element</summary>

---

`std::min_element` returns an iterator pointing to the smallest element.

```cpp
std::min_element(numbers.begin(), numbers.end());
```

`std::max_element` returns an iterator pointing to the largest element.

```cpp
std::max_element(numbers.begin(), numbers.end());
```

Because they return iterators, they must be dereferenced to obtain the stored value:

```cpp
int minimum = *std::min_element(numbers.begin(), numbers.end());
int maximum = *std::max_element(numbers.begin(), numbers.end());
```

For:

```text
6 3 17 9 11
```

the results are:

```text
minimum = 3
maximum = 17
```

</details>

---

<details>
<summary>std::distance</summary>

---

`std::distance` calculates the number of iterator steps between two positions.

```cpp
std::distance(container.begin(), result);
```

Example:

```cpp
std::vector<int> numbers;

numbers.push_back(10);
numbers.push_back(20);
numbers.push_back(30);

std::vector<int>::iterator result = easyfind(numbers, 30);

std::cout << std::distance(numbers.begin(), result);
```

Output:

```text
2
```

The value `30` is stored at index `2`.

`std::distance` is defined in:

```cpp
#include <iterator>
```

</details>

---

<details>
<summary>Container Capacity and size()</summary>

---

The `Span` class stores a maximum number of integers.

```cpp
unsigned int     maxNumber;
std::vector<int> numbers;
```

`maxNumber` represents the maximum allowed number of elements.

```cpp
Span sp(5);
```

Here:

```text
maxNumber = 5
```

`numbers.size()` returns the number of elements currently stored.

```cpp
if (numbers.size() >= maxNumber)
    throw std::runtime_error("Span is full");
```

If the vector already contains `maxNumber` elements, another number cannot be added.

```cpp
numbers.push_back(number);
```

`push_back()` adds the new number to the end of the vector.

</details>

---

<details>
<summary>Exceptions</summary>

---

Exceptions are used to report runtime errors safely.

The main keywords are:

* `throw` signals an error.
* `try` contains code that may throw an exception.
* `catch` handles the exception.

Example:

```cpp
void Span::addNumber(int number)
{
    if (numbers.size() >= maxNumber)
        throw std::runtime_error("Span is full");

    numbers.push_back(number);
}
```

The exception can be handled in `main()`:

```cpp
try
{
    sp.addNumber(42);
}
catch (const std::exception& e)
{
    std::cout << e.what() << std::endl;
}
```

`e.what()` returns the exception message.

</details>

---

<details>
<summary>std::runtime_error</summary>

---

`std::runtime_error` is a standard exception class used to represent errors detected while the program is running.

It is defined in:

```cpp
#include <stdexcept>
```

Example:

```cpp
throw std::runtime_error("Span is full");
```

This creates and throws an exception containing the message:

```text
Span is full
```

`std::runtime_error` inherits from `std::exception`, so it can be caught using:

```cpp
catch (const std::exception& e)
{
    std::cout << e.what() << std::endl;
}
```

A custom exception class can also be used:

```cpp
class SpanFullException : public std::exception
{
    public:
        virtual const char* what() const throw()
        {
            return ("Span is full");
        }
};
```

Then:

```cpp
throw SpanFullException();
```

</details>

---

<details>
<summary>Container Adapters</summary>

---

A container adapter provides a restricted interface built on top of another container.

Examples include:

```cpp
std::stack
std::queue
std::priority_queue
```

Unlike normal containers, adapters do not directly expose iterators.

For example, `std::stack` only exposes operations such as:

```cpp
push();
pop();
top();
empty();
size();
```

It does not provide:

```cpp
begin();
end();
```

CPP08 ex02 solves this limitation by creating `MutantStack`, which inherits from `std::stack` and exposes iterators from its underlying container.

</details>

---

<details>
<summary>std::stack</summary>

---

`std::stack` is a Last-In, First-Out container adapter.

```text
Top
 │
 ▼
+----+
| 30 |
+----+
| 20 |
+----+
| 10 |
+----+
```

The last element added is the first element removed.

Example:

```cpp
std::stack<int> stack;

stack.push(10);
stack.push(20);
stack.push(30);

std::cout << stack.top() << std::endl;
```

Output:

```text
30
```

Common operations:

| Function  | Purpose                            |
| --------- | ---------------------------------- |
| `push()`  | Adds an element to the top.        |
| `pop()`   | Removes the top element.           |
| `top()`   | Accesses the top element.          |
| `size()`  | Returns the number of elements.    |
| `empty()` | Checks whether the stack is empty. |

By default, `std::stack` uses `std::deque` as its underlying container.

</details>

---

<details>
<summary>Underlying Container of std::stack</summary>

---

`std::stack` is implemented on top of another container.

Conceptually:

```cpp
template <
    typename T,
    typename Container = std::deque<T>
>
class stack;
```

The underlying container is stored in a protected member named:

```cpp
c
```

A derived class can access this member:

```cpp
this->c
```

For example:

```cpp
iterator begin()
{
    return (this->c.begin());
}
```

This allows `MutantStack` to expose iterators even though `std::stack` normally does not provide them.

</details>

---

<details>
<summary>MutantStack</summary>

---

`MutantStack` is a class template that inherits from `std::stack`.

```cpp
template <typename T>
class MutantStack : public std::stack<T>
{
    // ...
};
```

It behaves like a normal stack but also provides iterators.

```cpp
MutantStack<int> stack;

stack.push(10);
stack.push(20);
stack.push(30);
```

The elements can then be traversed:

```cpp
MutantStack<int>::iterator it = stack.begin();

while (it != stack.end())
{
    std::cout << *it << std::endl;
    ++it;
}
```

A normal `std::stack` cannot be traversed this way because it does not expose `begin()` and `end()`.

</details>

---

<details>
<summary>Exposing Iterators from MutantStack</summary>

---

The iterator type can be taken from the underlying container:

```cpp
typedef typename std::stack<T>::container_type::iterator iterator;
```

Then `begin()` and `end()` can expose the underlying container's iterators:

```cpp
iterator begin()
{
    return (this->c.begin());
}

iterator end()
{
    return (this->c.end());
}
```

Const iterators can also be provided:

```cpp
typedef typename std::stack<T>::container_type::const_iterator const_iterator;

const_iterator begin() const
{
    return (this->c.begin());
}

const_iterator end() const
{
    return (this->c.end());
}
```

This preserves normal stack behavior while allowing iteration.

</details>

---

<details>
<summary>typedef</summary>

---

`typedef` creates an alternative name for an existing type.

```cpp
typedef typename std::stack<T>::container_type::iterator iterator;
```

Without `typedef`, the full iterator type would need to be written repeatedly:

```cpp
typename std::stack<T>::container_type::iterator
```

After defining the alias, it can be written simply as:

```cpp
iterator
```

Example:

```cpp
iterator begin()
{
    return (this->c.begin());
}
```

</details>

---

<details>
<summary>Inheritance from STL Classes</summary>

---

`MutantStack` publicly inherits from `std::stack`.

```cpp
template <typename T>
class MutantStack : public std::stack<T>
{
};
```

This means `MutantStack` inherits stack operations such as:

```cpp
push();
pop();
top();
size();
empty();
```

Example:

```cpp
MutantStack<int> stack;

stack.push(10);
stack.push(20);

std::cout << stack.top() << std::endl;
```

Because the inheritance is public, the public interface of `std::stack` remains public in `MutantStack`.

</details>

---

<details>
<summary>Orthodox Canonical Form</summary>

---

The Orthodox Canonical Form defines how an object is created, copied, assigned, and destroyed.

```cpp
ClassName();
ClassName(const ClassName& other);
ClassName& operator=(const ClassName& other);
~ClassName();
```

For the `Span` class:

```cpp
Span();
Span(unsigned int number);
Span(const Span& other);
Span& operator=(const Span& other);
~Span();
```

The copy constructor and assignment operator copy:

```cpp
maxNumber
numbers
```

Because `std::vector` manages its own memory, assigning one vector to another automatically performs a proper element-by-element copy.

```cpp
numbers = other.numbers;
```

</details>

---

<details>
<summary>Algorithm Complexity</summary>

---

Algorithm complexity describes how execution time grows as the amount of data increases.

| Operation             | Complexity     |
| --------------------- | -------------- |
| `vector::push_back()` | O(1) amortized |
| `std::find()`         | O(n)           |
| `std::min_element()`  | O(n)           |
| `std::max_element()`  | O(n)           |
| `std::sort()`         | O(n log n)     |
| `shortestSpan()`      | O(n log n)     |
| `longestSpan()`       | O(n)           |

`shortestSpan()` must sort the numbers before comparing neighboring values.

`longestSpan()` only needs to find the minimum and maximum values, so sorting is unnecessary.

</details>

---

<details>
<summary>Testing with 10,000 Numbers</summary>

---

The subject requires testing `Span` with at least 10,000 numbers.

Example:

```cpp
Span sp(10000);

for (int i = 0; i < 10000; i++)
    sp.addNumber(i);

std::cout << sp.shortestSpan() << std::endl;
std::cout << sp.longestSpan() << std::endl;
```

Expected output:

```text
1
9999
```

Because the stored numbers are:

```text
0 1 2 3 ... 9999
```

The shortest distance is:

```text
1
```

The longest distance is:

```text
9999 - 0 = 9999
```

A range of iterators can also be used to fill the span more conveniently.

</details>

---

## Exercises

| Exercise | Description                                                | Main Concepts                                          |
| -------- | ---------------------------------------------------------- | ------------------------------------------------------ |
| `ex00`   | Search for an integer inside a container using `easyfind`. | Function templates, iterators, `std::find`, exceptions |
| `ex01`   | Store integers and calculate shortest and longest spans.   | `std::vector`, iterator ranges, algorithms, exceptions |
| `ex02`   | Create an iterable version of `std::stack`.                | Container adapters, inheritance, iterators, `typedef`  |

---

## Resources

* https://cplusplus.com/reference/stl/
* https://cplusplus.com/reference/vector/vector/
* https://cplusplus.com/reference/algorithm/find/
* https://cplusplus.com/reference/algorithm/sort/
* https://cplusplus.com/reference/algorithm/min_element/
* https://cplusplus.com/reference/algorithm/max_element/
* https://cplusplus.com/reference/stack/stack/
* https://www.geeksforgeeks.org/cpp/the-c-standard-template-library-stl/
