/**
 * \file  WinException.cpp
 * \brief
 */


#include <StdStream.h>
#include <StdTest.h>
#include <Stl.h>

#include "CxWinException.h"
//--------------------------------------------------------------------------------------------------
int main(int, char **)
{
	try	{
        throw CxWinException(_T("i == 0"));
	}
    catch (const CxWinException &e) {
		e.vMessageBox();

		throw;
	}

	return EXIT_SUCCESS;
}
//--------------------------------------------------------------------------------------------------
