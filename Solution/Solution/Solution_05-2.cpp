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



class Lotto
{
public:
	Lotto() = default;
	Lotto(const Lotto& other) = delete;
	Lotto& operator=(const Lotto& other) = delete;
	~Lotto()
	{
		Clear();
	}

	void Make(int maxNum, int digitCount)
	{
		bool* arr = new bool[maxNum]();

		if (!empty())
		{
			Clear();
		}

		_count = digitCount;
		_lotto = new int[_count]();

		for (int i = 0; i < _count;)
		{
			int randNum = rand() % maxNum;
			if (arr[randNum] != true)
			{
				arr[randNum] = true;
				_lotto[i] = randNum + 1;
				++i;
			}
		}

		delete[] arr;
	}

	void Print()
	{
		if (empty())
			return;
		for (int i = 0; i < _count; ++i)
		{
			std::cout << _lotto[i] << " ";
		}
		std::cout << std::endl;
	}

	void Clear()
	{
		delete[] _lotto;
		_lotto = nullptr;
		_count = 0;
	}

private:
	int* _lotto = nullptr;
	int _count = 0;

	bool empty()
	{
		if (_lotto)
			return false;
		else
			return true;
	}

};

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

	Lotto lotto;

	for (int i = 0; i < 5; ++i)
	{
		lotto.Make(maxNum, count);

		lotto.Print();

	}



	return 0;
}