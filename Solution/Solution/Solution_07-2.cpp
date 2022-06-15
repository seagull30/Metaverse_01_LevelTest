#include <iostream>
#include <random>
#include <time.h>
#include <windows.h>
#include "Bingo.h"

// 문제를 파악한 내용
// 빙고판은 랜덤으로 생성한다.
// 빙고가 됬는지 체크해서 표시해준다. 
// 
// 해결 아이디어
// 빙고판의 랜덤한 자리에 숫자를 순서대로 넣고 만약 그자리에 다른 숫자가 들어있다면 다시 자리를 찾는다.
// 빙고가 되면 라인의 합이 0이 된다는것을 이용해 마지막에 고른 숫자의 행과 열을 체크해서 0이되면 빙고의 카운트를 올린다.

int main()
{
	srand(time(NULL));
	//빙고판 랜덤 생성

	Bingo bingo;
	std::cout << "빙고 크기를 입력하세요 : ";
	int inputnum;
	std::cin >> inputnum;

	bingo.Make(inputnum);

	while (bingo.ShowBingo() != bingo.ShowBingoSize() * 2 + 2)
	{
		system("cls");
		// 빙고판 출력
		bingo.Print();

		int inputNum = 0;
		std::cout << "숫자를 입력해 주세요 : ";
		std::cin >> inputNum;

		if (!bingo.Match(inputNum))
		{
			system("cls");
			continue;
		}

		// 빙고 체크
		bingo.Check();
		
	}
	return 0;
}
