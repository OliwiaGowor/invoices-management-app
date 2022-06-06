#pragma once
#include <iostream>
#include<sstream>

class PersonalData
{
	std::string name,
				address,
				NIP;
public:
	PersonalData();
	PersonalData(std::string name, std::string address, std::string NIP);
	void SetName(std::string name);
	std::string GetName();
	void SetAddress(std::string address);
	std::string GetAddress();
	void SetNIP(std::string NIP);
	std::string GetNIP();
	PersonalData ReadPersonalDataFromFile(std::string& line);
	friend std::ostream& operator<<(std::ostream& write, const PersonalData& writeThis);
};

