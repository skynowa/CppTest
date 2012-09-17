#include <windows.h>
#include <tchar.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
//---------------------------------------------------------------------------
BOOL bLogAppend(LPCTSTR pcszFilePath, LPCTSTR pcszText) {
	/*CHECK*/

	FILE *pFile = _tfopen(pcszFilePath, _T("a"));
	if (NULL == pFile) {
		return FALSE;
	}

	__try {
		SYSTEMTIME stST = {0};
		::GetLocalTime(&stST);

		_ftprintf(
			pFile, 
			_T("[%d:%d:%d]  %s\n---------------------------------------------------------------------------\n\n"), 
			stST.wHour, stST.wMinute, stST.wSecond, pcszText
		);
	}
	__finally {
		if (NULL != pFile) {
			fclose(pFile);	pFile = NULL;
		}
	}
	
	return TRUE;
}
//---------------------------------------------------------------------------
INT _tmain(INT argc, TCHAR *argv[]) {
	_tsetlocale (LC_ALL, _T(""));

	bLogAppend(_T("C:\\Test.log"), _T("Текст"));

	return 0;
}
//---------------------------------------------------------------------------
