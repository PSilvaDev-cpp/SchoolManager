#pragma once

#include <stdlib.h>
#include <cstdio>
#include <iostream>
#include "Institute.hpp"
#include "main.hpp"

std::vector<std::string> registeredInstitutes;
std::vector<Institute*> institutes;

std::string actualCommand;
Institute* selectedInstitute = nullptr;
Department* selectedDepartment = nullptr;
Role* selectedRole = nullptr;
Employee* selectedEmployee = nullptr;
Student* selectedStudent = nullptr;
Course* selectedCourse = nullptr;
std::string instituteName;

void CloseProgram()
{
	std::cout << "Exiting..." << std::endl;
	exit(0);
}

void Intro()
{
	std::cout << "Welcome to School Manager 01!" << std::endl;
	std::cout << std::endl;
	std::cout << "This is a simple school management system." << std::endl << std::endl;

	std::cout << "Type Institute name to Start Manage, or 'Exit' to exit the program" << std::endl << std::endl;

	std::cin >> instituteName;

	if (instituteName == "Exit")
	{
		CloseProgram();
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
		case 'N': Intro();
			break;
		case 'Y': RegisterInstitute(instituteName, registeredInstitutes, institutes, selectedInstitute);
			break;
		}
	}
}

int main()
{

	Intro();

	if(instituteName == "Exit")
	{
		CloseProgram();
	}


	
	

	while (selectedInstitute != nullptr && actualCommand != "Exit")
	{
		std::cout << selectedInstitute->GetName() << " > ";
		std::cout << "Type Command: ";
		std::cin >> actualCommand;

		if(actualCommand == "Exit")
		{
			std::cout << "Exiting..." << std::endl;
			break;
		}

		if (actualCommand == "Register")
		{
			std::cout << "Register '...' -Department-Role-Employee-Student-Course " << std::endl;
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
			else if( actualCommand == "Role")
			{
				std::string roleName;
				std::cout << "Type role name: ";
				std::cin >> roleName;
				std::string roleDescription;
				std::cout << "Type role description: ";
				std::cin >> roleDescription;
				selectedInstitute->CreateRole(roleName, roleDescription);
			}
			else if (actualCommand == "Employee")
			{
				std::string employeeName;
				std::cout << "Type employee name: ";
				std::cin >> employeeName;
				std::string employeeCPF;
				std::cout << "Type employee CPF: ";
				std::cin >> employeeCPF;
				std::string employeeRole;
				std::cout << "Type employee Role: ";
				std::cin >> employeeRole;
				std::string roleDesc;
				std::cout << "Type Role Description: ";
				std::cin >> roleDesc;
				std::string employeeDepartment;
				std::cout << "Type employee Department: ";
				std::cin >> employeeDepartment;
				std::string departmentDesc;
				std::cout << "Type Department Description: ";
				std::cin >> departmentDesc;
				long long salary;
				std::cout << "Type employee Salary: ";
				std::cin >> salary;
				selectedInstitute->CreateEmployee(employeeName, employeeCPF, employeeRole, roleDesc, employeeDepartment, departmentDesc, salary);
			}
			else if (actualCommand == "Student")
			{
				std::string studentName;
				std::cout << "Type student name: ";
				std::cin >> studentName;
				std::string studentCPF;
				std::cout << "Type student CPF: ";
				std::cin >> studentCPF;
				int age;
				std::cout << "Type student Age: ";
				std::cin >> age;
				selectedInstitute->CreateStudent(studentName, studentCPF, age);
			}
			else if (actualCommand == "Course")
			{
				std::string courseName;
				std::cout << "Type course name: ";
				std::cin >> courseName;
				std::string courseDescription;
				std::cout << "Type course description: ";
				std::cin >> courseDescription;
				selectedInstitute->CreateCourse(courseName, courseDescription);
			}
		}
		else if (actualCommand == "Show")
		{
			std::cout << "Show '...' -Departments-Roles-Employees-Students-Courses" << std::endl;

			std::cin >> actualCommand;
			if(actualCommand == "Departments")
			{
				selectedInstitute->GetDepartmentsNames();
			}
			else if (actualCommand == "Roles")
			{
				selectedInstitute->GetRolesNames();
			}
			else if (actualCommand == "Employees")
			{
				selectedInstitute->GetEmployeesNames();
			}
			else if (actualCommand == "Students")
			{
				selectedInstitute->GetStudentsNames();
			}
			else if (actualCommand == "Courses")
			{
				selectedInstitute->GetCoursesNames();
			}
		}
		else if (actualCommand == "Get")
		{
			std::cout << "Get '...' -Department-Role-Employee-Student-Course" << std::endl;

			std::cin >> actualCommand;
			if (actualCommand == "Department")
			{
				std::cout << "Type Department Name: ";
				std::string deptName;
				std::cin >> deptName;
				for(Department* dpt : selectedInstitute->GetDepartments())
				{
					if (dpt->GetName() == deptName)
					{
						selectedDepartment = dpt;
						std::cout << "Department " << deptName << " Selected" << std::endl;
						break;
					}
				}
				if(selectedDepartment == nullptr)
				{
					std::cout << "Department " << deptName << " Not Found !" << std::endl;
				}
			}
			else if (actualCommand == "Role")
			{
				std::cout << "Type Role Name: ";
				std::string roleName;
				std::cin >> roleName;
				for (Role* rle : selectedInstitute->GetRoles())
				{
					if (rle->GetName() == roleName)
					{
						selectedRole = rle;
						std::cout << "Role " << roleName << " Selected" << std::endl;
						break;
					}
				}
				if(selectedRole == nullptr)
				{
					std::cout << "Role " << roleName << " Not Found !" << std::endl;
				}
			}
			else if (actualCommand == "Employee")
			{
				std::cout << "Type Employee CPF: ";
				std::string empCPF;
				std::cin >> empCPF;
				for (Employee* emp : selectedInstitute->GetEmployees())
				{
					if (emp->GetCPF() == empCPF)
					{
						selectedEmployee = emp;
						std::cout << "Employee " << emp->GetName()<< "CPF: " << emp->GetCPF() << " Selected" << std::endl;
						break;
					}
				}
				if(selectedEmployee == nullptr)
				{
					std::cout << "Employee with CPF " << empCPF << " Not Found !" << std::endl;
				}
			}
			else if (actualCommand == "Student")
			{
				std::cout << "Type Student CPF: ";
				std::string stuCPF;
				std::cin >> stuCPF;
				for (Student* stu : selectedInstitute->GetStudents())
				{
					if (stu->GetCPF() == stuCPF)
					{
						selectedStudent = stu;
						std::cout << "Student " << stu->GetName() << "CPF: " << stu->GetCPF() << " Selected" << std::endl;
						break;
					}
				}
				if (selectedStudent == nullptr)
				{
					std::cout << "Student with CPF " << stuCPF << " Not Found !" << std::endl;
				}
			}
			else if (actualCommand == "Course")
			{
				std::cout << "Type Course Name: ";
				std::string courseName;
				std::cin >> courseName;
				for (Course* crs : selectedInstitute->GetCourses())
				{
					if (crs->GetName() == courseName)
					{
						selectedCourse = crs;
						std::cout << "Course " << crs->GetName() << " Selected" << std::endl;
						break;
					}
				}
				if (selectedCourse == nullptr)
				{
					std::cout << "Course " << courseName << " Not Found !" << std::endl;
				}
			}
		}
		else if (actualCommand == "StudentCourses")
		{
			if (selectedStudent != nullptr)
			{
				for (Course* crs : selectedStudent->GetRegisteredCourses())
				{
					std::cout << crs->GetName() << " " << std::endl;
				}
			}
			else
			{
				std::cout << "No Student Selected !" << std::endl;
			}
		}
		else if (actualCommand == "CourseRegisterStudent")
		{
			std::cout << "Type Student Name: CPF " << std::endl;
			std::string studentCPF;
			std::cin >> studentCPF;
		}
	}
	if (selectedInstitute == nullptr)
	{
	}
	return 0;
}
