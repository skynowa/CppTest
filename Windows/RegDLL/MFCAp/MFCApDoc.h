/**
 * \file  MFCApDoc.h
 * \brief
 */


// MFCApDoc.h : interface of the CMFCApDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MFCAPDOC_H__5EBFFE9E_4FB9_4020_8DFF_D350C233AE92__INCLUDED_)
#define AFX_MFCAPDOC_H__5EBFFE9E_4FB9_4020_8DFF_D350C233AE92__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMFCApDoc : public CDocument
{
protected: // create from serialization only
	CMFCApDoc();
	DECLARE_DYNCREATE(CMFCApDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCApDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMFCApDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMFCApDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCAPDOC_H__5EBFFE9E_4FB9_4020_8DFF_D350C233AE92__INCLUDED_)
