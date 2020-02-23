#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>

struct Person
{
	char name[20];
	char sex;		//'F'(女性), 'M'(男性)
};
typedef Person DataType;
#include "aqueue.h"
void main(void)
{
	Queue maleDancers, femaleDancers;
	Person p;
	char blankseparator;
	int i;
	ifstream fin;
	//打开文件并确认该文件存在
	fin.open("dance.dat");
	if (!fin)
	{
		cerr << "Unable to open file." << endl;
		exit(1);
	}
	while (fin.get(p.sex))
	{
		fin.get(blankseparator);	//滤空格
		fin.getline(p.name, 20, '\n');
		if (p.sex == 'F')
			femaleDancers.QInsert(p);
		else
			maleDancers.QInsert(p);
	}
	cout << "The dancing partners are:" << endl << endl;
	while (!femaleDancers.QEmpty() && !maleDancers.QEmpty())
	{
		p = femaleDancers.QDelete();
		cout << p.name << " ";	//输出女伴姓名
		p = maleDancers.QDelete();
		cout << p.name << endl;	//输出男伴姓名
	}
	cout << endl;
	if (!femaleDancers.QEmpty())
	{
		cout << "There are " << femaleDancers.QLength() << " women waiting for the next round." << endl;
		cout << femaleDancers.QFront().name << " will be the first to get a partner." << endl;
	}
		else if (!maleDancers.QEmpty())
		{
			cout << "There are " << maleDancers.QLength() << " men waiting for the next round." << endl;
			cout << maleDancers.QFront().name << " will be the first to get a partner." << endl;
		}
	system("pause");
}