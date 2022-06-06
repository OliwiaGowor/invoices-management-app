#include "Date.h"

Date::Date(): day(1), month(1), year(2000)
{
}

Date::Date(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

int Date::GetDay()
{
	return day;
}

int Date::GetMonth()
{
	return month;
}

int Date::GetYear()
{
	return year;
}

Date Date::ReadDateFromFile(std::string & line)
{
	Date tmpdate;
	std::stringstream ss(line);
	ss >> tmpdate.day >> tmpdate.month >> tmpdate.year;
	return tmpdate;
}

Date& Date::operator=(const Date& copyFromThis)
{
	if (this == &copyFromThis)
	{
		return *this;
	}
	this->day = copyFromThis.day;
	this->month = copyFromThis.month;
	this->year = copyFromThis.year;
	return *this;
}

std::ostream& operator<<(std::ostream& write, const Date& printThis)
{
	write << printThis.day << ' ' << printThis.month << ' ' << printThis.year << std::endl;
	return write;
}

