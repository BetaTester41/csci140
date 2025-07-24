#include <iostream>
#include <stdexcept>

void funcA();
void funcB();
void funcC(); // throws exception

int main(int argc, char const *argv[])
{
    funcA();
    return 0;
}

void funcA()
{
    funcB();
}

void funcB()
{
    try
    {
        funcC();
    }
    catch (const std::exception &)
    {
        std::cout << "Caught by funcB" << std::endl; // old method of catching errors with defined library.
        throw;                                       // tell other function to handle it >:)
    }
}

void funcC()
{
    throw; // cannot rethrow without anything that was threw (program exits)
    try
    {
        // throw std::runtime_error("There was a runtime error ");
        // throw "A cstyle string";
        throw 10;
    }
    catch (int e)
    {
        std::cout << e << std::endl; // old method of catching errors with defined library.
        throw;                       // tell other function to handle it >:)
    }
    catch (const char *msg)
    {
        std::cout << msg << std::endl;
    }
    catch (const std::runtime_error &)
    {
        std::cout << "Caught by runtime_error handler" << std::endl; // must be from most specific to least specific.
    }
    catch (const std::exception &)
    {
        std::cout << "Caught by general exception handler" << std::endl;
    }
}
