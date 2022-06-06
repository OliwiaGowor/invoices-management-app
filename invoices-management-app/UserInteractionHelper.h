#pragma once
#include <iostream>
#include <sstream>

class UserInteractionHelper
{

public:
	static int CheckIfInt();
	static double CheckIfDouble();
	static std::string CheckIfCorrectString();
};
