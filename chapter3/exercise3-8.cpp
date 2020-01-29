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
	//构造函数
	CardDeck(void);
	//洗牌
	void Shuffle(void);
	//返回下一张牌
	int GetCard(void);
	//梅花在0-12， 方块在13-25，红心在26-38，黑桃在39-51。每个花色中
	//第一张为A，最后三张为J、Q、K.，将牌C输出为“花色 牌值”
	void PrintCard(int c);
	//展示打印牌组
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
		//交换两张牌
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
		cout << "卡组已经抽完了." << endl;
		return -1;
	}
	int result = cards[currentCrd - 1];
	return result;
}
void CardDeck::PrintCard(int c)
{
	if (0 <= c && c < 13)
		cout << "梅花 ";
	else
		if (13 <= c && c < 26)
			cout << "方块 ";
		else
			if (26 <= c && c < 39)
				cout << "红心 ";
			else 
				if (39 <= c && c < 52)
					cout << "黑桃";
				else
					cout << "编号范围应该在0-51之间." << endl;
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