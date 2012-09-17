/****************************************************************************
* Class name:  CxWinException
* Description: 
* File name:   CxWinException.cpp
* Compilers:   Visual C++ 2010 
* String type: Ansi, Unicode
* Libraries:   WinAPI, Stl, XLib
* Author:      Alca
* E-mail:      dr.web.agent@gmail.com
* Created:     10.08.2010 9:50:30
* Version:     1.0.0.0 Debug
*
*****************************************************************************/


#include "CxWinException.h"


/****************************************************************************
*    Public methods                                                          
*                                                                            
*****************************************************************************/

//---------------------------------------------------------------------------
//TODO: - CxWinException (comment)
CxWinException::CxWinException(LPCTSTR msg) :
	m_err(::GetLastError()), 
	m_msg(msg)
{
	//code
}
//---------------------------------------------------------------------------
//TODO: - ~CxWinException (comment)
/*virtual*/
CxWinException::~CxWinException() {
	//code
}
//---------------------------------------------------------------------------
//TODO: - What ()
LPCTSTR CxWinException::What()  const {
	/*DEBUG*/

	return m_msg;
}
//---------------------------------------------------------------------------
//TODO: - vMessageBox ()
VOID CxWinException::vMessageBox() const {
	/*DEBUG*/

	TCHAR buf1 [512] = _T("");
	TCHAR buf2 [512] = _T("");
	TCHAR buf3 [512] = _T("");

	::lstrcpy(buf1, m_msg);

	// Display Last Error information if it's useful
	if (m_err != 0) {
		DWORD dwFlags = FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS;
		::FormatMessage(
			dwFlags, NULL, m_err,
			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), buf2, 512, NULL);

		::wsprintf(buf3, _T("%s\n\n     %s\n\n"), buf1, buf2);
	} else {
		::wsprintf(buf3, _T("%s"), buf1);
	}

	::MessageBox(0, buf3, _T("CxWinException"), MB_OK | MB_ICONERROR);
}
//---------------------------------------------------------------------------
