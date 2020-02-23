#include <iostream>
#include <stdlib.h>
using namespace std;

const int MaxDualStackSize = 100;
typedef int DataType;

class DualStack
{
private:
	int top1, top2;
	DataType stackStorage[MaxDualStackSize];
public:
	DualStack(void);
	void Push(DataType elt, int n);
	DataType Pop(int n);
	DataType Peek(int n);
	int StackEmpty(int n) const;
	int StackFull(int n) const;
	void ClearStack(int n);
};
DualStack::DualStack(void):top1(-1), top2(MaxDualStackSize){}
void DualStack::Push(DataType elt, int n)
{
	//如果指定的栈满了就无法再加入，退出
	if (StackFull(n))
		return;
	if (n == 1){
		top1++;
		stackStorage[top1] = elt;
	}
	else {
		top2--;
		stackStorage[top2] = elt;
	}
}
DataType DualStack::Pop(int n)
{
	DataType out;
	if (StackEmpty(n)){
		cerr << "Stack is empty." << endl;
		exit(1);
	}
	if (n == 1){
		out = stackStorage[top1];
		top1--;
	}
	else {
		out = stackStorage[top2];
		top2++;
	}
	return out;
}
DataType DualStack::Peek(int n)
{
	DataType out;
	if (StackEmpty(n)) {
		cerr << "Stack is empty." << endl;
		exit(1);
	}
	if (n == 1) {
		out = stackStorage[top1];
	}
	else {
		out = stackStorage[top2];
	}
	return out;
}
int DualStack::StackEmpty(int n) const
{
	if (n == 1){
		if (top1 == -1)
			return 1;
		else
			return 0;
	}
	else {
		if (top2 == MaxDualStackSize)
			return 1;
		else
			return 0;
	}
}
int DualStack::StackFull(int n) const
{
	//满的条件未必是整个数组都被其中一个栈堆满，如果两个栈顶相接也满足栈满的条件
	if (top1 == top2 - 1)
		return 1;
	if (n == 1) {
		if (top1 == MaxDualStackSize - 1)
			return 1;
		else
			return 0;
	}
	else {
		if (top2 == 0)
			return 1;
		else
			return 0;
	}
}
void DualStack::ClearStack(int n)
{
	if (n == 1)
		top1 = -1;
	else
		top2 = MaxDualStackSize;
}

void main(void)
{
	int tmp;
	DualStack ds;
	int i;
	for (i = 0; i < 20; i++)
	{
		cin >> tmp;
		if (tmp % 2 == 0)
			ds.Push(tmp, 1);
		else
			ds.Push(tmp, 2);
	}
	cout << "left side of DualStack: ";
	while (!ds.StackEmpty(1))
		cout << ds.Pop(1) << " ";
	cout << endl;
	cout << "right side of DualStack: ";
	while (!ds.StackEmpty(2))
		cout << ds.Pop(2) << " ";
	system("pause");
}