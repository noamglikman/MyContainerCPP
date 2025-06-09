#pragma once
#include "MyContainer.hpp"
#include <vector>
namespace my{
/**
 * @brief Iterator class that iterates over the container in reverse order.
 *
 * This iterator traverses the elements from the last to the first.
 *
 * @tparam T The type of elements stored in the container.
 */
template <typename T>
class ReverseIterator {
private:
    const MyContainer<T>& container;  // Reference to the original container (read-only)
    std::vector<T> reversedData;      // Local copy of the container's data, reversed
    size_t index;                     // Current index in the reversedData vector
    friend class MyContainer<T>; ///< Allow MyContainer to access private members

public:
    /**
     * @brief Constructs a ReverseIterator from a container.
     * Copies the container's data and reverses it.
     *
     * @param c The container to iterate over.
     */
    ReverseIterator(const MyContainer<T>& c)
        : container(c), reversedData(c.getData()), index(0) {
        std::reverse(reversedData.begin(), reversedData.end()); // Reverse the data order
    }

    /**
     * @brief Dereference operator to access the current element.
     *
     * @return The current element in the iteration.
     */
    T operator*() const {
        return reversedData[index];
    }

    /**
     * @brief Prefix increment operator to advance the iterator.
     *
     * @return Reference to the updated iterator.
     */
    ReverseIterator& operator++() {
        ++index;
        return *this;
    }

    /**
     * @brief Inequality operator to compare two iterators.
     *
     * @param other The other iterator to compare with.
     * @return true if the iterators are at different positions; false otherwise.
     */
    bool operator!=(const ReverseIterator& other) const {
        return index != other.index;
    }
    bool operator==(const ReverseIterator& other) const {
        return index == other.index;
    }
};
}


