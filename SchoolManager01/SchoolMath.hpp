#pragma once

#include <math.h>
#include "Student.hpp"
#include <vector>
#include <map>
#include "Calendar.hpp"

class Student;


class SchoolMath
{
public:
	
	SchoolMath()
	{
	}

	static int Sum(int a, int b) { return a + b; }
	static float fSum(float a, float b) { return a + b; }
	static int Subtract(int a, int b) { return a - b; }
	static float fSubtract(float a, float b) { return a - b; }
	static int Multiply(int a, int b) { return a * b; }
	static float fMultiply(float a, float b) { return a * b; }
	static float Divide(int a, int b) { return (float)a / (float)b; }

	static float Power(int base, int exponent) { return pow(base, exponent); }
	static float SquareRoot(int value) { return sqrt(value); }


	float CalculateAvarage(std::vector<float> SemesterGrades);

	

};