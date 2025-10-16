#include "Student.hpp"
#include <algorithm>
#include <iostream>
#include <string>

void Student::AddCourse(Course newCourse)
{
	auto it = std::find(registeredCourses.begin(), registeredCourses.end(), newCourse);
	if (it != registeredCourses.end())
	{
		(std::cout << "Course ") << newCourse.name << " already registered. " << std::endl;
	}
}