#include <stdexcept>
#include "linked_stack.h"

LinkedStack::LinkedStack()
{
    head = nullptr;
}

LinkedStack::~LinkedStack()
{
    while (!empty())
        pop();
}

void LinkedStack::push(int val)
{
    head = new Node{val, head};  // initilized like an array (automatically built)
}

void LinkedStack::pop()
{
    Node *temp{head};

    if (empty())
        throw std::runtime_error("Pop on empty stack not allowed"); // self explainatory
    
    head = (head -> next);

    delete temp;
}

int LinkedStack::peek()
{
    if (empty())
        throw std::runtime_error("Peek on empty stack not allowed"); // self explainatory

    return head->val;
}

bool LinkedStack::empty()
{
    return head == nullptr;
}
