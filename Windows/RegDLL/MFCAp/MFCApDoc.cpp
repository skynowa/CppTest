// MFCApDoc.cpp : implementation of the CMFCApDoc class
//

#include "stdafx.h"
#include "MFCAp.h"

#include "MFCApDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMFCApDoc

IMPLEMENT_DYNCREATE(CMFCApDoc, CDocument)

BEGIN_MESSAGE_MAP(CMFCApDoc, CDocument)
	//{{AFX_MSG_MAP(CMFCApDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFCApDoc construction/destruction

CMFCApDoc::CMFCApDoc()
{
	// TODO: add one-time construction code here

}

CMFCApDoc::~CMFCApDoc()
{
}

BOOL CMFCApDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMFCApDoc serialization

void CMFCApDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CMFCApDoc diagnostics

#ifdef _DEBUG
void CMFCApDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFCApDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMFCApDoc commands
