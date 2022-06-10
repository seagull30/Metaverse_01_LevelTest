#include <iostream>
#include <random>
#include <time.h>
#include <windows.h>





int main()
{
	srand(time(NULL));
	//������ ���� ����
	int bingoPan[5][5] = {};
	for (int i = 1; i <= 25; ++i)
	{
		int row = rand() % 5;
		int column = rand() % 5;
		if (bingoPan[row][column] != 0)
		{
			--i;
		}
		else
		{
			bingoPan[row][column] = i;
		}
	}

	int bingo = 0;
	while (true)
	{
		// ������ ���
		for (int row = 0; row < 5; ++row)
		{
			for (int column = 0; column < 5; ++column)
			{
				if (bingoPan[row][column] == 0)
				{
					std::cout << "    ";
				}
				else
				{
					std::cout.width(4);
					std::cout << bingoPan[row][column];
				}
			}
			std::cout << std::endl;
		}
		std::cout << "���� " << bingo << "���� ���� �ϼ��Ǿ����ϴ�." << std::endl;

		int inputNum = 0;
		std::cout << "���ڸ� �Է��� �ּ��� : ";
		std::cin >> inputNum;

		int x = 6;
		int y = 6;
		for (int row = 0; row < 5; ++row)
		{
			for (int column = 0; column < 5; ++column)
			{

				if (bingoPan[row][column] == inputNum)
				{
					bingoPan[row][column] = 0;
					x = column;
					y = row;
				}
			}
		}
		if (x == y == 6)
		{
			system("cls");
			continue;
		}

		// ���� üũ
		int rowbingocheck = 0;
		for (int i = 0; i < 5; ++i)
		{
			rowbingocheck += bingoPan[y][i];
		}
		if (rowbingocheck == 0)
			++bingo;

		int columnbingocheck = 0;
		for (int i = 0; i < 5; ++i)
		{
			columnbingocheck += bingoPan[i][x];
		}
		if (columnbingocheck == 0)
			++bingo;

		if (x == y)
		{
			int leftDiagonalCheak = 0;
			for (int i = 0; i < 5; ++i)
				leftDiagonalCheak += bingoPan[i][i];
			if (leftDiagonalCheak == 0)
				++bingo;
		}

		if (x + y == 4)
		{
			int rightDiagonalCheak = 0;
			for (int i = 0; i < 5; ++i)
				rightDiagonalCheak += bingoPan[i][4 - i];
			if (rightDiagonalCheak == 0)
				++bingo;
		}

		system("cls");
	}
	return 0;
}
