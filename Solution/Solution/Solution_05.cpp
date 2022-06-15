#include <iostream>
#include <random>
#include <time.h>
#include <stdbool.h>

// ������ �ľ��� ����
// �Է����� �ִ񰪰� ���� ���ڸ� �Է´´�.
// �ߺ��Ǵ� ���ڰ� ���� �ؾ��Ѵ�.
// 
// �ذ� ���̵��
// �Է¹��� �ִ� ��ŭ boolŸ�� ���� �迭�� ����� �ߺ��� �����Ѵ�.
//  �ִ񰪺��� ���� ���ڰ� ũ�� �ߺ��Ǵ� ���ھ��� ���ϴ� ������ ���ڸ� ������� ���ϹǷ� �Է��� �ٽ� �޴´�.

int* makeLotto(int maxNum, int count)
{
	bool* arr = new bool[maxNum]();
	int* lotto = new int[count]();
	for (int i = 0; i < count;)
	{
		int randNum = rand() % maxNum;
		if (arr[randNum] != true)
		{
			arr[randNum] = true;
			lotto[i] = randNum + 1;
			++i;
		}
	}
	delete[] arr;
	return lotto;
}

int main()
{
	srand(time(NULL));
	int maxNum = 0;
	int count = 0;
	while (true)
	{
		std::cout << "�ִ� : ";
		std::cin >> maxNum;

		std::cout << "�������� : ";
		std::cin >> count;

		if (count > maxNum)
		{
			std::cout << "���ڸ� �ٽ� �Է����ּ���\n";
			continue;
		}
		break;
	}

	int* lottoNum = makeLotto(maxNum, count);
	
	
	for (int i = 0; i < count; ++i)
	{
		std::cout << lottoNum[i] << " ";
	}
	std::cout << std::endl;

	
	delete[] lottoNum;

	return 0;
}