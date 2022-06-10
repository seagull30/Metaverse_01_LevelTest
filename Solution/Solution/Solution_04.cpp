#include <iostream>


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