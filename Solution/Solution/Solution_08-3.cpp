#include <iostream>
#include "Snail.h"
using namespace std;

int main()
{

	// 1. �迭 �����
	cout << "�迭�� ũ�⸦ �Է��ϼ��� : ";
	int size;
	cin >> size;

	Snail snail;

	// 2. ������ �迭 ����
	snail.Make(size);
	// 2-1. ������ ������ �ʱ�ȭ
	
	snail.move();
	
	// 3. ���
	snail.print();
	
}