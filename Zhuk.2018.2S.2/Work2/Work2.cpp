#include "stdafx.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include "Work2.h"
#include <stdexcept>

using namespace Work2;
using namespace std;

WORK2LIBRARY_API double** Work2:: allocateMemoryForMatrix(int n)
{
	if (n < 1)
		throw out_of_range("Invalid data");
	double** x = new double*[n];
	for (int i = 0; i < n; i++)
	{
		x[i] = new double[n];
	}
	return x;
}

WORK2LIBRARY_API void Work2::initZeroMatrix(double** matrix, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrix[i][j] = 0;
		}
	}
}

WORK2LIBRARY_API double Work2::sinTaylor(int x, double eps)
{
	double term = x, sum = 0;
	for (int i = 1; fabs(term) > eps; i++)
	{
		sum += term;
		term = -term * x * x / (2 * i) / (2 * i + 1);
	}
	return sum;
}

WORK2LIBRARY_API double Work2::cosTaylor(int x, double eps)
{
	double term = 1, sum = 0;
	for (int i = 1; fabs(term) > eps; i++)
	{
		sum += term;
		term = -term * x * x / (2 * i - 1) / (2 * i);
	}
	return sum;
}

WORK2LIBRARY_API void Work2::matrixTaylor(double** matrix, int n,double eps)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				matrix[i][j] = 0;
			else
				matrix[i][j] = (pow(M_E, Work2::sinTaylor((i + j), eps)) + Work2::cosTaylor(pow(i + j, 2), eps)) / Work2::sinTaylor(pow(i + 1, 2), eps);

		}
	}
}

WORK2LIBRARY_API void Work2::matrix(double** matrix, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				matrix[i][j] = 0;
			else
				matrix[i][j] = (pow(M_E, sin(i + j)) + cos(pow(i + j, 2))) / sin(pow(i + 1, 2));

		}
	}
}