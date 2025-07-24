#ifndef LINKED_STACK_H
#define LINKED_STACK_H

class LinkedStack
{
public:
    LinkedStack();
    ~LinkedStack();
    void push(int);
    void pop();
    int peek();
    bool empty();

private:
    struct Node
    {
        int val;
        Node *next;
    };
    Node *head;
};

#endif