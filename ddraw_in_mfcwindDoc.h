// ddraw_in_mfcwindDoc.h : interface of the CDdraw_in_mfcwindDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DDRAW_IN_MFCWINDDOC_H__A163EEBC_57D4_4F6F_91AB_5A17ED833225__INCLUDED_)
#define AFX_DDRAW_IN_MFCWINDDOC_H__A163EEBC_57D4_4F6F_91AB_5A17ED833225__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDdraw_in_mfcwindDoc : public CDocument
{
protected: // create from serialization only
	CDdraw_in_mfcwindDoc();
	DECLARE_DYNCREATE(CDdraw_in_mfcwindDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDdraw_in_mfcwindDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDdraw_in_mfcwindDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDdraw_in_mfcwindDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DDRAW_IN_MFCWINDDOC_H__A163EEBC_57D4_4F6F_91AB_5A17ED833225__INCLUDED_)
