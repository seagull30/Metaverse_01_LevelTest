#pragma once
#include <iostream>

using namespace std;

#define NOT_VISITED 0


class Snail
{
public:
	Snail() = default;
	~Snail()
	{
		delete[] _arr;
	}

	void Make(int size)
	{
		_size = size;
		_arr = new int[size * size];
		memset(_arr, 0, sizeof(int) * size * size);
	}

	void move()
	{
		for (int i = 0; i < _size * _size; ++i)
		{
			// 2-2. 발자국을 남긴다.
			_arr[_r * _size + _c] = _footstep;
			++_footstep;

			// 2-3. 이동할 위치를 계산한다.
			static const int dr[] = { 0, 1, 0, -1 };
			static const int dc[] = { 1, 0, -1, 0 };

			int nr = _r + dr[(int)_direction];
			int nc = _c + dc[(int)_direction];

			// 2-4. 이동이 가능한지 판별한다.
			// 2-4-1. 벽에 닿았을 떄 => r, c의 위치가 [0, size]
			if (nr < 0 || nr >= _size || nc < 0 || nc >= _size || _arr[nr * _size + nc] != NOT_VISITED)
			{
				_direction = (Direction)((_direction + 1) % DIR_MAX);
				nr = _r + dr[(int)_direction];
				nc = _c + dc[(int)_direction];
			}
			// 2-4-2. 이미 지나온 곳일 때 => arr[nr][nc] != 0

			_r = nr;
			_c = nc;
		}
	}

	void print()
	{
		for (int r = 0; r < _size; ++r)
		{
			for (int c = 0; c < _size; ++c)
			{
				cout << _arr[r * _size + c] << "\t";
			}
			cout << "\n";
		}
	}
private:
	int _r = 0;
	int _c = 0;
	int _size = 0;
	int _footstep = 1;
	int* _arr = nullptr;
	enum Direction { DIR_RIGHT, DIR_DOWN, DIR_LEFT, DIR_UP, DIR_MAX };
	Direction _direction = DIR_RIGHT;
};