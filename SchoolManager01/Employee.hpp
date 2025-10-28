#pragma once

#include "Person.hpp"


class Institute;
struct Role;
struct Department;

class Employee: public Person
{
public:

	Employee()
	{
	
	}

	Department* department;
	Role* role;

	long long Salary;

	void SetRole(Institute& institute, std::string roleName, std::string roleDesc);
	void SetSalary(long long newSalary);
	void SetDepartment(Institute& institute, std::string departmentName, std::string departmentDesc);
	long long GetSalary() { return Salary; }


	
};