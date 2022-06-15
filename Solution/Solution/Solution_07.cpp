#include <iostream>
#include <random>
#include <time.h>
#include <windows.h>

// ������ �ľ��� ����
// �������� �������� �����Ѵ�.
// ���� ����� üũ�ؼ� ǥ�����ش�. 
// 
// �ذ� ���̵��
// �������� ������ �ڸ��� ���ڸ� ������� �ְ� ���� ���ڸ��� �ٸ� ���ڰ� ����ִٸ� �ٽ� �ڸ��� ã�´�.
// ���� �Ǹ� ������ ���� 0�� �ȴٴ°��� �̿��� �������� �� ������ ��� ���� üũ�ؼ� 0�̵Ǹ� ������ ī��Ʈ�� �ø���.

#define BINGO_SIZE 5

int main()
{
	srand(time(NULL));
	//������ ���� ����
	int bingoPan[BINGO_SIZE][BINGO_SIZE] = {};
	for (int i = 1; i <= BINGO_SIZE * BINGO_SIZE;)
	{
		int randnum = rand() % (BINGO_SIZE * BINGO_SIZE);
		if (bingoPan[randnum / BINGO_SIZE][randnum % BINGO_SIZE] == 0)
		{
			bingoPan[randnum / BINGO_SIZE][randnum % BINGO_SIZE] = i;
			++i;
		}
	}

	int bingo = 0;
	while (true)
	{
		// ������ ���
		for (int row = 0; row < BINGO_SIZE; ++row)
		{
			for (int column = 0; column < BINGO_SIZE; ++column)
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

		int x = BINGO_SIZE + 1;
		int y = BINGO_SIZE + 1;
		for (int row = 0; row < BINGO_SIZE; ++row)
		{
			bool isExit = false;
			for (int column = 0; column < BINGO_SIZE; ++column)
			{

				if (bingoPan[row][column] == inputNum)
				{
					bingoPan[row][column] = 0;
					x = column;
					y = row;
					isExit = true;
				}
				if (isExit)
				{
					break;
				}
			}
		}
		if (x == BINGO_SIZE + 1 || y == BINGO_SIZE + 1)
		{
			system("cls");
			continue;
		}

		// ���� üũ
		int rowBingoCheck = 0;
		for (int i = 0; i < BINGO_SIZE; ++i)
		{
			rowBingoCheck += bingoPan[y][i];
		}
		if (rowBingoCheck == 0)
			++bingo;

		int columnBingoCheck = 0;
		for (int i = 0; i < BINGO_SIZE; ++i)
		{
			columnBingoCheck += bingoPan[i][x];
		}
		if (columnBingoCheck == 0)
			++bingo;

		if (x == y)
		{
			int leftDiagonalCheak = 0;
			for (int i = 0; i < BINGO_SIZE; ++i)
				leftDiagonalCheak += bingoPan[i][i];
			if (leftDiagonalCheak == 0)
				++bingo;
		}

		if (x + y == BINGO_SIZE - 1)
		{
			int rightDiagonalCheak = 0;
			for (int i = 0; i < BINGO_SIZE; ++i)
				rightDiagonalCheak += bingoPan[i][BINGO_SIZE - 1 - i];
			if (rightDiagonalCheak == 0)
				++bingo;
		}

		system("cls");
	}
	return 0;
}
