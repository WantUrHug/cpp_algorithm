#pragma once
#include <iostream>
#include <stdlib.h>
using namespace std;

const int MaxPQSize = 50;

class PQueue
{
private:
	int count;
	DataType pqlist[MaxPQSize];
public:
	PQueue(void);
	void PQInsert(const DataType& item);
	DataType PQDelete(void);
	void ClearPQ(void);
	int PQEmpty(void) const;
	int PQLength(void) const;
	int PQFull(void) const;
};
PQueue::PQueue():count(0){}
void PQueue::PQInsert(const DataType& item)
{
	if (count == MaxPQSize)
	{
		cerr << "Priority queue overflow!" << endl;
		exit(1);
	}
	//并不是删除最前面一个，所以和 FIFO 队列不同
	pqlist[count] = item;
	count++;
}
DataType PQueue::PQDelete(void)
{
	DataType min;
	int i, minindex = 0;

	if (count > 0)
	{
		min = pqlist[0];
		for (i = 1; i < count; i++)
		{
			if (pqlist[i] < min) {
				min = pqlist[i];
				minindex = i;
			}
		}
		pqlist[minindex] = pqlist[count - 1];
		count--;
	}
	else {
		cerr << "Deleting from empty pqueue!" << endl;
		exit(1);
	}
	return min;
}
void PQueue::ClearPQ(void)
{
	count = 0;
}
int PQueue::PQEmpty(void) const
{
	if (count == 0)
		return 1;
	else
		return 0;
}
int PQueue::PQLength(void) const
{
	return count;
}
int PQueue::PQFull(void) const
{
	if (count == MaxPQSize)
		return 1;
	else
		return 0;
}