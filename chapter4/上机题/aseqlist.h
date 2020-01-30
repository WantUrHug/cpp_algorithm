
#include <iostream>
#include <stdlib.h>
using namespace std;
const int MaxListSize = 50;

class SeqList
{
private:
	//��ű������͵�ǰ��Ԫ�ظ���
	DataType listitem[MaxListSize];
	int size;
public:
	SeqList(void);
	//���ʱ�Ԫ�صķ���
	int ListSize(void) const;
	int ListEmpty(void) const;
	int Find(DataType& item) const;
	DataType GetData(int pos) const;
	//�ı����Ԫ�صķ���
	void Insert(const DataType &item);
	void Delete(const DataType &item);
	DataType DeleteFront(void);
	void ClearList(void);
};
SeqList::SeqList(void):size(0){}
int SeqList::ListSize(void) const
{
	return size;
}
int SeqList::ListEmpty(void) const
{
	if (size == 0)
		return 0;
	else
		return 1;
}
void SeqList::Insert(const DataType &item)
{
	//����Ԫ�ػ�ʹ�ñ�Խ����
	if (size + 1 > MaxListSize)
	{
		cerr << "Maximum list size execeeded" << endl;
		exit(1);
	}
	listitem[size] = item;
	size++;
}
void SeqList::Delete(const DataType &item)
{
	int i = 0;
	while (i < size && !(listitem[i] == item))
	{
		i++;
	}
	//���iС��size��˵�����ҵ���Ҫɾ���Ķ��󣬶�������ΪԽ�����˳�
	if (i < size)
	{
		while (i < size - 1)
		{
			//��Ϊ������i+1������������size-1
			listitem[i] = listitem[i + 1];
			i++;
		}
		//Ԫ��������һ
		size--;
	}
}
DataType SeqList::GetData(int pos) const
{
	//����Ƿ�Խ��
	if (pos < 0 || pos >= size)
	{
		cerr << "pos is out of range." << endl;
		exit(1);
	}
	return listitem[pos];
}
//Find�ǽ�ѡ�е���ֵ���ص����ò����У�����ֵ��������ʾ�Ƿ��ҵ���һ�����
int SeqList::Find(DataType& item) const
{
	int i = 0;
	if (ListEmpty())
		//��Ϊ�շ���0
		return 0;
	while (i < size && !(listitem[i] == item))
		i++;
	if (i < size)
	{
		item = listitem[i];
		return 1;
	}
	else
		return 0;
}
DataType SeqList::DeleteFront(void)
{
	if (size == 0)
	{
		cerr << "List is empty." << endl;
		exit(1);
	}
	DataType front = listitem[0];
	for (int i = 0; i < size - 1; i++)
	{
		listitem[i] = listitem[i + 1];
	}
	size--;
	return front;

}