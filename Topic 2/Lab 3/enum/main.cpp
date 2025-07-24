#include <iostream>

enum Day //: long // to change ty
{
    SUNDAY, // automatically starts at 0
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY
};

// enum WeekendDay
// {
//     SATURDAY,
//     SUNDAY
// };

std::string days[]{"Sunday", "Monday", "Tuesday"};

void printDailyMsg(Day);

int main(int argc, char const *argv[])
{
    //int SUNDAY = 10; // hides the real enum value
    printDailyMsg(SUNDAY); // to get the enum value in namespace
    return 0;
}

void printDailyMsg(Day day)
{
    switch (day)
    {
    case FRIDAY: case SATURDAY: case SUNDAY:
        std::cout << "It's " << days[day] << "! Hope you're having a nice weekend!\n";
        break;
    
    default:
        std::cout << "Another work day (T_T)\n";
        break;
    }
}