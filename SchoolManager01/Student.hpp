#pragma once

#include "Person.hpp"
#include <vector>
#include "Course.hpp"
#include "Calendar.hpp"
#include "Address.hpp"


class Institute;



class Student : public Person
{

public:

	Student()
	{

	}

	std::map<std::string, std::string> CourseMonthlyFee;
	std::string registerStates[2] = { "Registered", "Banned" };
	std::string feeStates[2] = { "Paid off", "In Dept" };

	Person* accountable;

	std::string registerState;

	std::vector<Course*> registeredCourses;

	std::map<std::string,std::map<std::string, std::string>> monthlyFees;

	std::map<Course*, std::string> courseStates;


	void RegisterAccountable(std::string personName, std::string personCPF);
	Person* GetAccountable() const { return accountable; }

	void SetRegisterState(std::string newRegisterState)
	{
		if(registerStates->find(newRegisterState))
		{ 
			registerState = newRegisterState; 
			return;
		}
		std::cout << newRegisterState << "Is not a valid register state." << std::endl;
	}
	std::string GetRegisterState() const { return registerState; }

	void AddCourse(Institute* institute, std::string newCourse);
	std::vector<Course*> GetRegisteredCourses() const { return registeredCourses; };

	void AddMonthlyFee(std::string month, std::string courseName, std::string feeeState);
	void GetMonthlyFees() const;
	bool CheckIfHasDepts() const;

	void SetCourseState(Course targetCourse, std::string newState);
	std::map<Course*, std::string> GetCourseStates() const { return courseStates; };

	bool CheckIfCourseRegister(std::string course);
	bool CheckIfValidFeeState(std::string feeState);


};