/**
 * \file
 * \brief
 */


#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>

//---------------------------------------------------------------------------
void func(unsigned char []) {
	std::cout << "void func(unsigned char []) << \n";
}
//---------------------------------------------------------------------------
int main(void) {
	char* ptr = 0;
	func(reinterpret_cast<unsigned char*>(ptr));


	system("pause");
	return 0;
}
//---------------------------------------------------------------------------
