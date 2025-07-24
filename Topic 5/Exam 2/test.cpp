#include <iostream>

#include "linked_stack.h"

int main(int argc, char const *argv[])
{
    int i{};
    std::string strings[]{"A", "few", "words", "of", "encouragement"};
    LinkedStack stack;

    for (; i <= 100; ++i)
        stack.push(strings[(i+1)%5]);

    while (!stack.empty())
    {
        std::cout << stack.peek() << std::endl;
        stack.pop();
    }
    

    return 0;
}
