#include "PersonalData.h"

PersonalData::PersonalData(): name("nieznane"), address("nieznany"), NIP("nieznany")
{
}

PersonalData::PersonalData(std::string name, std::string address, std::string NIP)
{
    this->name = name;
    this->address = address;
    this->NIP = NIP;
}

void PersonalData::SetName(std::string name)
{
    this->name = name;
}

std::string PersonalData::GetName()
{
    return name;
}

void PersonalData::SetAddress(std::string address)
{
    this->address = address;
}

std::string PersonalData::GetAddress()
{
    return address;
}

void PersonalData::SetNIP(std::string NIP)
{
    this->NIP = NIP;
}

std::string PersonalData::GetNIP()
{
    return NIP;
}

PersonalData PersonalData::ReadPersonalDataFromFile(std::string& line)
{
    PersonalData tmppersonaldata;
    std::stringstream ss(line);
    std::string tmp;
    std::string space = " ";

    ss >> tmp >> tmp >> tmppersonaldata.address >> tmp >> tmppersonaldata.NIP;
    return tmppersonaldata;
}

std::ostream& operator<<(std::ostream& write, const PersonalData& writeThis)
{
    write << writeThis.name << std::endl << writeThis.address << std::endl << writeThis.NIP << std::endl;
    return write;
}