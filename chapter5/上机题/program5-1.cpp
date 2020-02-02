#include <iostream>
typedef char DataType;
#include "astack.h"

void Deblank(char*s, char*t)
{
	while (*s != NULL)
	{
		if (*s != ' ')
			*t = *s;
		s++;
		t++;
	}
	*t = NULL;
}
int main()
{
	const int True = 1, False = 0;
	Stack S;
	
	char palstring[80], deblankstring[80], c;
	int ispalindrome = True; //假定是回文
	cin.getline(palstring, 80, '\n');

	Deblank(palstring, deblankstring);
	int i = 0;
	while (deblankstring[i] != '\0')
	{
		S.Push(deblankstring[i]);
		i++;
	}

	i = 0;
	while (!S.StackEmpty())
	{
		c = S.Pop();
		if (c != deblankstring[i])
		{
			ispalindrome = False; break;
		}
		i++;
	}
	if (ispalindrome) {
		cout << '\"' << palstring << '\"' << "is palindrome" << endl;
	}
	else
		cout<< '\"' << palstring << '\"' << "is not palindrome" << endl;
	system("pause");
}