#include <iostream>

// ������ �ľ��� ����
// �迭�� �迭�� ũ�Ⱑ �Է� ������ ������ ������������ �����ؾ� �Ѵ�.
// 
// �ذ� ���̵��
// �迭�� ������ �迭�� ũ�⸦ ������ 2�� for���� ���� �迭�� ���ʰ� �������� ���ؼ� ū���� ��� �������� ������.
// 


void sortArray(int* arr, int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			if (arr[i] > arr[j])
			{
				int temp;
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}


int main()
{
	int arr[5] = { 5,2,4,1,3 };
	sortArray(arr, 5);	
}