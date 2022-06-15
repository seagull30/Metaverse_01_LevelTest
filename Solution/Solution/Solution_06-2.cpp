#include <iostream>
#include <random>
#include <time.h>
#include <string>

#include "Deck.h"
#include "Player.h"

// 문제를 파악한 내용
// 플레이어에게 중복되지 않게 카드를 나눠줘야 한다.
// 준 카드를 화면에 출력한다.
// 해결 아이디어
// bool타입 배열을 통해 플레이어에게 준 카드였는지 체크하고 만약 준카드 였다면 다시 카드를 고른다.
// 랜덤한 53보다 작은 숫자를 받아 나누기 연산을 통한 값은 도형 나머지 연산을 통한 값은 카드의 번호로 출력해준다 
// 조커도 나누기연산을 통해 따로 나온다. 

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
			std::cout << "♠";
			break;

		case 1:
			std::cout << "♣";
			break;

		case 2:
			std::cout << "♥";
			break;

		case 3:
			std::cout << "◆";
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
