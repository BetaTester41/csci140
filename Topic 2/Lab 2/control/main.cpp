#include <iostream>

int main(int argc, char const *argv[])
{
    size_t i{10};
    // {
    //     size_t i{10};

    //     while (i > 0) // still works when nothing is initilized (for loop)
    //     {
    //         // if (i <= 0) break;
    //         std::cout << i << std::endl;
    //         --i;
    //     }
    // }
    // std::cout << i << std::endl; // i cannot be used outside the loop

    do
    {
        std::cout << i-- << std::endl;
    } while (i > 0); // you need the semicolin after the do loop for some reason :(
    std::cout << i-- << std::endl;

    return 0;
}


/*

Relational Operations
> (greater than)
< (less than)
>= (greater than or equal)
<= (less than or equal)

Equalitity Operator
== (equals)
!= (inequality)

Compareative Operators
&& (and)
|| (or)

*/