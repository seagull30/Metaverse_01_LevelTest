#include <iostream>


void swap(int* a, int* b)
{
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

void printMultiplierOf3()
{
	int i = 3;
	while (i < 1000)
	{
		std::cout << i << " ";
		i *= 3;
	}
	std::cout << std::endl;
}


int main()
{
	printMultiplierOf3();
}
