#pragma once
#include <iostream>
#include "VAT.h"
#include "Unit.h"
#include "ListOfInvoices.h"

class FileManagement
{
	std::string fileNameVAT,
				fileNameUnit,
				fileNameInvoices;

public:
	FileManagement();
	FileManagement(std::string fileNameVAT, std::string fileNameUnit, std::string fileNameInvoices);
	void LoadInvoices(ListOfInvoices& list);
	void SaveInvoices(std::shared_ptr<ListOfInvoicesElement> list);
	void SaveVATrates(VAT& vat);
	void LoadVATrates(VAT& vat);
	void SaveUnitTypes(Unit& unit);
	void LoadUnitTypes(Unit& unit);
	
};
