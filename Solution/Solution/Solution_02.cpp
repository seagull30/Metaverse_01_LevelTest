#include <iostream>

void main()
{
	int i = 3;
	while (i < 1000)
	{
		std::cout << i << " ";
		i *= 3;
	}
}