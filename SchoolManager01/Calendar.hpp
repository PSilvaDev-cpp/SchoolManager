#pragma once

#include <map>
#include <vector>
#include <string>
#include <array>


class Calendar
{

public:

	std::string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	
	std::map<std::string, int> monthDays = {
		{"January", 31},
		{"February", 28}, // 29 in leap years
		{"March", 31},
		{"April", 30},
		{"May", 31},
		{"June", 30},
		{"July", 31},
		{"August", 31},
		{"September", 30},
		{"October", 31},
		{"November", 30},
		{"December", 31}
	};

	std::string daysOfWeek[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

	bool CheckMonth(std::string month)
	{
		for (std::string validMonth : months)
		{
			if (validMonth == month)
			{
				return true;
			}
			return false;
		}
	}

};



