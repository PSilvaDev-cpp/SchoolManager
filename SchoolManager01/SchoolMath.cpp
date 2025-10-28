#include "SchoolMath.hpp"

#include "Calendar.hpp"
#include <chrono>

float SchoolMath::CalculateAvarage(std::vector<float> SemesterGrades)
{
	float total = 0;
	for(float grade : SemesterGrades)
	{
		fSum(total, grade);
	}
	
	Divide(total, SemesterGrades.size());
	
	return total;
}

