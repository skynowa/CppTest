#include <windows.h>
#include <tchar.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <assert.h>
//---------------------------------------------------------------------------
BOOL bLogAppend(LPCTSTR pcszFilePath, LPCTSTR pcszText) {
	assert(NULL != pcszFilePath);
	assert(NULL != pcszText);

	_tsetlocale(LC_ALL, _T(""));

	FILE *pFile = _tfopen(pcszFilePath, _T("a"));
	assert(NULL != pFile);

	_ftprintf(pFile, _T("%s"), pcszText);

	fclose(pFile);	
	pFile = NULL;

	return TRUE;
}
//---------------------------------------------------------------------------
INT _tmain(INT argc, TCHAR *argv[]) {
	BOOL bRes = FALSE;

	bRes = bLogAppend(_T("C:\\Test.log"), _T("�������� ������� ���������.\n"));


	return 0;
}
//---------------------------------------------------------------------------

/*
��� ��������� ������� ������ (VC++ 2008):
???????? ??????? ????????? 


� ���������� ������� ������ (VC++ 2008):
�������� ������� ���������.


� ���������� ������� ������ (CG++ 2010):
������ �ᯥ譮 �����襭�.
*/
