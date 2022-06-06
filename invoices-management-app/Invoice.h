#pragma once
#include <iostream>
#include<string>
#include <vector>
#include<memory>
#include<fstream>
#include <sstream>
#include "Date.h"
#include "Product.h"
#include "PersonalData.h"

class Invoice
{
protected:
	std::string type,
				number,
				place,
				paymentMethod,
				accountNumber,
				bankName,
				issuer;
	PersonalData seller,
				 buyer;
	Date dateOfIssue,
		dateOfDelivery,
		dateOfPayment;
	double sumNetto,
			sumVAT,
			sumBrutto;
	std::vector<Product> products;
	
public:
	Invoice();
	Invoice(std::string type, std::string number, std::string place, Date dateOfIssue, Date dateOfDelivery, PersonalData seller,
		PersonalData buyer, std::vector<Product> products, double sumNetto, double sumVAT,
		double sumBrutto, std::string paymentMethod, std::string accountNumber, std::string bankName,
		Date dateOfPayment ,std::string issuer);

	std::string GetType();
	std::string GetNumber();
	std::string GetPlace();
	std::string GetIssuer();
	PersonalData SetSeller();
	PersonalData SetBuyer();
	PersonalData GetBuyer();
	Date SetDate();
	Date GetDateOfIssue();
	Date GetDateOfDelivery();
	std::vector<Product> GetProducts();

	double CalculateSumNetto(std::vector<Product>& products);
	double CalculateSumVAT(std::vector<Product>& products);
	double CalculateSumBrutto(std::vector<Product>& products);

	virtual void WriteInvoiceOnScreen();
	virtual void WriteInvoiceToFile(std::ostream& file);
};