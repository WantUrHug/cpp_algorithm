#pragma once
#include <time.h>
const unsigned long maxshort = 65536L;
const unsigned long	multiplier = 1194211693L;
const unsigned long adder = 12345L;

class RandomNumber
{
private:	
	//��ŵ�ǰ���ӵ�˽�г�Ա
	unsigned long randSeed;

public:
	//���캯����ȱ��ֵ0��ʾϵͳ�Զ���������
	RandomNumber(unsigned long s = 0);
	//���� 0 <= value <= n-1 ���������
	unsigned short Random(unsigned long n);
	//���� 0 <= value <= 1.0 �����ʵ��
	double fRandom(void);
};
//����������
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