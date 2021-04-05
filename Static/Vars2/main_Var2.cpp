/**
 * \file
 * \brief
 *
 * \todo
 */


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


#include <StdTest.h>

#include "CxVars.h"
#include "module.h"

//---------------------------------------------------------------------------
int main(int, char **) {
	{
		some_func();
		CxVars::m_Var;
	}

	return 0;
}
//---------------------------------------------------------------------------
