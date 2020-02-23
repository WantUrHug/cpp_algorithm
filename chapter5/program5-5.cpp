#include <iostream>
#include "chapter3/random.h"

typedef int DataType;
#include "aqueue.h"

enum DigitKind{ones, tens};
//n是L中的元素数
void Distribute(int L[], Queue digitQueue[], int n, DigitKind kind)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (kind == ones)
			digitQueue[L[i] % 10].QInsert(L[i]);
		else
			digitQueue[L[i] / 10].QInsert(L[i]);
	}
}
void Collect(Queue digitQueue[], int L[])
{
	int i = 0, digit = 0;
	for (digit = 0; digit < 10; digit++)
	{
		while (!digitQueue[digit].QEmpty())
			L[i++] = digitQueue[digit].QDelete();
	}
}
void PrintArray(int L[], int n)
{
	int i = 0;
	while (i < n)
	{
		cout.width(5);
		cout << L[i];
		if (++i % 10 == 0) {
			cout << endl;
		}
	}
	cout << endl;
}
void main(void)
{
	Queue digitQueue[10];
	int L[50];
	int i = 0;
	int item;
	RandomNumber rnd;
	for (i = 0; i < 50; i++)
		L[i] = rnd.Random(100);
	Distribute(L, digitQueue, 50, ones);
	Collect(digitQueue, L);
	PrintArray(L, 50);
	Distribute(L, digitQueue, 50, tens);
	Collect(digitQueue, L);
	PrintArray(L, 50);
	system("pause");
}