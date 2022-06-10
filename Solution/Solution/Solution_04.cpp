#include <iostream>

// 문제를 파악한 내용
// 배열과 배열의 크기가 입력 값으로 들어오고 오름차순으로 정렬해야 한다.
// 
// 해결 아이디어
// 배열이 들어오면 배열의 크기를 가지고 2중 for문을 통해 배열의 왼쪽과 오른쪽을 비교해서 큰값을 계속 오른쪽을 보낸다.
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