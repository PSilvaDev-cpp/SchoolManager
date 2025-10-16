#pragma once

#include <stdlib.h>
#include <cstdio>
#include <iostream>
#include "Institute.hpp"
#include "main.hpp"

int main()
{
	std::vector<std::string> registeredInstitutes;
	std::vector<Institute*> institutes;
	Institute* selectedInstitute;
	
	void Intro();
	{
		std::cout << "Welcome to School Manager 01!" << std::endl;
		std::cout << "This is a simple school management system." << std::endl;		
	}

	std::cout << "Type Institute name, or 'Exit' to exit the program" << std::endl;
	std::string instituteName;
	std::cin >> instituteName;

	if(instituteName == "Exit")
	{
		std::cout << "Exiting..." << std::endl;
		return 0;
	}

	if (VerifyInstitute(instituteName, registeredInstitutes))
	{
		std::cout << "Institute " << instituteName << " Selected" << std::endl;
		selectedInstitute = institutes[std::distance(registeredInstitutes.begin(), std::find(registeredInstitutes.begin(), registeredInstitutes.end(), instituteName))];
	}
	else
	{
		std::cout << "Institute " << instituteName << " Not Found, Register new Institute ? (Y/N)" << std::endl;
		char answer;
		std::cin >> answer;
		switch (answer)
		{
			case 'N':
				break;
			case 'Y': RegisterInstitute(instituteName, registeredInstitutes, institutes, selectedInstitute);
				break;
		}
	}

	std::string actualCommand;
	
	while (&selectedInstitute != nullptr && actualCommand != "Exit")
	{
		std::cout << "Type Command: ";
		std::cin >> actualCommand;

		if(actualCommand == "Exit")
		{
			std::cout << "Exiting..." << std::endl;
			break;
		}

		if (actualCommand == "Register")
		{
			std::cout << "Register '...' " << std::endl;
			std::cin >> actualCommand;

			if (actualCommand == "Department")
			{	
				std::string departmentName;
				std::cout << "Type department name: ";
				std::cin >> departmentName;
				std::string departmentDescription;
				std::cout << "Type department description: ";
				std::cin >> departmentDescription;
				selectedInstitute->CreateDepartment(departmentName, departmentDescription);
			}
		}
		else if (actualCommand == "Show")
		{
			std::cout << "Show '...'" << std::endl;

			std::cin >> actualCommand;
			if(actualCommand == "Departments")
			{
				selectedInstitute->GetDepartments();
			}
		}
	}
	return 0;
}
