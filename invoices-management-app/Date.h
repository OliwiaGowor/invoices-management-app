#pragma once
#include<iostream>
#include<sstream>

class Date
{
	int day,
		month,
		year;
public:
	Date();
	Date(int day, int month, int year);
	int GetDay();
	int GetMonth();
	int GetYear();
	Date ReadDateFromFile(std::string& line);
	friend std::ostream& operator<<(std::ostream& print, const Date& printThis);
	Date& operator=(const Date& copyFromThis);
};
