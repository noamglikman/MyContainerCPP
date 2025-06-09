#pragma once
#include "MyContainer.hpp"
#include <vector>
#include <algorithm>
namespace my{
/**
 * @brief MiddleOutOrder iterator that traverses elements from the middle outward.
 *
 * This iterator starts at the middle element of the container, then alternates
 * scanning elements to the left and right, moving outward.
 *
 * For example, given the container with elements [7,15,6,1,2], the iteration order will be:
 * 6, 15, 1, 7, 2.
 *
 * If the container size is even, the middle index is chosen as floor(size/2).
 *
 * @tparam T The type of elements stored in the container.
 */
template <typename T>
class MiddleOutOrder {
private:
    std::vector<T> data;       ///< Local copy of the container's data.
    size_t index;              ///< Current position in iteration (number of elements returned).
    size_t midIdx;             ///< Index of the middle element (starting point).
    int leftOffset;            ///< Offset from the middle for the next element on the left side.
    int rightOffset;           ///< Offset from the middle for the next element on the right side.
    bool fromLeft;             ///< Flag indicating whether the next element is taken from the left or right side.
    friend class MyContainer<T>; ///< Allow MyContainer to access private members
public:
    /**
     * @brief Constructs the iterator from a container.
     *
     * Copies the container's data and initializes iteration variables.
     * The middle element index is set to floor(size/2).
     *
     * @param container The container to iterate over.
     */
    MiddleOutOrder(const MyContainer<T>& container)
        : data(container.getData()), index(0), fromLeft(true)
    {
        midIdx = data.size() / 2;  // floor for even sizes
        leftOffset = 1;
        rightOffset = 1;
    }

    /**
     * @brief Constructs a fully specified iterator.
     *
     * Used for creating copies or custom iterator states.
     *
     * @param d Data vector.
     * @param idx Current iteration index.
     * @param mid Middle index.
     * @param left Offsets for left side.
     * @param right Offsets for right side.
     * @param fromL Whether next element is from left or right.
     */
    MiddleOutOrder(const std::vector<T>& d, size_t idx, size_t mid, int left, int right, bool fromL)
        : data(d), index(idx), midIdx(mid), leftOffset(left), rightOffset(right), fromLeft(fromL) {}

    /**
     * @brief Dereference operator to access the current element.
     *
     * @return The current element according to middle-out order.
     */
    T operator*() const {
        if (index == 0)
            return data[midIdx];  // first element is always middle
        else if (fromLeft)
            return data[midIdx - leftOffset];
        else
            return data[midIdx + rightOffset];
    }

    /**
     * @brief Prefix increment operator to advance the iterator.
     *
     * Advances the iterator by alternating between left and right elements,
     * increasing offsets accordingly.
     *
     * @return Reference to the updated iterator.
     */
    MiddleOutOrder& operator++() {
        ++index;
        if (index == 1) {
            // after returning middle element, next from left side
            fromLeft = true;
        } else {
            if (fromLeft) {
                ++leftOffset;
            } else {
                ++rightOffset;
            }
            fromLeft = !fromLeft; // alternate side
        }
        return *this;
    }

    /**
     * @brief Inequality operator to compare two iterators.
     *
     * Iterators are different if their index differs.
     *
     * @param other The other iterator to compare with.
     * @return true if iterators differ; false otherwise.
     */
    bool operator!=(const MiddleOutOrder& other) const {
        return index != other.index;
    }
    bool operator==(const MiddleOutOrder& other) const {
    return index == other.index;
    }

};
}


