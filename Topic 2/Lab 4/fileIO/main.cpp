#include <iostream>
#include <fstream> // file stream

#define BUFFER_SIZE 2048

void writeArray(int[], size_t, std::string &);
void readArray(int[], size_t, std::string &);
void printArray(int[], size_t);
void copyFile(const std::string &, const std::string &);

int main(int argc, char const *argv[])
{
    size_t arraySize{6};
    int srcArray[]{1, 3, 5, 7, 9, 11};
    int dstArray[6]{};
    std::string path("data.txt");

    writeArray(srcArray, arraySize, path);
    readArray(dstArray, arraySize, path);

    printArray(dstArray, arraySize);

    copyFile("test_pattern.png", "test_pattern_copy.png");

    return 0;
}

void writeArray(int array[], size_t count, std::string &path)
{
    std::ofstream out(path); // creates an output file object named "out"

    for (size_t i = 0; i < count; ++i)
        out << array[i] << std::endl;

    out.close(); // good habit to close file object
}

void readArray(int array[], size_t count, std::string &path)
{
    std::ifstream in(path); // creates an output file object named "out"

    for (size_t i = 0; i < count; ++i)
        in >> array[i];

    in.close(); // good habit to close file object
}

void printArray(int array[], size_t count)
{
    std::cout << "[ ";
    for (size_t i = 0; i < count; ++i)
        std::cout << array[i] << " ";
    std::cout << "]" << std::endl;
}

void copyFile(const std::string &srcPath, const std::string &dstPath)
{
    std::ifstream src(srcPath, std::ios::binary);
    std::ofstream dst(dstPath, std::ios::binary);
    char buffer[BUFFER_SIZE];

    while (true)
    {
        src.read(buffer, BUFFER_SIZE);

        if (src.gcount() == 0)
            break;

        dst.write(buffer, src.gcount());
    }
    src.close();
    dst.close();
}
