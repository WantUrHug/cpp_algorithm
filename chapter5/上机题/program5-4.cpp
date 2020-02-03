#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>

struct Person
{
	char name[20];
	char sex;		//'F'(Ů��), 'M'(����)
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
	//���ļ���ȷ�ϸ��ļ�����
	fin.open("dance.dat");
	if (!fin)
	{
		cerr << "Unable to open file." << endl;
		exit(1);
	}
	while (fin.get(p.sex))
	{
		fin.get(blankseparator);	//�˿ո�
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
		cout << p.name << " ";	//���Ů������
		p = maleDancers.QDelete();
		cout << p.name << endl;	//����а�����
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