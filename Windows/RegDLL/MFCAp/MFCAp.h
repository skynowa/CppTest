/**
 * \file
 * \brief
 *
 * \todo
 */


// MFCAp.h : main header file for the MFCAP application
//

#if !defined(AFX_MFCAP_H__F8A2F375_03A4_466C_8233_89303292E1F3__INCLUDED_)
#define AFX_MFCAP_H__F8A2F375_03A4_466C_8233_89303292E1F3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMFCApApp:
// See MFCAp.cpp for the implementation of this class
//

class CMFCApApp : public CWinApp
{
public:
	CMFCApApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCApApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMFCApApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCAP_H__F8A2F375_03A4_466C_8233_89303292E1F3__INCLUDED_)
