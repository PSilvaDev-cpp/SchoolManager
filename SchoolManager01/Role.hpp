#pragma once

#include <string>
#include <vector>


struct  Role
{
	std::vector<std::string> roles = { "President", "Manager", "Teacher", "Inspector", "Cleaner", "IT Technician", "Security", "Trainee" };

	std::string name;
	std::string description = "";

	long long BaseSalary = 0;

	void SetName(std::string Name) { name = Name; }
	std::string GetName() { return name; }

	void SetDescription(std::string Description) { description = Description; }
	std::string GetDescription() { return description; }

};