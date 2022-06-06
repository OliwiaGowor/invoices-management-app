#pragma once
#include<vector>
#include<iostream>
#include<fstream>
#include<string>

class VAT
{
	int VATrate,
		choosenVAT;
	std::vector<int> VATrates;
	
public:
	VAT();
	std::vector<int> GetVATrates();	
	std::vector<int>* GetAddressVATrates();
	void AddVat();
	void DeleteVAT();
	int ChooseVAT();
	void WriteVAT();
};
