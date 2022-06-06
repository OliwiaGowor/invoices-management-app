#include "Product.h"

Product::Product() :productName("nieznana"), choosenUnit("x"), quantity(0), priceNetto(0),
valueNetto(0), choosenVAT(0), amountVAT(0), valueBrutto(0)
{
}

Product::Product(std::string productName, std::string choosenUnit, int quantity, double priceNetto,
	double valueNetto, double choosenVAT, double amountVAT, double valueBrutto)
{
	this->productName = productName;
	this->choosenUnit = choosenUnit;
	this->quantity = quantity;
	this->priceNetto = priceNetto;
	this->valueNetto = valueNetto;
	this->choosenVAT = choosenVAT;
	this->amountVAT = amountVAT;
	this->valueBrutto = valueBrutto;
}

void Product::SetProductName(std::string productName)
{
	this->productName = productName;
}

std::string Product::GetProductName()
{
	return productName;
}

std::string Product::GetChoosenUnit()
{
	return choosenUnit;
}

int Product::GetQuantity()
{
	return quantity;
}

double Product::GetChoosenVAT()
{
	return choosenVAT;
}

double Product::GetPriceNetto()
{
	return priceNetto;
}

Product Product::ReadProductFromFile(std::string& line, std::string& productName)
{
	Product tmpproduct;
	tmpproduct.SetProductName(productName);

	std::stringstream ss(line);
	
	ss >> tmpproduct.choosenUnit >> tmpproduct.quantity >> tmpproduct.priceNetto >> tmpproduct.valueNetto
		>> tmpproduct.choosenVAT >> tmpproduct.amountVAT >> tmpproduct.valueBrutto;

	return tmpproduct;
}

double Product::CalculateValueNetto(double& priceNetto, int& quantity)
{
	valueNetto = priceNetto * quantity;
	return valueNetto;
}

double Product::GetValueNetto()
{
	return valueNetto;
}

double Product::CalculateAmountVAT(double& valueNetto, double& choosenVAT)
{
	amountVAT = valueNetto * (choosenVAT / 100);
	return amountVAT;
}

double Product::GetAmountVAT()
{
	return amountVAT;
}

double Product::CalculateValueBrutto(double& valueNetto, double& amountVAT)
{
	valueBrutto = valueNetto + amountVAT;
	return valueBrutto;
}

double Product::GetValueBrutto()
{
	return valueBrutto;
}

////////////////////////////////////////////////

void ProductManagement::AddNewProduct(std::vector<Product>& products, Unit& unit, VAT& vat)
{
	Product tmpproduct;
	std::string tmpproductName,
		tmpchoosenUnit;
	int	tmpquantity;
	double tmppriceNetto,
		tmpvalueNetto,
		tmpchoosenVAT,
		tmpamountVAT,
		tmpvalueBrutto;

	int choice = 1;

	while (choice)
	{
		if (choice == 1)
		{
			std::cout << "Podaj nazwe przedmiotu: ";
			std::getline(std::cin, tmpproductName);
			tmpchoosenUnit = unit.ChooseUnit();
			std::cout << "Podaj ilosc przedmiotow: ";
			tmpquantity = UserInteractionHelper::CheckIfInt();
			std::cout << "Podaj cene Netto przemiotu: ";
			tmppriceNetto = UserInteractionHelper::CheckIfDouble();
			tmpvalueNetto = tmpproduct.CalculateValueNetto(tmppriceNetto, tmpquantity);
			tmpchoosenVAT = vat.ChooseVAT();
			tmpamountVAT = tmpproduct.CalculateAmountVAT(tmpvalueNetto, tmpchoosenVAT);
			tmpvalueBrutto = tmpproduct.CalculateValueBrutto(tmpvalueNetto, tmpamountVAT);

			Product newProduct(tmpproductName, tmpchoosenUnit, tmpquantity, tmppriceNetto, tmpvalueNetto,
				tmpchoosenVAT, tmpamountVAT, tmpvalueBrutto);
			products.push_back(newProduct);

			std::cout << "Czy chcesz dodac kolejny produkt?" << std::endl;
			std::cout << "[1] tak | [2] nie" << std::endl;
			choice = UserInteractionHelper::CheckIfInt();
			std::cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
		}
		else if (choice == 2)
		{
			choice = 0;
		}
		else
		{
			std::cout << "Podaj poprawna liczbe!" << std::endl;
			choice = UserInteractionHelper::CheckIfInt();
		}
	}
}

std::ostream& operator<<(std::ostream& write, const Product& writeThis)
{
	write << writeThis.productName << std::endl << writeThis.choosenUnit << ' ' << writeThis.quantity << ' '
		<< writeThis.priceNetto << ' ' << writeThis.valueNetto <<  ' ' <<
		writeThis.choosenVAT <<  ' ' << writeThis.amountVAT <<  ' ' << writeThis.valueBrutto << std::endl;
	return write;
}

