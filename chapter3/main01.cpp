#include <iostream>
#include <iomanip>
#include "random.h"

int TossCoins(int numberCoins)
{
	static RandomNumber coinToss;
	int i, tosses = 0;
	for (i = 0; i < numberCoins; i++)
		tosses += coinToss.Random(2);
	return tosses;
}
/*
int main(void)
{
	const int NCOINS = 10;
	const long NTOSSES = 50000;

	long i, heads[NCOINS + 1];
	int j, position;

	for (j = 0; j <= NCOINS; j++)
	{ 
		heads[j] = 0;
	}
	for (i = 0; i < NTOSSES; i++)
	{ 
		heads[TossCoins(NCOINS)] += 1;
	}
	for (i = 0; i <= NCOINS; i++)
	{
		position = int(float(heads[i]) / float(NTOSSES) * 72);
		std::cout << std::setw(6) << i << " ";
		for (j = 0; j < position - 1; j++)
		{
			std::cout << " ";
		}
		std::cout << "*" << std::endl;
	}
}*/