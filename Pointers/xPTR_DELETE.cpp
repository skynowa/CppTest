/****************************************************************************
* Class name:  Test
* Description: 
* File name:   Test.h
* Compilers:   Visual C++ 2010 
* String type: Ansi, Unicode
* Libraries:   WinAPI, Stl, XLib
* Author:      Alca
* E-mail:      dr.web.agent@gmail.com
* Created:     01.12.2010 11:39:05
* Version:     1.0.0.0 Debug
*
*****************************************************************************/


#include <XLib/xCommon.h>

#include <string>
#include <stdio.h>
#include <sstream>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <iterator>
#include <utility>
#include <ctime>
//---------------------------------------------------------------------------
template<class T>
inline void deletePtr_with_ref(T*& a_ptr) {
    delete a_ptr;
    a_ptr = 0;
}
//---------------------------------------------------------------------------
template<class T>
inline void deletePtr_without_ref(T* a_ptr) {
    delete a_ptr;
    a_ptr = 0;
}
//---------------------------------------------------------------------------
void func() {
	{
		int *ptr = new int; //ptr указывает на выделенную под int память
		deletePtr_with_ref(ptr); //после этого память выделенная под int освобождена, и ptr нулевой
		xASSERT(NULL == ptr);

		if (ptr) {
			*ptr = 42; //WIN управление сюда никогда не передаётся
		}
	}

	{
		int *ptr = new int; //ptr указывает на выделенную под int память
		xASSERT(NULL != ptr);

		deletePtr_without_ref(ptr); //после этого память выделенная под int освобождена, но ptr продолжает указывать на этот участок памяти
		xASSERT(NULL != ptr);

		if (ptr) {
			*ptr = 42; //FAIL ты обращаешься к памяти которая не выделена
		}
	}

}
//---------------------------------------------------------------------------
INT _tmain(INT iArgc, TCHAR *pszArgv[]) {
	func();

	system("pause");
	return 0;
}
//---------------------------------------------------------------------------
