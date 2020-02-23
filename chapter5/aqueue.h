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
	//�ı���еĲ���
	void QInsert(const DataType& item);
	DataType QDelete(void);
	void ClearQueue(void);
	//���ʶ���
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
	//��Ϊ�����ӣ����Լ�������Ϊ rear ��λ����
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
	//��ǰ��ɾ��������ɾ�� front ���λ��
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