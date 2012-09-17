/****************************************************************************
*	[...тест...]
*
*****************************************************************************/


#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>

#include <XLib/Debug/CXAssert.h>
//---------------------------------------------------------------------------
BOOL                            g_bRes    = FALSE;
INT                             g_iRes    = - 1;
UINT                            g_uiRes   = 0;
ULONG                           g_ulRes   = 0;
ULONGLONG                       g_ullRes  = 0UL;
HANDLE                          g_hRes    = INVALID_HANDLE_VALUE;
HWND                            g_hwndRes = NULL;
tstring                         g_sRes;
std::vector<tstring>            g_vecsRes; 
std::map<tstring, tstring>      g_mapsRes;
std::multimap<tstring, tstring> g_mmsRes; 
//---------------------------------------------------------------------------
int incPre(int &i) {
	i = i + 1; //увеличиваем переменную на 1
	return i;   //возвращаем новое значение
}
int incPos(int &i) {
	int r = i;  //сохраняем исходное значение
	i = i + 1; //увеличиваем переменную на 1
	return r;  //возвращаем старое значение
}
//---------------------------------------------------------------------------
INT main(int argc, char* argv[]) {
	int i = 1;
	int x = 0;

	x = ++i; //результат: x = 2, i = 2
	tcout << std::endl;


	i = 1;
	x = i++; //результат: x = 1, i = 2
	tcout << std::endl;


	i = 1;
	x = ++i; //результат: x = 2, i = 2
	tcout << std::endl;



    tcout << std::endl << std::endl;
	//system("pause");
	return 0;
}
//---------------------------------------------------------------------------