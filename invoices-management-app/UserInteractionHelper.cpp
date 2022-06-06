#include "UserInteractionHelper.h"

int UserInteractionHelper::CheckIfInt()
{
    int number;
    std::cin >> number;
    while (!std::cin)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
        std::cout << "Podaj liczbe!" << std::endl;
        std::cin >> number;
    }
    return number;
}

double UserInteractionHelper::CheckIfDouble()
{
    double number;
    std::cin >> number;
    while (!std::cin)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
        std::cout << "Podaj liczbe!" << std::endl;
        std::cin >> number;
    }
    return number;
}

std::string UserInteractionHelper::CheckIfCorrectString()
{
    std::string checkThis;

    std::getline(std::cin, checkThis);
    while (checkThis.find(" ") != std::string::npos)
    {
        std::cin.clear();
        std::cout << "Niepoprawny format! Dozwolone tylko jedno slowo." << std::endl;
        std::cin >> checkThis;
    }
        return checkThis;
}