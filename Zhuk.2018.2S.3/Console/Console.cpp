#include "stdafx.h"
#include "Work3.h"
#include <iostream>
#include <iomanip>

using namespace std;
using namespace Work3;

bool checkVariable(int);
void displayMatrix(int**, int);

int main()
{
	int n = 0;

	do
	{
		cout << "enter n = ";
		cin >> n;
		system("cls");
	} while (checkVariable(n));

	int** matrix = allocateMemoryForMatrix(n);

	initRandMatrix(matrix, n);

	displayMatrix(matrix, n);
	cout << endl;

	int** newmatrix = task8(matrix,n);

	cout << "Finish matrix : " << endl;
	displayMatrix(newmatrix, n);

	system("pause");
	return 0;
}

bool checkVariable(int n)
{
	return !(n > 0);
}

void displayMatrix(int** matrix, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << std::setw(4) << matrix[i][j] << " ";
		}
		cout << endl;
	}
}