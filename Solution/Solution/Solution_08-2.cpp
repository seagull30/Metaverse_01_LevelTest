#include <iostream>

using namespace std;

#define NOT_VISITED 0

int main()
{

	// 1. 배열 만들기
	cout << "배열의 크기를 입력하세요 : ";
	int size;
	cin >> size;
	int* arr = new int[size * size];
	memset(arr, 0, sizeof(int) * size * size);
	// 2. 달팽이 배열 세팅
	// 2-1. 달팽이 데이터 초기화
	int r = 0;
	int c = 0;
	int footstep = 1;
	enum Direction { DIR_RIGHT, DIR_DOWN, DIR_LEFT, DIR_UP, DIR_MAX };
	Direction direction = DIR_RIGHT;
	for (int i = 0; i < size * size; ++i)
	{
		// 2-2. 발자국을 남긴다.
		arr[r * size + c] = footstep;
		++footstep;

		// 2-3. 이동할 위치를 계산한다.
		static const int dr[] = { 0, 1, 0, -1 };
		static const int dc[] = { 1, 0, -1, 0 };

		int nr = r + dr[(int)direction];
		int nc = c + dc[(int)direction];

		// 2-4. 이동이 가능한지 판별한다.
		// 2-4-1. 벽에 닿았을 떄 => r, c의 위치가 [0, size]
		if (nr < 0 || nr >= size || nc < 0 || nc >= size || arr[nr * size + nc] != NOT_VISITED)
		{
			direction = (Direction)((direction + 1) % DIR_MAX);
			nr = r + dr[(int)direction];
			nc = c + dc[(int)direction];
		}
		// 2-4-2. 이미 지나온 곳일 때 => arr[nr][nc] != 0

		r = nr;
		c = nc;
	}
	// 3. 출력
	for (int r = 0; r < size; ++r)
	{
		for (int c = 0; c < size; ++c)
		{
			cout << arr[r * size + c] << "\t";
		}
		cout << "\n";
	}
	delete[] arr;
}