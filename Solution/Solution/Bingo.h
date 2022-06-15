#pragma once

#define CREATE_BINGO_COLUMN(type,size) new type*[size]
#define CREATE_BINGO_ROW(type,size) new type[size]

class Bingo
{
public:
	Bingo() = default;
	~Bingo()
	{
		Clear();
	}

	void Make(int bingoSize)
	{
		_bingoSize = bingoSize;
		_board = CREATE_BINGO_COLUMN(int, _bingoSize);
		for (int i = 0; i < _bingoSize; ++i)
		{
			_board[i] = CREATE_BINGO_ROW(int, _bingoSize);
			memset(_board[i], 0, sizeof(int) * _bingoSize);
		}

		for (int i = 1; i <= _bingoSize * _bingoSize;)
		{
			int randnum = rand() % (_bingoSize * _bingoSize);
			if (_board[randnum / _bingoSize][randnum % _bingoSize] == 0)
			{
				_board[randnum / _bingoSize][randnum % _bingoSize] = i;
				++i;
			}
		}
	}
	int ShowBingo() const
	{
		return _bingo;
	}
	int ShowBingoSize() const
	{
		return _bingoSize;
	}
	void Print() const
	{
		for (int row = 0; row < _bingoSize; ++row)
		{
			for (int column = 0; column < _bingoSize; ++column)
			{
				if (_board[row][column] == 0)
				{
					std::cout << "    ";
				}
				else
				{
					std::cout.width(4);
					std::cout << _board[row][column];
				}
			}
			std::cout << std::endl;
		}
		std::cout << "현재 " << _bingo << "줄의 빙고가 완성되었습니다." << std::endl;
	}

	bool Match(int inputNum)
	{
		for (int row = 0; row < _bingoSize; ++row)
		{
			for (int column = 0; column < _bingoSize; ++column)
			{

				if (_board[row][column] == inputNum)
				{
					_board[row][column] = 0;
					_x = column;
					_y = row;
					return true;
				}

			}
		}
		return false;
	}

	void Check()
	{
		int rowBingoCheck = 0;
		for (int i = 0; i < _bingoSize; ++i)
		{
			rowBingoCheck += _board[_y][i];
		}
		if (rowBingoCheck == 0)
			++_bingo;

		int columnBingoCheck = 0;
		for (int i = 0; i < _bingoSize; ++i)
		{
			columnBingoCheck += _board[i][_x];
		}
		if (columnBingoCheck == 0)
			++_bingo;

		if (_x == _y)
		{
			int leftDiagonalCheak = 0;
			for (int i = 0; i < _bingoSize; ++i)
				leftDiagonalCheak += _board[i][i];
			if (leftDiagonalCheak == 0)
				++_bingo;
		}

		if (_x + _y == _bingoSize - 1)
		{
			int rightDiagonalCheak = 0;
			for (int i = 0; i < _bingoSize; ++i)
				rightDiagonalCheak += _board[i][_bingoSize - 1 - i];
			if (rightDiagonalCheak == 0)
				++_bingo;
		}
	}

	void Clear()
	{
		for (int i = 0; i < _bingoSize; ++i)
		{

			delete[] _board[i];
			_board[i] = nullptr;
		}
		delete[] _board;
		_board = nullptr;
	}


private:
	int** _board = nullptr;
	int _bingoSize = 0;
	int _bingo = 0;
	int _x = 0;
	int _y = 0;
};
