#include <iostream>
#include <stdlib.h>
using namespace std;

class Tempreture
{
private:
	float highTemp, lowTemp;
public:
	Tempreture(float h, float l);
	void UpdateTemp(float temp);
	float GetHighTemp(void) const;
	float GetLowTemp(void) const;
};
Tempreture::Tempreture(float h, float l):highTemp(h), lowTemp(l)
{}
void Tempreture::UpdateTemp(float temp)
{
	if (temp > highTemp)
		highTemp = temp;
	if (temp < lowTemp)
		lowTemp = temp;
}
float Tempreture::GetHighTemp(void) const
{
	return highTemp;
}
float Tempreture::GetLowTemp(void) const
{
	return lowTemp;
}
Tempreture Average(Tempreture a[], int n)
{
	float avg_lowtemp = 0;
	float avg_hightemp = 0;
	for (int i = 0; i < n; i++)
	{
		avg_lowtemp += a[i].GetLowTemp();
		avg_hightemp += a[i].GetHighTemp();
	}
	Tempreture avg(avg_hightemp / n, avg_lowtemp / n);
	return avg;
}
//void main(void)
//{
//	Tempreture t1(70, 60), t2(100, 50);
//	Tempreture a[2] = { t1, t2 };
//	Tempreture t3 = Average(a, 2);
//	cout << t3.GetHighTemp() << ", " << t3.GetLowTemp() << endl;
//	system("pause");
//}