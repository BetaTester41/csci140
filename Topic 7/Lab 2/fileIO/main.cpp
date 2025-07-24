#include <iostream>
#include <fstream> // file stream
#include <string>
#include <cstdlib>
#include <random>

void printUsage();
void genFile(const std::string &, size_t);
void printFile(const std::string &);
void copyFile(const std::string &, const std::string &);

int main(int argc, char const *argv[])
{
    /*
    -g <file_path> <qty>        generate a file of random ints
    -p <file_path>              print contents of the file
    -c <from_path> <to_path>    copy from to to
    */
    if (argc < 2 || argc > 4)
    {
        printUsage();
        return 1;
    }

    switch (argv[1][1])
    {
    case 'g':
        genFile(argv[2], std::stoi(argv[3]));
        break;

    case 'p':
        printFile(argv[2]);
        break;

    case 'c':
        copyFile(argv[2], argv[3]);
        break;

    default:
        printUsage();
        break;
    }

    return 0;
}

void printUsage()
{
    std::cout << "Usage for SuperCopy:\n"
              << "  -g <file_path> <qty>\t\tgenerate a file of random ints\n"
              << "  -p <file_path>\t\tprint contents of the file\n"
              << "  -c <from_path> <to_path>\tcopy from from_path to to_path" << std::endl;
}

void genFile(const std::string &filePath, size_t qty)
{
    std::ofstream out(filePath);
    for (size_t i = 0; i < qty; ++i)
        out << rand() << std::endl;
    out.close();
}

void printFile(const std::string &filePath)
{
    std::ifstream in(filePath);
    std::string line;

    if (!in)
    {
        std::cout << "General IO Error";
    }

    while (in)
    {
        std::getline(in, line);
        std::cout << line << std::endl;
    }

    in.close();
}

void copyFile(const std::string &, const std::string &) {}