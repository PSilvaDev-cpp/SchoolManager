#pragma once

#include "Person.hpp"
#include <vector>
#include "Course.hpp"
#include "Calendar.hpp"

enum class RegisterState
{
	Registered,
	Unregistered,
	Banned
};

enum class EStudentFeeState
{
	Paid_off,
	In_Dept
};

struct CourseMonthlyFee
{
	Course course;
	std::string feeState;
};

class Student : public Person
{

	std::vector<std::string> registerStates = { "Registered", "Unregistered", "Banned" };
	std::vector<std::string> feeStates = { "Paid off", "In Dept" };

	Student()
	{

	}

	Person accountable;

	RegisterState registerState;

	std::vector<Course> registeredCourses;

	std::map<std::string,CourseMonthlyFee> conthlyFees;

	std::map<Course, std::string> courseStates;


	void SetAccountable(Person newAccountable) { accountable = newAccountable; }
	Person GetAccountable() const { return accountable; }

	void SetRegisterState(RegisterState newRegisterState) { registerState = newRegisterState; }
	RegisterState GetRegisterState() const { return registerState; }

	void AddCourse(Course newCourse);
	std::vector<Course> GetRegisteredCourses() const { return registeredCourses; };

	void AddMonthlyFee(std::string month, CourseMonthlyFee newMonthlyFee);
	std::map<std::string, CourseMonthlyFee> GetMonthlyFees() const { return conthlyFees; };

	void SetCourseState(Course targetCourse, std::string newState);
	std::map<Course, std::string> GetCourseStates() const { return courseStates; };




};