// MFCApView.h : interface of the CMFCApView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MFCAPVIEW_H__30953B6F_AD03_420B_883F_F27405A15A9E__INCLUDED_)
#define AFX_MFCAPVIEW_H__30953B6F_AD03_420B_883F_F27405A15A9E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMFCApView : public CView
{
protected: // create from serialization only
	CMFCApView();
	DECLARE_DYNCREATE(CMFCApView)

// Attributes
public:
	CMFCApDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCApView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMFCApView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMFCApView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MFCApView.cpp
inline CMFCApDoc* CMFCApView::GetDocument()
   { return (CMFCApDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCAPVIEW_H__30953B6F_AD03_420B_883F_F27405A15A9E__INCLUDED_)
