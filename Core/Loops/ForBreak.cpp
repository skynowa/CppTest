/**
 * \file
 * \brief
 *
 * \todo
 */


#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

//---------------------------------------------------------------------------
int main(int, char **) {

	for (int i = 0; i < 100; ++ i) {
		{
			{
				if (50 == i) {
					break;
				}
				std::cout << "break 1" << std::endl;
			}
			std::cout << "break 2" << std::endl;
		}
		std::cout << "break 3" << std::endl;
	}

	std::cout << "end" << std::endl;
	system("pause");
	return 0;
}
//---------------------------------------------------------------------------
