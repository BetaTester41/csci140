#include <fstream>
#include <string>
#include <iostream>

#define BUFFER_SIZE 1024

void combineFiles(const std::string&, const std::string&, const std::string&);

int main(int argc, char const *argv[])
{
    std::string inputs[3];
    std::cout << "Enter file 1 path: ";
    std::getline(std::cin, inputs[0]);
    std::cout << "Enter file 2 path: ";
    std::getline(std::cin, inputs[1]);
    std::cout << "Enter file 3 path: ";
    std::getline(std::cin, inputs[2]);
    combineFiles(inputs[0], inputs[1], inputs[2]);

    return 0;
}

void combineFiles(const std::string &file1, const std::string &file2, const std::string &out)
{
    std::ifstream src1(file1, std::ios::binary | std::ios::in);
    std::ifstream src2(file2, std::ios::binary | std::ios::in);
    std::ofstream out1(out, std::ios::binary | std::ios::out);
    char buffer[BUFFER_SIZE];

    if (!src1 || !src2)
    {
        std::cout << "Error opening files!" << std::endl;
        return;
    }

    std::cout << "Write from file 1" << std::endl;

    while (true)
    {
        src1.read(buffer, BUFFER_SIZE);
        if (src1.gcount() == 0)
            break;
        out1.write(buffer, src1.gcount());
    }

    std::cout << "Write from file 2" << std::endl;

    out1 << '\n';
    
    while (true)
    {
        src2.read(buffer, BUFFER_SIZE);
        if (src2.gcount() == 0)
            break;
        out1.write(buffer, src2.gcount());
    }
    src1.close();
    src2.close();
    out1.close();
}