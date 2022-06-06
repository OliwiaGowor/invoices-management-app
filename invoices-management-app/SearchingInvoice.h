#pragma once
#include "ListOfInvoices.h"
class SearchingInvoice
{
public:
	void SearchInvoiceByNumber(std::shared_ptr<ListOfInvoicesElement> list);
	void SearchInvoiceByBuyerName(std::shared_ptr<ListOfInvoicesElement> list);
	void SearchInvoiceByBuyerNIP(std::shared_ptr<ListOfInvoicesElement> list);
	void SearchInvoiceByDateOfIssue(std::shared_ptr<ListOfInvoicesElement> list);
};

