#pragma once
#include <iostream>
#include <stdlib.h>
using namespace std;

const int MaxQSize = 50;

class Queue
{
private:
	int front, rear, count;
	DataType qlist[MaxQSize];
public:
	Queue(void);
	//改变队列的操作
	void QInsert(const DataType& item);
	DataType QDelete(void);
	void ClearQueue(void);
	//访问队列
	DataType QFront(void);
	int QLength(void) const;
	int QEmpty(void) const;
	int QFull(void) const;
	void Qprint(void);
};
Queue::Queue(void):front(0),rear(0),count(0){}
void Queue::QInsert(const DataType& item)
{
	if (count == MaxQSize)
	{
		cerr << "Queue overflow!" << endl;
		exit(1);
	}
	count++;
	//因为是增加，所以加在索引为 rear 的位置上
	qlist[rear] = item;
	rear = (rear + 1) % MaxQSize;
}
DataType Queue::QDelete(void)
{
	if (count == 0)
	{
		cerr << "Delete from empty queue!" << endl;
		exit(1);
	}
	//从前面删除所以是删除 front 这个位置
	DataType temp;
	temp = qlist[front];
	count--;
	front = (front + 1) % MaxQSize;
	return temp;
}
void Queue::ClearQueue(void)
{
	count = 0;
}
DataType Queue::QFront(void)
{
	return qlist[front];
}
int Queue::QLength(void) const
{
	return count;
}
int Queue::QEmpty(void) const
{
	if (count == 0)
		return 1;
	else
		return 0;
}
int Queue::QFull(void) const
{
	if (count == MaxQSize)
		return 1;
	else
		return 0;
}