#pragma once
#include <iostream>
#include "Invoice.h"

class CorrectiveInvoice : public Invoice
{
	std::string numberOfCorrected,
		causeOfCorrection;
	Date dateOfCorrected;
	std::vector<Product> productsAC;

public:
	CorrectiveInvoice();
	CorrectiveInvoice(std::string type, std::string number, std::string numberOfCorrected, Date dateOfCorrected, std::string place, Date dateOfIssue, Date dateOfDelivery, PersonalData seller,
		PersonalData buyer, std::vector<Product> products, std::vector<Product> productsAC, double sumNetto, double sumVAT,
		double sumBrutto, std::string paymentMethod, std::string accountNumber, std::string bankName,
		Date dateOfPayment, std::string causeOfCorrection, std::string issuer);	
	double CalculateSumNettoAC(std::vector<Product>& products, std::vector<Product>& productsAC);
	double CalculateSumBruttoAC(std::vector<Product>& products, std::vector<Product>& productsAC);
	double CalculateSumVATAC(std::vector<Product>& products, std::vector<Product>& productsAC);
	void WriteInvoiceOnScreen();
	void WriteInvoiceToFile(std::ostream& file);
};


