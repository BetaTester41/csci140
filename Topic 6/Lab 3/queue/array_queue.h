#include "queue.h"
#include "empty_queue_exception.h"

#ifndef ARRAY_QUEUE_H
#define ARRAY_QUEUE_H

#define INIT_SZ 16
#define SCALING 2

template <typename T>

class ArrayQueue : public Queue<T>
{
public:
    ArrayQueue() : array{new T[INIT_SZ]}, currentSize{INIT_SZ}, count{}, frnt{-1}, bck{-1} { /*Empty*/ };
    ~ArrayQueue()
    {
        while (!empty())
            dequeue();
    };
    // From Queue.h
    void enqueue(const T &item)
    {
        if (count == currentSize)
            resize();
        array[(++bck) % currentSize] = item;
        if (empty())
            frnt = bck;
        ++count;
    }

    void dequeue()
    {
        if (empty())
            throw EmptyQueueException("Cannot dequeue and empty queue");

        frnt = (++frnt) % currentSize;
        --count;

        if (empty())
            frnt = bck = -1;
    }

    T front() const
    {
        if (empty())
            throw EmptyQueueException("Front called on empty queue");
        return array[frnt];
    }

    bool empty() const { return count == 0; }

private:
    T *array;
    size_t currentSize;
    size_t count;
    int frnt;
    int bck;

    void resize()
    {
        currentSize *= SCALING;
        T *temp{new T[currentSize]};
        for (size_t i = 0; i < count; ++i)
            temp[i] = array[(frnt++) % currentSize];
        frnt = 0;
        bck = count - 1;
        delete[] array;
        array = temp;
    }
};

#endif