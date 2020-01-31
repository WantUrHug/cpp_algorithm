struct Test
{
	const char *name;
	int testNumber;
};
#include <string>
int operator == (const Test& t1, const Test& t2)
{
	return strcmp(t1.name, t2.name) == 0;
}
typedef Test DataType;
#include "aseqlist.h"

//int main(void)
//{
//	SeqList SubmittedTests, borrowedTests;
//	string t1_name, t1_num, t2_name, t2_num, t3_name, t3_num;
//	cout << "请输入第一个学生的姓名：";
//	cin >> t1_name;
//	cout << "请输入第一个学生的考试号：";
//	cin >> t1_num;
//	Test t1 = { t1_name.c_str(), scanf_s(t1_num.c_str())};
//	cout << "请输入第二个学生的姓名：";
//	cin >> t2_name;
//	cout << "请输入第二个学生的考试号：";
//	cin >> t2_num;
//	Test t2 = { t2_name.c_str(), scanf_s(t2_num.c_str())};
//	cout << "请输入第三个学生的姓名：";
//	cin >> t3_name;
//	cout << "请输入第三个学生的考试号：";
//	cin >> t3_num;
//	Test t3 = { t3_name.c_str(), scanf_s(t3_num.c_str())};
//	//第一个阶段，交卷。输入
//	SubmittedTests.Insert(t1); SubmittedTests.Insert(t2); SubmittedTests.Insert(t3);
//	//第二个阶段，查卷
//	string check_name;
//	cout << "请输入要查卷的学生姓名："; cin >> check_name;
//	Test check_item;
//	check_item.name = check_name.c_str();
//	int r = SubmittedTests.Find(check_item);
//	if (r == 0)
//	{
//		cout << "查询的对象不存在！" << endl;
//		exit(1);
//	}
//	SubmittedTests.Delete(check_item);
//	borrowedTests.Insert(check_item);
//	//第三个阶段，交回借出的试卷
//	string return_name;
//	Test return_item;
//	cout << "请输入要交回试卷的学生姓名："; cin >> return_name;
//	return_item.name = return_name.c_str();
//	r = borrowedTests.Find(return_item);
//	if (r == 0)
//	{
//		cout << "该姓名不存在借出试卷的名单中！" << endl;
//		exit(1);
//	}
//	borrowedTests.Delete(check_item);
//	SubmittedTests.Insert(check_item);
//	//第四个阶段，收回所有试卷
//	while (borrowedTests.ListSize() > 0)
//	{
//		Test item = borrowedTests.DeleteFront();
//		SubmittedTests.Insert(item);
//	}
//	for (r = 0; r < SubmittedTests.ListSize(); r++)
//	{
//		DataType p = SubmittedTests.GetData(r);
//		cout << p.name << " " << p.testNumber << endl;
//	}
//}