#include <iostream>
#include <string> // getline

std::string getStringInput(const std::string &);
int getInteger(const std::string &);
void clearInStream();

int main(int argc, char const *argv[])
{
    // std::cout << getStringInput("Enter name: ") << /*std::endl*/ '\n';
    int value;

    while (true)
    {
        value = getInteger("Enter number (-1 to stop): ");

        if(value == -1) break;
        std::cout << value << std::endl;
    }

    return 0;
}

std::string getStringInput(const std::string &prompt)
{
    std::string input;

    std::cout << prompt;
    // std::cin >> input; // input only takes string until space delimiter
    std::getline(std::cin, input); // gets the whole line of input :)

    return input;
}

int getInteger(const std::string &prompt)
{
    int value;

    std::cout << prompt;
    std::cin >> value;

    if (std::cin) return value; // catch if cin is buggin (aka letter for int)

    clearInStream();

    std::cout << "Very bad input! Try again... >:(\n";
    return getInteger(prompt); 
}

void clearInStream()
{
    std::cin.clear();
    std::cin.ignore(1024, '\n');
}