typedef int DataType;
#include "astack.h"

void MultibaseOutput(long num, int B)
{
	Stack S;
	do {
		S.Push(num%B);
		num /= B;
	} while (num != 0);
	while (!S.StackEmpty())
	{
		cout << S.Pop();
	}
}
void main()
{
	long num; int B;
	for (int i = 0; i < 3; i++)
	{
		cout << "Enter non-negative decimal number and base " << "(2 <= B <= 9):";
		cin >> num >> B;
		cout << num << " base " << B << " is ";
		MultibaseOutput(num, B);
		cout << endl;
	}
}