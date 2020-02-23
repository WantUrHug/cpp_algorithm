#pragma once
#include <time.h>
const unsigned long maxshort = 65536L;
const unsigned long	multiplier = 1194211693L;
const unsigned long adder = 12345L;

class RandomNumber
{
private:	
	//存放当前种子的私有成员
	unsigned long randSeed;

public:
	//构造函数。缺存值0表示系统自动给出种子
	RandomNumber(unsigned long s = 0);
	//产生 0 <= value <= n-1 的随机整数
	unsigned short Random(unsigned long n);
	//产生 0 <= value <= 1.0 的随机实数
	double fRandom(void);
};
//种子生成器
RandomNumber::RandomNumber(unsigned long s)
{
	if (s == 0)
		randSeed = time(0);
	else
		randSeed = s;
}
unsigned short RandomNumber::Random(unsigned long n)
{
	randSeed = multiplier * randSeed + adder;
	return (unsigned short)((randSeed >> 16) % n);
}
double RandomNumber::fRandom(void)
{
	return Random(maxshort) / double(maxshort);
}