// RDLLMFC.h : main header file for the RDLLMFC DLL
//

#if !defined(AFX_RDLLMFC_H__B7D99F2A_4953_4D09_AA45_4E03770B4C9D__INCLUDED_)
#define AFX_RDLLMFC_H__B7D99F2A_4953_4D09_AA45_4E03770B4C9D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CRDLLMFCApp
// See RDLLMFC.cpp for the implementation of this class
//

class CRDLLMFCApp : public CWinApp
{
public:
	CRDLLMFCApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRDLLMFCApp)
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CRDLLMFCApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RDLLMFC_H__B7D99F2A_4953_4D09_AA45_4E03770B4C9D__INCLUDED_)
