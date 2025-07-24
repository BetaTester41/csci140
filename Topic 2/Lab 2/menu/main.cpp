#include <iostream>

/*
Main Menu

1) Print hello
2) Print goodbye
3) Exit

*/

void printMenu();
char getInput(const std::string &);
void processChoice(char);
bool isValidChoice(char);
char toLower(char);

int main(int argc, char const *argv[])
{
    int choice;
    while (true)
    {
        printMenu();
        choice = getInput("Enter choice (a, b, c): ");

        if (choice == 'c')
            break;

        processChoice(choice);
    }
    return 0;
}

void printMenu()
{
    std::cout << "Main Menu\n"
              << "a) Print hello\n"
              << "b) Print goodbye\n"
              << "c) Exit\n";
            // changed from numbers to letters
}

char getInput(const std::string &prompt)
{
    char choice;
    // change from number to letter
    
    std::cout << prompt;
    std::cin >> choice;
    choice = toLower(choice);

    if (isValidChoice(choice)) return choice; // base case

    std::cout << "\nBad Choice!! Try again...\n" << std::endl;

    return getInput(prompt); // recursion :0
}

void processChoice(char choice)
{
    switch (choice)
    {
    case 'a':
        std::cout << "\nHello\n\n";
        break;
    case 'b':
        std::cout << "\nGoodbye\n\n";
        break;
    // default:
    //     std::cout << "\nBad input\n\n";
    //     break;
    // simpler method of validating choices...
    }
}

bool isValidChoice(char choice)
{
    switch (choice)
    {
    case 'a' : case 'b' : case 'c':
        return true;
    }
    return false;
}

char toLower(char c) 
{
    if (c >= 'A' && c <= 'Z') c |= 32;
    // c += 32; also work, but bitwise is faster :)
    return c;
}