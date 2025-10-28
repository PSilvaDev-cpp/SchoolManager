#include "Institute.hpp"
#include "Role.hpp"
#include "Department.hpp"
#include "Employee.hpp"


void Employee::SetRole(Institute& institute, std::string roleName, std::string roleDesc)
{
	if(std::find(institute.registeredRoles.begin(), institute.registeredRoles.end(), roleName) != institute.registeredRoles.end())
	{
		role = institute.roles[std::distance(institute.registeredRoles.begin(), std::find(institute.registeredRoles.begin(), institute.registeredRoles.end(), roleName))];
	}
	else
	{
		std::cout << " Role " << roleName << " not found in Institute " << institute.GetName() << ", Create new Role ? Y/N " << std::endl;
		char answer;
		std::cin >> answer;
		
		switch (answer)
		{
		case 'N':
			return;
			break;
		case 'Y':
			institute.CreateRole(roleName, roleDesc);
			break;
		}
	}
	
	
}

void Employee::SetSalary(long long newSalary)
{
	Salary = newSalary;
}

void Employee::SetDepartment(Institute& institute, std::string departmentName, std::string departmentDesc)
{
	if (std::find(institute.registeredDepartments.begin(), institute.registeredDepartments.end(), departmentName) != institute.registeredDepartments.end())
	{
		department = institute.departments[std::distance(institute.registeredDepartments.begin(), std::find(institute.registeredDepartments.begin(), institute.registeredDepartments.end(),departmentName))];
	}
	else
	{
		std::cout << " Role " << departmentName << " not found in Institute " << institute.GetName() << ", Create new Role ? Y/N " << std::endl;
		char answer;
		std::cin >> answer;

		switch (answer)
		{
		case 'N':
			return;
			break;
		case 'Y':
			institute.CreateRole(departmentName, departmentDesc);
			break;
		}
	}
}