#pragma once

#include "Person.hpp"



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

	void SetSalary(long long newSalary) { Salary = newSalary; }
	long long GetSalary() { return Salary; }

	
};