#pragma once

#include <string>
#include <vector>
#include "Student.hpp"
#include "Calendar.hpp"
#include <map>

class Student;
class Institute;

class Course
{
public:

	std::vector<std::string> courseCategorys = { "Graduation", "Post Graduate", "MBA", "Doctorate", "Masters Degree" };

	std::vector<std::string> courseNames = { "Portuguese", "Math", "History", "Geography", "Science", "Physics", "Engineering", "Software Engineering", "Mechanic Engineering", "Physical Education", "Medicine" };

	std::vector<std::string> courseStates = { "On Going", "Completed", "Locked", "Cancelled" };

	std::vector<std::string> courseFeeStates = { "Paid", "Unpaid", "Partialy Paid", "Overdue" };

	Course()
	{

	}

	std::string name;
	bool operator==(const Course& other) const
	{
		return name == other.name;
	}

	std::string category;
	std::string state;
	std::string description;
	std::string feeState;

	std::vector<std::string> registeredStudents;
	std::vector<Student*> students;

	int registeredStudentsAmount = 0;

	long long monthlyFee = 0;

	int durationInMonths = 0;

	std::vector<float> semesterGrades;

	float averageGrade = 0;

	std::map<int, float> SemesterGrades;



	void SetName(std::string courseName) { courseName = courseName; }
	std::string GetName() const { return name; }

	void SetDescription(std::string newDescription) { description = newDescription; }
	std::string GetDescription() const { return description; }

	void SetCategory(std::string courseCategory) { courseCategory = courseCategory; }
	std::string GetCategory() const { return category; }

	void RegisterNewStudent(Institute* institute, std::string studentName, std::string studentCPF);
	std::vector<std::string> GetRegisteredStudents() const { return registeredStudents; }

	int GetRegisteredStudentsAmount() { if (registeredStudents.empty()) { return NULL; } return registeredStudents.size(); }

	void SetMonthlyFee(long long newMonthlyFee) { monthlyFee = newMonthlyFee; }
	long long GetMonthlyFee() const { return monthlyFee; }

	void SetGrade(float NewGrade) { averageGrade = NewGrade; }
	float GetGrade() const { return averageGrade; }

};