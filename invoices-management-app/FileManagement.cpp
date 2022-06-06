#include "FileManagement.h"

FileManagement::FileManagement()
{
}

FileManagement::FileManagement(std::string fileNameVAT, std::string fileNameUnit, std::string fileNameInvoices)
{
    this->fileNameVAT = fileNameVAT;
    this->fileNameUnit = fileNameUnit;
    this->fileNameInvoices = fileNameInvoices;
}

void FileManagement::LoadInvoices(ListOfInvoices& list)
{
    std::ifstream file;
    std::string line;
    file.open(fileNameInvoices, std::ios::in);

    if (file.is_open())
    {  
        list.ReadInvoiceFromFile(line, fileNameInvoices);
        file.close();
    }
    else
        std::cout << "Wystapil blad podczas wczytywania faktur!" << std::endl;
}

void FileManagement::SaveInvoices(std::shared_ptr<ListOfInvoicesElement> list)
{
    ListOfInvoicesElement* t = list.get();
    std::ofstream file;
    std::string line;
    file.open(fileNameInvoices);

    if (file)
    {
        while (t)
        {
            (t->pInvoice)->WriteInvoiceToFile(file);
            t = t->pNext.get();
        }  
    } 
    else
        {
            std::cout << "Wystapil blad podczas zapisywania faktur!" << std::endl;
        }
}

void FileManagement::SaveVATrates(VAT& vat)
{
    std::ofstream file;
    std::string line;
    file.open(fileNameVAT);
    auto * ptr = vat.GetAddressVATrates();

    if (file)
    {
        for (int i = 0; i < (*ptr).size(); i++)
        {
            file << (*ptr)[i] << std::endl;
        }
    }
    else
        std::cout << "Wystapil blad podczas zapisywania wartosci VAT!" << std::endl;

    file.close();
}

void FileManagement::LoadVATrates(VAT& vat)
{
    std::ifstream file(fileNameVAT);
    std::string line;
    int tmp;
    auto* ptr = vat.GetAddressVATrates();

    if (file.is_open())
    {
        while (std::getline(file, line))
        {
            tmp = atoi(line.c_str());
            (*ptr).push_back(tmp);
        }
    }
    else
        std::cout << "Wystapil blad podczas wczytywania wartosci VAT!" << std::endl;
        
}

void FileManagement::SaveUnitTypes(Unit& unit)
{
    std::ofstream file;
    std::string line;
    file.open(fileNameUnit);
    auto* ptr = unit.GetAddressUnitTypes();
    if (file)
    {
        for (int i = 0; i < unit.GetUnitTypes().size(); i++)
        {
            file << (*ptr)[i] << std::endl;
        }
    }
    else
        std::cout << "Wystapil blad podczas zapisywania jednostek sprzedazy!" << std::endl;

    file.close();
}

void FileManagement::LoadUnitTypes(Unit& unit)
{
    std::ifstream file(fileNameUnit);
    std::string line,
                tmp;
    auto* ptr = unit.GetAddressUnitTypes();

    if (file.is_open())
    {
        while (std::getline(file, line))
        {
            tmp = line;
            (*ptr).push_back(tmp);
        }
    }
    else
        std::cout << "Wystapil blad podczas wczytywania jednostek sprzedazy!" << std::endl;
}