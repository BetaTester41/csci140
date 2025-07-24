#include "queue.h"
#include "node.h"
#include "empty_queue_exception.h"

#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H

template <typename T>

class LinkedQueue : public Queue<T>
{
    LinkedQueue() : head{}, tail{} {} // constructor
    ~LinkedQueue()
    {
        while (!empty())
            dequeue();
    };

public:
    void enqueue(const T &item)
    {
        // Node<t> node{new Node<t>{item, nullptr}};
        tail = (empty() ? head : tail->next) = new Node<t>{item, nullptr}; // simplified programming
        // if (empty())
        //     head = node;
        // else
        //     tail->next = node;
        // tail = node;
    }
    void dequeue()
    {
        if (empty())
            throw EmptyQueueException("Cannot dequeue and empty queue");
        Node<T> *temp{head};
        head = head->next;
        delete temp;
        if (empty())
            tail = nullptr;
    }
    T front() const
    {
        if (empty())
            throw EmptyQueueException("Front called on empty queue");
        return head->item;
    }
    bool empty() const
    {
        return head == nullptr;
    }

private:
    Node<T> *head;
    Node<T> *tail;
};

#endif