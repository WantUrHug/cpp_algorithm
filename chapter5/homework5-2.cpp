typedef int DataType;
#include "chapter5/astack.h"
#include <stdlib.h>

int main(void)
{
	int list[10];
	int i, t;
	for (i = 0; i < 10; i++)
	{
		cin >> t;
		list[i] = t;
	}
	Stack s;
	for (i = 0; i < 10; i++)
	{
		cout << list[i] << "  ";
		s.Push(list[i]);
	}
	cout << endl;
	while (!s.StackEmpty())
	{
		cout << s.Pop() << "  ";
	}
	system("pause");
}