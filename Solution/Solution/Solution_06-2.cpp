#include <iostream>
#include <random>
#include <time.h>
#include <string>

#include "Deck.h"
#include "Player.h"

// ������ �ľ��� ����
// �÷��̾�� �ߺ����� �ʰ� ī�带 ������� �Ѵ�.
// �� ī�带 ȭ�鿡 ����Ѵ�.
// �ذ� ���̵��
// boolŸ�� �迭�� ���� �÷��̾�� �� ī�忴���� üũ�ϰ� ���� ��ī�� ���ٸ� �ٽ� ī�带 ����.
// ������ 53���� ���� ���ڸ� �޾� ������ ������ ���� ���� ���� ������ ������ ���� ���� ī���� ��ȣ�� ������ش� 
// ��Ŀ�� �����⿬���� ���� ���� ���´�. 

void printCard(std::string name, int* deck)
{
	std::cout << name << " : ";
	for (int i = 0; i < 7; ++i)

	{
		int sign = deck[i] / 13;
		int value = deck[i] % 13;
		switch (sign)
		{
		case 0:
			std::cout << "��";
			break;

		case 1:
			std::cout << "��";
			break;

		case 2:
			std::cout << "��";
			break;

		case 3:
			std::cout << "��";
			break;

		default:
			std::cout << "Joker";
			break;
		}
		switch (value)
		{
		case 0:
			if (sign == 4)
				break;
			std::cout << "A";
			break;

		case 10:
			std::cout << "J";
			break;

		case 11:
			std::cout << "Q";
			break;

		case 12:
			std::cout << "K";
			break;

		default:
			std::cout << value + 1;
			break;
		}
		std::cout << ", ";
	}
	std::cout << std::endl;
}

int main()
{
	srand(time(NULL));
	
	Deck deck;
	int* player1 = deck.Make();

	printCard("player 1", player1);

	Player player2;
	
	player2.changeName("player 2");
	player2.PickCard(&deck);
	player2.Print();

	deck.ToString();

	delete[] player1;

}
