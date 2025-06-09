#pragma once
#include "MyContainer.hpp"
#include <vector>
#include <algorithm>
namespace my{
/**
 * @brief Iterator class that iterates over the container in ascending order.
 *
 * This iterator traverses the elements from the smallest to the largest.
 *
 * @tparam T The type of elements stored in the container.
 */
template <typename T>
class AscendingIterator {

private:
    const MyContainer<T>& container; ///< Reference to the original container (read-only)
    std::vector<T> sortedData;       ///< Local copy of the container's data, sorted ascending
    size_t index;                    ///< Current index in the sortedData vector

public:
    friend class MyContainer<T>; ///< Allow MyContainer to access private members
    /**
     * @brief Constructs an AscendingIterator from a container.
     * Copies the container's data and sorts it in ascending order.
     *
     * @param c The container to iterate over.
     */
    AscendingIterator(const MyContainer<T>& c)
        : container(c), sortedData(c.getData()), index(0) {
        std::sort(sortedData.begin(), sortedData.end()); ///< Sort the data in ascending order
    }

    /**
     * @brief Dereference operator to access the current element.
     *
     * @return The current element in the iteration.
     */
    T operator*() const {
        return sortedData[index];
    }

    /**
     * @brief Prefix increment operator to advance the iterator.
     *
     * @return Reference to the updated iterator.
     */
    AscendingIterator& operator++() {
        ++index;
        return *this;
    }

    /**
     * @brief Inequality operator to compare two iterators.
     *
     * @param other The other iterator to compare with.
     * @return true if the iterators are at different positions; false otherwise.
     */
    bool operator!=(const AscendingIterator& other) const {
        return index != other.index;
    }
    bool operator==(const AscendingIterator& other) const {
    return index == other.index;
    }

};
}


