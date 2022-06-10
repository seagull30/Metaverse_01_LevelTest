#include <iostream>
#include <random>
#include <time.h>
#include <stdbool.h>

// 문제를 파악한 내용
// 입력으로 최댓값과 생성 숫자를 입력는다.
// 중복되는 숫자가 없게 해야한다.
// 
// 해결 아이디어
// 입력받은 최댓값 만큼 bool타입 동적 배열을 만들어 중복을 방지한다.
//  최댓값보다 생성 숫자가 크면 중복되는 숫자없이 원하는 개수의 숫자를 출력하지 못하므로 입력을 다시 받는다.


int main()
{
	srand(time(NULL));
	int maxNum = 0;
	int count = 0;
	while (true)
	{
		std::cout << "최댓값 : ";
		std::cin >> maxNum;

		std::cout << "생성숫자 : ";
		std::cin >> count;

		if (count > maxNum)
		{
			std::cout << "숫자를 다시 입력해주세요\n";
			continue;
		}
		break;
	}

	bool* arr = new bool[maxNum]();
	
	for (int i = 0; i < count; ++i)
	{
		int randNum = rand() % maxNum;
		if (arr[randNum] == true)
		{
			--i;
		}
		else
		{
			arr[randNum] = true;
			std::cout << randNum + 1 << " ";

		}
	}
	std::cout << std::endl;

	delete[] arr;

	return 0;
}