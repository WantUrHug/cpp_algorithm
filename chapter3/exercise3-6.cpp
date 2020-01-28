#include <iostream>
#include <stdlib.h>
using namespace std;
class Calendar
{
private:
	int year;
	bool leapyr;
public:
	//构造函数
	Calendar(int y, bool ly);
	//返回从该年第一天到给定月(m)，给定日(dd)的天数
	int NumDays(int m, int dd);
	//指示某年是否是闰年
	bool Leapyear(void);
	//给出是一年中的第几天，返回 mm/dd/yy 的格式
	void PrintDate(int ndays);
};
Calendar::Calendar(int y, bool ly = false)
{
	year = y;
	if (y % 100 == 0) {
		if (y % 400 == 0)
			leapyr = true;
		else
			leapyr = false;
	}
	else {
		if (y % 4 == 0)
			leapyr = true;
		else
			leapyr = false;
	}
}
int Calendar::NumDays(int m, int dd)
{
	int adder;
	if (leapyr == true)
		adder = 1;
	else
		adder = 0;
	switch (m)
	{
	case 1:
		return dd;
	case 2:
		return 31 + dd;
	case 3:
		return 59 + adder + dd;
	case 4:
		return 90 + adder + dd;
	case 5:
		return 120 + adder + dd;
	case 6:
		return 151 + adder + dd;
	case 7:
		return 181 + adder + dd;
	case 8:
		return 212 + adder + dd;
	case 9:
		return 242 + adder + dd;
	case 10:
		return 273 + adder + dd;
	case 11:
		return 304 + adder + dd;
	case 12:
		return 334 + adder + dd;
	default:
		break;
	}
}
bool Calendar::Leapyear(void)
{
	return leapyr;
}
void Calendar::PrintDate(int ndays)
{
	int adder;
	if (leapyr == true)
		adder = 1;
	else
		adder = 0;

	if (ndays <= 31)
		cout << "01//" << ndays << "//" << year << endl;
	else
		if (ndays <= 59 + adder)
			cout << "02//" << ndays - 31 << "//" << year << endl;
		else
			if (ndays <= 90 + adder)
				cout << "03//" << ndays - 59 - adder << "//" << year << endl;
			else
				if (ndays <= 120 + adder)
					cout << "04//" << ndays - 90 - adder << "//" << year << endl;
				else
					if (ndays <= 151 + adder)
						cout << "05//" << ndays - 120 - adder << "//" << year << endl;
					else
						if (ndays <= 181 + adder)
							cout << "06//" << ndays - 151 - adder << "//" << year << endl;
						else
							if (ndays <= 212 + adder)
								cout<< "07//" << ndays - 181 - adder << "//" << year << endl;
							else
								if (ndays <= 242 + adder)
									cout << "08//" << ndays - 212 - adder << "//" << year << endl;
								else
									if (ndays <= 273 + adder)
										cout << "09//" << ndays - 242 - adder << "//" << year << endl;
									else
										if (ndays <= 304 + adder)
											cout << "10//" << ndays - 273 - adder << "//" << year << endl;
										else 
											if (ndays <= 334 + adder)
												cout << "11//" << ndays - 304 - adder << "//" << year << endl;
											else
												if (ndays <= 365 + adder)
													cout << "12//" << ndays - 334 - adder << "//" << year << endl;
}						
//int main()
//{
//	Calendar c(2020, true);
//	cout << "Is it a leap year? " << c.Leapyear() << endl;
//	cout << "2.29 numdays is " << c.NumDays(2, 29) << endl;
//	c.PrintDate(77);
//	system("pause");
//}