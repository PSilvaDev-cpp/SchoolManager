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

long long SchoolMath::CalculateTotalFee(std::map<std::string, CourseMonthlyFee>& MonthlyFees)
{
	long long total = 0;

	for (const auto& monthFee : MonthlyFees)
	{
		if (monthFee.second.feeState == "In Dept")
		{
			fSum(total, monthFee.second.course.GetMonthlyFee());
		}
	}
	return total;
}