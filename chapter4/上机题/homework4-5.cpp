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
//	cout << "�������һ��ѧ����������";
//	cin >> t1_name;
//	cout << "�������һ��ѧ���Ŀ��Ժţ�";
//	cin >> t1_num;
//	Test t1 = { t1_name.c_str(), scanf_s(t1_num.c_str())};
//	cout << "������ڶ���ѧ����������";
//	cin >> t2_name;
//	cout << "������ڶ���ѧ���Ŀ��Ժţ�";
//	cin >> t2_num;
//	Test t2 = { t2_name.c_str(), scanf_s(t2_num.c_str())};
//	cout << "�����������ѧ����������";
//	cin >> t3_name;
//	cout << "�����������ѧ���Ŀ��Ժţ�";
//	cin >> t3_num;
//	Test t3 = { t3_name.c_str(), scanf_s(t3_num.c_str())};
//	//��һ���׶Σ���������
//	SubmittedTests.Insert(t1); SubmittedTests.Insert(t2); SubmittedTests.Insert(t3);
//	//�ڶ����׶Σ����
//	string check_name;
//	cout << "������Ҫ����ѧ��������"; cin >> check_name;
//	Test check_item;
//	check_item.name = check_name.c_str();
//	int r = SubmittedTests.Find(check_item);
//	if (r == 0)
//	{
//		cout << "��ѯ�Ķ��󲻴��ڣ�" << endl;
//		exit(1);
//	}
//	SubmittedTests.Delete(check_item);
//	borrowedTests.Insert(check_item);
//	//�������׶Σ����ؽ�����Ծ�
//	string return_name;
//	Test return_item;
//	cout << "������Ҫ�����Ծ��ѧ��������"; cin >> return_name;
//	return_item.name = return_name.c_str();
//	r = borrowedTests.Find(return_item);
//	if (r == 0)
//	{
//		cout << "�����������ڽ���Ծ�������У�" << endl;
//		exit(1);
//	}
//	borrowedTests.Delete(check_item);
//	SubmittedTests.Insert(check_item);
//	//���ĸ��׶Σ��ջ������Ծ�
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