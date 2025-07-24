#ifndef QUEUE_H
#define QUEUE_H

template <typename T>
struct Queue
{
    virtual ~Queue() {};
    virtual void enqueue(const T &) = 0;
    virtual void dequeue() = 0;
    virtual T front() const = 0;
    virtual bool empty() const = 0;
};

#endif