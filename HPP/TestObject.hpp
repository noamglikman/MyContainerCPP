#pragma once
#include <string>
#include <iostream>

namespace my {

class TestObject {
private:
    int value;
    std::string name;

public:
    // Constructors
    TestObject(int val = 0, const std::string& str = "") 
        : value(val), name(str) {}

    // Copy constructor
    TestObject(const TestObject& other) 
        : value(other.value), name(other.name) {}

    // Assignment operator
    TestObject& operator=(const TestObject& other) {
        if (this != &other) {
            value = other.value;
            name = other.name;
        }
        return *this;
    }

    // Comparison operators
    bool operator<(const TestObject& other) const {
        if (value == other.value) {
            return name < other.name;
        }
        return value < other.value;
    }
    bool operator>(const TestObject& other) const {
        return other < *this; // Use the less than operator for comparison
    }

    bool operator<=(const TestObject& other) const {
        return !(*this > other);
    }
    bool operator>=(const TestObject& other) const {
        return !(*this < other);
    }
    bool operator==(const TestObject& other) const {
        return value == other.value && name == other.name;
    }

    bool operator!=(const TestObject& other) const {
        return !(*this == other);
    }

    // Stream operator
    friend std::ostream& operator<<(std::ostream& os, const TestObject& obj) {
        os << "(" << obj.value << "," << obj.name << ")";
        return os;
    }
};

} // namespace my