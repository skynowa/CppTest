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
		int *ptr = new int; //ptr ��������� �� ���������� ��� int ������
		deletePtr_with_ref(ptr); //����� ����� ������ ���������� ��� int �����������, � ptr �������
		xASSERT(NULL == ptr);

		if (ptr) {
			*ptr = 42; //WIN ���������� ���� ������� �� ���������
		}
	}

	{
		int *ptr = new int; //ptr ��������� �� ���������� ��� int ������
		xASSERT(NULL != ptr);

		deletePtr_without_ref(ptr); //����� ����� ������ ���������� ��� int �����������, �� ptr ���������� ��������� �� ���� ������� ������
		xASSERT(NULL != ptr);

		if (ptr) {
			*ptr = 42; //FAIL �� ����������� � ������ ������� �� ��������
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
