/**
 * \file  CxWinException.h
 * \brief
 */


#pragma once

#include <windows.h>
#include <tchar.h>
//--------------------------------------------------------------------------------------------------
class CxWinException
{
public:
			 CxWinException(LPCTSTR msg);
	virtual ~CxWinException();

	LPCTSTR  What() const;
	VOID     vMessageBox() const;

private:
	DWORD    m_err;
	LPCTSTR  m_msg;
};
//--------------------------------------------------------------------------------------------------
