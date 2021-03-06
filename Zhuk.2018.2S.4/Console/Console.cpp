#include "stdafx.h"
#include "Work4.h"
#include <iostream>
#include <iomanip>

using namespace std;
using namespace Work4;

bool checkVariable(int);
void displayMatrix(int**, int);

int main()
{
	int n = 0;

	do
	{
		cout << "enter n = ";
		cin >> n;
	} while (checkVariable(n));

	int ** matrix = allocateMemoryForMatrix(n);
	initRandMatrix(matrix, n);

	displayMatrix(matrix, n);

	int ** newmatrix = task13(matrix, n);

	cout << "finish matrix :" << endl;
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
	for (int i = 0; i < n ; i++)
	{
		for (int j = 0; j < n ; j++)
		{
			if (j > i)
			cout << std::setw(10) << matrix[j][i] << " ";
			if (j <= i)
				cout << std::setw(10) << matrix[i][j] << " ";
		}
		cout << endl;
	}
}
