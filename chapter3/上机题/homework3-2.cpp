#include <iostream>
#include <stdlib.h>

using namespace std;

class Student
{
private:
	int studentid;
	int gradepts, units;
	float gpa;
	inline float ComputeGPA(void);
public:
	inline Student(int studid, int studgradepts, int studunits);
	//void ReadGradeInfo(void);
	void PrintGradeInfo(void);
	void UpdateGradeInfo(int newunits, int newgradepts);
};
Student::Student(int studid, int studgradepts, int studunits)
{
	studentid = studid;
	gradepts = studgradepts;
	units = studunits;
}
float Student::ComputeGPA(void)
{
	return float(gradepts) / float(units);
}
void Student::PrintGradeInfo(void)
{
	cout << "Student " << studentid << " grade: " << gradepts << ", units:" << units << endl;
}
void Student::UpdateGradeInfo(int newunits, int newgradepts)
{
	gradepts = newgradepts;
	units = newunits;
}
//int main(void)
//{
//	Student s1(1047, 120, 40), s2(3050, 75, 20), s3(0022, 100, 75);
//	s1.PrintGradeInfo(); s2.PrintGradeInfo(); s3.PrintGradeInfo();
//	s3.UpdateGradeInfo(40, 10);
//	s3.PrintGradeInfo();
//	system("pause");
//}