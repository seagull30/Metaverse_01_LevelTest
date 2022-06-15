#pragma once
#include <iostream>
#include "Deck.h"

class Player
{
public:
	Player() = default;

	Player(std::string name) : _name(name) {}

	Player(const Player& other) = delete;

	Player& operator=(const Player& other) = delete;

	~Player()
	{
		Clear();
	}

	void changeName(std::string name)
	{
		_name = name;
	}

	void PickCard(Deck* deck)
	{
		_deck = deck;
		_hand = _deck->Make();
		_cardCount = 7;
	}

	void Print()
	{
		if (_name == "" || _hand == nullptr)
			return;
		std::cout << _name << " : ";
		for (int i = 0; i < _cardCount; i++)
		{
			std::cout << convertToCardString(_hand[i]) << ", ";
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

	void Clear()
	{
		_name = "";
		HandClear();
	}

	void HandClear()
	{
		delete[] _hand;
		_hand = nullptr;
		_cardCount = 0;
	}

private:
	std::string		_name = "";
	int* _hand = nullptr;
	int		_cardCount = 0;
	Deck* _deck = nullptr;
};