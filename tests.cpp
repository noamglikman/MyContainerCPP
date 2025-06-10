//noamglikman1@gmail.com
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "AscendingOrder.hpp"
#include "DescendingOrder.hpp"
#include "MiddleOutOrder.hpp"
#include "MyContainer.hpp"
#include "Order.hpp"
#include "ReverseOrder.hpp"
#include "SideCrossOrder.hpp"
#include "TestObject.hpp"
#include <exception>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "doctest.h"

using namespace my;



//test cases for AscendingIterator, DescendingIterator, MiddleOutOrder, OrderIterator, ReverseIterator, and SideCrossOrder
// tests for AscendingIterator
TEST_CASE("AscendingIterator basic iteration test") {
    MyContainer<int> container; 
    container.add(7);
    container.add(15);
    container.add(6);
    container.add(1);
    container.add(2);

    auto it = container.begin_ascending_order();
    auto end = container.end_ascending_order();

    std::vector<int> results;
    for (; it != end; ++it) {
        results.push_back(*it);
    }

    std::vector<int> expected = {1, 2, 6, 7, 15};
    CHECK(results == expected);
}
// tests for AscendingIterator with empty container
TEST_CASE("AscendingIterator with empty container") {
    my::MyContainer<int> container;
    auto it = container.begin_ascending_order();

    auto end = container.end_ascending_order();

    CHECK(it == end); 
}
// tests for AscendingIterator with single element
TEST_CASE("AscendingIterator with single element") {
    my::MyContainer<int> container;
    container.add(42);

    auto it = container.begin_ascending_order();

    auto end = container.end_ascending_order();

    CHECK(it != end);
    CHECK(*it == 42);

    ++it;
    CHECK(it == end);
}
// tests for AscendingIterator with duplicate elements
TEST_CASE("AscendingIterator with duplicate elements") {
    my::MyContainer<int> container;
    container.add(3);
    container.add(1);
    container.add(3);
    container.add(2);
    container.add(1);

    std::vector<int> expected = {1, 1, 2, 3, 3};

    std::vector<int> result;
    for (auto it = container.begin_ascending_order(); it != container.end_ascending_order(); ++it) {
        result.push_back(*it);
    }

    CHECK(result == expected);
}
// tests for AscendingIterator should not modify the original container
TEST_CASE("AscendingIterator should not modify the original container") {
    my::MyContainer<int> container;
    container.add(5);
    container.add(2);
    container.add(9);

    AscendingIterator<int> it(container); 
    std::vector<int> original = container.getData();
    CHECK(original == std::vector<int>{5, 2, 9});
}
// tests for AscendingIterator with strings
TEST_CASE("AscendingIterator with strings") {
    my::MyContainer<std::string> container;
    container.add("banana");
    container.add("apple");
    container.add("cherry");

    std::vector<std::string> result;
    for (auto it = container.begin_ascending_order(); it != container.end_ascending_order(); ++it) {
        result.push_back(*it);
    }

    std::vector<std::string> expected = {"apple", "banana", "cherry"};
    CHECK(result == expected);
}
//tests for AscendingIterator with double values
TEST_CASE("AscendingIterator with double values") {
    MyContainer<double> container;
    container.add(3.14);
    container.add(2.71);
    container.add(1.41);

    std::vector<double> result;
    for (auto it = container.begin_ascending_order(); it != container.end_ascending_order(); ++it) {
        result.push_back(*it);
    }

    std::vector<double> expected = {1.41, 2.71, 3.14};
    CHECK(result == expected);
}






// tests for DescendingIterator
// tests for DescendingIterator basic iteration test
//empty container
TEST_CASE("Empty container") {
    MyContainer<int> c;
    auto it = c.begin_descending_order();
    auto end = c.end_descending_order();
    CHECK(it == end);
}
//single element container
TEST_CASE("Single element container") {
    MyContainer<int> c;
    c.add(42);
    auto it = c.begin_descending_order();
    auto end = c.end_descending_order();

    CHECK(it != end);
    CHECK(*it == 42);
    ++it;
    CHECK(it == end);
}  
//multiple elements, distinct
TEST_CASE("Multiple elements, distinct") {
    MyContainer<int> c;
    c.add(10);
    c.add(20);
    c.add(5);

    auto it = c.begin_descending_order();
    auto end = c.end_descending_order();

    std::vector<int> results;
    while (it != end) {
        results.push_back(*it);
        ++it;
    }
    
    std::vector<int> expected = {20, 10, 5};
    CHECK(results == expected);
}
//multiple elements, duplicates
TEST_CASE("Multiple elements, duplicates") {
    MyContainer<int> c;
    c.add(5);
    c.add(10);
    c.add(5);
    c.add(20);
    c.add(10);

    auto it = c.begin_descending_order();
    auto end = c.end_descending_order();

    std::vector<int> results;
    while (it != end) {
        results.push_back(*it);
        ++it;
    }
    std::vector<int> expected = {20, 10, 10, 5, 5};
    CHECK(results == expected);
}
//tests for DescendingIterator with double values
TEST_CASE("DescendingIterator with double values") {
    MyContainer<double> c;
    c.add(3.14);
    c.add(2.71);
    c.add(1.41);

    auto it = c.begin_descending_order();
    auto end = c.end_descending_order();

    std::vector<double> results;
    while (it != end) {
        results.push_back(*it);
        ++it;
    }
    
    std::vector<double> expected = {3.14, 2.71, 1.41};
    CHECK(results == expected);
}
//DescendingIterator works with strings
TEST_CASE("DescendingIterator works with strings") {
    MyContainer<std::string> sc;
    sc.add("apple");
    sc.add("orange");
    sc.add("banana");
    sc.add("apple");

    auto it = sc.begin_descending_order();
    auto end = sc.end_descending_order();

    std::vector<std::string> results;
    while (it != end) {
        results.push_back(*it);
        ++it;
    }
    std::vector<std::string> expected = {"orange", "banana", "apple", "apple"};
    CHECK(results == expected);
}





// tests for MiddleOutOrderIterator
// tests for MiddleOutOrderIterator basic tests
//empty container
TEST_CASE("Empty container") {
    MyContainer<int> c;
    auto it = c.begin_middle_out_order();
    auto end = c.end_middle_out_order();
    CHECK(it == end);
}
//single element container
TEST_CASE("Single element container") {
    MyContainer<int> c;
    c.add(42);
    auto it = c.begin_middle_out_order();
    auto end = c.end_middle_out_order();

    CHECK(it != end);
    CHECK(*it == 42);
    ++it;
    CHECK(it == end);
}
//multiple elements, distinct
TEST_CASE("Multiple elements, distinct") {
    MyContainer<int> c;
    c.add(10);
    c.add(20);
    c.add(5);

    auto it = c.begin_middle_out_order();
    auto end = c.end_middle_out_order();

    std::vector<int> results;
    while (it != end) {
        results.push_back(*it);
        ++it;
    }
    
    std::vector<int> expected = {20, 10, 5};
    CHECK(results == expected);
}
//multiple elements, duplicates
TEST_CASE("Multiple elements, duplicates") {
    MyContainer<int> c;
    c.add(5);
    c.add(10);
    c.add(5);
    c.add(20);
    c.add(10);

    auto it = c.begin_middle_out_order();
    auto end = c.end_middle_out_order();

    std::vector<int> results;
    while (it != end) {
        results.push_back(*it);
        ++it;
    }
    std::vector<int> expected = {5, 10, 20, 5, 10};
    CHECK(results == expected);
}
// tests for MiddleOutOrderIterator with double values
TEST_CASE("MiddleOutOrderIterator with double values") {
    MyContainer<double> c;
    c.add(3.14);
    c.add(2.71);
    c.add(1.41);

    auto it = c.begin_middle_out_order();
    auto end = c.end_middle_out_order();

    std::vector<double> results;
    while (it != end) {
        results.push_back(*it);
        ++it;
    }
    
    std::vector<double> expected = {2.71, 3.14, 1.41};
    CHECK(results == expected);
}
//MiddleOutOrderIterator works with strings
TEST_CASE("MiddleOutOrderIterator works with strings") {
    MyContainer<std::string> sc;
    sc.add("apple");
    sc.add("orange");
    sc.add("banana");
    sc.add("apple");

    auto it = sc.begin_middle_out_order();
    auto end = sc.end_middle_out_order();

    std::vector<std::string> results;
    while (it != end) {
        results.push_back(*it);
        ++it;
    }
    std::vector<std::string> expected = {"banana","orange", "apple","apple"};
    CHECK(results == expected);
}

TEST_CASE("even number of elements in MiddleOutOrderIterator") {
    MyContainer<int> c;
    c.add(1);
    c.add(2);
    c.add(3);
    c.add(4);

    auto it = c.begin_middle_out_order();
    auto end = c.end_middle_out_order();

    std::vector<int> results;
    while (it != end) {
        results.push_back(*it);
        ++it;
    }
    
    std::vector<int> expected = {3, 2, 4, 1};
    CHECK(results == expected);
}
TEST_CASE("odd number of elements in MiddleOutOrderIterator") {
    MyContainer<int> c;
    c.add(1);
    c.add(2);
    c.add(3);

    auto it = c.begin_middle_out_order();
    auto end = c.end_middle_out_order();

    std::vector<int> results;
    while (it != end) {
        results.push_back(*it);
        ++it;
    }
    
    std::vector<int> expected = {2,1,3};
    CHECK(results == expected);
}






// tests for OrderIterator
TEST_CASE("Order basic iteration test") {
    MyContainer<int> container; 
    container.add(7);
    container.add(15);
    container.add(6);
    container.add(1);
    container.add(2);

    auto it = container.begin_order();
    auto end = container.end_order();

    std::vector<int> results;
    for (; it != end; ++it) {
        results.push_back(*it);
    }

    std::vector<int> expected = {7,15,6,1,2};
    CHECK(results == expected);
}
// tests for OrderIterator with empty container
TEST_CASE("Order with empty container") {
    my::MyContainer<int> container;
    auto it = container.begin_order();
    auto end = container.end_order();

    CHECK(it == end); 
}
// tests for OrderIterator with single element
TEST_CASE("Order with single element") {
    my::MyContainer<int> container;
    container.add(42);

    auto it = container.begin_order();
    auto end = container.end_order();

    CHECK(it != end);
    CHECK(*it == 42);

    ++it;
    CHECK(it == end);
}
// tests for OrderIterator with duplicate elements
TEST_CASE("Order with duplicate elements") {
    my::MyContainer<int> container;
    container.add(3);
    container.add(1);
    container.add(3);
    container.add(2);
    container.add(1);

    std::vector<int> expected = {3,1,3,2,1};

    std::vector<int> result;
    for (auto it = container.begin_order(); it != container.end_order(); ++it) {
        result.push_back(*it);
    }

    CHECK(result == expected);
}
// tests for OrderIterator should not modify the original container
TEST_CASE("Order should not modify the original container") {
    my::MyContainer<int> container;
    container.add(5);
    container.add(2);
    container.add(9);

    OrderIterator<int> it(container); 
    std::vector<int> original = container.getData();
    CHECK(original == std::vector<int>{5, 2, 9});
}
//test for OrderIterator with double values
TEST_CASE("Order with double values") {
    MyContainer<double> container;
    container.add(3.14);
    container.add(2.71);
    container.add(1.41);

    std::vector<double> result;
    for (auto it = container.begin_order(); it != container.end_order(); ++it) {
        result.push_back(*it);
    }

    std::vector<double> expected = {3.14, 2.71, 1.41};
    CHECK(result == expected);
}
// tests for OrderIterator with strings
TEST_CASE("Order with strings") {
    my::MyContainer<std::string> container;
    container.add("banana");
    container.add("apple");
    container.add("cherry");

    std::vector<std::string> result;
    for (auto it = container.begin_order(); it != container.end_order(); ++it) {
        result.push_back(*it);
    }

    std::vector<std::string> expected = {"banana", "apple", "cherry"};
    CHECK(result == expected);
}






// tests for ReverseIterator
TEST_CASE("Reverse basic iteration test") {
    MyContainer<int> container; 
    container.add(7);
    container.add(15);
    container.add(6);
    container.add(1);
    container.add(2);

    auto it = container.begin_reverse_order();
    auto end = container.end_reverse_order();

    std::vector<int> results;
    for (; it != end; ++it) {
        results.push_back(*it);
    }

    std::vector<int> expected = {2, 1, 6, 15, 7};
    CHECK(results == expected);
}
// tests for ReverseIterator with empty container
TEST_CASE("Reverse with empty container") {
    my::MyContainer<int> container;
    auto it = container.begin_reverse_order();
    auto end = container.end_reverse_order();

    CHECK(it == end); 
}
// tests for ReverseIterator with single element
TEST_CASE("Reverse with single element") {
    my::MyContainer<int> container;
    container.add(42);

    auto it = container.begin_reverse_order();
    auto end = container.end_reverse_order();

    CHECK(it != end);
    CHECK(*it == 42);

    ++it;
    CHECK(it == end);
}
// tests for ReverseIterator with duplicate elements
TEST_CASE("Reverse with duplicate elements") {
    my::MyContainer<int> container;
    container.add(3);
    container.add(1);
    container.add(3);
    container.add(2);
    container.add(1);

    std::vector<int> expected = {1,2,3,1,3};

    std::vector<int> result;
    for (auto it = container.begin_reverse_order(); it != container.end_reverse_order(); ++it) {
        result.push_back(*it);
    }

    CHECK(result == expected);
}
// tests for ReverseIterator should not modify the original container
TEST_CASE("Reverse should not modify the original container") {
    my::MyContainer<int> container;
    container.add(5);
    container.add(2);
    container.add(9);

    ReverseIterator<int> it(container); 
    std::vector<int> original = container.getData();
    CHECK(original == std::vector<int>{5,2,9});
}
// tests for ReverseIterator with double values
TEST_CASE("Reverse with double values") {
    MyContainer<double> container;
    container.add(3.14);
    container.add(2.71);
    container.add(1.41);

    std::vector<double> result;
    for (auto it = container.begin_reverse_order(); it != container.end_reverse_order(); ++it) {
        result.push_back(*it);
    }

    std::vector<double> expected = {1.41, 2.71, 3.14};
    CHECK(result == expected);
}
// tests for ReverseIterator with strings
TEST_CASE("Reverse with strings") {
    my::MyContainer<std::string> container;
    container.add("banana");
    container.add("apple");
    container.add("cherry");

    std::vector<std::string> result;
    for (auto it = container.begin_reverse_order(); it != container.end_reverse_order(); ++it) {
        result.push_back(*it);
    }

    std::vector<std::string> expected = {"cherry", "apple", "banana"};
    CHECK(result == expected);
}





// tests for SideCrossOrder
TEST_CASE("SideCross iteration test") {
    MyContainer<int> container; 
    container.add(7);
    container.add(15);
    container.add(6);
    container.add(1);
    container.add(2);

    auto it = container.begin_side_cross_order();
    auto end = container.end_side_cross_order();

    std::vector<int> results;
    for (; it != end; ++it) {
        results.push_back(*it);
    }

    std::vector<int> expected = {1,15,2,7,6};
    CHECK(results == expected);
}
// tests for SideCrossOrder with empty container
TEST_CASE("SideCross with empty container") {
    my::MyContainer<int> container;
    auto it = container.begin_side_cross_order();
    auto end = container.end_side_cross_order();

    CHECK(it == end); 
}
// tests for SideCrossOrder with single element
TEST_CASE("SideCross with single element") {
    my::MyContainer<int> container;
    container.add(42);

    auto it = container.begin_side_cross_order();
    auto end = container.end_side_cross_order();

    CHECK(it != end);
    CHECK(*it == 42);

    ++it;
    CHECK(it == end);
}
// tests for SideCrossOrder with duplicate elements
TEST_CASE("SideCross with duplicate elements") {
    my::MyContainer<int> container;
    container.add(3);
    container.add(1);
    container.add(3);
    container.add(2);
    container.add(1);

    std::vector<int> expected = {1,3,1,3,2};

    std::vector<int> result;
    for (auto it = container.begin_side_cross_order(); it != container.end_side_cross_order(); ++it) {
        result.push_back(*it);
    }
    CHECK(result == expected);
    
}
// tests for SideCrossOrder should not modify the original container
TEST_CASE("SideCross should not modify the original container") {
    my::MyContainer<int> container;
    container.add(5);
    container.add(2);
    container.add(9);

    SideCrossOrder<int> it(container); 
    std::vector<int> original = container.getData();
    CHECK(original == std::vector<int>{5,2,9});
}
// tests for SideCrossOrder with double values
TEST_CASE("SideCross with double values") {
    MyContainer<double> container;
    container.add(3.14);
    container.add(2.71);
    container.add(1.41);

    std::vector<double> result;
    for (auto it = container.begin_side_cross_order(); it != container.end_side_cross_order(); ++it) {
        result.push_back(*it);
    }

    std::vector<double> expected = {1.41, 3.14, 2.71};
    CHECK(result == expected);
}
// tests for SideCrossOrder with strings
TEST_CASE("SideCross with strings") {
    my::MyContainer<std::string> container;
    container.add("banana");
    container.add("apple");
    container.add("cherry");

    std::vector<std::string> result;
    for (auto it = container.begin_side_cross_order(); it != container.end_side_cross_order(); ++it) {
        result.push_back(*it);
    }

    std::vector<std::string> expected = {"apple", "cherry","banana"};
    CHECK(result == expected);
}
// tests for SideCrossOrder with TestObject
TEST_CASE("TestObject SideCrossOrder") {
    MyContainer<TestObject> container;
    container.add(TestObject(7, "seven"));
    container.add(TestObject(15, "fifteen"));
    container.add(TestObject(6, "six"));
    container.add(TestObject(1, "one"));
    container.add(TestObject(2, "two"));

    auto it = container.begin_side_cross_order();
    auto end = container.end_side_cross_order();

    std::vector<TestObject> results;
    for (; it != end; ++it) {
        results.push_back(*it);
    }

    std::vector<TestObject> expected = {TestObject(1, "one"), TestObject(15, "fifteen"), TestObject(2, "two"), TestObject(7, "seven"), TestObject(6, "six")};
    CHECK(results == expected);
}
TEST_CASE("TestObject SideCrossOrder with empty container") {
    MyContainer<TestObject> container;
    auto it = container.begin_side_cross_order();
    auto end = container.end_side_cross_order();

    CHECK(it == end); 
}
// tests for SideCrossOrder with single TestObject element
TEST_CASE("TestObject SideCrossOrder with single element") {
    MyContainer<TestObject> container;
    container.add(TestObject(42, "forty-two"));

    auto it = container.begin_side_cross_order();
    auto end = container.end_side_cross_order();

    CHECK(it != end);
    CHECK(*it == TestObject(42, "forty-two"));

    ++it;
    CHECK(it == end);
}
// tests for SideCrossOrder with duplicate TestObject elements  
TEST_CASE("TestObject SideCrossOrder with duplicate elements") {
    MyContainer<TestObject> container;
    container.add(TestObject(3, "three"));
    container.add(TestObject(1, "one"));
    container.add(TestObject(3, "three"));
    container.add(TestObject(2, "two"));
    container.add(TestObject(1, "one"));

    std::vector<TestObject> expected = {TestObject(1, "one"), TestObject(3, "three"), TestObject(1, "one"), TestObject(3, "three"), TestObject(2, "two")};

    std::vector<TestObject> result;
    for (auto it = container.begin_side_cross_order(); it != container.end_side_cross_order(); ++it) {
        result.push_back(*it);
    }

    CHECK(result == expected);
}
TEST_CASE("TestObject ascending order ")
{
    MyContainer<TestObject> container;
    container.add(TestObject(7, "seven"));
    container.add(TestObject(15, "fifteen"));
    container.add(TestObject(6, "six"));
    container.add(TestObject(1, "one"));
    container.add(TestObject(2, "two"));

    auto it = container.begin_ascending_order();
    auto end = container.end_ascending_order();

    std::vector<TestObject> results;
    for (; it != end; ++it) {
        results.push_back(*it);
    }

    std::vector<TestObject> expected = {TestObject(1, "one"), TestObject(2, "two"), TestObject(6, "six"), TestObject(7, "seven"), TestObject(15, "fifteen")};
    CHECK(results == expected);
}
// tests for TestObject with empty container
TEST_CASE("TestObject ascending order with empty container") {
    MyContainer<TestObject> container;
    auto it = container.begin_ascending_order();
    auto end = container.end_ascending_order();

    CHECK(it == end); 
}
// tests for TestObject with single element
TEST_CASE("TestObject ascending order with single element") {
    MyContainer<TestObject> container;
    container.add(TestObject(42, "forty-two"));

    auto it = container.begin_ascending_order();
    auto end = container.end_ascending_order();

    CHECK(it != end);
    CHECK(*it == TestObject(42, "forty-two"));

    ++it;
    CHECK(it == end);
}
// tests for TestObject with duplicate elements
TEST_CASE("TestObject ascending order with duplicate elements") {
    MyContainer<TestObject> container;
    container.add(TestObject(3, "three"));
    container.add(TestObject(1, "one"));
    container.add(TestObject(3, "three"));
    container.add(TestObject(2, "two"));
    container.add(TestObject(1, "one"));

    std::vector<TestObject> expected = {TestObject(1, "one"), TestObject(1, "one"), TestObject(2, "two"), TestObject(3, "three"), TestObject(3, "three")};

    std::vector<TestObject> result;
    for (auto it = container.begin_ascending_order(); it != container.end_ascending_order(); ++it) {
        result.push_back(*it);
    }

    CHECK(result == expected);
}
// tests for TestObject with double values
TEST_CASE("TestObject ascending order with double values") {
    MyContainer<TestObject> container;
    container.add(TestObject(3.14, "pi"));
    container.add(TestObject(2.71, "e"));
    container.add(TestObject(1.41, "sqrt2"));

    auto it = container.begin_ascending_order();
    auto end = container.end_ascending_order();

    std::vector<TestObject> results;
    while (it != end) {
        results.push_back(*it);
        ++it;
    }

    std::vector<TestObject> expected = {TestObject(1.41, "sqrt2"), TestObject(2.71, "e"), TestObject(3.14, "pi")};
    CHECK(results == expected);
}
TEST_CASE("TestObject descending order ")
{
    MyContainer<TestObject> container;
    container.add(TestObject(7, "seven"));
    container.add(TestObject(15, "fifteen"));
    container.add(TestObject(6, "six"));
    container.add(TestObject(1, "one"));
    container.add(TestObject(2, "two"));

    auto it = container.begin_descending_order();
    auto end = container.end_descending_order();

    std::vector<TestObject> results;
    for (; it != end; ++it) {
        results.push_back(*it);
    }

    std::vector<TestObject> expected = {TestObject(15, "fifteen"), TestObject(7, "seven"), TestObject(6, "six"), TestObject(2, "two"), TestObject(1, "one")};
    CHECK(results == expected);
}
// tests for TestObject with empty container
TEST_CASE("TestObject descending order with empty container") {
    MyContainer<TestObject> container;
    auto it = container.begin_descending_order();
    auto end = container.end_descending_order();

    CHECK(it == end); 
}
// tests for TestObject with single element
TEST_CASE("TestObject descending order with single element") {
    MyContainer<TestObject> container;
    container.add(TestObject(42, "forty-two"));

    auto it = container.begin_descending_order();
    auto end = container.end_descending_order();

    CHECK(it != end);
    CHECK(*it == TestObject(42, "forty-two"));

    ++it;
    CHECK(it == end);
}
// tests for TestObject with duplicate elements
TEST_CASE("TestObject descending order with duplicate elements") {
    MyContainer<TestObject> container;
    container.add(TestObject(3, "three"));
    container.add(TestObject(1, "one"));
    container.add(TestObject(3, "three"));
    container.add(TestObject(2, "two"));
    container.add(TestObject(1, "one"));

    std::vector<TestObject> expected = {TestObject(3, "three"), TestObject(3, "three"), TestObject(2, "two"), TestObject(1, "one"), TestObject(1, "one")};

    std::vector<TestObject> result;
    for (auto it = container.begin_descending_order(); it != container.end_descending_order(); ++it) {
        result.push_back(*it);
    }

    CHECK(result == expected);
}
// tests for TestObject with double values
TEST_CASE("TestObject descending order with double values") {
    MyContainer<TestObject> container;
    container.add(TestObject(3.14, "pi"));
    container.add(TestObject(2.71, "e"));
    container.add(TestObject(1.41, "sqrt2"));

    auto it = container.begin_descending_order();
    auto end = container.end_descending_order();

    std::vector<TestObject> results;
    while (it != end) {
        results.push_back(*it);
        ++it;
    }

    std::vector<TestObject> expected = {TestObject(3.14, "pi"), TestObject(2.71, "e"), TestObject(1.41, "sqrt2")};
    CHECK(results == expected);
}
// tests for TestObject with strings
TEST_CASE("TestObject descending order with strings") {
    MyContainer<TestObject> container;
    container.add(TestObject(3, "banana"));
    container.add(TestObject(1, "apple"));
    container.add(TestObject(2, "cherry"));

    auto it = container.begin_descending_order();
    auto end = container.end_descending_order();

    std::vector<TestObject> results;
    while (it != end) {
        results.push_back(*it);
        ++it;
    }

    std::vector<TestObject> expected = {TestObject(3, "banana"), TestObject(2, "cherry"), TestObject(1, "apple")};
    CHECK(results == expected);
}
TEST_CASE("TestObject reverse order ")
{
    MyContainer<TestObject> container;
    container.add(TestObject(7, "seven"));
    container.add(TestObject(15, "fifteen"));
    container.add(TestObject(6, "six"));
    container.add(TestObject(1, "one"));
    container.add(TestObject(2, "two"));

    auto it = container.begin_reverse_order();
    auto end = container.end_reverse_order();

    std::vector<TestObject> results;
    for (; it != end; ++it) {
        results.push_back(*it);
    }

    std::vector<TestObject> expected = {TestObject(2, "two"), TestObject(1, "one"), TestObject(6, "six"), TestObject(15, "fifteen"), TestObject(7, "seven")};
    CHECK(results == expected);
}
// tests for TestObject with empty container
TEST_CASE("TestObject reverse order with empty container") {
    MyContainer<TestObject> container;
    auto it = container.begin_reverse_order();
    auto end = container.end_reverse_order();

    CHECK(it == end); 
}
// tests for TestObject with single element
TEST_CASE("TestObject reverse order with single element") {
    MyContainer<TestObject> container;
    container.add(TestObject(42, "forty-two"));

    auto it = container.begin_reverse_order();
    auto end = container.end_reverse_order();

    CHECK(it != end);
    CHECK(*it == TestObject(42, "forty-two"));

    ++it;
    CHECK(it == end);
}
// tests for TestObject with duplicate elements
TEST_CASE("TestObject reverse order with duplicate elements") {
    MyContainer<TestObject> container;
    container.add(TestObject(3, "three"));
    container.add(TestObject(1, "one"));
    container.add(TestObject(3, "three"));
    container.add(TestObject(2, "two"));
    container.add(TestObject(1, "one"));

    std::vector<TestObject> expected = {TestObject(1, "one"), TestObject(2, "two"), TestObject(3, "three"), TestObject(1, "one"), TestObject(3, "three")};

    std::vector<TestObject> result;
    for (auto it = container.begin_reverse_order(); it != container.end_reverse_order(); ++it) {
        result.push_back(*it);
    }

    CHECK(result == expected);
}
// tests for TestObject with double values
TEST_CASE("TestObject reverse order with double values") {
    MyContainer<TestObject> container;
    container.add(TestObject(3.14, "pi"));
    container.add(TestObject(2.71, "e"));
    container.add(TestObject(1.41, "sqrt2"));

    auto it = container.begin_reverse_order();
    auto end = container.end_reverse_order();

    std::vector<TestObject> results;
    while (it != end) {
        results.push_back(*it);
        ++it;
    }

    std::vector<TestObject> expected = {TestObject(1.41, "sqrt2"), TestObject(2.71, "e"), TestObject(3.14, "pi")};
    CHECK(results == expected);
}
// tests for TestObject with SideCrossOrder
TEST_CASE("TestObject SideCrossOrder with TestObject") {
    MyContainer<TestObject> container;
    container.add(TestObject(7, "seven"));
    container.add(TestObject(15, "fifteen"));
    container.add(TestObject(6, "six"));
    container.add(TestObject(1, "one"));
    container.add(TestObject(2, "two"));

    auto it = container.begin_side_cross_order();
    auto end = container.end_side_cross_order();

    std::vector<TestObject> results;
    for (; it != end; ++it) {
        results.push_back(*it);
    }

    std::vector<TestObject> expected = {TestObject(1, "one"), TestObject(15, "fifteen"), TestObject(2, "two"), TestObject(7, "seven"), TestObject(6, "six")};
    CHECK(results == expected);
}
// tests for TestObject with empty container
TEST_CASE("TestObject SideCrossOrder with empty container") {
    MyContainer<TestObject> container;
    auto it = container.begin_side_cross_order();
    auto end = container.end_side_cross_order();

    CHECK(it == end); 
}
// tests for TestObject with single element
TEST_CASE("TestObject SideCrossOrder with single element") {
    MyContainer<TestObject> container;
    container.add(TestObject(42, "forty-two"));

    auto it = container.begin_side_cross_order();
    auto end = container.end_side_cross_order();

    CHECK(it != end);
    CHECK(*it == TestObject(42, "forty-two"));

    ++it;
    CHECK(it == end);
}
// tests for TestObject with duplicate elements 
TEST_CASE("TestObject SideCrossOrder with duplicate elements") {
    MyContainer<TestObject> container;
    container.add(TestObject(3, "three"));
    container.add(TestObject(1, "one"));
    container.add(TestObject(3, "three"));
    container.add(TestObject(2, "two"));
    container.add(TestObject(1, "one"));

    std::vector<TestObject> expected = {TestObject(1, "one"), TestObject(3, "three"), TestObject(1, "one"), TestObject(3, "three"), TestObject(2, "two")};

    std::vector<TestObject> result;
    for (auto it = container.begin_side_cross_order(); it != container.end_side_cross_order(); ++it) {
        result.push_back(*it);
    }

    CHECK(result == expected);
}
// tests for TestObject with double values
TEST_CASE("TestObject SideCrossOrder with double values") {
    MyContainer<TestObject> container;
    container.add(TestObject(3.14, "pi"));
    container.add(TestObject(2.71, "e"));
    container.add(TestObject(1.41, "sqrt2"));

    auto it = container.begin_side_cross_order();
    auto end = container.end_side_cross_order();

    std::vector<TestObject> results;
    while (it != end) {
        results.push_back(*it);
        ++it;
    }

    std::vector<TestObject> expected = {TestObject(1.41, "sqrt2"), TestObject(3.14, "pi"), TestObject(2.71, "e")};
    CHECK(results == expected);
}
// tests for TestObject with OrderIterator
TEST_CASE("TestObject OrderIterator") {
    MyContainer<TestObject> container;
    container.add(TestObject(7, "seven"));
    container.add(TestObject(15, "fifteen"));
    container.add(TestObject(6, "six"));
    container.add(TestObject(1, "one"));
    container.add(TestObject(2, "two"));

    auto it = container.begin_order();
    auto end = container.end_order();

    std::vector<TestObject> results;
    for (; it != end; ++it) {
        results.push_back(*it);
    }

    std::vector<TestObject> expected = {TestObject(7, "seven"), TestObject(15, "fifteen"), TestObject(6, "six"), TestObject(1, "one"), TestObject(2, "two")};
    CHECK(results == expected);
}
// tests for TestObject with empty container
TEST_CASE("TestObject OrderIterator with empty container") {
    MyContainer<TestObject> container;
    auto it = container.begin_order();
    auto end = container.end_order();

    CHECK(it == end); 
}
// tests for TestObject with single element
TEST_CASE("TestObject OrderIterator with single element") {
    MyContainer<TestObject> container;
    container.add(TestObject(42, "forty-two"));

    auto it = container.begin_order();
    auto end = container.end_order();

    CHECK(it != end);
    CHECK(*it == TestObject(42, "forty-two"));

    ++it;
    CHECK(it == end);
}
// tests for TestObject with duplicate elements
TEST_CASE("TestObject OrderIterator with duplicate elements") {
    MyContainer<TestObject> container;
    container.add(TestObject(3, "three"));
    container.add(TestObject(1, "one"));
    container.add(TestObject(3, "three"));
    container.add(TestObject(2, "two"));
    container.add(TestObject(1, "one"));

    std::vector<TestObject> expected = {TestObject(3, "three"), TestObject(1, "one"), TestObject(3, "three"), TestObject(2, "two"), TestObject(1, "one")};

    std::vector<TestObject> result;
    for (auto it = container.begin_order(); it != container.end_order(); ++it) {
        result.push_back(*it);
    }

    CHECK(result == expected);
}
// tests for TestObject with double values
TEST_CASE("TestObject OrderIterator with double values") {
    MyContainer<TestObject> container;
    container.add(TestObject(3.14, "pi"));
    container.add(TestObject(2.71, "e"));
    container.add(TestObject(1.41, "sqrt2"));

    auto it = container.begin_order();
    auto end = container.end_order();

    std::vector<TestObject> results;
    while (it != end) {
        results.push_back(*it);
        ++it;
    }

    std::vector<TestObject> expected = {TestObject(3.14, "pi"), TestObject(2.71, "e"), TestObject(1.41, "sqrt2")};
    CHECK(results == expected);
}   
// tests for TestObject with strings
TEST_CASE("TestObject OrderIterator with strings") {
    MyContainer<TestObject> container;
    container.add(TestObject(3, "banana"));
    container.add(TestObject(1, "apple"));
    container.add(TestObject(2, "cherry"));

    auto it = container.begin_order();
    auto end = container.end_order();

    std::vector<TestObject> results;
    while (it != end) {
        results.push_back(*it);
        ++it;
    }

    std::vector<TestObject> expected = {TestObject(3, "banana"), TestObject(1, "apple"), TestObject(2, "cherry")};
    CHECK(results == expected);
}


