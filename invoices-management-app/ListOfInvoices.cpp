#include "ListOfInvoices.h"


std::shared_ptr<ListOfInvoicesElement> ListOfInvoices::GetpHead()
{
    return pHead;
}

void ListOfInvoices::CreateInvoice(Unit& unit, VAT& vat)
{
    std::string tmptype,
        tmpnumber,
        tmpnumberOfCorrected,
        tmpplace,
        tmppaymentMethod,
        tmpaccountNumber,
        tmpbankName,
        tmpcauseOfCorrection,
        tmpissuer;
    PersonalData tmpseller,
        tmpbuyer;
    Date tmpdateOfCorrected,
        tmpdateOfIssue,
        tmpdateOfDelivery,
        tmpdateOfPayment;
    double tmpsumNetto,
        tmpsumVAT,
        tmpsumBrutto;
    Invoice tmpinvoice;
    CorrectiveInvoice tmpcorrective;
    ProductManagement productmanagement;
    std::vector<Product> tmpproducts,
        tmpproductsAC;

    std::cout << "Wybierz typ faktury: " <<std::endl;
    std::cout << "[1] faktura VAT | [2] faktura korygujaca" << std::endl;
    int choice1 = UserInteractionHelper::CheckIfInt();
    if (choice1 == 1)
    {
        tmptype = "faktura VAT";
    }
    else if (choice1 == 2)
    {
        tmptype = "faktura korygujaca";
    }
    else 
    {
        std::cout << "Podaj poprawna liczbe!" << std::endl;
        choice1 = UserInteractionHelper::CheckIfInt();
    }
 
    std::cout << "Podaj numer faktury: ";
    std::cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
    tmpnumber = UserInteractionHelper::CheckIfCorrectString();
    while (CheckIfThereIsInvoiceWithSuchNumber(tmpnumber) != nullptr)
    {
        std::cout << "Faktura o takim numerze juz istnieje! Podaj inny numer." << std::endl;
        tmpnumber = UserInteractionHelper::CheckIfCorrectString();
    }
    if (choice1 == 2)
    {
        std::cout << "Podaj numer korygowanej faktury: ";
        tmpnumberOfCorrected = UserInteractionHelper::CheckIfCorrectString();
        std::cout << "Podaj date wystawienia korygowanej faktury (format: dzien miesiac rok):  ";
        tmpdateOfCorrected = tmpinvoice.SetDate();
        std::cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
    }
    std::cout << "Podaj miejsce wystawienia faktury: ";
    tmpplace = UserInteractionHelper::CheckIfCorrectString();
    std::cout << "Podaj date wystawienia faktury (format: dzien miesiac rok): ";
    tmpdateOfIssue = tmpinvoice.SetDate();
    std::cout << "Podaj date wykonania uslugi/ dostarczenia towaru (format: dzien miesiac rok): ";
    tmpdateOfDelivery = tmpinvoice.SetDate();
    
    tmpseller = tmpinvoice.SetSeller();
    tmpbuyer = tmpinvoice.SetBuyer();

    if (choice1 == 2)
    {
        std::cout << "PRODUKTY PRZED KOREKTA: " << std::endl;
    }
    else if (choice1 == 1)
    {
        std::cout << "PRODUKTY: " << std::endl;
    }
    productmanagement.AddNewProduct(tmpproducts, unit, vat);
    if (choice1 == 2)
    {
        std::cout << "PRODUKTY PO KOREKCIE: " << std::endl;
        productmanagement.AddNewProduct(tmpproductsAC, unit, vat);
    }
    if (choice1 == 2)
    {
        tmpsumNetto = tmpcorrective.CalculateSumNettoAC(tmpproducts, tmpproductsAC);
        tmpsumVAT = tmpcorrective.CalculateSumVATAC(tmpproducts, tmpproductsAC);
        tmpsumBrutto = tmpcorrective.CalculateSumBruttoAC(tmpproducts, tmpproductsAC);
    }
    else if (choice1 == 1)
    {
        tmpsumNetto = tmpinvoice.CalculateSumNetto(tmpproducts);
        tmpsumVAT = tmpinvoice.CalculateSumVAT(tmpproducts);
        tmpsumBrutto = tmpinvoice.CalculateSumBrutto(tmpproducts);
    }
    std::cout << "Podaj rodzaj platnosci: ";
    std::cout << "[1]- przelew | [2]- gotowka " << std::endl;
    int choice2 = UserInteractionHelper::CheckIfInt();
    if (choice2 == 1)
    {
        tmppaymentMethod = "przelew";
        std::cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
        std::cout << "Podaj numer konta: ";
        tmpaccountNumber = UserInteractionHelper::CheckIfCorrectString();
        std::cout << "Podaj nazwe banku: ";
        std::getline(std::cin, tmpbankName);
    }
    else if (choice2 == 2)
    {
        tmppaymentMethod = "gotowka";
        tmpaccountNumber = "-";
        tmpbankName = "-";
    }
    else
    {
        std::cout << "Podaj poprawna liczbe!" << std::endl;
        choice2 = UserInteractionHelper::CheckIfInt();
    }
    std::cout << "Podaj date platnosci (format: dzien miesiac rok): ";
    tmpdateOfPayment = tmpinvoice.SetDate();
    std::cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
    if (choice1 == 2)
    {
        std::cout << "Przyczyna korekty: ";
        std::cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
        std::getline(std::cin, tmpcauseOfCorrection);
    }  
    std::cout << "Osoba upowazniona do wystawienia faktury: ";
    std::getline(std::cin, tmpissuer);
    std::cout << std::endl;

    AddInvoice(tmptype, tmpnumber, tmpnumberOfCorrected,
        tmpdateOfCorrected, tmpplace, tmpdateOfIssue, tmpdateOfDelivery, tmpseller, tmpbuyer, tmpproducts, tmpproductsAC, 
        tmpsumNetto, tmpsumVAT, tmpsumBrutto, tmppaymentMethod, tmpaccountNumber, tmpbankName, tmpdateOfPayment, 
tmpcauseOfCorrection, tmpissuer);
}

void ListOfInvoices::CorrectTheInvoice(Unit& unit, VAT& vat)
{
    std::string tmptype,
        tmpnumber,
        tmpnumberOfCorrected,
        tmpplace,
        tmppaymentMethod,
        tmpaccountNumber,
        tmpbankName,
        tmpcauseOfCorrection,
        tmpissuer;
    PersonalData tmpseller,
        tmpbuyer;
    Date tmpdateOfCorrected,
        tmpdateOfIssue,
        tmpdateOfDelivery,
        tmpdateOfPayment;
    double tmpsumNetto,
        tmpsumVAT,
        tmpsumBrutto;
    Invoice tmpinvoice;
    CorrectiveInvoice tmpcorrective;
    ProductManagement productmanagement;
    std::vector<Product> tmpproducts,
        tmpproductsAC;

    std::cout << "Podaj numer faktury, ktora chcesz skorygowac: ";
    std::cin >> tmpnumberOfCorrected;
    auto ptr = CheckIfThereIsInvoiceWithSuchNumber(tmpnumberOfCorrected);
    if (ptr == nullptr)
    {
        std::cout << "Faktura o podanym numerze nie istnieje!";
        return;
    }
    if (ptr->GetType() == "faktura korygujaca")
    {
        std::cout << "Nie mo¿na skorygowaæ faktury korygujacej!";
        return;
    }
    tmptype = "faktura korygujaca";
    tmpnumberOfCorrected = ptr->GetNumber();
        std::cout << "Podaj numer faktury korygujacej: ";
    std::cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
    tmpnumber = UserInteractionHelper::CheckIfCorrectString();
    while (CheckIfThereIsInvoiceWithSuchNumber(tmpnumber) != nullptr)
    {
        std::cout << "Faktura o takim numerze juz istnieje! Podaj inny numer." << std::endl;
        tmpnumber = UserInteractionHelper::CheckIfCorrectString();
    }
    tmpdateOfCorrected = ptr->GetDateOfIssue();
    std::cout << "Podaj miejsce wystawienia faktury: ";
    tmpplace = UserInteractionHelper::CheckIfCorrectString();
    std::cout << "Podaj date wystawienia faktury korygujacej (format: dzien miesiac rok): ";
    tmpdateOfIssue = tmpinvoice.SetDate();
    tmpdateOfDelivery = ptr->GetDateOfDelivery();

    tmpseller = tmpinvoice.SetSeller();
    tmpbuyer = tmpinvoice.SetBuyer();

    tmpproducts = ptr->GetProducts();

    std::cout << "PRODUKTY PO KOREKCIE: " << std::endl;
    productmanagement.AddNewProduct(tmpproductsAC, unit, vat);

    tmpsumNetto = tmpcorrective.CalculateSumNettoAC(tmpproducts, tmpproductsAC);
    tmpsumVAT = tmpcorrective.CalculateSumVATAC(tmpproducts, tmpproductsAC);
    tmpsumBrutto = tmpcorrective.CalculateSumBruttoAC(tmpproducts, tmpproductsAC);

    std::cout << "Podaj rodzaj platnosci: ";
    std::cout << "[1]- przelew | [2]- gotowka " << std::endl;
    int choice2 = UserInteractionHelper::CheckIfInt();
    if (choice2 == 1)
    {
        tmppaymentMethod = "przelew";
        std::cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
        std::cout << "Podaj numer konta: ";
        tmpaccountNumber = UserInteractionHelper::CheckIfCorrectString();
        std::cout << "Podaj nazwe banku: ";
        std::getline(std::cin, tmpbankName);
    }
    else if (choice2 == 2)
    {
        tmppaymentMethod = "gotowka";
        tmpaccountNumber = "-";
        tmpbankName = "-";
    }
    else
    {
        std::cout << "Podaj poprawna liczbe!" << std::endl;
        choice2 = UserInteractionHelper::CheckIfInt();
    }
    std::cout << "Podaj date platnosci (format: dzien miesiac rok): ";
    tmpdateOfPayment = tmpinvoice.SetDate();
    std::cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
    std::cout << "Przyczyna korekty: ";
    std::cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
    std::getline(std::cin, tmpcauseOfCorrection);
    std::cout << "Osoba upowazniona do wystawienia faktury: ";
    std::getline(std::cin, tmpissuer);
    std::cout << std::endl;

    AddInvoice(tmptype, tmpnumber, tmpnumberOfCorrected,
        tmpdateOfCorrected, tmpplace, tmpdateOfIssue, tmpdateOfDelivery, tmpseller, tmpbuyer, tmpproducts, tmpproductsAC,
        tmpsumNetto, tmpsumVAT, tmpsumBrutto, tmppaymentMethod, tmpaccountNumber, tmpbankName, tmpdateOfPayment,
        tmpcauseOfCorrection, tmpissuer);

}

void ListOfInvoices::AddInvoice(std::string type, std::string number, std::string numberOfCorrected, Date dateOfCorrected, std::string place, Date dateOfIssue,
    Date dateOfDelivery, PersonalData seller, PersonalData buyer, std::vector<Product> products,
    std::vector<Product> productsAC, double sumNetto,
    double sumVAT, double sumBrutto, std::string paymentMethod, std::string accountNumber, std::string bankName, Date dateOfPayment, std::string causeOfCorrection,
    std::string issuer)
{
    std::unique_ptr<ListOfInvoicesElement> newOne(new ListOfInvoicesElement);

    if (!pHead)
    {
        if (type == "faktura VAT")
        {
            std::unique_ptr<Invoice> tmp = std::make_unique<Invoice>(type, number, place, dateOfIssue, dateOfDelivery, seller,
            buyer, products, sumNetto, sumVAT, sumBrutto, paymentMethod,  accountNumber, bankName,  dateOfPayment, issuer);
            newOne->pInvoice = move(tmp);
        }
        else if (type == "faktura korygujaca")
        {
            std::unique_ptr<CorrectiveInvoice> tmp = std::make_unique<CorrectiveInvoice>(type, number, numberOfCorrected,
                dateOfCorrected, place, dateOfIssue, dateOfDelivery, seller, buyer, products, productsAC, sumNetto,
                sumVAT, sumBrutto, paymentMethod, accountNumber, bankName, dateOfPayment, causeOfCorrection, issuer);
            newOne->pInvoice = move(tmp);
        }  
            pHead = move(newOne);
    }
    else
    {
        ListOfInvoicesElement* tmp2 = pHead.get();
        while (tmp2->pNext)
        {
            tmp2 = tmp2->pNext.get();
        }
        if (type == "faktura VAT")
        {
            std::unique_ptr<Invoice> tmp = std::make_unique<Invoice>(type, number, place, dateOfIssue, dateOfDelivery, seller,
                buyer, products, sumNetto, sumVAT, sumBrutto, paymentMethod, accountNumber, bankName, dateOfPayment, issuer);
            newOne->pInvoice = move(tmp);
        }
        else if (type == "faktura korygujaca")
        {
            std::unique_ptr<CorrectiveInvoice> tmp = std::make_unique<CorrectiveInvoice>(type, number, numberOfCorrected,
                dateOfCorrected, place, dateOfIssue, dateOfDelivery, seller, buyer, products, productsAC, sumNetto,
                sumVAT, sumBrutto, paymentMethod, accountNumber, bankName, dateOfPayment, causeOfCorrection, issuer);
            newOne->pInvoice = move(tmp);
        }
        tmp2->pNext = move(newOne);
    }
}

void ListOfInvoices::DeleteInvoice()
  {
    ListOfInvoicesElement* tmp = pHead.get();
    std::cout << "Podaj numer faktury, ktora chcesz usunac: " << std::endl;
    std::cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
    std::string tmpdata, userinput = UserInteractionHelper::CheckIfCorrectString();
    
    int counter = 1;
    while (tmp)
    {
        tmpdata = (tmp->pInvoice)->GetNumber();
        if (userinput == tmpdata)
        {
            if (pHead == nullptr)
            {
                return;
            }
            else if (counter == 1)
            {
                std::shared_ptr<ListOfInvoicesElement> tmp = std::move(pHead);
                pHead = std::move(tmp->pNext);
                std::cout << "Pomyslnie usunieto wybrana fakture!" << std::endl;
                return;
            }
            else if (counter >= 2)
            {
                int i = 1;
                int j = 1;
                ListOfInvoicesElement* tmp = pHead.get();
                while (tmp)
                {
                    tmp = tmp->pNext.get();
                    i++;
                }
                tmp = pHead.get();
                while (tmp)
                {
                    if ((j + 1) == counter) break;
                    tmp = tmp->pNext.get();
                    j++;
                }
                if (i <= counter)
                {
                    return;
                }
                if (tmp->pNext->pNext)
                {
                    std::unique_ptr<ListOfInvoicesElement> tmp2 = std::move(tmp->pNext->pNext);
                    tmp->pNext = std::move(tmp2);
                    std::cout << "Pomyslnie usunieto wybrana fakture!" << std::endl;
                    return;
                }
                else
                {
                    tmp->pNext = std::move(tmp->pNext->pNext);
                    std::cout << "Pomyslnie usunieto wybrana fakture!" << std::endl;
                    return;
                }
            }
        }
        tmp = tmp->pNext.get();
        counter++;
    }
    std::cout << "Brak faktury o takich parametrach." << std::endl;

}

void ListOfInvoices::WriteAll()
{
    auto t = pHead.get();
    if (t) {
        while (t) {
             (t->pInvoice)->WriteInvoiceOnScreen();
            t = t->pNext.get();
        }
    }
    else 
    {
        std::cout << "Brak faktur." << std::endl;
    }
}

ListOfInvoices::~ListOfInvoices()
{
    while (pHead)
    {
        pHead = std::move(pHead->pNext);
    }
}

void ListOfInvoices::ReadInvoiceFromFile(std::string& line, std::string fileName)
{
    std::string tmptype,
        tmpnumber,
        tmpnumberOfCorrected,
        tmpplace,
        tmppaymentMethod,
        tmpaccountNumber,
        tmpbankName,
        tmpcauseOfCorrection,
        tmpissuer,
        tmpproductname;
    PersonalData tmpseller,
        tmpbuyer;
    Date tmpdateOfCorrected,
        tmpdateOfIssue,
        tmpdateOfDelivery,
        tmpdateOfPayment;
    double tmpsumNetto,
        tmpsumVAT,
        tmpsumBrutto;
    Invoice tmpinvoice;
    CorrectiveInvoice tmpcorrective;
    std::vector<Product> tmpproducts,
        tmpproductsAC;
    Product tmpproduct;
    int counter = 1;
    int invoicetype = 0; //1 - faktura VAT, 2 - faktura korygujaca
    
    std::string tmp = "";
    std::ifstream file(fileName);
  
        while (std::getline(file, line))
        {
            std::stringstream ss(line);
            switch (counter)
            {
            case 1:
                tmptype = line;
                if (line == "faktura VAT")
                {
                    invoicetype = 1;
                    counter++;
                    break;
                }
                else if (line == "faktura korygujaca")
                {
                    invoicetype = 2;
                    counter ++;
                    break;
                }
            case 2:
                 if (invoicetype == 1)
                {
                    ss >> tmpnumber >> tmpplace;       
                    counter = 4;
                    break;
                }
                else if (invoicetype == 2)
                {
                     ss >> tmpnumber >> tmpnumberOfCorrected >> tmpplace;
                    counter++;
                    break;
                }
            case 3:
               tmpdateOfCorrected = tmpdateOfCorrected.ReadDateFromFile(line);
                counter++;
                break;
            case 4:
                tmpdateOfIssue = tmpdateOfIssue.ReadDateFromFile(line);
                counter++;
                break;
            case 5:
                tmpdateOfDelivery = tmpdateOfDelivery.ReadDateFromFile(line);
                counter++;
                break;
            case 6:
                tmpseller.SetName(line);
                counter++;
                break;
            case 7:
                tmpseller.SetAddress(line);
                counter++;
                break;
            case 8:
                tmpseller.SetNIP(line);
                counter++;
                break;
            case 9:
                tmpbuyer.SetName(line);
                counter++;
                break;
            case 10:
                tmpbuyer.SetAddress(line);
                counter++;
                break;
            case 11:
                tmpbuyer.SetNIP(line);
                counter++;
                break;
            case 12:
                if (line != "end")
                {
                    tmpproductname = line;
                    counter++;
                    break;
                }
                else if (line == "end" && invoicetype == 1)
                {
                    counter = 16;
                    break;
                }
                else if (line == "end" && invoicetype == 2)
                {
                    counter = 14;
                    break;
                }  
            case 13:
                tmpproduct = tmpproduct.ReadProductFromFile(line, tmpproductname);
                tmpproducts.push_back(tmpproduct);
                counter = 12;
                break;
            case 14:
                    if (line != "end")
                    {
                        tmpproductname = line;
                        counter++;
                        break;
                    }
                    else if (line == "end" && invoicetype == 1)
                    {
                        counter = 16;
                        break;
                    }
                    else if (line == "end" && invoicetype == 2)
                    {
                        counter = 16;
                        break;
                    }  
            case 15:
                tmpproduct = tmpproduct.ReadProductFromFile(line, tmpproductname);
                tmpproductsAC.push_back(tmpproduct);
                counter = 14;
                break;
            case 16:
                if (invoicetype == 1)
                {
                    ss >> tmpsumNetto >> tmpsumVAT >> tmpsumBrutto >> tmppaymentMethod >> tmpaccountNumber;
                    counter++;
                    break;
                }
                else if (invoicetype == 2)
                {
                    ss >> tmpsumNetto >> tmpsumVAT >> tmpsumBrutto >> tmppaymentMethod >> tmpaccountNumber;
                    counter++;
                    break;
                }
            case 17:
                if (invoicetype == 1)
                {
                   tmpbankName = line;
                    counter = 19;
                    break;
                }
                else if (invoicetype == 2)
                {
                    tmpbankName = line;
                    counter++;
                    break;
                }
            case 18:
                tmpcauseOfCorrection = line;
                counter++;
                break;
            case 19:
                tmpissuer = line;
                counter++;
                break;
            case 20:
                tmpdateOfPayment = tmpdateOfPayment.ReadDateFromFile(line);     
                AddInvoice(tmptype, tmpnumber, tmpnumberOfCorrected,
                    tmpdateOfCorrected, tmpplace, tmpdateOfIssue, tmpdateOfDelivery, tmpseller, tmpbuyer, tmpproducts, tmpproductsAC,
                    tmpsumNetto, tmpsumVAT, tmpsumBrutto, tmppaymentMethod, tmpaccountNumber, tmpbankName, tmpdateOfPayment,
                    tmpcauseOfCorrection, tmpissuer);
                tmpproducts.clear();
                tmpproductsAC.clear();
                counter = 1;
                break;
            }
      
        }      
}

std::shared_ptr<Invoice> ListOfInvoices::CheckIfThereIsInvoiceWithSuchNumber(std::string number)
{
    ListOfInvoicesElement* t = pHead.get();
    std::string tmpdata;

    if (t) {
        while (t)
        {
            tmpdata = (t->pInvoice)->GetNumber();
            if (tmpdata == number)
            {
                return t->pInvoice;
            }
            t = t->pNext.get();
        }
    }
    else
    {
        return nullptr;
    }
    return nullptr;
}