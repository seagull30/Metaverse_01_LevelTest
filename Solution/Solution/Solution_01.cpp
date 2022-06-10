#include <iostream>

// 문제를 파악한 내용
// 포인터와 래퍼런스로 각각 숫자 2개를 받아 두 값의 위치를 바꾼다.
// 
// 해결 아이디어
// 포인터는 널포인터도 받기 때문에 예외처리를 해줘야한다.
// 래퍼런스는 매개변수가 널포인터인지 확인을 해주기 때문에 예외처리를 안해주어도 된다.

void swap(int* a, int* b)
{
	if (a == NULL || b == NULL)
		return;
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void swap(int& a, int& b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

int main()
{

}