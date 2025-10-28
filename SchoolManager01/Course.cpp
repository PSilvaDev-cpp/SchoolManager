#include <iostream>
#include "Institute.hpp"
#include "Course.hpp"

void Course::RegisterNewStudent(Institute* institute, std::string studentName, std::string studentCPF)
{
	if (institute == nullptr) { return; }

	if (institute->CheckRegisteredStudents(studentName, studentCPF))
	{
		for (std::string registers : registeredStudents)
		{
			if (registers == studentCPF)
			{
				std::cout << " Student " << studentName << " with CPF " << studentCPF << " already registered in Course " << name << std::endl;
				std::cout << " Register Command Aborted " << std::endl;
				return;
			}
			registeredStudents.push_back(studentCPF);
			
			if (institute->students.empty()) { std::cout << "ERROR. Instite students none" << std::endl;  return; }

			for (Student* studentPtr : institute->students)
			{
				if (studentPtr->GetCPF() == studentCPF)
				{
					students.push_back(studentPtr);
				}
			}

		}
	}

}

