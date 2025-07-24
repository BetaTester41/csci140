#include <stdexcept>

#ifndef EMPTY_QUEUE_EXCEPTION
#define EMPTY_QUEUE_EXCEPTION

struct EmptyQueueException : public std::runtime_error
{
    EmptyQueueException(const std::string &msg) : std::runtime_error(msg) {};
    EmptyQueueException() : EmptyQueueException("Cannot call on empty queue.") {};
};

#endif