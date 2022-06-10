#include <iostream>

// 문제를 파악한 내용
// 1000보다 작은 3의 승수를 출력한다.
// 
// 해결 아이디어
// i의 값을 3부터 시작해서 3을 곱하면서 출력한다.
// 


void main()
{
	int i = 3;
	while (i < 1000)
	{
		std::cout << i << " ";
		i *= 3;
	}
}