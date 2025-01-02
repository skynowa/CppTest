/**
 * \file  CxWinException.cpp
 * \brief
 */


#include "CxWinException.h"

//--------------------------------------------------------------------------------------------------
CxWinException::CxWinException(
    LPCTSTR msg
) :
    m_err(::GetLastError()),
    m_msg(msg)
{
}
//--------------------------------------------------------------------------------------------------
/* virtual */
CxWinException::~CxWinException()
{
}
//--------------------------------------------------------------------------------------------------
LPCTSTR
CxWinException::What() const
{
	return m_msg;
}
//--------------------------------------------------------------------------------------------------
VOID
CxWinException::vMessageBox() const
{
	TCHAR buf1 [512] = {};
	TCHAR buf2 [512] = {};
	TCHAR buf3 [512] = {};

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
//--------------------------------------------------------------------------------------------------
