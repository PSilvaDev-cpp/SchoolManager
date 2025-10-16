#pragma once 

#include <string>
#include "Employee.hpp"
#include <map>
#include "Role.hpp"
#include <array>
#include <vector>

struct Department
{

	

	std::string name;
	std::string description = "";
	std::map<Employee, Role> Employees;
	std::vector<Role> roles;

	
	void SetName(std::string departmentName) { name = departmentName; }
	std::string GetName() { return name; }

	void SetDescription(std::string departmentDescription) { description = departmentDescription; }
	std::string GetDescription() { return description; }

	void AddEmployee(Employee newEmployee);
	void RemoveEmployee(Employee targetEmployee);
	std::map<Employee, Role> GetEmployees() { return Employees; }

	void AddRole(Role newRole);
	void RemoveRole(Role targetRole);
	std::vector<Role> GetRoles() { return roles; }

};

