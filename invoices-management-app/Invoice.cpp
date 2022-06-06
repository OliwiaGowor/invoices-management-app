#include "Invoice.h"

Invoice::Invoice() : number("nieznany"), place("nieznane"), dateOfIssue(), seller(), buyer(), products(), sumNetto(0),
sumVAT(0), sumBrutto(0), paymentMethod("nieznana"), accountNumber("nieznany"), bankName("nieznana"), dateOfPayment(), issuer("nieznana")
{
}

Invoice::Invoice(std::string type, std::string number, std::string place, Date dateOfIssue, Date dateOfDelivery, PersonalData seller,
	PersonalData buyer, std::vector<Product> products, double sumNetto, double sumVAT,
	double sumBrutto, std::string paymentMethod, std::string accountNumber, std::string bankName,
	Date dateOfPayment, std::string issuer)
{
	this->type = "faktura VAT";
	this->number = number;
	this->place = place;
	this->dateOfIssue = dateOfIssue;
	this->dateOfDelivery = dateOfDelivery;
	this->seller = seller;
	this->buyer = buyer;
	this->products = products;
	this->sumNetto = sumNetto;
	this->sumVAT = sumVAT;
	this->sumBrutto = sumBrutto;
	this->paymentMethod = paymentMethod;
	this->accountNumber = accountNumber;
	this->bankName = bankName;
	this->dateOfPayment = dateOfPayment;
	this->issuer = issuer;
}

std::string Invoice::GetType()
{
	return type;
}

std::string Invoice::GetNumber()
{
	return number;
}

std::string Invoice::GetPlace()
{
	return place;
}

std::string Invoice::GetIssuer()
{
	return issuer;
}

PersonalData Invoice::SetSeller()
{
	std::string name,
		address,
		NIP;

	std::cout << "Podaj imie i nazwisko/ nazwe sprzedawcy: ";
	std::cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
	std::getline(std::cin, name);
	std::cout << "Podaj adres sprzedawcy: ";
	std::getline(std::cin, address);
	std::cout << "Podaj NIP/PESEL sprzedawcy: ";
	std::getline(std::cin, NIP);

	PersonalData newseller(name, address, NIP);
	return newseller;
}

PersonalData Invoice::SetBuyer()
{
	std::string name,
		address,
		NIP;

	std::cout << "Podaj imie i nazwisko/ nazwe kupujacego: ";
	std::getline(std::cin, name);
	std::cout << "Podaj adres kupujacego: ";
	std::getline(std::cin, address);
	std::cout << "Podaj NIP/PESEL kupujacego: ";
	std::getline(std::cin, NIP);

	PersonalData newbuyer(name, address, NIP);
	return newbuyer;
}

PersonalData Invoice::GetBuyer()
{
	return buyer;
}

Date Invoice::SetDate()
{
	int day,
		month,
		year;

	std::cin >> day >> month >> year;
	while (!std::cin)
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
		std::cout << "Nieprawidlowy format!" << std::endl;
		std::cin >> day >> month >> year;
	}
	Date date(day, month, year);
	return date;
}

Date Invoice::GetDateOfIssue()
{
	return dateOfIssue;
}

Date Invoice::GetDateOfDelivery()
{
	return dateOfDelivery;
}

std::vector<Product> Invoice::GetProducts()
{
	return products;
}

double Invoice::CalculateSumNetto(std::vector<Product>& products)
{
	for (int i = 0; i < products.size(); i++)
	{
		sumNetto += products[i].GetValueNetto();
	}
	return sumNetto;
}

double Invoice::CalculateSumVAT(std::vector<Product>& products)
{
	for (int i = 0; i < products.size(); i++)
	{
		sumVAT += products[i].GetAmountVAT();
	}
	return sumVAT;
}

double Invoice::CalculateSumBrutto(std::vector<Product>& products)
{
	for (int i = 0; i < products.size(); i++)
	{
		sumBrutto += products[i].GetValueBrutto();
	}
	return sumBrutto;
}

void Invoice::WriteInvoiceOnScreen()
{
	std::cout << type << ' ' << "nr" << ' ' << number << std::endl;
	std::cout << "Miejsce i data wystawienia faktury: " << place << ", " << dateOfIssue.GetDay() << '.'
		<< dateOfIssue.GetMonth() << '.' << dateOfIssue.GetMonth() << std::endl;
	std::cout << "Data dostarczenia towaru/ wykonania uslugi: " << dateOfDelivery.GetDay() << '.'
		<< dateOfDelivery.GetMonth() << '.' << dateOfDelivery.GetMonth() << std::endl;
	std::cout << "Sprzedawca: " << seller.GetName() << " | " << seller.GetAddress() << " | " << "NIP/PESEL: "
		<< seller.GetNIP() << std::endl;
	std::cout << "Nabywca: " << buyer.GetName() << " | " << buyer.GetAddress() << " | " << "NIP/PESEL: "
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
	std::cout << "Razem: Netto: " << sumNetto << " | " << "VAT: " << sumVAT << " | " << "Brutto: " << sumBrutto << std::endl;
	std::cout << "Forma platnosci: " << paymentMethod << std::endl;
	std::cout << "Numer konta: " << accountNumber << std::endl;
	std::cout << "Nazwa banku: " << bankName << std::endl;
	std::cout << "Data platnosci: " << dateOfPayment.GetDay() << '.' << dateOfPayment.GetMonth() << '.'
		<< dateOfPayment.GetYear() << std::endl;
	std::cout << "Osoba upowazniona do wystawienia faktury: " << issuer << std::endl << std::endl;
}

void Invoice::WriteInvoiceToFile(std::ostream& file)
{
	file << type << std::endl << number << ' ' << place << std::endl<< dateOfIssue << dateOfDelivery << seller << buyer;
	for (int i = 0; i < products.size(); i++)
	{
		file << products[i];
	}
	file << "end" << std::endl << sumNetto << ' ' << sumVAT << ' ' << sumBrutto << ' ' << paymentMethod << ' ' << accountNumber 
		<< std::endl << bankName << std::endl << issuer << std::endl << dateOfPayment;
}