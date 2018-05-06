// Work1.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Work2Library.h"

using namespace Work2;

WORK2LIBRARY_API void  hexInclusionSort(int array[], int n)
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

WORK2LIBRARY_API void   deleteElement(int array[], int & n,int num)
{
	for (int i = num; i < n - 1; i++)
	{
		array[i] = array[i + 1];
	}
	n--;
}

WORK2LIBRARY_API bool isBadNumber(int x, int badsymbol)
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

