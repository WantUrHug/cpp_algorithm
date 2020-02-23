typedef double DataType;
#include "chapter5/aqueue.h"
#include <fstream>
#include <stdlib.h>
void Queue::Qprint(void)
{
	int cnt = 0;
	if (QEmpty())
	{
		cout << "Queue is empty." << endl;
		return;
	}
	while (!QEmpty()) {
		DataType e = QDelete();
		cout << e;
		cnt += 1;
		if (cnt == 8) {
			cout << endl;
			cnt = 0;
		}
		else {
			cout << "   ";
		}
	}
	cout << endl;
}
void main(void)
{
	double a;
	Queue q;
	ifstream fin;
	fin.open("pq.dat");
	if (!fin)
	{
		cerr << "Unable to open file 'pq.dat'." << endl;
		exit(1);
	}
	while (fin >> a)
	{
		q.QInsert(a);
	}
	q.Qprint();
	system("pause");
}