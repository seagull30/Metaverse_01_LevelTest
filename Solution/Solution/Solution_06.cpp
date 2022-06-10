#include <iostream>
#include <random>
#include <time.h>
#include <string>


void cardDistribution(std::string name, bool* deck)
{
	std::cout << name << " : ";
	
	for (int i = 0; i < 7; ++i)
	{
		int randNum = rand() % 53;
		if (deck[randNum] == true)
		{
			--i;
			continue;
		}
		deck[randNum] = true;
		int sign = randNum / 13;
		int value = randNum % 13;
		switch (sign)
		{
		case 0:
			std::cout << "¢¼";
			break;

		case 1:
			std::cout << "¢À";
			break;

		case 2:
			std::cout << "¢¾";
			break;

		case 3:
			std::cout << "¡ß";
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


int main()
{
	srand(time(NULL));
	bool deck[53] = {};

	cardDistribution("player 1", deck);
	cardDistribution("player 2", deck);

}