#include <stdexcept>
#include "array_stack.h"

// uses name of class to find where it belongs to
ArrayStack::ArrayStack() : ArrayStack(INIT_SIZE) { }
// the call MUST be before the body of the constructor

// overloaded funciton, useful for defined sizes
ArrayStack::ArrayStack(size_t initSize)
{
    count = 0;
    currentSize = initSize;
    stack = new int[currentSize];
}

// colins cannot be used
// must always be public
ArrayStack::~ArrayStack()
{
    delete[] stack;
}

void ArrayStack::push(int val)
{
    if (count == currentSize)
        resize(); // we need to resize if the stack is full

    stack[count++] = val;
}

void ArrayStack::pop()
{
    if (empty())
        throw std::runtime_error("Pop on empty stack not allowed"); // self explainatory

    --count;
}

int ArrayStack::peek()
{

    if (empty())
        throw std::runtime_error("Peek on empty stack not allowed"); // self explainatory

    return stack[count - 1];
}

bool ArrayStack::empty()
{
    return count == 0;
}

void ArrayStack::resize()
{
    currentSize *= SCALING_FACTOR;

    int *newStack{new int[currentSize]}; // make new array using pointers

    for (size_t i = 0; i < count; ++i)
        newStack[i] = stack[i];

    delete[] stack; // free up the memory
    stack = newStack;
}
