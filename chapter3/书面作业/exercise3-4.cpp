#include <iostream>

class X
{
private:
	int a, b, c;
public:
	X(int x, int y, int z);
	int F(void);
};
X::X(int x = 1, int y = 1, int z = 1)
{
	a = x; b = y; c = z;
}
int X::F(void)
{
	if (a > b & a > c)
		return a;
	if (b > a & b > c)
		return b;
	if (c > a & c > b)
		return c;
}