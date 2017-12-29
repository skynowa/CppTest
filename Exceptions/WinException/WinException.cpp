#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

#include "CxWinException.h"
//---------------------------------------------------------------------------
int main() {
	try	{
        throw CxWinException(_T("i == 0"));
	} 
    catch (const CxWinException &e) {
		e.vMessageBox();

		throw;
	}

	return EXIT_SUCCESS;
}
//---------------------------------------------------------------------------
