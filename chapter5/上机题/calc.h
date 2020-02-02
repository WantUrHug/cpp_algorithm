#pragma once
enum Boolean { False, True };
typedef double DataType;
#include "astack.h"

class Calculator
{
private:
	Stack S;
	void Enter(double num);
	Boolean GetTwoOperands(double& opnd1, double& opdn2);
	void Compute(char op);
public:
	Calculator(void);
	void Run(void);
	void Clear(void);
};
Calculator::Calculator(){}
void Calculator::Enter(double num)
{
	S.Push(num);
}
Boolean Calculator::GetTwoOperands(double& opnd1, double& opnd2)
{
	if (S.StackEmpty())
	{
		cerr << "Missing operand!" << endl;
		return False;
	}
	opnd1 = S.Pop();
	if (S.StackEmpty())
	{
		cerr << "Missing operand!" << endl;
		return False;
	}
	opnd2 = S.Pop();
	return True;
}
void Calculator::Compute(char op)
{
	Boolean result;
	double opnd1, opnd2;
	result = GetTwoOperands(opnd1, opnd2);
	if (result == True)
	{
		switch (op)
		{
		case '+':S.Push(opnd2 + opnd1); break;
		case '-':S.Push(opnd2 - opnd1); break;
		case '*':S.Push(opnd2 * opnd1); break;
		case '/': {
			if (opnd1 == 0.0) {
				cerr << "Divide by 0!" << endl;
				S.ClearStack();
			}
			else
				S.Push(opnd2 / opnd1);
			break;
		}
		case '^':S.Push(pow(opnd2, opnd1)); break;
		}
	}
	else
		S.ClearStack();
}
void Calculator::Run(void)
{
	char c;
	double newopnd;

	while (cin >> c, c != '=')
	{
		switch (c)
		{
		case '+':
		case '-':
		case '*':
		case '/':
		case '^':
			Compute(c);
			break;
		default:
			cin.putback(c);
			cin >> newopnd;
			Enter(newopnd);
			break;
		}
	}
	if (!S.StackEmpty())
		cout << S.Peek() << endl;
}
void Calculator::Clear(void)
{
	S.ClearStack();
}
