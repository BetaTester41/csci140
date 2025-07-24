#include <stdexcept>

#include "linked_stack.h"

LinkedStack::LinkedStack() : head{} {} // nothing required in the function body

LinkedStack::~LinkedStack() // meant to deallocate heap memory items
{
    while (!empty()) pop();
}

void LinkedStack::push(const std::string &item)
{
    head = new Node{item, head};
}

void LinkedStack::pop()
{
    Node *tmp{head};
    if (empty())
        throw std::runtime_error("Cannot pop when empty");
    head = head->next;
    delete tmp;
}

std::string LinkedStack::peek() const
{
    if (empty())
        throw std::runtime_error("Cannot peek when empty");

    return head->item;
}

bool LinkedStack::empty() const
{
    return (head == nullptr);
}
