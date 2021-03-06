#include "stdafx.h"
#include "Work2.h"
#include <iostream>
#include <iomanip>

using namespace std;
using namespace Work2;

bool checkVariable(int , double );
void displayMatrix(double**, int);
void compessionMatrix(double**, double**, int, double);

int main()
{
	int n = 0;
	double eps = 0;
	
	do
	{
		cout << "enter n = ";
		cin >> n;
		cout << "enter eps = ";
		cin >> eps;
		system ("cls");
	} while (checkVariable(n, eps));
    
	double** matrixx = allocateMemoryForMatrix(n);
	double** taylormartix = allocateMemoryForMatrix(n);

	initZeroMatrix(matrixx, n);
	initZeroMatrix(taylormartix, n);

	matrix(matrixx, n);
	matrixTaylor(taylormartix, n, eps);

	displayMatrix(matrixx, n);
	cout << endl << "Taylor matrix: " << endl;
	displayMatrix(taylormartix, n);
	cout << endl;

	compessionMatrix(matrixx, taylormartix, n, eps);

	system("pause");
    return 0;
}

bool checkVariable(int n, double eps)
{
	return !(n > 0 && eps < 1 && eps > 0);
}

void displayMatrix(double** matrix, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << std::setw(10) << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void compessionMatrix(double** firstmatrix, double** secondmatrix, int n, double eps)
{
	int counter = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (fabs(firstmatrix[i][j] - secondmatrix[i][j]) < eps)
				counter++;
		}
	}
	int procent = counter * 100 / (n*n);
	cout << "Matrix coinside on" << procent << "%" << endl;
}