#include <iostream>
#include <random>
#include <time.h>
#include <string>

// 문제를 파악한 내용
// 플레이어에게 중복되지 않게 카드를 나눠줘야 한다.
// 준 카드를 화면에 출력한다.
// 해결 아이디어
// bool타입 배열을 통해 플레이어에게 준 카드였는지 체크하고 만약 준카드 였다면 다시 카드를 고른다.
// 랜덤한 53보다 작은 숫자를 받아 나누기 연산을 통한 값은 도형 나머지 연산을 통한 값은 카드의 번호로 출력해준다 
// 조커도 나누기연산을 통해 따로 나온다. 
bool deck[53] = {};

int* pickCard()
{
	int* card = new int[7];
	for (int i = 0; i < 7; ++i)
	{
		int randNum = rand() % 53;
		if (deck[randNum] == true)
		{
			--i;
			continue;
		}
		deck[randNum] = true;
		card[i] = randNum;
	}
	return card;
}

void pickCard(int* playerCard)
{

	for (int i = 0; i < 7; ++i)
	{
		int randNum = rand() % 53;
		if (deck[randNum] == true)
		{
			--i;
			continue;
		}
		deck[randNum] = true;
		playerCard[i] = randNum;
	}
}

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
			std::cout << value;
			break;
		}
		std::cout << ", ";
	}
	std::cout << std::endl;
}


std::string convertToCardString(int cardIndex)

{
	int cardTypeIndex = cardIndex / 13;
	int cardNumberIndex = cardIndex % 13;
	static const std::string CARD_TYPE[] = { "♠" ,"♣","♥","◆" };
	static const std::string CARD_NUMBER[] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

	if (cardTypeIndex == 4)
	{
		return "Joker";
	}
	else
	{
		return CARD_TYPE[cardTypeIndex] + CARD_NUMBER[cardNumberIndex];
	}

}

std::string convertToCardString(int* cardIndex)
{

	std::string cardstring = {};
	for (int i = 0; i < 7; ++i)

	{
		int sign = cardIndex[i] / 13;
		int value = cardIndex[i] % 13;
		switch (sign)
		{
		case 0:

			cardstring += "♠";
			break;

		case 1:

			cardstring += "♣";
			break;

		case 2:

			cardstring += "♥";
			break;

		case 3:

			cardstring += "◆";
			break;

		default:

			cardstring += "Joker";
			break;
		}
		switch (value)
		{
		case 0:
			if (sign == 4)
				break;
			cardstring += "A";
			break;

		case 10:
			cardstring += "J";
			break;

		case 11:
			cardstring += "Q";
			break;

		case 12:
			cardstring += "K";
			break;

		default:
			cardstring += std::to_string(value);
			break;
		}
		cardstring += ", ";
	}
	return cardstring;
}


int main()
{
	srand(time(NULL));

	int player1[7];
	pickCard(player1);

	int* player2 = pickCard();

	printCard("player 1", player1);

	std::cout << "player 2 : ";
	for (int i = 0;; i++)
	{
		std::cout << convertToCardString(player2[i]) << ", ";
	}


	delete[] player2;
}