#include <iostream>
#include <stdlib.h>
using namespace std;

class Accumulator
{
private:
	//一个作为总和的数
	float sum;
public:
	Accumulator(float N);
	void Add(float N);
	void Print(void);
};
Accumulator::Accumulator(float N = 0):sum(N)
{}
void Accumulator::Add(float N)
{
	sum += N;
}
void Accumulator::Print(void)
{
	cout << sum << endl;
}
class Trade
{
private:
	Accumulator Debits, Credits, Balance;
public:
	Trade(Accumulator B);
	void Add(float N);
	void ReadRecords(float datas[], int size);
	void PrintAll(void);
};
Trade::Trade(Accumulator B)
{
	Debits = Accumulator(0);
	Credits = Accumulator(0);
	Balance = B;
}
void Trade::Add(float N)
{
	Balance.Add(N);
	if (N > 0)
		Credits.Add(N);
	if (N < 0)
		Debits.Add(-N);
}
void Trade::ReadRecords(float datas[], int size)
{
	for (int i = 0; i < size; i++)
	{
		Add(datas[i]);
		if (datas[i] == 0)
		{
			break;
		}
	}
	PrintAll();
}
void Trade::PrintAll(void)
{
	cout << "Balance: "; Balance.Print();
	cout << "Debits: "; Debits.Print();
	cout << "Credits: "; Credits.Print();
}
//int main()
//{
//	Accumulator B(100);
//	Trade t(B);
//	float trades[] = { 100, -100, 200, -200, 300, 0 };
//	int length = sizeof(trades) / sizeof(trades[0]);
//	t.ReadRecords(trades, length);
//	system("pause");
//}