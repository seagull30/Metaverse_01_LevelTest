#include <iostream>
// ������ �ľ��� ����
// ���� 1������ ���� 3�� 5�� 1+2n�� ��ŭ �����Ѵ�.
// �տ� �����̽��ٴ� ���� �þ���� 1���� �پ���.
// �ذ� ���̵��
// for���� 2�����θ���� 1���� ������ ������ �����ش�.
// for�� 2���� ���� �����̽��� ���� ������ �Է����ش�.



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