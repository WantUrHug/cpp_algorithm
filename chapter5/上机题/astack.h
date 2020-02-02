#pragma once
#include <iostream>
#include <stdlib.h>
using namespace std;

const int MaxStackSize = 50;

//typedef int DataType;

class Stack
{
private:
	DataType stacklist[MaxStackSize];
	int top;
public:
	Stack(void);
	void Push(const DataType& item);
	DataType Pop(void);
	void ClearStack(void);
	//∑√Œ ’ª∂•‘™Àÿ
	DataType Peek(void) const;
	int	StackEmpty(void) const;
	int StackFull(void) const;
};
Stack::Stack(void) :top(-1) {};

void Stack::Push(const DataType &item)
{
	if (top == MaxStackSize - 1) {
		cout << "Stack is full." << endl;
		return;
		//exit(1);
	}
	top++;
	stacklist[top] = item;
}

DataType Stack::Pop(void)
{
	if (top == -1) {
		cerr << "Stack is empty." << endl;
		exit(1);
	}
	DataType top_item = stacklist[top];
	top--;
	return top_item;
}

DataType Stack::Peek(void) const
{
	if (top == -1) {
		cerr << "Stack is empty." << endl;
		exit(1);
	}
	return stacklist[top];
}

int Stack::StackEmpty(void) const
{
	return top == -1;
}

int Stack::StackFull(void) const
{
	return top == MaxStackSize - 1;
}

void Stack::ClearStack(void)
{
	//–ﬁ∏ƒ’ª∂•÷∏’Îº¥ø…
	top = -1;
}