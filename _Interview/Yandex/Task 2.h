// Напишите код, преобразующий 32-битное целочисленное представление ip-адреса в строковое.
// http://forum.vingrad.ru/forum/topic-365389.html

#include <sstream>
#include <conio.h>
#include <iostream>

void main() 
{
	std::stringstream result;
	const std::string ip = "10101100000100000010111101011110";
	const unsigned int size = ip.size();

	if(32 == size)
	{
		unsigned int number = 0;
		for(unsigned int h=7, i=0; i<size; ++i, --h)
		{
			char ch = ip[i];
			number += (atoi(&ch) << h);			
			
			if(0 == h)
			{
				result << number;	
				if(i != size - 1) result << '.';
				
				number = 0;
				h = 8;
			}
		}				
	}

	std::cout << result.str();
	_getch();
}

