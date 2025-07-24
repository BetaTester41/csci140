#include <string>

#include "node.h"

#ifndef LINKED_STACK_H
#define LINKED_STACK_H

class LinkedStack
{
public:
    LinkedStack();
    ~LinkedStack();
    void push(const std::string &);
    void pop();
    std::string peek() const;
    bool empty() const;

private:
    Node *head;
};

#endif