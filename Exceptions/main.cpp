#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

#include "CxWinException.h"
//---------------------------------------------------------------------------
int _tmain(int argc, TCHAR *argv[]) {
	try	{
		INT i = 0;

		i = 10;

		if (10 == i) {
			throw CxWinException(_T("i == 0"));
		}
	} catch (const CxWinException &e) {
		// Indicate the problem
		e.vMessageBox();
		throw;
	}

	system("pause");
	return 0;
}
//---------------------------------------------------------------------------
