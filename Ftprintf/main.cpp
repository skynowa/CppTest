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

	bRes = bLogAppend(_T("C:\\Test.log"), _T("Операция успешно завершена.\n"));


	return 0;
}
//---------------------------------------------------------------------------

/*
Без установки текущей локали (VC++ 2008):
???????? ??????? ????????? 


С установкой текущей локали (VC++ 2008):
Операция успешно завершена.


С установкой текущей локали (CG++ 2010):
ЋЇҐа жЁп гбЇҐи­® § ўҐаиҐ­ .
*/
