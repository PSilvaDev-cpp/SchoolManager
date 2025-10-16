#pragma once

#include <string>
#include <map>
#include "Address.hpp"


class Person
{
	std::string name = "";
	std::string cpf = "";
	std::string rg = "";
	int age = 0;
	Address address;

public:

	Person()
	{

	}
	virtual ~Person()
	{

	}


	void SetName(std::string Name)
	{
		name = Name;
	}
	std::string GetName() { return name; };

	void SetCPF(std::string CPF)
	{
		cpf = CPF;
	}
	std::string GetCPF() { return cpf; };

	void SetRG(std::string RG)
	{
		rg = RG;
	}
	std::string GetRG() { return rg; };

	void SetAge(int Age)
	{
		age = Age;
	}
	int GetAge() { return age; };

	void SetAdress(std::string Street, std::string District, int Number)
	{
		address.street = Street;
		address.district = District;
		address.Number = Number;
	}
	Address GetAdress() { return address; };
	

};