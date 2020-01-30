#include <iostream>
#include <stdlib.h>
typedef int DataType;
#include "aseqlist.h"

void InserteMax(SeqList &L, int elt)
{
	for (int i = 0; i < L.ListSize(); i++)
	{
		if (elt < L.GetData(i))
		{
			cout << "elt is samller than one item in the list." << endl;
			return;
		}
	}
	L.Insert(elt);
}
//int main(void) {
//	SeqList L;
//	L.Insert(10);
//	L.Insert(20);
//	L.Insert(5);
//	int datalist[10] = { 6, 3, 10, 17, 25, 35, 15, 17, 8, 29 };
//	for (int i = 0; i < 10; i++)
//	{
//		InserteMax(L, datalist[i]);
//	}
//	for (int i = 0; i < L.ListSize(); i++)
//	{
//		cout << L.GetData(i) << " ";
//	}
//	cout << endl;
//	system("pause");
//}