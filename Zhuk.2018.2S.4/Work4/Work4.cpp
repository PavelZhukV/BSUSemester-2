#include "stdafx.h"
#include <cmath>
#include "Work4.h"
#include <stdexcept>

using namespace Work4;
using namespace std;

WORK4LIBRARY_API int** Work4::allocateMemoryForMatrix(int n)
{
	if (n < 1)
		throw out_of_range("Invalid data");
	int** x = new int*[n];
	for (int i = 0; i < n; i++)
	{
		x[i] = new int[i+1];
	}
	return x;
}

WORK4LIBRARY_API void Work4::initRandMatrix(int** matrix, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			matrix[i][j] = rand() % 10;
		}
	}
}

WORK4LIBRARY_API int** Work4::task13(int** matrix, int n)
{
	int ** newmatrix = Work4::allocateMemoryForMatrix(n);
	Work4::initZeroMatrix(newmatrix, n);
	int a = 0, b = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			for (int r = 0; r < n; r++)
			{
				if (i < r)
					a = matrix[r][i];
				else
					a = matrix[i][r];

				if (r < j)
					b = matrix[j][r];
				else
					b = matrix[r][j];

				newmatrix[i][j] += a * b;
		    }
		}
	}
	return newmatrix;
}

WORK4LIBRARY_API void Work4::initZeroMatrix(int** matrix, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			matrix[i][j] = 0;
		}
	}
}