#include "VAT.h"

VAT::VAT() : VATrate(0)
{
}

std::vector<int> VAT::GetVATrates()
{
    return std::vector<int>();
}

std::vector<int>* VAT::GetAddressVATrates()
{   
    return &VATrates;
}

void VAT::AddVat()
{
    std::cout << "Podaj nowa stawke VAT : ";
    std::cin >> VATrate;
    
    while (!std::cin)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
        std::cout << "Podaj poprawna stawke (w %)!" << std::endl;
        std::cin >> VATrate;
    }
    
    for (int i = 0; i < VATrates.size(); i++)
    {
        if (VATrate == VATrates[i])
        {
            std::cout << "Stawka VAT juz istnieje!" << std::endl;
                return;
        }
    }
    VATrates.push_back(VATrate);
    std::cout << "Pomyslnie dodano nowa stawke VAT!" << std::endl;
    return;
}

void VAT::DeleteVAT()
{  
    WriteVAT();
    std::cout << "Podaj stawke VAT do usuniecia (w %): ";
    std::cin >> VATrate;

    while (!std::cin)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
        std::cout << "Podaj poprawna stawke (w %)!" << std::endl;
        std::cin >> VATrate;

    }

    for (int i = 0; i < VATrates.size(); i++)
    {
        if (VATrate == VATrates[i])
        {
            int index = i;
            VATrates.erase(VATrates.begin() + index);
            std::cout << "Pomyslnie usunieto wybrana stawke VAT!" << std::endl;
            return;
        }         
    }
    std::cout << "Taka stawka VAT nie istnieje" << std::endl;
    return;
}

int VAT::ChooseVAT()
{
    WriteVAT();
    bool rightVAT = true;

    while (rightVAT)
    {  
        std::cout << "Wybierz stawke VAT (w %): ";
        std::cin >> VATrate;

        for (int i = 0; i < VATrates.size(); i++)
        {
            if (VATrate == VATrates[i])
            {
                rightVAT = false;
                choosenVAT = VATrate;
                std::cout << "Pomyœlnie wybrano stawke VAT." << std::endl;
                return choosenVAT;
            }
        } 
        std::cout << "Taka stawka VAT nie istnieje" << std::endl;
    }
}

void VAT::WriteVAT()
{
    for (int i = 0; i < VATrates.size(); i++)
    {
        std::cout << "Dostepne stawki VAT: " << std::endl;
        std::cout << i+1 << '.' << VATrates[i] << '%' << std::endl;
    }
}