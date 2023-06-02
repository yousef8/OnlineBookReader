#include "utilities.h"
#include <iostream>
#include <vector>
#include <string>

int readInt(int low, int high)
{
    std::cout << "\nEnter number in range (" << low << " - " << high << ") : ";
    int value;
    std::cin >> value;

    if (low <= value && value <= high)
        return value;

    std::cout << "ERROR: number out of range... Try again\n";
    return readInt(low, high);
}

int showReadMenu(const std::vector<std::string> &choices, std::string header)
{
    std::cout << "\n" << header << " :\n";
    for (int choice{0}; choice < (int)choices.size(); choice++)
    {
        std::cout << "\t" << choice + 1 << " : " << choices[choice] << "\n";
    }

    return readInt(1, choices.size());
}