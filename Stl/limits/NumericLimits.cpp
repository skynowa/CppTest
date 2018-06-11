#include <assert.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <time.h>
#include <iostream>
//---------------------------------------------------------------------------
std::string Num2String(unsigned long Integral ) {
	std::string str;  //INT_MAX;

	str.resize(10, '\0');
	sprintf(&str[0], "%ld", Integral);
	str.resize( str.size() );

	return str;
}
//---------------------------------------------------------------------------
int main(int, char **) {
	std::string sStr = Num2String(320000);
	std::cout << "Num2String(320000):	" << sStr  << std::endl;

	return 0;
}
//---------------------------------------------------------------------------
