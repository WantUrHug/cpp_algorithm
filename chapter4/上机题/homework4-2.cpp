struct Person
{
	const char* name;
	int age;
	const char* gender;
};
#include <string>
int operator == (Person X, Person Y)
{
	return strcmp(X.name, Y.name) == 0;
}
typedef Person DataType;
#include "aseqlist.h"

void PrintByGender(const SeqList &L, const char* sex)
{
	if (L.ListEmpty() == 0)
	{
		cout << "List is empty." << endl;
		return;
	}
	for (int i = 0; i < L.ListSize(); i++)
	{
		if (strcmp(sex, L.GetData(i).gender) == 0)
		{
			DataType p = L.GetData(i);
			cout << p.name << ", " << p.age << " years old, " << p.gender << endl;
		}
	}
}
int Inlist(const SeqList& L, const char *nm, Person &p)
{
	p.name = nm;
	int r = L.Find(p);
	return r;
}
int main() 
{
	DataType a = { "jack", 20, "male" };
	DataType b = { "mary", 22, "female" };
	DataType c = { "tom", 30, "male" };
	//cout << a.name << endl;
	SeqList L;
	L.Insert(a); L.Insert(b); L.Insert(c);
	PrintByGender(L, "female");
	Person d;
	cout << Inlist(L, "jack", d) << endl;;
	system("pause");
}