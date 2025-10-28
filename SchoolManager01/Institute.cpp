#include <algorithm>
#include <iostream>
#include "Institute.hpp"





void Institute::RegisterDepartment(Department* newDepartment)
{
	departments.push_back(newDepartment);
	std::cout << " Department " << newDepartment->GetName() << " Registered Successfully " << std::endl;
}

void Institute::CreateDepartment(std::string departmentName, std::string departmentDescription)
{
	if(std::find(registeredDepartments.begin(), registeredDepartments.end(), departmentName) != registeredDepartments.end())
	{
		std::cout << "Department with name " << departmentName << " already exists." << std::endl;
		std::cout << "Register Command aborted" << std::endl;
		return;
	}
	registeredDepartments.push_back(departmentName);
	Department* newDepartment = new Department();
	newDepartment->SetName(departmentName);
	newDepartment->SetDescription(departmentDescription);
	RegisterDepartment(newDepartment);
}

void Institute::RegisterRole(Role* newRole)
{
	roles.push_back(newRole);
}

void Institute::CreateRole(std::string roleName, std::string roleDescription)
{
	if (std::find(registeredRoles.begin(), registeredRoles.end(), roleName) != registeredRoles.end())
	{
		std::cout << " Role " << roleName << " already Registered " << std::endl;
		std::cout << "Register Command aborted" << std::endl;
		return;
	}
	registeredRoles.push_back(roleName);
	Role* newRole = new Role();
	newRole->SetName(roleName);
	newRole->SetDescription(roleDescription);
	RegisterRole(newRole);
}

bool Institute::CheckRegisteredEmployees(std::string employeeName, std::string employeeCPF)
{
	if (find(registeredEmployeesNames.begin(), registeredEmployeesNames.end(), employeeName) != registeredEmployeesNames.end())
	{
		if (find(registeredEmployeesCPF.begin(), registeredEmployeesCPF.end(), employeeCPF) != registeredEmployeesCPF.end())
		{
			return true;
		}
	}
	return false;
}

void Institute::RegisterEmployee(Employee* newEmployee)
{
	employees.push_back(newEmployee);
}

void Institute::CreateEmployee(std::string employeeName, std::string employeeCPF, std::string employeeRole, std::string roleDesc, std::string employeeDepartment, std::string departmentDesc, long long salary)
{
	if(CheckRegisteredEmployees(employeeName, employeeCPF))
	{
		std::cout << "Employee: " << employeeName << "CPF: " << employeeCPF << "already registered !" << std::endl;
		std::cout << "Register Command aborted" << std::endl;
		return;
	}

	if (std::find(registeredRoles.begin(), registeredRoles.end(), employeeRole) == registeredRoles.end())
	{
		std::cout << " Role " << employeeRole << " NOT FOUND, create new role: " << employeeRole << "?  Y/N" << std::endl;
		char answer;
		std::cin >> answer;
		switch (answer)
		{
			case 'N':
				std::cout << " Employee Registration Aborted " << std::endl;
				return;
				break;
			case 'Y':
				CreateRole(employeeRole, roleDesc);
				break;
			
		}
	}

	if (std::find(registeredDepartments.begin(), registeredDepartments.end(), employeeDepartment) == registeredDepartments.end())
	{
		std::cout << "Department with name " << employeeDepartment << " NOT FOUND, create new department: " << employeeDepartment << "?  Y/N" << std::endl;
		char answer;
		std::cin >> answer;
		switch (answer)
		{
		case 'N':
			std::cout << " Employee Registration Aborted " << std::endl;
			return;
			break;
		case 'Y':
			CreateDepartment(employeeDepartment, departmentDesc);
			break;
		}
	}
	
	registeredEmployeesNames.push_back(employeeName);
	Employee* newEmployee = new Employee();
	newEmployee->SetName(employeeName);
	newEmployee->SetCPF(employeeCPF);
	newEmployee->SetRole(*this, employeeRole, roleDesc);
	newEmployee->SetDepartment(*this, employeeDepartment, departmentDesc);
	newEmployee->SetSalary(salary);
	RegisterEmployee(newEmployee);
}

bool Institute::CheckRegisteredStudents(std::string studentName, std::string studentCPF)
{
	if (find(registeredStudentsNames.begin(), registeredStudentsNames.end(), studentName) != registeredStudentsNames.end())
	{
		if (find(registeredStudentsCPF.begin(), registeredStudentsCPF.end(), studentCPF) != registeredStudentsCPF.end())
		{
			return true;
		}
	}
	return false;
}

void Institute::RegisterStudent(Student* newStudent)
{
	students.push_back(newStudent);
}

void Institute::CreateStudent(std::string studentName, std::string studentCPF, int age)
{

	if (CheckRegisteredStudents(studentName, studentCPF))
	{
		std::cout << "Student: " << studentName << "CPF: " << studentCPF << "already registered !" << std::endl;
		std::cout << "Register Command aborted" << std::endl;
		return;
	}
	
	registeredStudentsNames.push_back(studentName);
	registeredStudentsCPF.push_back(studentCPF);

	Student* newStudent = new Student();
	newStudent->SetName(studentName);
	newStudent->SetCPF(studentCPF);
	newStudent->SetAge(age);
	std::cout << " Enter Student Adress Street: " << std::endl;
	std::string studentStreet;
	std::cin >> studentStreet;
	std::cout << " Enter Student Adress District: " << std::endl;
	std::string studentDistrict;
	std::cin >> studentDistrict;
	std::cout << " Enter Student Adress Number: " << std::endl;
	int studentNumber;
	std::cin >> studentNumber;
	newStudent->SetAdress(studentStreet, studentDistrict, studentNumber);
	std::cout << " Register Accountable Person for Student " << studentName << " ? Y/N " << std::endl;
	char answer;
	std::cin >> answer;
	switch (answer)
	{
	case 'N' :
		std::cout << " Student " << studentName << "Accountable seted as itself" << std::endl;
		newStudent->accountable = newStudent;
		break;

	case 'Y':
		std::cout << " Enter Accountable Person Name: " << std::endl;
		std::string personName;
		std::cin >> personName;
		std::cout << " Enter Accountable Person CPF: " << std::endl;
		std::string personCPF;
		std::cin >> personCPF;
		newStudent->RegisterAccountable(personName, personCPF);
	}
	RegisterStudent(newStudent);
}

void Institute::RegisterCourse(Course* newCourse)
{
	courses.push_back(newCourse);
}

void Institute::CreateCourse(std::string courseName, std::string courseDescription)
{
	if (std::find(registeredCourses.begin(), registeredCourses.end(), courseName) != registeredCourses.end())
	{
		std::cout << " Course " << courseName << " already Registered " << std::endl;
		std::cout << "Register Command aborted" << std::endl;
		return;
	}
	registeredCourses.push_back(courseName);
	Course* newCourse = new Course();
	newCourse->SetName(courseName);
	newCourse->SetDescription(courseDescription);
	RegisterCourse(newCourse);
}

