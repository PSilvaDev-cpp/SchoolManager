#pragma once

#include <stdlib.h>
#include <cstdio>
#include <iostream>
#include <string>




bool VerifyInstitute(std::string instituteName, std::vector<std::string>& registeredInstitutes)
{
	return (std::find(registeredInstitutes.begin(), registeredInstitutes.end(), instituteName) != registeredInstitutes.end());
}

void RegisterInstitute(std::string newInstitute, std::vector<std::string>& registeredInstitutes, std::vector<Institute*>& institutes, Institute* &selectedInstitute)
{
	selectedInstitute = new Institute();
	selectedInstitute->name = newInstitute;
	registeredInstitutes.push_back(newInstitute);
	institutes.push_back(selectedInstitute);
}

//void RegisterClass(std::string className, std::string classDescription)