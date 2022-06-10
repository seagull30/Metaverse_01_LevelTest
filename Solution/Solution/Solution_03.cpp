#include <iostream>

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