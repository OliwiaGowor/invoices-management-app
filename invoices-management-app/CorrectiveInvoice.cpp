#include "CorrectiveInvoice.h"

CorrectiveInvoice::CorrectiveInvoice(): numberOfCorrected("nieznane"), dateOfCorrected(), productsAC(), 
causeOfCorrection("nieznana"), Invoice()
{
}

CorrectiveInvoice::CorrectiveInvoice(std::string type, std::string number, std::string numberOfCorrected, Date dateOfCorrected, std::string place, Date dateOfIssue,
	Date dateOfDelivery, PersonalData seller, PersonalData buyer, std::vector<Product> products, 
	std::vector<Product> productsAC, double sumNetto,
	double sumVAT, double sumBrutto, std::string paymentMethod, std::string accountNumber, std::string bankName, Date dateOfPayment, std::string causeOfCorrection,
	std::string issuer) : Invoice(type, number, place, dateOfIssue, dateOfDelivery, seller, buyer, products, sumNetto, sumVAT,
	sumBrutto, paymentMethod, accountNumber, bankName, dateOfPayment, issuer)
{
	this->type = "faktura korygujaca";
	this->number = number;
	this->numberOfCorrected = numberOfCorrected;
	this->dateOfCorrected = dateOfCorrected;
	this->place = place;
	this->dateOfIssue = dateOfIssue;
	this->dateOfDelivery = dateOfDelivery;
	this->seller = seller;
	this->buyer = buyer;
	this->products = products;
	this->productsAC = productsAC;
	this->sumNetto = sumNetto;
	this->sumVAT = sumVAT;
	this->sumBrutto = sumBrutto;
	this->paymentMethod = paymentMethod;
	this->accountNumber = accountNumber;
	this->bankName = bankName;
	this->dateOfPayment = dateOfPayment;
	this->causeOfCorrection = causeOfCorrection;
	this->issuer = issuer;
}

double CorrectiveInvoice::CalculateSumNettoAC(std::vector<Product>& products, std::vector<Product>& productsAC)
{
	for (int i = 0; i < products.size(); i++)
	{
		sumNetto += products[i].GetValueNetto();
	}
	for (int i = 0; i < products.size(); i++)
	{
		sumNetto += productsAC[i].GetValueNetto();
	}
	return sumNetto;
}

double CorrectiveInvoice::CalculateSumBruttoAC(std::vector<Product>& products, std::vector<Product>& productsAC)
{
	for (int i = 0; i < products.size(); i++)
	{
		sumBrutto += products[i].GetValueBrutto();
	}
	for (int i = 0; i < products.size(); i++)
	{
		sumBrutto += productsAC[i].GetValueBrutto();
	}
	return sumBrutto;
}

double CorrectiveInvoice::CalculateSumVATAC(std::vector<Product>& products, std::vector<Product>& productsAC)
{
	for (int i = 0; i < products.size(); i++)
	{
		sumVAT += products[i].GetAmountVAT();
	}
	for (int i = 0; i < products.size(); i++)
	{
		sumVAT += productsAC[i].GetAmountVAT();
	}
	return sumVAT;
}

void CorrectiveInvoice::WriteInvoiceOnScreen()
{
	std::cout << type << ' ' << "nr" << ' ' << number << std::endl;
	std::cout << "Numer korygowanej faktury: " << numberOfCorrected << std::endl;
	std::cout << "Data wystawienia faktury korygujacej: " << dateOfIssue.GetDay() << '.'
		<< dateOfIssue.GetMonth() << '.' << dateOfIssue.GetMonth() << std::endl;
	std::cout << "Miejsce i data wystawienia faktury: " << place << ", " << dateOfCorrected.GetDay() << '.'
		<< dateOfCorrected.GetMonth() << '.' << dateOfCorrected.GetMonth() << std::endl;
	std::cout << "Data dostarczenia towaru/ wykonania uslugi: " << dateOfDelivery.GetDay() << '.'
		<< dateOfDelivery.GetMonth() << '.' << dateOfDelivery.GetMonth() << std::endl;
	std::cout << "Sprzedawca: " << seller.GetName() << " | " << seller.GetAddress() << " | " << "NIP: "
		<< seller.GetNIP() << std::endl;
	std::cout << "Nabywca: " << buyer.GetName() << " | " << buyer.GetAddress() << " | " << "NIP: "
		<< buyer.GetNIP() << std::endl;
	std::cout << "Produkty: " << std::endl;
	for (int i = 0; i < products.size(); i++)
	{
		std::cout << i + 1 << ". " << products[i].GetProductName() << " | " << "jednostka: "
			<< products[i].GetChoosenUnit() << " | " << "ilosc: " << products[i].GetQuantity() << std::endl;
		std::cout << "cena Netto: " << products[i].GetPriceNetto() << " | " << "wartosc Netto: "
			<< products[i].GetValueNetto() << " | " << "stawka VAT: " << products[i].GetChoosenVAT() << " | "
			<< "kwota VAT: " << products[i].GetAmountVAT() << " | " << "wartosc Brutto: " << products[i].GetValueBrutto() << std::endl;
	}
	std::cout << "Produkty po korekcie: " << std::endl;
	for (int i = 0; i < productsAC.size(); i++)
	{
		std::cout << i + 1 << ". " << productsAC[i].GetProductName() << " | " << "jednostka: "
			<< productsAC[i].GetChoosenUnit() << " | " << "ilosc: " << productsAC[i].GetQuantity() << std::endl;
		std::cout << "cena Netto: " << products[i].GetPriceNetto() << " | " << "wartosc Netto: "
			<< productsAC[i].GetValueNetto() << " | " << "stawka VAT: " << productsAC[i].GetChoosenVAT() << " | "
			<< "kwota VAT: " << productsAC[i].GetAmountVAT() << " | " << "wartosc Brutto: " << productsAC[i].GetValueBrutto() << std::endl;
	}
	std::cout << "Razem: Netto: " << sumNetto << " | " << "VAT: " << sumVAT << " | " << "Brutto: " << sumBrutto << std::endl;
	std::cout << "Forma platnosci: " << paymentMethod << std::endl;
	std::cout << "Numer konta: " << accountNumber << std::endl;
	std::cout << "Nazwa banku: " << bankName << std::endl;
	std::cout << "Data platnosci: " << dateOfPayment.GetDay() << '.' << dateOfPayment.GetMonth() << '.'
		<< dateOfPayment.GetYear() << std::endl;
	std::cout << "Powod korekty: " << causeOfCorrection << std::endl;
	std::cout << "Osoba upowazniona do wystawienia faktury: " << issuer << std::endl << std::endl;
}

void CorrectiveInvoice::WriteInvoiceToFile(std::ostream& file)
{
	file << type << std::endl << number << ' ' << numberOfCorrected << ' ' << place << std::endl << dateOfCorrected 
		<< dateOfIssue << dateOfDelivery << seller << buyer;
	for (int i = 0; i < products.size(); i++)
	{
		file << products[i];

	}
	file << "end" << std::endl;
	for (int i = 0; i < productsAC.size(); i++)
	{
		file << productsAC[i];

	}
	file << "end" << std::endl << sumNetto << ' ' << sumVAT << ' ' << sumBrutto << ' ' << paymentMethod << ' ' << accountNumber 
		<< std::endl << bankName << std::endl << causeOfCorrection << std::endl << issuer << std::endl << dateOfPayment;
}
