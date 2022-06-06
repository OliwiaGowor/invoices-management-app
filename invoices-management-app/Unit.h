#pragma once
#include<iostream>
#include<string>
#include<vector>

class Unit
{
	std::string unitType,
				choosenUnit;
	std::vector<std::string> unitTypes;

public:
	Unit();
	std::vector<std::string> GetUnitTypes();
	std::vector<std::string>* GetAddressUnitTypes();
	void AddUnit();
	void DeleteUnit();
	std::string ChooseUnit();
	void WriteUnits();
};
