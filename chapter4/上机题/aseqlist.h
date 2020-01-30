
#include <iostream>
#include <stdlib.h>
using namespace std;
const int MaxListSize = 50;

class SeqList
{
private:
	//存放表的数组和当前的元素个数
	DataType listitem[MaxListSize];
	int size;
public:
	SeqList(void);
	//访问表元素的方法
	int ListSize(void) const;
	int ListEmpty(void) const;
	int Find(DataType& item) const;
	DataType GetData(int pos) const;
	//改变表中元素的方法
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
	//插入元素会使得表越界吗？
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
	//如果i小于size，说明是找到了要删除的对象，而不是因为越界了退出
	if (i < size)
	{
		while (i < size - 1)
		{
			//因为这里有i+1，所以上面是size-1
			listitem[i] = listitem[i + 1];
			i++;
		}
		//元素数量减一
		size--;
	}
}
DataType SeqList::GetData(int pos) const
{
	//检查是否越界
	if (pos < 0 || pos >= size)
	{
		cerr << "pos is out of range." << endl;
		exit(1);
	}
	return listitem[pos];
}
//Find是将选中的数值返回到引用参数中，返回值是用来表示是否找到的一个结果
int SeqList::Find(DataType& item) const
{
	int i = 0;
	if (ListEmpty())
		//表为空返回0
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