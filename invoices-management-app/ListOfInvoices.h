#pragma once
#include "Invoice.h"
#include "CorrectiveInvoice.h"
#include "UserInteractionHelper.h"
#include<memory>

struct ListOfInvoicesElement
{
	std::unique_ptr<ListOfInvoicesElement> pNext;
    std::shared_ptr<Invoice> pInvoice;
};

class ListOfInvoices
{
    std::shared_ptr<ListOfInvoicesElement> pHead;
  
public:
    std::shared_ptr<ListOfInvoicesElement> GetpHead();
	void CreateInvoice(Unit& unit, VAT& vat);
    void CorrectTheInvoice(Unit& unit, VAT& vat);
	void AddInvoice(std::string type, std::string number, std::string numberOfCorrected, Date dateOfCorrected, std::string place, Date dateOfIssue,
        Date dateOfDelivery, PersonalData seller, PersonalData buyer, std::vector<Product> products,
        std::vector<Product> productsAC, double sumNetto,
        double sumVAT, double sumBrutto, std::string paymentMethod, std::string accountNumber, std::string bankName, Date dateOfPayment, std::string causeOfCorrection,
        std::string issuer);
	void DeleteInvoice();
	void WriteAll();
    void ReadInvoiceFromFile(std::string& line, std::string fileName);
    std::shared_ptr<Invoice> CheckIfThereIsInvoiceWithSuchNumber(std::string number);
	~ListOfInvoices();
};

