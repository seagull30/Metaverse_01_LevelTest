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