/**
 * \file
 * \brief
 *
 * \todo
 */


// MFCApView.cpp : implementation of the CMFCApView class
//

#include "stdafx.h"
#include "DLLCode.h"
#include "MFCAp.h"

#include "MFCApDoc.h"
#include "MFCApView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMFCApView

IMPLEMENT_DYNCREATE(CMFCApView, CView)

BEGIN_MESSAGE_MAP(CMFCApView, CView)
	//{{AFX_MSG_MAP(CMFCApView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFCApView construction/destruction

CMFCApView::CMFCApView()
{
	// TODO: add construction code here

}

CMFCApView::~CMFCApView()
{
}

BOOL CMFCApView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMFCApView drawing

void CMFCApView::OnDraw(CDC* pDC)
{
   // DLL MFC Library function call
   CRect rect;
   rect.top=10;
   rect.left=10;
   rect.right=200;
   rect.bottom=200;

   DrawEllipse(rect,pDC);

   // DLL class object call
   int a, b, c;
   CString str;
   Dllclass classFromDLL;

   classFromDLL.Arg = 6;   // Warming: you should not do this, sine
                           // the DLL object can be dynamically unloaded.

   a = classFromDLL.Add(3, 2);
   b = classFromDLL.Sub(3, 2);
   c = classFromDLL.Arg;

   int y = 250, dy;
   TEXTMETRIC tm;
   pDC->GetTextMetrics(&tm);
   dy = tm.tmHeight + tm.tmExternalLeading;

   str.Format("DLL class Add function return: %d", a);
   pDC->TextOut(20, y, str);
   y += dy;
   str.Format("DLL class Sub function return: %d", b);
   pDC->TextOut(20, y, str);
   y += dy;
   str.Format("DLL class Arg Variable return: %d", c);
   pDC->TextOut(20, y, str);
   y += dy;

   // DLL global function and variable call, Note: the DLLfun1 function
   // writes to a console, not a window, therefore, we should not call it!
   a = DLLArg;
   b = DLLfun2(30);

   str.Format("DLL class Arg Variable return: %d", a);
   pDC->TextOut(20, y, str);
   y += dy;
   str.Format("DLL function \"DLLfun2\" return: %d", b);
   pDC->TextOut(20, y, str);
}
/////////////////////////////////////////////////////////////////////////////
// CMFCApView printing

BOOL CMFCApView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFCApView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFCApView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMFCApView diagnostics

#ifdef _DEBUG
void CMFCApView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApDoc* CMFCApView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApDoc)));
	return (CMFCApDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMFCApView message handlers
