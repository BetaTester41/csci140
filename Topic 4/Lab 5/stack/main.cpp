#include <iostream>

#include "array_stack.h"
#include "linked_stack.h"

int main(int argc, char const *argv[])
{
    // ArrayStack stack;
    ArrayStack stack(100); // use the overloaded constructor
    // LinkedStack stack;

    for (size_t i = 0; i < 100; ++i)
        stack.push(i);

    while (!stack.empty())
    {
        std::cout << stack.peek() << std::endl;
        stack.pop();
    }

    return 0;
}
