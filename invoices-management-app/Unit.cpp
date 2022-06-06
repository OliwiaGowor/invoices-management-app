#include "Unit.h"

Unit::Unit():unitType("x")
{
}

std::vector<std::string> Unit::GetUnitTypes()
{
	return unitTypes;
}

std::vector<std::string>* Unit::GetAddressUnitTypes()
{
    return &unitTypes;
}


void Unit::AddUnit()
{
    std::cout << "Podaj nowa jednostke sprzedazy: ";
    std::cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
    std::getline(std::cin, unitType);

    for (int i = 0; i < unitTypes.size(); i++)
    {
        if (unitType == unitTypes[i])
        {
            std::cout << "Jednostka sprzedazy juz istnieje!" << std::endl;
            return;
        }
    }
    unitTypes.push_back(unitType);
    std::cout << "Pomyslnie dodano nowa jednostke sprzedazy!" << std::endl;
    return;
}

void Unit::DeleteUnit()
{
    WriteUnits();
    std::cout << "Podaj jednostke sprzedazy do usuniecia (nazwa): ";
    std::cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
    std::getline(std::cin, unitType);

    for (int i = 0; i < unitTypes.size(); i++)
    {
        if (unitType == unitTypes[i])
        {
            int index = i;
            unitTypes.erase(unitTypes.begin() + index);
            std::cout << "Pomyslnie usunieto wybrana jednostke sprzedazy!" << std::endl;
            return;
        }
    }
    std::cout << "Taka jednostka sprzedazy nie istnieje" << std::endl;
    return;
}

std::string Unit::ChooseUnit()
{
    WriteUnits();
    bool rightUnit = true;

    while (rightUnit)
    {
        std::cout << "Wybierz jednostke sprzedazy (nazwa): ";
        std::cin.clear();
        std::getline(std::cin, unitType);

        for (int i = 0; i < unitTypes.size(); i++)
        {
            if (unitType == unitTypes[i])
            {
                rightUnit = false;
                choosenUnit = unitType;
                std::cout << "Pomyœlnie wybrano jednostke sprzedazy." << std::endl;
                return choosenUnit;
            }
        }
        std::cout << "Taka jednostka sprzedazy nie istnieje" << std::endl;
    }
}

void Unit::WriteUnits()
{
    for (int i = 0; i < unitTypes.size(); i++)
    {
        std::cout << "Dostepne jednostki sprzedazy: " << std::endl;
        std::cout << i + 1 << '.' << unitTypes[i] << std::endl;
    }
}