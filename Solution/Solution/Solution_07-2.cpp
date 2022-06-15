#include <iostream>
#include <random>
#include <time.h>
#include <windows.h>
#include "Bingo.h"

// ������ �ľ��� ����
// �������� �������� �����Ѵ�.
// ���� ����� üũ�ؼ� ǥ�����ش�. 
// 
// �ذ� ���̵��
// �������� ������ �ڸ��� ���ڸ� ������� �ְ� ���� ���ڸ��� �ٸ� ���ڰ� ����ִٸ� �ٽ� �ڸ��� ã�´�.
// ���� �Ǹ� ������ ���� 0�� �ȴٴ°��� �̿��� �������� �� ������ ��� ���� üũ�ؼ� 0�̵Ǹ� ������ ī��Ʈ�� �ø���.

int main()
{
	srand(time(NULL));
	//������ ���� ����

	Bingo bingo;
	std::cout << "���� ũ�⸦ �Է��ϼ��� : ";
	int inputnum;
	std::cin >> inputnum;

	bingo.Make(inputnum);

	while (bingo.ShowBingo() != bingo.ShowBingoSize() * 2 + 2)
	{
		system("cls");
		// ������ ���
		bingo.Print();

		int inputNum = 0;
		std::cout << "���ڸ� �Է��� �ּ��� : ";
		std::cin >> inputNum;

		if (!bingo.Match(inputNum))
		{
			system("cls");
			continue;
		}

		// ���� üũ
		bingo.Check();
		
	}
	return 0;
}
