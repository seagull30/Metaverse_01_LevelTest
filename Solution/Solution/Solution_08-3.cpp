#include <iostream>
#include "Snail.h"
using namespace std;

int main()
{

	// 1. 배열 만들기
	cout << "배열의 크기를 입력하세요 : ";
	int size;
	cin >> size;

	Snail snail;

	// 2. 달팽이 배열 세팅
	snail.Make(size);
	// 2-1. 달팽이 데이터 초기화
	
	snail.move();
	
	// 3. 출력
	snail.print();
	
}