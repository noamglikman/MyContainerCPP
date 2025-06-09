noamglikman1@gmail.com
---

## Compilation & Execution

The project uses a standard `Makefile`. Run the following commands from the project root:

| Command         | Description                                |
| `make demo_run`     | Compile and run the demo program           |
| `make test_run`     | Compile and run unit tests with doctest    |
| `make valgrind` | Run memory checks with valgrind            |
| `make clean`    | Remove build files and executables         |

---

## Class: MyContainer

The `MyContainer` class is a dynamic container supporting any comparable type.

### Key Methods:
- `void add(const T& element)` — Add an element to the container.
- `void remove(const T& element)` — Remove **all** occurrences of an element. Throws an exception if not found.
- `size_t size() const` — Return the current size of the container.
- `friend std::ostream& operator<<` — Print the container contents.

### Template Support:
The class is templated to support types like `int`, `double`, `std::string`, etc.

---

## Iterators

Each iterator supports `begin()` and `end()` methods and overloads `*`, `++`, `==`, `!=`.

* **Project stracture:**
```bash
.
├── HPP
│   ├── AscendingOrder.hpp
│   ├── DescendingOrder.hpp
│   ├── MiddleOutOrder.hpp
│   ├── MyContainer.hpp
│   ├── Order.hpp
│   ├── ReverseOrder.hpp
│   ├── SideCrossOrder.hpp
│   └── doctest.h
├── OBJ
│   └── tests.o
├── ReadME.md
├── demo.cpp
├── makefile
├── tests
└── tests.cpp
```
### Supported Iterators:

| Name               | Description |
|--------------------|-------------|
| `AscendingOrder`   | Sorts in increasing order. E.g., `[1, 2, 6, 7, 15]` |
| `DescendingOrder`  | Sorts in decreasing order. E.g., `[15, 7, 6, 2, 1]` |
| `SideCrossOrder`   | Alternates smallest, largest, next smallest, next largest... E.g., `[1, 15, 2, 7, 6]` |
| `ReverseOrder`     | Reverses the original insertion order. E.g., `[2, 1, 6, 15, 7]` |
| `Order`            | Keeps original insertion order. E.g., `[7, 15, 6, 1, 2]` |
| `MiddleOutOrder`   | Starts from the middle, alternating left and right. E.g., `[6, 15, 1, 7, 2]` |

---

## Unit Testing

The project uses [doctest]

- All member functions of `MyContainer`
- Edge cases (e.g., removing non-existing elements)
- All iterators and their traversal logic
## list of all test

MyContainer Tests

1. MyContainer basic operations
   - Adds three elements (5, 10, 15)
   - Checks size is 3
   - Checks data matches a vector with the added values

2. MyContainer with empty container
   - Checks an empty container (no additions)
   - Checks size is 0
   - Checks the data vector is indeed empty

3. MyContainer with single element
   - Adds one element (42)
   - Checks size is 1
   - Checks data contains only the added value

4. MyContainer remove elements
   - Adds three elements (1, 2, 3)
   - Removes element 2
   - Checks size is 2
   - Checks data contains only elements 1 and 3

5. MyContainer remove non-existing element
   - Adds two elements (1, 2)
   - Attempts to remove a non-existing element (3)
   - Checks that the operation throws std::runtime_error
   - Checks size remains 2
   - Checks data is unchanged

6. MyContainer size method
   - Checks size of empty container (0)
   - Adds one element and checks size (1)
   - Adds another element and checks size (2)
   - Removes one element and checks size (1)
   - Removes another element and checks size (0)

AscendingIterator Tests

7. AscendingIterator basic iteration test
   - Adds several elements (7, 15, 6, 1, 2)
   - Iterates over the container in ascending order
   - Checks the iteration returns the values sorted: {1, 2, 6, 7, 15}

8. AscendingIterator with empty container
   - Checks iteration on empty container
   - Checks that the begin iterator equals the end iterator (no elements to iterate)

9. AscendingIterator with single element
   - Adds one element (42)
   - Checks that the iterator start is not equal to end
   - Checks the returned value is 42
   - Advances iterator and checks it reaches the end

10. AscendingIterator with duplicate elements
    - Adds elements with duplicates (3, 1, 3, 2, 1)
    - Checks iteration returns a sorted vector with duplicates: {1, 1, 2, 3, 3}

11. AscendingIterator should not modify the original container
    - Adds elements (5, 2, 9)
    - Checks iteration does not modify the original container (original vector remains the same)
AscendingIterator Tests

12. AscendingIterator with strings
   - Adds strings ("banana", "apple", "cherry")
   - Iterates over the container in ascending alphabetical order
   - Checks the iteration returns: {"apple", "banana", "cherry"}

13. AscendingIterator with double values
   - Adds double values (3.14, 2.71, 1.41)
   - Iterates over the container in ascending numerical order
   - Checks the iteration returns: {1.41, 2.71, 3.14}


DescendingIterator Tests

14. Empty container
   - Tests descending iteration on an empty container
   - Checks that the begin iterator equals the end iterator (no elements)

15. Single element container
   - Adds a single element (42)
   - Tests descending iteration returns that element first
   - Checks iterator advances to end after the element

16. Multiple elements, distinct
   - Adds multiple distinct elements (10, 20, 5)
   - Tests descending iteration returns elements in descending order: {20, 10, 5}

17. Multiple elements, duplicates
   - Adds multiple elements with duplicates (5, 10, 5, 20, 10)
   - Tests descending iteration returns elements in descending order including duplicates: {20, 10, 10, 5, 5}

18. DescendingIterator with double values
   - Adds double values (3.14, 2.71, 1.41)
   - Tests descending iteration returns values in descending order: {3.14, 2.71, 1.41}

19. DescendingIterator works with strings
   - Adds strings with duplicates ("apple", "orange", "banana", "apple")
   - Tests descending iteration returns strings in descending alphabetical order including duplicates: {"orange", "banana", "apple", "apple"}
MiddleOutOrderIterator Tests

20. Empty container
   - Creates an empty container
   - Checks that the iterator begin equals end (no elements)

21. Single element container
   - Adds one element (42)
   - Checks iterator is not end
   - Checks dereferenced iterator equals 42
   - Advances iterator and checks it reaches end

22. Multiple elements, distinct
    - Adds three distinct elements (10, 20, 5)
    - Iterates through container using MiddleOutOrder
    - Checks the result is {20, 10, 5}

23. Multiple elements, duplicates
    - Adds multiple elements with duplicates (5, 10, 5, 20, 10)
    - Iterates using MiddleOutOrder
    - Checks result is {5, 10, 20, 5, 10}

24. MiddleOutOrderIterator with double values
    - Adds double values (3.14, 2.71, 1.41)
    - Iterates using MiddleOutOrder
    - Checks result is {2.71, 3.14, 1.41}

25. MiddleOutOrderIterator works with strings
    - Adds strings ("apple", "orange", "banana", "apple")
    - Iterates using MiddleOutOrder
    - Checks result is {"banana", "orange", "apple", "apple"}

OrderIterator Tests

26. Order basic iteration test
    - Adds elements (7, 15, 6, 1, 2)
    - Iterates in insertion order
    - Checks result is {7, 15, 6, 1, 2}

27. Order with empty container
    - Creates empty container
    - Checks iterator begin equals end

28. Order with single element
    - Adds one element (42)
    - Checks iterator is not end
    - Checks dereferenced iterator equals 42
    - Advances iterator and checks it reaches end

29. Order with duplicate elements
    - Adds elements with duplicates (3, 1, 3, 2, 1)
    - Iterates using OrderIterator
    - Checks result is {3, 1, 3, 2, 1}

30. OrderIterator - Does not modify original container
    - Adds elements (5, 2, 9)
    - Verifies that using OrderIterator does not alter the original container content: {5, 2, 9}

31. OrderIterator - Double values
    - Adds double values (3.14, 2.71, 1.41)
    - Checks ordered iteration returns in insertion order: {3.14, 2.71, 1.41}

32. OrderIterator - Strings
    - Adds strings ("banana", "apple", "cherry")
    - Checks ordered iteration returns in insertion order: {"banana", "apple", "cherry"}

33. ReverseIterator - Basic iteration
    - Adds elements (7, 15, 6, 1, 2)
    - Verifies reverse iteration returns elements in reverse insertion order: {2, 1, 6, 15, 7}

34. ReverseIterator - Empty container
    - Initializes an empty container
    - Checks begin == end for reverse iterator

35. ReverseIterator - Single element
    - Adds one element (42)
    - Verifies reverse iteration returns that single element: {42}

36. ReverseIterator - Duplicates
    - Adds elements (3, 1, 3, 2, 1)
    - Checks reverse iteration returns: {1, 2, 3, 1, 3}

37. ReverseIterator - Does not modify original container
    - Adds elements (5, 2, 9)
    - Verifies that using ReverseIterator does not alter the container: {5, 2, 9}

38. ReverseIterator - Double values
    - Adds double values (3.14, 2.71, 1.41)
    - Verifies reverse iteration returns in reverse insertion order: {1.41, 2.71, 3.14}

39. ReverseIterator - Strings
    - Adds strings ("banana", "apple", "cherry")
    - Verifies reverse iteration: {"cherry", "apple", "banana"}

40. SideCrossOrder - Basic iteration
    - Adds elements (7, 15, 6, 1, 2)
    - Verifies side-cross iteration returns: {1, 15, 2, 7, 6}

41. SideCrossOrder - Empty container
    - Initializes empty container
    - Checks begin == end for side-cross iterator

42. SideCrossOrder - Single element
    - Adds one element (42)
    - Verifies side-cross iteration returns that single element: {42}

43. SideCrossOrder - Duplicates
    - Adds elements (3, 1, 3, 2, 1)
    - Verifies side-cross iteration returns: {1, 3, 1, 3, 2}

44. SideCrossOrder - Does not modify original container
    - Adds elements (5, 2, 9)
    - Verifies that SideCrossOrder does not change the container: {5, 2, 9}

45. SideCrossOrder - Double values
    - Adds double values (3.14, 2.71, 1.41)
    - Verifies side-cross order: {1.41, 3.14, 2.71}

46. SideCrossOrder - Strings
    - Adds strings ("banana", "apple", "cherry")
    - Verifies side-cross order: {"apple", "cherry", "banana"}
---
## demo_run example
g++ -c -Wall -std=c++17 -g -IHPP/ demo.cpp -o OBJ/demo.o
g++ -Wall -std=c++17 -g -o demo OBJ/demo.o
./demo
Size: 5, Elements: [7, 15, 6, 1, 2]
Ascending order: 1 2 6 7 15 
Descending order: 15 7 6 2 1 
Side Cross order: 1 15 2 7 6 
Reverse order: 2 1 6 15 7 
Order order: 7 15 6 1 2 
Middle Out order: 6 15 1 7 2 
## Memory Safety

Run `make valgrind` to ensure no memory leaks exist. All dynamic allocations are properly managed.

---

## Dependencies

- C++17 or higher
- `doctest` (included in test files)
- `valgrind` for memory analysis (Linux/macOS)

---

## Notes

- All iterator logic is encapsulated and reusable.
- Namespace used: `my` (update to your actual namespace).
- Code is split into `.hpp` and `.cpp` files as per standard practice oll iterator is in `.hpp`.
---

## Contact

For any questions or suggestions, please contact:  
_[noamglikman1@gmail.com]_

---
