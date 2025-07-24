#include "test.h"
#include "queue.h"
// #include "linked_queue.h"
#include "array_queue.h"
#include "empty_queue_exception.h"

// #define SETUP Queue<int> *q { new LinkedQueue<int> }
#define SETUP Queue<int> *q { new ArrayQueue<int> }
#define CLEAN delete q
#define TEVAL 5
#define TVALS int testVals[] { 1, 2, 3, 4, 5, 6, 7, 8, 9 }
#define TSIZE 9

void testQueueInitiallyEmpty();
void testQueueNotEmptyAfterAdd();
void testFrontReturnsAddedValue();
void testRemoveOnEmptyQueueThrows();
void testRemoveEmptiesQueue();
void testQueueFifoOrder();

int main(int argc, char const *argv[])
{
    testQueueInitiallyEmpty();
    testQueueNotEmptyAfterAdd();
    testFrontReturnsAddedValue();
    testRemoveOnEmptyQueueThrows();
    testRemoveEmptiesQueue();
    testQueueFifoOrder();
    return 0;
}

void testQueueInitiallyEmpty()
{
    SETUP;
    testTrue(q->empty(), "Testing QueueInitiallyEmpty: Empty initial queue.");
    CLEAN;
}

void testQueueNotEmptyAfterAdd()
{
    SETUP;
    q->enqueue(TEVAL);
    testFalse(q->empty(), "Testing QueueNotEmptyAfterAdd: Value add to queue.");
    CLEAN;
}

void testFrontReturnsAddedValue()
{
    SETUP;
    q->enqueue(TEVAL);
    testEqual(q->front(), TEVAL, "Testing FrontReturnsAddedValue: Add value matches test value.");
    CLEAN;
}

void testRemoveOnEmptyQueueThrows()
{
    SETUP;
    try
    {
        q->dequeue();
        testFail("Testing RemoveOnEmptyQueueThrows: Didn't throw on dequeue on empty.");
    }
    catch (const EmptyQueueException &)
    {
        testPass("Testing RemoveOnEmptyQueueThrows: Throws correctly if dequeue on empty.");
    }
    catch (const std::exception &)
    {
        testFail("Testing RemoveOnEmptyQueueThrows: Incorrect throw.");
    }
    CLEAN;
}

void testRemoveEmptiesQueue()
{
    SETUP;
    q->enqueue(TEVAL);
    q->dequeue();
    testTrue(q->empty(), "Testing RemoveEmptiesQueue: Empty after item is added and removed");
    CLEAN;
}

void testQueueFifoOrder()
{
    SETUP;
    TVALS;
    std::string msg{"Testing QueueFifoOrder: FIFO Order"};

    size_t i{0};
    for (; i < TSIZE; ++i)
        q->enqueue(testVals[i]);
    i = 0;
    while (!q->empty())
    {
        if (testVals[i++] != q->front())
            break;
        q->dequeue();
    }
    (q->empty() ? testPass(msg) : testFail(msg));
    CLEAN;
}
