#pragma once
#include "MyContainer.hpp"
#include <vector>
#include <algorithm>
namespace my{
/**
 * @brief SideCrossOrder iterator that alternates smallest and largest elements.
 *
 * This iterator traverses the container by alternating between the smallest and largest elements,
 * starting from the smallest, then the largest, then the next smallest, then the next largest, and so on.
 *
 * For example, given the container with elements [7,15,6,1,2], the iteration order will be:
 * 1, 15, 2, 7, 6.
 *
 * @tparam T The type of elements stored in the container.
 */
template <typename T>
class SideCrossOrder {
private:
    std::vector<T> sortedData;  ///< Local sorted copy of the container's data.
    size_t index;               ///< Current iterator position (number of elements traversed).
    size_t startIdx;            ///< Index of the next element to take from the start (smallest).
    size_t endIdx;              ///< Index of the next element to take from the end (largest).
    bool fromStart;             ///< Flag indicating whether to take element from start or end next.
    friend class MyContainer<T>; ///< Allow MyContainer to access private members

public:
    /**
     * @brief Constructs the iterator from a container.
     *
     * Copies the container data into a local vector and sorts it in ascending order.
     * Initializes iteration state to start from the smallest element.
     *
     * @param container The container to iterate over.
     */
    SideCrossOrder(const MyContainer<T>& container)
        : index(0), startIdx(0), endIdx(0), fromStart(true)
    {
        sortedData = container.getData();  ///< Copy container data.
        std::sort(sortedData.begin(), sortedData.end());  ///< Sort data in ascending order.
        endIdx = sortedData.size() - 1;    ///< Set end index to last element.
    }

    /**
     * @brief Constructs an iterator with full control over iteration state.
     *
     * Used internally to create iterator copies or end iterators.
     *
     * @param data Sorted data vector.
     * @param idx Current iteration index.
     * @param start Index of next element from start.
     * @param end Index of next element from end.
     * @param fromStart Whether next element is from start or end.
     */
    SideCrossOrder(const std::vector<T>& data, size_t idx, size_t start, size_t end, bool fromStart)
        : sortedData(data), index(idx), startIdx(start), endIdx(end), fromStart(fromStart) {}

    /**
     * @brief Dereference operator to access the current element.
     *
     * @return The current element according to the side-cross order.
     */
    T operator*() const {
        return fromStart ? sortedData[startIdx] : sortedData[endIdx];
    }

    /**
     * @brief Prefix increment operator to advance the iterator.
     *
     * Advances the iterator by moving either the start or end index inward,
     * and toggling the fromStart flag to alternate sides.
     *
     * @return Reference to the updated iterator.
     */
    SideCrossOrder& operator++() {
        if (fromStart)
            ++startIdx;
        else
            --endIdx;
        fromStart = !fromStart;
        ++index;
        return *this;
    }

    /**
     * @brief Inequality operator to compare two iterators.
     *
     * Iterators are different if their position indices differ.
     *
     * @param other The other iterator to compare to.
     * @return true if iterators differ; false otherwise.
     */
    bool operator!=(const SideCrossOrder& other) const {
        return index != other.index;
    }
    bool operator==(const SideCrossOrder& other) const {
        return index == other.index;
    }
};

}

