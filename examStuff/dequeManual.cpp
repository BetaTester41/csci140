#include <iostream>
#include <stdexcept>

class Deque {
private:
    int* data;       // Pointer to the dynamic array
    int capacity;    // Total capacity of the deque
    int front;       // Index of the front element
    int back;        // Index of the back element
    int size;        // Current number of elements

    // Resize the deque when it becomes full
    void resize() {
        int newCapacity = capacity * 2;
        int* newData = new int[newCapacity];

        // Copy elements to the new array
        for (int i = 0; i < size; ++i)
            newData[i] = data[(front + i) % capacity];

        delete[] data;
        data = newData;
        capacity = newCapacity;
        front = 0;
        back = size - 1;
    }

public:
    Deque(int initialCapacity = 4) : capacity(initialCapacity), size(0) {
        data = new int[capacity];
        front = 0;
        back = -1;
    }

    ~Deque() {
        delete[] data;
    }

    // Push to the back (like a stack or queue)
    void pushBack(int value) {
        if (size == capacity)
            resize();
        back = (back + 1) % capacity;
        data[back] = value;
        ++size;
    }

    // Push to the front
    void pushFront(int value) {
        if (size == capacity)
            resize();
        front = (front - 1 + capacity) % capacity;
        data[front] = value;
        ++size;
    }

    // Pop from the back (like a stack)
    int popBack() {
        if (size == 0)
            throw std::underflow_error("Deque is empty");
        int value = data[back];
        back = (back - 1 + capacity) % capacity;
        --size;
        return value;
    }

    // Pop from the front (like a queue)
    int popFront() {
        if (size == 0)
            throw std::underflow_error("Deque is empty");
        int value = data[front];
        front = (front + 1) % capacity;
        --size;
        return value;
    }

    // Check if the deque is empty
    bool isEmpty() const {
        return size == 0;
    }

    // Display the contents of the deque
    void display() const {
        for (int i = 0; i < size; ++i)
            std::cout << data[(front + i) % capacity] << " ";
        std::cout << std::endl;
    }
};

int main() {
    Deque deque;

    // Stack-like operations
    deque.pushBack(10);
    deque.pushBack(20);
    std::cout << "After pushBack: ";
    deque.display(); // Output: 10 20

    deque.popBack();
    std::cout << "After popBack: ";
    deque.display(); // Output: 10

    // Queue-like operations
    deque.pushFront(5);
    std::cout << "After pushFront: ";
    deque.display(); // Output: 5 10

    deque.popFront();
    std::cout << "After popFront: ";
    deque.display(); // Output: 10

    return 0;
}
