#include "SearchingInvoice.h"

void SearchingInvoice::SearchInvoiceByNumber(std::shared_ptr<ListOfInvoicesElement> list)
{
    std::string tmpdata, userinput;
    ListOfInvoicesElement* t = list.get();
   
    std::cout << "Podaj numer faktury, ktora chcesz wyszukac: ";
    std::cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
    std::getline(std::cin, userinput);
    
    if(t){
        while (t)
        {
            tmpdata = (t->pInvoice)->GetNumber();
            if (tmpdata == userinput)
            {
                (t->pInvoice)->WriteInvoiceOnScreen();
                return;
            }
            t = t->pNext.get(); 
        }
        std::cout << "Nie znalezniono faktury o podanych parametrach!" << std::endl;
    }
    else
    {
        std::cout << "Brak faktur" << std::endl;
    }
}

void SearchingInvoice::SearchInvoiceByBuyerName(std::shared_ptr<ListOfInvoicesElement> list)
{
    std::string userinput;
    PersonalData tmpdata;
    ListOfInvoicesElement* t = list.get();

    std::cout << "Podaj nazwe kupujacego: ";
    std::cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
    std::getline(std::cin, userinput);

    if (t) {
        while (t)
        {
            tmpdata = (t->pInvoice)->GetBuyer();
            if (tmpdata.GetName() == userinput)
            {
                (t->pInvoice)->WriteInvoiceOnScreen();
            }
            t = t->pNext.get();
        }
    }
    else
    {
        std::cout << "Brak faktur" << std::endl;
    }
}

void SearchingInvoice::SearchInvoiceByBuyerNIP(std::shared_ptr<ListOfInvoicesElement> list)
{
    std::string userinput;
    PersonalData tmpdata;
    ListOfInvoicesElement* t = list.get();

    std::cout << "Podaj NIP/PESEL kupujacego: ";
    std::cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
    std::getline(std::cin, userinput);

    if (t) {
        while (t)
        {
            tmpdata = (t->pInvoice)->GetBuyer();
            if (tmpdata.GetNIP() == userinput)
            {
                (t->pInvoice)->WriteInvoiceOnScreen();
            }
            t = t->pNext.get();
        }
    }
    else
    {
        std::cout << "Brak faktur" << std::endl;
    }
}

void SearchingInvoice::SearchInvoiceByDateOfIssue(std::shared_ptr<ListOfInvoicesElement> list)
{
    Date tmpdata;
    ListOfInvoicesElement* t = list.get();
    int day,
        month,
        year;

    std::cout << "Podaj date (format: dzien miesiac rok): ";
    std::cin >> day >> month >> year;
    while (!std::cin)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
        std::cout << "Nieprawidlowy format!" << std::endl;
        std::cin >> day >> month >> year;
    }

    if (t) {
        while (t)
        {
            tmpdata = (t->pInvoice)->GetDateOfIssue();
            if (tmpdata.GetDay() == day && tmpdata.GetMonth() == month && tmpdata.GetYear() == year)
            {
                (t->pInvoice)->WriteInvoiceOnScreen();
            }
            t = t->pNext.get();
        }
    }
    else
    {
        std::cout << "Brak faktur" << std::endl;
    }
}