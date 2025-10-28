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

	std::vector<std::string> registeredDepartments;
	std::vector<std::string> registeredRoles;
	std::vector<std::string> registeredEmployeesNames;
	std::vector<std::string> registeredEmployeesCPF;
	std::vector<std::string> registeredStudentsNames;
	std::vector<std::string> registeredStudentsCPF;
	std::vector<std::string> registeredCourses;

	Institute()
	{
	
	}

	std::string name;

	Address adress;

	std::vector<Department*> departments;

	std::vector<Role*> roles;

	std::vector<Employee*> employees;

	std::vector<Student*> students;

	std::vector<Course*> courses;

	std::string GetName() const { return name; }

	void CreateDepartment(std::string departmentName, std::string departmentDescription);
	void RegisterDepartment(Department* newDepartment);
	std::vector<Department*> GetDepartments() const { return departments; };
	void GetDepartmentsNames() const { for (Department* dpts : departments) { std::cout << dpts->GetName() << std::endl; } };

	void CreateRole(std::string roleName, std::string roleDescription);
	void RegisterRole(Role* newRole);
	std::vector<Role*> GetRoles() const { return roles; };
	void GetRolesNames() const { for (Role* rls : roles) { std::cout << rls->GetName() << std::endl; } };

	void CreateEmployee(std::string employeeName, std::string employeeCPF, std::string employeeRole, std::string roleDesc, std::string employeeDepartment, std::string departmentDesc, long long salary);
	void RegisterEmployee(Employee* newEmployee);
	std::vector<Employee*> GetEmployees() const { return employees; };
	void GetEmployeesNames() const { for (Employee* emp : employees ) { std::cout << emp->GetName() << std::endl; }
};

	void CreateStudent(std::string studentName, std::string studentCPF, int studentAge);
	void RegisterStudent(Student* newStudent);
	std::vector<Student*> GetStudents() const { return students; };
	void GetStudentsNames() const { for (Student* stdt : students) { std::cout << stdt->GetName() << std::endl; } }

	void CreateCourse(std::string courseName, std::string courseDescription);
	void RegisterCourse(Course* newCourse);
	std::vector<Course*> GetCourses() const { return courses; };
	void GetCoursesNames() const { for (Course* cors : courses) { std::cout << cors->GetName(); } };

	bool CheckRegisteredStudents(std::string studentName, std::string studentCPF);
	bool CheckRegisteredEmployees(std::string employeesName, std::string employeesCPF);

};