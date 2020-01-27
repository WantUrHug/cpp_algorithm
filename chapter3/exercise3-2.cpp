#include <iostream>
#include <stdlib.h>
using namespace std;

class Box
{
private:
	float a, b, c;
public:
	Box(float, float, float);
	float* getLines(void);
	float CalArea(void);
	float CalVolume(void);
};
Box::Box(float a1, float b1, float c1) {
	a = a1;
	b = b1;
	c = c1;
}
float* Box::getLines(void) {
	float lines[3];
	lines[0], lines[1], lines[2] = a, b, c;
	return lines;
}
float Box::CalArea(void) {
	float output = a * b * 2 + a * c * 2 + b * c * 2;
	return output;
}
float Box::CalVolume(void) {
	float output = a * b * c;
	return output;
}

bool PostDescriber(Box box)
{
	float* pp;
	pp = box.getLines();
	float a = *pp;
	float b = *(pp + 1);
	float c = *(pp + 2);
	cout << "a=" << a << ",b=" << b << ",c=" << c << endl;
	if ((2 * a + 2 * b + c < 100) || (a + 2 * b + 2 * c < 100) || (2 * a + b + 2 * c < 100))
		return true;
	else
		return false;
}
int main(void) {
	Box box(25, 25, 25);
	cout << "Area of our box is " << box.CalArea() << endl;
	cout << "Volume of out box is " << box.CalVolume() << endl;
	cout << PostDescriber(box) << endl;
	system("pause");
}