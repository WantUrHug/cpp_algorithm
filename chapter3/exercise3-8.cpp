#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int ToolRandInt(int min, int max)
{
	srand((unsigned)time(NULL));
	int r = rand() % (max - min + 1) + min;
	return r;
}
class CardDeck
{
private:
	int cards[52];
	int currentCrd;
public:
	//���캯��
	CardDeck(void);
	//ϴ��
	void Shuffle(void);
	//������һ����
	int GetCard(void);
	//÷����0-12�� ������13-25��������26-38��������39-51��ÿ����ɫ��
	//��һ��ΪA���������ΪJ��Q��K.������C���Ϊ����ɫ ��ֵ��
	void PrintCard(int c);
	//չʾ��ӡ����
	void ShowCards(void);
};
CardDeck::CardDeck(void)
{
	int length = sizeof(cards) / sizeof(cards[0]);
	//cout << length << endl;;
	for (int i = 0; i < length; i++)
		cards[i] = i;
	currentCrd = 0;
	Shuffle();
}
void CardDeck::Shuffle(void)
{
	int length = sizeof(cards) / sizeof(cards[0]);
	//cout << length << endl;;
	for (int j = 0; j < length; j++)
	{
		int randnumber = ToolRandInt(j, length - 1);
		//����������
		int tmp = cards[j];
		cards[j] = cards[randnumber];
		cards[randnumber] = tmp;
	}
}
int CardDeck::GetCard(void)
{	
	if (currentCrd <= 51)
		currentCrd += 1;
	else
	{
		cout << "�����Ѿ�������." << endl;
		return -1;
	}
	int result = cards[currentCrd - 1];
	return result;
}
void CardDeck::PrintCard(int c)
{
	if (0 <= c && c < 13)
		cout << "÷�� ";
	else
		if (13 <= c && c < 26)
			cout << "���� ";
		else
			if (26 <= c && c < 39)
				cout << "���� ";
			else 
				if (39 <= c && c < 52)
					cout << "����";
				else
					cout << "��ŷ�ΧӦ����0-51֮��." << endl;
					return;
	switch (c%13)
	{
	case 0:
		cout << "A";
	case 1:
		cout << "2";
	case 2:
		cout << "3";
	case 3:
		cout << "4";
	case 4:
		cout << "5";
	case 5:
		cout << "6";
	case 6:
		cout << "7";
	case 7:
		cout << "8";
	case 8:
		cout << "9";
	case 9:
		cout << "10";
	case 10:
		cout << "J";
	case 11:
		cout << "Q";
	case 12:
		cout << "K";
	}
	cout << endl;
}
void CardDeck::ShowCards(void) {
	int length = sizeof(cards) / sizeof(cards[0]);
	for (int i = 0; i < length ; i++)
	{
		if (cards[i] >= 0)
		{
			cout << cards[i] << ", ";
		}
	}
	cout << endl;
}

//int main()
//{
//	CardDeck cd;
//	cd.ShowCards();
//	cd.Shuffle();
//	cd.ShowCards();
//	cout << cd.GetCard() << endl;
//	cout << cd.GetCard() << endl;
//	system("pause");
//}