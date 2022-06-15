#include <iostream>
#include <random>
#include <time.h>
#include <windows.h>

// 문제를 파악한 내용
// 빙고판은 랜덤으로 생성한다.
// 빙고가 됬는지 체크해서 표시해준다. 
// 
// 해결 아이디어
// 빙고판의 랜덤한 자리에 숫자를 순서대로 넣고 만약 그자리에 다른 숫자가 들어있다면 다시 자리를 찾는다.
// 빙고가 되면 라인의 합이 0이 된다는것을 이용해 마지막에 고른 숫자의 행과 열을 체크해서 0이되면 빙고의 카운트를 올린다.

#define BINGO_SIZE 5

int main()
{
	srand(time(NULL));
	//빙고판 랜덤 생성
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
		// 빙고판 출력
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
		std::cout << "현재 " << bingo << "줄의 빙고가 완성되었습니다." << std::endl;

		int inputNum = 0;
		std::cout << "숫자를 입력해 주세요 : ";
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

		// 빙고 체크
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
