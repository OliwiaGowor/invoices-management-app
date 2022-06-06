#pragma once
#include "VAT.h"
#include "Unit.h"
#include "ListOfInvoices.h"
#include "FileManagement.h"
#include "SearchingInvoice.h"

class Menu
{
	int choice;
	ListOfInvoices list;
	VAT vat;
	Unit unit;
	FileManagement mainArgs;
	SearchingInvoice search;

public:
	Menu(FileManagement& args);
	void RunProgram();
	void MainMenu();
	void MenuAddInvoice();
	void MenuSearch();
	void MenuVATmanagement();
	void MenuUnitManagement();
};