#pragma once
#include "MyContainer.hpp"
#include <vector>
#include <algorithm>

namespace my {

/**
 * @brief A template class that provides an iterator to traverse
 *        a MyContainer<T> in descending order (from largest to smallest).
 *
 * @tparam T The type of the elements stored in the container.
 */
template <typename T>
class DescendingIterator {

private:
    const MyContainer<T>& container;  ///< Reference to the original container (read-only)
    std::vector<T> sortedData;        ///< Local copy of the container's data, sorted in descending order
    size_t index;                     ///< Index for iterating over sortedData
    friend class MyContainer<T>; ///< Allow MyContainer to access private members

public:
    /**
     * @brief Constructor that initializes the iterator with a container and sorts its elements in descending order.
     *
     * @param c The container to iterate over.
     */
    DescendingIterator(const MyContainer<T>& c)
        : container(c), sortedData(c.getData()), index(0) {
        std::sort(sortedData.begin(), sortedData.end(), std::greater<T>()); // Sort in descending order
    }

    /**
     * @brief Dereference operator.
     * @return The current element pointed to by the iterator.
     */
    T operator*() const {
        return sortedData[index];
    }

    /**
     * @brief Prefix increment operator to advance the iterator.
     * @return Reference to the updated iterator.
     */
    DescendingIterator& operator++() {
        ++index;
        return *this;
    }

    /**
     * @brief Inequality comparison operator.
     * @param other Another iterator to compare with.
     * @return true if the two iterators are at different positions, false otherwise.
     */
    bool operator!=(const DescendingIterator& other) const {
        return index != other.index;
    }
    bool operator==(const DescendingIterator& other) const {
    return index == other.index;
    }
};

} // namespace my
