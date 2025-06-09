
// noamglikman1@gmail.com

#ifndef MY_CONTAINER_H
#define MY_CONTAINER_H

#include <vector>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <type_traits>
#include <iostream>

namespace my {

/**
 * @brief A generic container class that holds elements of type T.
 * 
 * This class provides basic container functionality such as adding, removing,
 * and accessing elements, while internally using a std::vector to store the data.
 * 
 * @tparam T The type of elements stored in the container. Defaults to int.
 */

template <typename T>
class AscendingIterator; // Forward declaration of AscendingIterator
template <typename T>
class DescendingIterator; // Forward declaration of DescendingIterator
template <typename T> class MiddleOutOrder; // Forward declaration of MiddleOutOrder
template <typename T> class SideCrossOrder; // Forward declaration of SideCrossOrder
template <typename T> class OrderIterator; // Forward declaration of OrderIterator
template <typename T> class ReverseIterator; // Forward declaration of ReverseIterator

template <typename T = int >
class MyContainer {
    // static_assert(std::is_copy_constructible<T>::value, "T must be copy constructible");
    // static_assert(std::is_copy_assignable<T>::value, "T must be copy assignable");
    // static_assert(
    //     std::is_convertible<decltype(std::declval<T>() < std::declval<T>()), bool>::value,
    //     "T must support operator< for sorting"
    // );
    // static_assert(
    //     std::is_convertible<decltype(std::declval<std::ostream&>() << std::declval<T>()), std::ostream&>::value,
    //     "T must support operator<< for printing"
    // );
private:
    std::vector<T> data; ///< Internal storage of elements
    // friend class AscendingIterator<T>; // Allow AscendingIterator to access private members
public:
    
    /**
     * @brief Adds a new element to the container.
     * 
     * @param value The element to add.
     */
    void add(const T& value) {
        data.push_back(value);
    }

    /**
     * @brief Removes all occurrences of a given element from the container.
     * 
     * If the element is not found, throws a std::runtime_error.
     * 
     * @param value The element to remove.
     * @throws std::runtime_error if the element is not found in the container.
     */
    void remove(const T& value) {
        auto oldSize = data.size();
        // Moves all elements equal to value to the end and erases them physically
        data.erase(std::remove(data.begin(), data.end(), value), data.end());
        if (data.size() == oldSize) {
            throw std::runtime_error("Error: element not found in container.");
        }
    }

    /**
     * @brief Returns the number of elements currently stored in the container.
     * 
     * @return int The container size.
     */
    int size() const {
        return static_cast<int>(data.size());
    }

    /**
     * @brief Outputs the container's size and elements to the given output stream.
     * 
     * Format: "Size: N, Elements: [elem1, elem2, ...]"
     * 
     * @param os The output stream.
     * @param container The container to output.
     * @return std::ostream& The output stream after writing.
     */
    friend std::ostream& operator<<(std::ostream& os, const MyContainer<T>& container) {
        os << "Size: " << container.data.size() << ", Elements: [";
        for (size_t i = 0; i < container.data.size(); ++i) {
            os << container.data[i];
            if (i < container.data.size() - 1) os << ", ";
        }
        os << "]";
        return os;
    }

    /**
     * @brief Provides const access to the internal data vector.
     * 
     * Used primarily by iterators or other helper classes to read container data.
     * 
     * @return const std::vector<T>& Reference to the internal data vector.
     */
    const std::vector<T>& getData() const {
        return data;
    }

    AscendingIterator<T> begin_ascending_order(){
        return AscendingIterator(*this);
    }
    AscendingIterator<T> end_ascending_order(){
        AscendingIterator it(*this);
        it.index = it.sortedData.size(); ///< Set index to the end of sortedData
        return it;
    }
    DescendingIterator<T> begin_descending_order(){
        return DescendingIterator(*this);
    }
    DescendingIterator<T> end_descending_order(){
        DescendingIterator it(*this);
        it.index = it.sortedData.size(); ///< Set index to the end of sortedData
        return it;
    }

    SideCrossOrder<T> begin_side_cross_order(){
        return SideCrossOrder(*this);
    }
    SideCrossOrder<T> end_side_cross_order(){
        SideCrossOrder it(*this);
        it.index = it.sortedData.size(); ///< Set index to the end of sortedData
        return it;
    }
    MiddleOutOrder<T> begin_middle_out_order(){
        return MiddleOutOrder(*this);
    }
    MiddleOutOrder<T> end_middle_out_order(){
        MiddleOutOrder it(*this);
        it.index = it.data.size(); ///< Set index to the end of data
        return it;
    }
    OrderIterator<T> begin_order(){
        return OrderIterator(*this);
    }
    OrderIterator<T> end_order(){
        OrderIterator it(*this);
        it.index = data.size();
        return it;
    }
    ReverseIterator<T> begin_reverse_order(){
        return ReverseIterator(*this);
    }
    ReverseIterator<T> end_reverse_order(){
        ReverseIterator it(*this);
        it.index = it.reversedData.size();
        return it;
    }
};

} // namespace my

#endif // MY_CONTAINER_H
