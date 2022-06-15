#pragma once
#include <iostream>


class Deck
{
public:
	Deck() = default;
	~Deck() = default;

	void ToString()
	{
		for (int i = 0; i < 53; ++i)
		{
			if (!_deck[i])
				std::cout << convertToCardString(i) << ", ";
		}
		std::cout << std::endl;
	}

	std::string convertToCardString(int cardIndex)

	{
		int cardTypeIndex = cardIndex / 13;
		int cardNumberIndex = cardIndex % 13;
		static const std::string CARD_TYPE[] = { "¢¼", "¢À", "¢¾", "¡ß" };
		static const std::string CARD_NUMBER[] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };

		if (cardTypeIndex == 4)
		{
			return "Joker";
		}
		else
		{
			return CARD_TYPE[cardTypeIndex] + CARD_NUMBER[cardNumberIndex];
		}

	}

	int* Make()
	{
		
		int* card = new int[7];
		for (int i = 0; i < 7;)
		{
			int randNum = rand() % 53;
			if (!_deck[randNum])
			{
				_deck[randNum] = true;
				card[i] = randNum;
				++i;
			}

		}
		remainingCards -= 7;
		return card;
	}

private:
	bool _deck[53] = {};
	int remainingCards = 53;
};