// Work1Concsole.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Work1Library.h"

using namespace Work1;
using namespace std;


int main()
{
	const int N = 256;
	int array[] = { 1,5,16,7,20,22,46,22,30 };
	int narray[256] ;
	int n = 9, k = 0;
	char a = 'E';
	int resarray[] = { 1,16,20,22,5,7 };
	int resnarray[] = { 46,30 };

	task13(array, n, a, narray, k);
	
    return 0;
}

