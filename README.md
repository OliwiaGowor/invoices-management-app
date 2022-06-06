# Invoices Management App
## Table of contents
* [App description](#app-description)
* [Additional files](#additional-files)
* [Used elements](#used-elements)

## App description	
  The Invoices Management app is console based program, which consists of following functions:

* displaying all saved invoices;

* adding a new invoice, distinguishing between a VAT invoice and a correcting invoice;

* correcting the selected, existing invoice;

* deletion of a selected invoice (by providing the number of the invoice);

* searching for the desired invoice by various criteria:
	-invoice number,
	
	-name / surname of the buyer,
	
	-date of invoice,
	
	-NIP / PESEL number of the buyer;

* management of VAT rates - overview of available VAT rates, adding, deleting;

* management of sales units - review of available units, adding, deleting;

* returning to the previous stages of the menu.

  Navigating the menu and making selections is done by entering the number of the selected option available in the program menu.
  
  
## Additional files
  All of the data is stored as text files. There are three configuration files: a file containing data on VAT rates, a file containing data on sales units and a file containing saved invoices.


## Used elements
  The program is based on Object-Oriented Programming. It uses class inheritance mechanism. Smart pointers were also used in the program to implement singly linked list, which contains invoices.
