#include <iostream>
#include "HPP/MyContainer.hpp"
#include "HPP/AscendingOrder.hpp"
#include "HPP/DescendingOrder.hpp"
#include "HPP/ReverseOrder.hpp"
#include "HPP/Order.hpp"
#include "HPP/MiddleOutOrder.hpp"
#include "HPP/SideCrossOrder.hpp"
#include "HPP/TestObject.hpp"           
using namespace my;
int main() {
    MyContainer<int> container;
    container.add(7);
    container.add(15);
    container.add(6);
    container.add(1);
    container.add(2);

    std::cout << "Size of container: " << container.size() << std::endl;
    std::cout << "Ascending order: ";
    for (auto it = container.begin_ascending_order(); it != container.end_ascending_order(); ++it) {
        std::cout << *it << ' ';   // 1 2 6 7 15
    }
    std::cout << std::endl;

    std::cout << "Descending order: ";
    for (auto it = container.begin_descending_order(); it != container.end_descending_order(); ++it) {
        std::cout << *it << ' ';  // 15 7 6 2 1
    }
    std::cout << std::endl;
    std::cout << "Side cross order: ";
    for (auto it = container.begin_side_cross_order(); it != container.end_side_cross_order(); ++it) {
        std::cout << *it << ' ';  // 1 15 2 7 6
    }
    std::cout << std::endl;
    std::cout << "reverse order: ";
    for (auto it = container.begin_reverse_order(); it != container.end_reverse_order(); ++it) {
        std::cout << *it << ' ';  // 2 1 6 15 7
    }
    std::cout << std::endl;
    std::cout << "begin order: ";
    for (auto it = container.begin_order(); it != container.end_order(); ++it) {
        std::cout << *it << ' ';  // 7 15 6 1 2
    }
    std::cout << std::endl;
    std::cout << "middle order: ";
    for (auto it = container.begin_middle_out_order(); it != container.end_middle_out_order(); ++it) {
        std::cout << *it << ' ';  // 6 15 1 7 2
    }

    MyContainer<TestObject> TestObjectContainer;
    TestObjectContainer.add(TestObject(7, "seven"));
    TestObjectContainer.add(TestObject(15, "fifteen"));
    TestObjectContainer.add(TestObject(6, "six"));
    TestObjectContainer.add(TestObject(1, "one"));
    TestObjectContainer.add(TestObject(2, "two"));
    std::cout << std::endl;

    std::cout << "Ascending order: ";
    for (auto it = TestObjectContainer.begin_ascending_order(); it != TestObjectContainer.end_ascending_order(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    std::cout << "Descending order: ";
    for (auto it = TestObjectContainer.begin_descending_order(); it != TestObjectContainer.end_descending_order(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    std::cout << "Side cross order: ";
    for (auto it = TestObjectContainer.begin_side_cross_order(); it != TestObjectContainer.end_side_cross_order(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    std::cout << "Reverse order: ";
    for (auto it = TestObjectContainer.begin_reverse_order(); it != TestObjectContainer.end_reverse_order(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    std::cout << "Middle out order: ";
    for (auto it = TestObjectContainer.begin_middle_out_order(); it != TestObjectContainer.end_middle_out_order(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;
    return 0;
}
