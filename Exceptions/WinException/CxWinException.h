/****************************************************************************
* Class name:  CxWinException
* Description: 
* File name:   CxWinException.h
* Compilers:   Visual C++ 2010 
* String type: Ansi, Unicode
* Libraries:   WinAPI, Stl, XLib
* Author:      Alca
* E-mail:      dr.web.agent@gmail.com
* Created:     10.08.2010 9:50:30
* Version:     1.0.0.0 Debug
*
*****************************************************************************/


#ifndef CxWinExceptionH
#define CxWinExceptionH
//---------------------------------------------------------------------------
#include <windows.h>
#include <tchar.h>
//---------------------------------------------------------------------------
class CxWinException {
	public:
				 CxWinException(LPCTSTR msg);
		virtual ~CxWinException();

		LPCTSTR  What          () const;
		VOID     vMessageBox   () const;

	private:
		DWORD    m_err;
		LPCTSTR  m_msg;
};
//---------------------------------------------------------------------------
#endif //CxWinExceptionH
