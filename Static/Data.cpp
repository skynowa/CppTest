#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>


static char g_sBuff_1[10] = {0};
static char g_sBuff_2[10];


void vTest()
{
    static char szBuff_1[10 + 1] = {0};
    static char szBuff_2[10 + 1];

    std::cout << "szBuff_1: " << szBuff_1 << std::endl;
    std::cout << "szBuff_2: " << szBuff_2 << std::endl;
}
//---------------------------------------------------------------------------
int main(int, char **) {
    static char _szBuff_1[10 + 1] = {0};
    static char _szBuff_2[10 + 1];

    vTest();



    std::cout << "g_sBuff_1: " << g_sBuff_1 << std::endl;
    std::cout << "g_sBuff_2: " << g_sBuff_2 << std::endl;
    std::cout << "_szBuff_1: " << _szBuff_1 << std::endl;
    std::cout << "_szBuff_2: " << _szBuff_2 << std::endl;



	system("pause");
	return 0;
}
//---------------------------------------------------------------------------
