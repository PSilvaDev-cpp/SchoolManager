#pragma once

#include "Calendar.hpp"
#include <string>
#include "Address.hpp"
#include <vector>
#include "Person.hpp"
#include "Department.hpp"
#include "Role.hpp"
#include "Employee.hpp"
#include "Student.hpp"
#include "Course.hpp"
#include <iostream>

class Institute
{
public:

	std::vector<std::string> departmentNames;

	Institute()
	{
	
	}

	std::string name;

	Address adress;

	std::vector<Department*> departments;

	std::vector<Employee*> employees;

	std::vector<Student*> students;

	std::vector<Course*> courses;

	std::string GetName() const { return name; }

	void CreateDepartment(std::string departmentName, std::string departmentDescription);
	void RegisterDepartment(Department* newDepartment);
	void GetDepartments() const { for (Department* dpts : departments) { std::cout << dpts->name << std::endl; } };

	void RegisterEmployee(std::string newName, std::string newCPF);
	std::vector<Employee*> GetEmployees() const { return employees; };

	void RegisterStudent(Student* newStudent);
	std::vector<Student*> GetStudents() const { return students; }

	void RegisterCourse(Course* newCourse)
	{
		if(std::find(courses.begin(), courses.end(), newCourse) == courses.end())
		{
			courses.push_back(newCourse);
		}
		else { std::cout << "Course already registered." << std::endl; }
	}
	std::vector<Course*> GetCourses() const { return courses; };

};