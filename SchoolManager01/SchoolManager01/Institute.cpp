#include "Institute.hpp"
#include <algorithm>
#include <iostream>





void Institute::RegisterDepartment(Department* newDepartment)
{
	departments.push_back(newDepartment);
}

void Institute::CreateDepartment(std::string departmentName, std::string departmentDescription)
{
	if(std::find(departmentNames.begin(), departmentNames.end(), departmentName) != departmentNames.end())
	{
		std::cout << "Department with name " << departmentName << " already exists." << std::endl;
		return;
	}
	departmentNames.push_back(departmentName);
	Department* newDepartment = new Department();
	newDepartment->SetName(departmentName);
	newDepartment->SetDescription(departmentDescription);
	RegisterDepartment(newDepartment);
}

void Institute::RegisterEmployee(std::string newName, std::string newCPF)
{
	Employee* newEmployee = new Employee();
	
}