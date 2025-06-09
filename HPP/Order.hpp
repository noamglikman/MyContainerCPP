#pragma once
#include "MyContainer.hpp"
#include <vector>
namespace my{
/**
 * @brief Iterator that scans the container in its original order.
 * 
 * For example, if the container holds [7,15,6,1,2], 
 * this iterator will traverse the elements in the order: 7, 15, 6, 1, 2.
 * 
 * @tparam T The data type stored in the container.
 */
template <typename T>
class OrderIterator {
private:
    const MyContainer<T>& container; ///< Reference to the original container (read-only)
    size_t index;                    ///< Current index for iteration
    friend class MyContainer<T>; ///< Allow MyContainer to access private members
public:
    /**
     * @brief Constructor that initializes the iterator with the container reference.
     * Starts the iteration at the beginning (index 0).
     * 
     * @param c Reference to the container to iterate over.
     */
    OrderIterator(const MyContainer<T>& c)
        : container(c), index(0) {}

    /**
     * @brief Dereference operator to access the current element.
     * 
     * @return The element at the current index in the container.
     */
    T operator*() const {
        return container.getData()[index];
    }

    /**
     * @brief Prefix increment operator to move the iterator to the next element.
     * 
     * @return Reference to the incremented iterator.
     */
    OrderIterator& operator++() {
        ++index;
        return *this;
    }

    /**
     * @brief Inequality comparison operator.
     * Checks if two iterators are at different positions.
     * 
     * @param other Another iterator to compare against.
     * @return true if the iterators point to different elements; false otherwise.
     */
    bool operator!=(const OrderIterator& other) const {
        return index != other.index;
    }
    bool operator==(const OrderIterator& other) const {
    return index == other.index;
    }
};
}