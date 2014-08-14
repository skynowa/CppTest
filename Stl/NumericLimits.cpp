#include <windows.h>
#include <assert.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <assert.h>
#include <dos.h>
#include <math.h>
#include <time.h>
#include <iostream>

#include <XLib/NumericLimits.h>
//---------------------------------------------------------------------------
std::string Num2String(ULONG Integral ) {
	std::string str;  //INT_MAX;

	str.resize(10, '\0');
	sprintf(&str[0], "%u", Integral);
	str.resize(strlen(str.c_str()));

	return str; 
}
//---------------------------------------------------------------------------
int main(int argc, char* argv[]) {
	bCheckNumericLimits();



	std::string sStr = Num2String(320000);
	//std::cout << "Num2String(320000):	" << sStr  << std::endl;
	

	system("pause");

	return 0;
}
//---------------------------------------------------------------------------




