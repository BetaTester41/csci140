#include <iostream>

#define COL_QTY 3
#define ROW_QTY 3

void print2dArray(int[][COL_QTY]);

int main(int argc, char const *argv[])
{
    int map[][COL_QTY]{1, 2, 3, 4, 5, 6, 7, 8, 9}; // the size of the column is required (row is optional)

    print2dArray(map);

    return 0;
}

void print2dArray(int map[][COL_QTY])
{
    for (size_t row = 0; row < ROW_QTY; ++row)
    {
        for (size_t col = 0; col < COL_QTY; ++col)
        {
            std::cout << map[row][col] << ' ';
        }
        std::cout << std::endl;
    }
}