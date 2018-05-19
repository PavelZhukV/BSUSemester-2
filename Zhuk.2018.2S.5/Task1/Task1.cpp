#include "stdafx.h"
#include <iostream>


void onlyWords(char*);
void cleanStr(char*);
void displayStr(char*);

int main()
{
	char string[256] = "ud duhud sd # % Jnbb& udfus) hsi/ dufh";

	displayStr(string);
	std::cout << "\n";
	
	onlyWords(string);

	displayStr(string);

	system("pause");

    return 0;
}

void onlyWords(char* string)
{
	char symbol[256] = " qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
	char* copy = new char[strlen(string)];
	int len = strlen(string);

	cleanStr(copy);

	for (int i = 0,j = 0; i < len; i++)
	{
		if (strchr(symbol, string[i]) != nullptr)
		{
			copy[j] = string[i];
			j++;
			copy[j] = '\0';
		}
	}

	cleanStr(string);
	strcpy(string, copy);

	delete[] copy;
}
void cleanStr(char* string)
{
	int len = strlen(string);
	for (int i = 0; i < len; i++)
	{
		string = '\0';
	}
}

void displayStr(char* string)
{
	int len = strlen(string);
	for (int i = 0; i < len; i++)
		{
			std::cout << string[i];
		}
	std::cout << " ";
}