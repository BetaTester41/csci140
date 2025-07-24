#include <cstddef>

#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

#define INIT_SIZE 8
#define SCALING_FACTOR 2

class ArrayStack
{
public:
    ArrayStack();
    ArrayStack(size_t);
    ~ArrayStack();
    void push(int);
    void pop();
    int peek();
    bool empty();

private:
    void resize();
    int *stack;
    size_t count;
    size_t currentSize;
};

#endif