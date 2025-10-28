#include "Student.hpp"
#include <algorithm>
#include <iostream>
#include <string>
#include "Institute.hpp"
#include "Calendar.hpp"


void Student::RegisterAccountable(std::string personName, std::string personCPF)
{
	if(accountable != nullptr)
	{
		std::cout << " Accountable Person already registered: " << accountable->GetName() << " CPF: " << accountable->GetCPF() << std::endl;
		std::cout << " Replace Accountable Person ? Y/N " << std::endl;
		char answer;
		std::cin >> answer;
		switch (answer)
		{
			case 'N':
				std::cout << " Accountable Person Registration Aborted " << std::endl;
				return;
				break;
			case 'Y':
				accountable->SetName(personName);
				accountable->SetCPF(personCPF);
				std::cout << " Enter Accountable Person Adress Street: " << std::endl;
				std::string personStreet;
				std::cin >> personStreet;
				std::cout << " Enter Accountable Person Adress District: " << std::endl;
				std::string personDistrict;
				std::cin >> personDistrict;
				std::cout << " Enter Accountable Person Adress Number: " << std::endl;
				int personNumber;
				std::cin >> personNumber;
				accountable->SetAdress(personStreet, personDistrict, personNumber);
		}
		return;
	}

	Person* newAccountable = new Person();
	accountable = newAccountable;
	accountable->SetName(personName);
	accountable->SetCPF(personCPF);
	std::cout << " Enter Accountable Person Adress Street: " << std::endl;
	std::string personStreet;
	std::cin >> personStreet;
	std::cout << " Enter Accountable Person Adress District: " << std::endl;
	std::string personDistrict;
	std::cin >> personDistrict;
	std::cout << " Enter Accountable Person Adress Number: " << std::endl;
	int personNumber;
	std::cin >> personNumber;
	accountable->SetAdress(personStreet, personDistrict, personNumber);
}

bool Student::CheckIfCourseRegister(std::string course)
{
	for(Course* crs : registeredCourses)
	{
		if(crs->GetName() == course)
		{
			return true;
		}
		return false;
	}
}

bool Student::CheckIfValidFeeState(std::string feeState)
{
	for(std::string validState : feeStates)
	{
		if(validState == feeState)
		{
			return true;
		}
	}
}

void Student::AddCourse(Institute* institute, std::string newCourse)
{
	for(Course* crs : institute->courses)
	{
		if(crs->GetName() == newCourse)
		{
			registeredCourses.push_back(crs);
			courseStates[crs] = "In Progress";
			std::cout << " Course: " << newCourse << " added to Student: " << GetName() << std::endl;
			return;
		}
	}	
}
void Student::AddMonthlyFee(std::string month, std::string courseName, std::string feeeState)
{
	if (!Calendar().CheckMonth(month) || !CheckIfCourseRegister(courseName))
	{
		std::cout << " Invalid Month or Course not registered for Student: " << GetName() << std::endl;
		std::cout << " Monthly Fee Registration Aborted " << std::endl;
		return;
	}
		CourseMonthlyFee.insert({ courseName, feeeState }).first->second;
		monthlyFees[month] = CourseMonthlyFee;
}
void Student::GetMonthlyFees() const
{
	for (const auto& monthEntry : monthlyFees)
	{
		std::cout << "Month: " << monthEntry.first << std::endl;
		for (const auto& courseEntry : monthEntry.second)
		{
			std::cout << "  Course: " << courseEntry.first << " - Fee State: " << courseEntry.second << std::endl;
		}
	}
}

bool Student::CheckIfHasDepts() const
{
	for (const auto& monthEntry : monthlyFees)
	{
		for (const auto& courseEntry : monthEntry.second)
		{
			if (courseEntry.second == "In Dept")
			{
				return true;
			}
		}
	}
	return false;
}