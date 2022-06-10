#include <iostream>

// 문제를 파악한 내용
// 배열의 크기가 주어진다.
// 배열의 숫자는 한쪽방향으로 커지다 끝에 다다르면 방향을 바꾼다. 
// 해결 아이디어
// 배열을 동적할당으로 생성한다.
// switch문을 통해 숫자가 한쪽끝에 다다르면 다른방향으로 향하게 한다. 


int main()
{
	int arraySize;
	std::cout << "배열의 크기를 입력하세요 : ";
	std::cin >> arraySize;
	int** arr=new int*[arraySize];
	for (int i = 0; i < arraySize; ++i)
	{
		arr[i] = new int[arraySize];
	}

	int row = 0, column = 0;
	int maxRow = arraySize - 1, maxColumn = arraySize - 1;
	int minRow = 0, minColumn = 0;
	int type = 1;
	for (int i = 1; i <= arraySize * arraySize; ++i)
	{
		arr[row][column] = i;
		switch (type)
		{
		case 1:

			++column;
			if (maxColumn == column)
			{
				++minRow;
				++type;
			}
			break;

		case 2:
			++row;
			if (maxRow == row)
			{
				--maxColumn;
				++type;
			}
			break;

		case 3:
			--column;
			if (minColumn == column)
			{
				--maxRow;
				++type;
			}
			break;

		case 4:
			--row;
			if (minRow == row)
			{
				++minColumn;
				type = 1;
			}
			break;
		default:
			break;
		}

	}

	for (int i = 0; i < arraySize; ++i)
	{
		for (int j = 0; j < arraySize; ++j)
		{
			std::cout.width(4);
			std::cout << arr[i][j];
		}
		std::cout << std::endl;
	}
	return 0;
}