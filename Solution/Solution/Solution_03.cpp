#include <iostream>
// 문제를 파악한 내용
// 별은 1개에서 부터 3개 5개 1+2n개 만큼 증가한다.
// 앞에 스페이스바는 열이 늘어날수로 1개씩 줄어든다.
// 해결 아이디어
// for문을 2중으로만들어 1차는 라인의 개수를 정해준다.
// for문 2개를 통해 스페이스와 별의 개수를 입력해준다.



int main()
{
	for (int line = 0; line < 5; ++line)
	{
		for (int spacebar = 4; spacebar - line > 0; --spacebar)
		{
			std::cout << " ";
		}
		for (int star = 0; star < 1 + (line * 2); ++star)
		{
			std::cout << "*";
		}
		std::cout << std::endl;
	}
}