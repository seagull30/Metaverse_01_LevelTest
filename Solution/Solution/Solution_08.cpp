#include <iostream>


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