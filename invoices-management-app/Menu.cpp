#include "Menu.h"

Menu::Menu(FileManagement& args)
{
    this->mainArgs = args;
}

void Menu::RunProgram()
{
    auto ptr = list.GetpHead();
    mainArgs.LoadUnitTypes(unit);
    mainArgs.LoadVATrates(vat);
    mainArgs.LoadInvoices(list);

    Menu::MainMenu();

    mainArgs.SaveUnitTypes(unit);
    mainArgs.SaveVATrates(vat);
    mainArgs.SaveInvoices(list.GetpHead());
    list.~ListOfInvoices();
}

void Menu::MainMenu()
{
    this->choice = 1;

    while (choice)
    {
        std::cout << "Program do faktur" << std::endl;
        std::cout << "---------------------------------" << std::endl;
        std::cout << "MENU WYBORU" << std::endl << std::endl;

        std::cout << "[1]- Wyswietl faktury" << std::endl;
        std::cout << "[2]- Dodaj nowa fakture" << std::endl;
        std::cout << "[3]- Usun fakture" << std::endl;
        std::cout << "[4]- Wyszukaj fakture" << std::endl;
        std::cout << "[5]- Zarzadzaj stawkami VAT" << std::endl;
        std::cout << "[6]- Zarzadzaj jednostkami sprzedazy" << std::endl;
        std::cout << "[0]- Wyjscie" << std::endl << std::endl;

        this->choice = UserInteractionHelper::CheckIfInt();

        switch (choice)
        {
        case 1:
             list.WriteAll();
            break;
        case 2:
            MenuAddInvoice();
            break;
        case 3:
            list.DeleteInvoice();
            break;
        case 4:
            MenuSearch();
            break;
        case 5:
            MenuVATmanagement();
            break;
        case 6:
            MenuUnitManagement();
            break;
        case 0:
            choice = 0;
            break;
        default:
            std::cout << "Podaj poprawna liczbe!" << std::endl << std::endl;
            break;
        }
    }
}

void Menu::MenuAddInvoice()
{
    this->choice = 1;

    while (choice)
    {
        std::cout << "Program do faktur" << std::endl;
        std::cout << "---------------------------------" << std::endl;
        std::cout << "DODAJ NOWA FAKTURE" << std::endl << std::endl;

        std::cout << "[1]- Dodaj nowa fakture (VAT/korygujaca)" << std::endl;
        std::cout << "[2]- Skoryguj istniejaca fakture" << std::endl;
        std::cout << "[9]- Powrot" << std::endl;
        std::cout << "[0]- Wyjscie" << std::endl;

        this->choice = UserInteractionHelper::CheckIfInt();

        switch (choice)
        {
        case 1:
            list.CreateInvoice(unit, vat);
            break;
        case 2:
            list.CorrectTheInvoice(unit, vat);
            break;
        case 9:
            return;
            break;
        case 0:
            choice = 0;
            break;
        default:
            std::cout << "Podaj poprawna liczbe!" << std::endl << std::endl;
            break;
        }
    }
}

void Menu::MenuSearch()
{
    this->choice = 1;

    while (choice)
    {
        std::cout << "Program do faktur" << std::endl;
        std::cout << "---------------------------------" << std::endl;
        std::cout << "WYSZUKAJ FAKTURE" << std::endl << std::endl;

        std::cout << "[1]- Wyszukaj fakture po numerze" << std::endl;
        std::cout << "[2]- Wyszukaj fakture po nazwie kupujacego" << std::endl;
        std::cout << "[3]- Wyszukaj fakture po numerze NIP kupujacego" << std::endl;
        std::cout << "[4]- Wyszukaj fakture po dacie wystawienia" << std::endl;
        std::cout << "[9]- Powrot" << std::endl;
        std::cout << "[0]- Wyjscie" << std::endl;

        this->choice = UserInteractionHelper::CheckIfInt();

        switch (choice)
        {
        case 1:
            search.SearchInvoiceByNumber(list.GetpHead());
            break;
        case 2:
            search.SearchInvoiceByBuyerName(list.GetpHead());
            break;
        case 3:
            search.SearchInvoiceByBuyerNIP(list.GetpHead());
            break;
        case 4:
            search.SearchInvoiceByDateOfIssue(list.GetpHead());
            break;
        case 9:
            return;
            break;
        case 0:
            choice = 0;
        default:
            std::cout << "Podaj poprawna liczbe!" << std::endl << std::endl;
            break;
        }
    }
}

void Menu::MenuVATmanagement()
{
    this->choice = 1;

    while (choice)
    {
        std::cout << "Program do faktur" << std::endl;
        std::cout << "---------------------------------" << std::endl;
        std::cout << "ZARZADZAJ STAWKAMI VAT" << std::endl << std::endl;

        std::cout << "[1]- Dodaj nowa stawke VAT" << std::endl;
        std::cout << "[2]- Usun istniejaca stawke VAT" << std::endl;
        std::cout << "[3]- Wyswietl dostepne stawki VAT" << std::endl;
        std::cout << "[9]- Powrot" << std::endl;
        std::cout << "[0]- Wyjscie" << std::endl;

        this->choice = UserInteractionHelper::CheckIfInt();

        switch (choice)
        {
        case 1:
            vat.AddVat();
            break;
        case 2:
            vat.DeleteVAT();
            break;
        case 3:
            vat.WriteVAT();
            break;
        case 9:
            return;
            break;
        case 0:
            choice = 0;
            break;
        default:
            std::cout << "Podaj poprawna liczbe!" << std::endl << std::endl;
            break;
        }
    }
}

void Menu::MenuUnitManagement()
{
    this->choice = 1;

    while (choice)
    {

        std::cout << "Program do faktur" << std::endl;
        std::cout << "---------------------------------" << std::endl;
        std::cout << "ZARZADZAJ JEDNOSTKAMI SPRZEDAZY" << std::endl << std::endl;

        std::cout << "[1]- Dodaj nowa jednostke sprzedazy" << std::endl;
        std::cout << "[2]- Usun istniejaca jednostke sprzedazy" << std::endl;
        std::cout << "[3]- Wyswietl dostepne jednostki sprzedazy" << std::endl;
        std::cout << "[9]- Powrot" << std::endl;
        std::cout << "[0]- Wyjscie" << std::endl;

        this->choice = UserInteractionHelper::CheckIfInt();

        switch (choice)
        {
        case 1:
            unit.AddUnit();
            break;
        case 2:
            unit.DeleteUnit();
            break;
        case 3:
            unit.WriteUnits();
            break;
        case 9:
            return;
        default:
            std::cout << "Podaj poprawna liczbe!" << std::endl << std::endl;
            break;
        }
    }
}
