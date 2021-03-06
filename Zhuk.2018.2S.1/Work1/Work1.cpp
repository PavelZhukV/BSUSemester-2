// Work1.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Work1Library.h"

using namespace Work1;
using namespace std;

WORK1LIBRARY_API void Work1:: hexInclusionSort(int array[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int index = i;
		int value = array[i];
		while ((index > 0) && (firstHexSymbol(array[index - 1]) > firstHexSymbol(value)))
		{
			array[index] = array[index - 1];
			index--;
		}
		array[index] = value;
	}
}

WORK1LIBRARY_API void Work1::  deleteElement(int array[], int & n,int num)
{
	for (int i = num; i < n - 1; i++)
	{
		array[i] = array[i + 1];
	}
	n--;
}

WORK1LIBRARY_API bool Work1:: isBadNumber(int x, int badsymbol)
{
	while (x > 0)
	{
		if (x % 16 == badsymbol)
			return 1;
		else
			x /= 16;
	}
	return 0;
}

WORK1LIBRARY_API int Work1:: firstHexSymbol(int x)
{
	while (x >= 15)
	{
		x /= 16;
	}
	return x;
}

WORK1LIBRARY_API void Work1 :: task13(int array[], int & n,char a ,int narray[],int & k)
{
	deleteEqualElements(array, n);
	hexInclusionSort(array, n);
	deleteInNewArray(array, n, a, narray, k);
}

WORK1LIBRARY_API int Work1:: badSymbol(char symbol)
{
	int a;
	switch (symbol)
	{
	case 'A':
		a = 10;
		break;
	case 'B':
		a = 11;
		break;
	case 'C':
		a = 12;
		break;
	case 'D':
		a = 13;
		break;
	case 'E':
		a = 14;
		break;
	case 'F':
		a = 15;
		break;
	}
	return a;
}

WORK1LIBRARY_API void Work1:: deleteEqualElements(int array[], int & n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j= i+1;j<n;j++)
			if (array[i] == array[j])
			{
				deleteElement(array, n, j);
				j--;
			}
	}
}

WORK1LIBRARY_API void Work1::deleteInNewArray (int array[], int & n, char a, int narray[], int & k)
{
	k = 0;
	for (int i = 0,j = -1; i < n; i++)
	{
		if (isBadNumber(array[i], badSymbol(a)))
		{
			j++;
			k++;
			narray[j] = array[i];
			deleteElement(array, n, i);
			i--;
		}
	}
}