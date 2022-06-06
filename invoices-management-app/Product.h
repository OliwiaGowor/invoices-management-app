#pragma once
#include <string>
#include<sstream>
#include "VAT.h"
#include "Unit.h"
#include"UserInteractionHelper.h"
class Product
{
	std::string productName,
				choosenUnit;
	int	quantity;
	double priceNetto,
			valueNetto,
			choosenVAT,
			amountVAT,
			valueBrutto;

public:
	Product();
	Product(std::string productName, std::string choosenUnit, int quantity, double priceNetto,
		double valueNetto, double choosenVAT, double amountVAT, double valueBrutto);
	void SetProductName(std::string productName);
	std::string GetProductName();
	std::string GetChoosenUnit();
	int GetQuantity();
	double GetChoosenVAT();
	double GetPriceNetto();
	Product ReadProductFromFile(std::string& line, std::string& productName);
	double CalculateValueNetto(double& priceNetto, int& quantity);
	double GetValueNetto();
	double CalculateAmountVAT(double& valueNetto, double& choosenVAT);
	double GetAmountVAT();
	double CalculateValueBrutto(double& valueNetto, double& amountVAT);
	double GetValueBrutto();
	friend std::ostream& operator<<(std::ostream& write, const Product& writeThis);
};


class ProductManagement
{
public:
	void AddNewProduct(std::vector<Product>& products, Unit& unit, VAT& vat);
};

