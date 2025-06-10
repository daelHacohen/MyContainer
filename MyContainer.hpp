//dael12345@gmail.com
#pragma once
#include <vector>
#include <algorithm>
#include <iostream>
#include <stdexcept>

namespace dael_containers {

        /**
     * @class MyContainer
     * @brief A generic container class that stores elements of type T (default: int).
     *        Supports adding, removing elements, and multiple custom iteration orders.
     *
     * @tparam T The type of elements stored in the container. Must be comparable.
     */
    template<typename T = int>
    class MyContainer {
    private:
        std::vector<T> data;  // Internal storage

    public:
         /**
         * @brief Adds an element to the container.
         * @param value The value to insert.
         */
        void add(const T& item) {
            data.push_back(item);
        }

         /**
         * @brief Removes all occurrences of the specified element from the container.
         * @param value The value to remove.
         * @throws std::runtime_error If the element is not found.
         */
        void remove(const T& item) {
            auto originalSize = data.size();
            data.erase(std::remove(data.begin(), data.end(), item), data.end());//this line moving all "item" to the end of the vector (with commend "remove") and then erase them (with commend "erase").

            if (data.size() == originalSize) {
                throw std::runtime_error("Item not found in container.");
            }
        }

        /**
        * @brief Returns the number of elements currently in the container.
        * @return The size of the container.
        */
        size_t size() const {
            return data.size();
        }

         /**
         * @brief Overloads the output stream operator for displaying the container contents.
         */
        friend std::ostream& operator<<(std::ostream& os, const MyContainer<T>& container) {
            os << "[";
            for (size_t i = 0; i < container.data.size(); ++i) {
                os << container.data[i];
                if (i < container.data.size() - 1) {
                    os << ", ";
                }
            }
            os << "]";
            return os;
        }

    //---------------------------AscendingOrderIterator-----------------------------------

     /**
     * @class AscendingOrder
     * @brief Iterates through the container from smallest to largest element.
     */
    class AscendingOrderIterator {
    private:
        const MyContainer<T>& container;
        std::vector<T> sortedData;
        size_t index;

    public:
        AscendingOrderIterator(const MyContainer<T>& cont, bool isEnd = false)
            : container(cont), sortedData(cont.data), index(0)
        {
            std::sort(sortedData.begin(), sortedData.end());
            if (isEnd) {
                index = sortedData.size(); 
            }
        }

        // Dereferencing to get current value
        const T& operator*() const {
            return sortedData.at(index);
        }

        // Prefix increment to advance iterator
        AscendingOrderIterator& operator++() {
            ++index;
            return *this;
        }

        // Inequality check
        bool operator!=(const AscendingOrderIterator& other) const {
            return index != other.index;
        }

        // Equality check
        bool operator==(const AscendingOrderIterator& other) const {
            return index == other.index;
        }
    };

    // Helper methods for begin/end of the iterator
    AscendingOrderIterator beginAscending() const {
        return AscendingOrderIterator(*this);
    }

    AscendingOrderIterator endAscending() const {
        return AscendingOrderIterator(*this, true);
    }


    //---------------------------DescendingOrderIterator-----------------------------------

    /**
    * @class DescendingOrder
    * @brief Iterates through the container from largest to smallest element.
    */
    class DescendingOrderIterator {
        private:

            const MyContainer<T>& container;
            std::vector<T> sortedData;
            int index;  

        public:

            DescendingOrderIterator(const MyContainer<T>& cont, bool isEnd = false): container(cont), sortedData(cont.data)
            {
                std::sort(sortedData.begin(), sortedData.end());
                if (isEnd || sortedData.empty()) {
                    index = -1;
                } else {
                    index = static_cast<int>(sortedData.size()) - 1;
                }
            }

            // Dereferencing to get current value
            const T& operator*() const {
                if (index < 0 || index >= static_cast<int>(sortedData.size())) {
                    throw std::out_of_range("Iterator out of bounds");
                }
                return sortedData[index];
            }

            // Prefix increment to advance iterator
            DescendingOrderIterator& operator++() {
                if (index >= 0) {
                    --index;
                }
                return *this;
            }

            // Inequality check
            bool operator!=(const DescendingOrderIterator& other) const {
                return index != other.index;
            }

            // Equality check
            bool operator==(const DescendingOrderIterator& other) const {
                return index == other.index;
            }
    };

    // Helper methods for begin/end of the iterator
    DescendingOrderIterator beginDescending() const {
        return DescendingOrderIterator(*this);
    }

    DescendingOrderIterator endDescending() const {
        return DescendingOrderIterator(*this, true);
    }



    //---------------------------SideCrossOrderIterator-----------------------------------

     /**
     * @class SideCrossOrder
     * @brief Alternates between the smallest and largest elements.
     */
    class SideCrossOrderIterator {
        private:
            const MyContainer<T>& container;
            std::vector<T> sortedData;
            size_t leftIndex;   // Index from the beginning
            size_t rightIndex;  // Index from the end
            bool takeFromLeft;  // Whether to take from the left side
            size_t currentStep; // How many steps we've taken

        public:
            SideCrossOrderIterator(const MyContainer<T>& cont, bool isEnd = false)
                : container(cont), sortedData(cont.data), leftIndex(0), 
                rightIndex(cont.size() > 0 ? cont.size() - 1 : 0), 
                takeFromLeft(true), currentStep(0)
            {
                std::sort(sortedData.begin(), sortedData.end());
                if (isEnd || sortedData.empty()) {
                    currentStep = sortedData.size();  // Points to end
                }
            }

            // Dereferencing to get current value
            const T& operator*() const {
                if (currentStep >= sortedData.size()) {
                    throw std::out_of_range("Iterator out of bounds");
                }
                
                if (takeFromLeft) {
                    return sortedData[leftIndex];
                } else {
                    return sortedData[rightIndex];
                }
            }

            // Prefix increment to advance iterator
            SideCrossOrderIterator& operator++() {
                if (currentStep >= sortedData.size()) {
                    return *this; // Already at end
                }

                // Move indices according to what we took
                if (takeFromLeft) {
                    leftIndex++;
                } else {
                    if (rightIndex > 0) rightIndex--;
                }

                currentStep++;
                
                // Switch sides for next step (if we haven't reached the end)
                if (currentStep < sortedData.size()) {
                    takeFromLeft = !takeFromLeft;
                }

                return *this;
            }

            // Inequality check
            bool operator!=(const SideCrossOrderIterator& other) const {
                return currentStep != other.currentStep;
            }

            // Equality check
            bool operator==(const SideCrossOrderIterator& other) const {
                return currentStep == other.currentStep;
            }
    };

    // Helper methods for begin/end of the iterator
    SideCrossOrderIterator beginSideCross() const {
        return SideCrossOrderIterator(*this);
    }

    SideCrossOrderIterator endSideCross() const {
        return SideCrossOrderIterator(*this, true);
    }


   //---------------------------ReverseOrderIterator-----------------------------------

     /**
     * @class ReverseOrder
     * @brief Iterates through the container in reverse of insertion order.
     */
    class ReverseOrderIterator {
        private:
            const MyContainer<T>& container;
            int index; // Current position in the original data (using int to allow -1)
            
        public:
            ReverseOrderIterator(const MyContainer<T>& cont, bool isEnd = false): container(cont), index(cont.size() > 0 ? static_cast<int>(cont.size()) - 1 : -1)
            {
                if (isEnd || cont.size() == 0) {
                    index = -1; // -1 indicates end
                }
            }

            // Dereferencing to get current value
            const T& operator*() const {
                if (index < 0 || index >= static_cast<int>(container.data.size())) {
                    throw std::out_of_range("Iterator out of bounds");
                }
                return container.data[index];
            }

            // Prefix increment to advance iterator
            ReverseOrderIterator& operator++() {
                if (index < 0) {
                    return *this; // if already at end
                }
                
                index--; 
                
                return *this;
            }

            // Inequality check
            bool operator!=(const ReverseOrderIterator& other) const {
                return index != other.index;
            }

            // Equality check
            bool operator==(const ReverseOrderIterator& other) const {
                return index == other.index;
            }
    };

    // Helper methods for begin/end of the iterator
    ReverseOrderIterator beginReverse() const {
        return ReverseOrderIterator(*this);
    }

    ReverseOrderIterator endReverse() const {
        return ReverseOrderIterator(*this, true);
    }


    //---------------------------OrderIterator-----------------------------------

     /**
     * @class Order
     * @brief Iterates through the container in the order elements were added.
     */
    class OrderIterator{
        private:
            const MyContainer<T>& container;
            size_t index;

        public:
            OrderIterator(const MyContainer<T>& cont, bool isEnd = false):container(cont),index(0){
                if (isEnd || cont.size() == 0) {
                    index = cont.size(); 
                }
            }

            // Dereferencing to get current value
            const T& operator*() const {
                if (index >= container.data.size()) 
                {
                    throw std::out_of_range("Iterator out of bounds");
                }
                return container.data[index];
            }

            // Prefix increment to advance iterator
            OrderIterator& operator++() {
                if (index < container.data.size()) 
                {
                    ++index;
                }
                return *this;
            }

            // Inequality check
            bool operator!=(const OrderIterator& other) const {
                return index != other.index;
            }

            // Equality check
            bool operator==(const OrderIterator& other) const {
                return index == other.index;
            }
    };

    // Helper methods for begin/end of the iterator
    OrderIterator beginOrder() const {
        return OrderIterator(*this);
    }

    OrderIterator endOrder() const {
        return OrderIterator(*this, true);
    }

//---------------------------MiddleOutOrderIterator-----------------------------------

 /**
 * @class MiddleOutOrder
 * @brief Starts from the middle element and alternates between expanding left and right.
 */
class MiddleOutOrderIterator {
    private:
        const MyContainer<T>& container;
        std::vector<size_t> visitOrder; // The order in which to visit indices
        size_t currentStep; // Current position in visitOrder

         /**
         * @brief Builds the visit order for the iterator starting from the middle index,
         *        then alternating to the left and right.
         * 
         * For even-sized containers, the middle index is taken as floor(size / 2).
         * Indices are added alternately: middle, left1, right1, left2, right2, ...
         */
        void buildVisitOrder() {
            size_t size = container.size();
            if (size == 0) return;
            
            // Find middle index (round down for even numbers)
            size_t middleIndex = size / 2;
            visitOrder.push_back(middleIndex);
            
            // Now alternate left and right from the middle
            size_t leftOffset = 1;   // Distance to the left of middle
            size_t rightOffset = 1;  // Distance to the right of middle
            bool goLeft = true;      // Start with left
            
            while (visitOrder.size() < size) {
                if (goLeft) {
                    // Try to go left
                    if (middleIndex >= leftOffset) {
                        size_t leftIndex = middleIndex - leftOffset;
                        visitOrder.push_back(leftIndex);
                        leftOffset++;
                    }
                    goLeft = false; // Next time go right
                } else {
                    // Try to go right
                    size_t rightIndex = middleIndex + rightOffset;
                    if (rightIndex < size) {
                        visitOrder.push_back(rightIndex);
                        rightOffset++;
                    }
                    goLeft = true; // Next time go left
                }
            }
        }

    public:
        MiddleOutOrderIterator(const MyContainer<T>& cont, bool isEnd = false)
            : container(cont), currentStep(0)
        {
            // Build the visit order: middle, then alternating left-right
            if (cont.size() > 0) {
                buildVisitOrder();
            }
            
            if (isEnd) {
                currentStep = visitOrder.size(); // Points to end
            }
        }

        // Dereferencing to get current value
        const T& operator*() const {
            if (currentStep >= visitOrder.size()) {
                throw std::out_of_range("Iterator out of bounds");
            }
            size_t dataIndex = visitOrder[currentStep];
            return container.data[dataIndex];
        }

        // Prefix increment to advance iterator
        MiddleOutOrderIterator& operator++() {
            if (currentStep < visitOrder.size()) {
                currentStep++;
            }
            return *this;
        }

        // Inequality check
        bool operator!=(const MiddleOutOrderIterator& other) const {
            return currentStep != other.currentStep;
        }

        // Equality check
        bool operator==(const MiddleOutOrderIterator& other) const {
            return currentStep == other.currentStep;
        }
    };

     // Helper methods for begin/end of the iterator
    MiddleOutOrderIterator beginMiddleOut() const {
        return MiddleOutOrderIterator(*this);
    }

     MiddleOutOrderIterator endMiddleOut() const {
        return MiddleOutOrderIterator(*this, true);
    }
    

};

} 
