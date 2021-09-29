#if !defined(AFX_FORMVIEWEX_H__833A3815_CD4B_47AD_9AEF_55091D0E7037__INCLUDED_)
#define AFX_FORMVIEWEX_H__833A3815_CD4B_47AD_9AEF_55091D0E7037__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FormViewEx.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFormViewEx form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CFormViewEx : public CFormView
{
protected:
	CFormViewEx();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CFormViewEx)

// Form Data
public:
	//{{AFX_DATA(CFormViewEx)
	enum { IDD = IDD_FORMVIEW };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFormViewEx)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CFormViewEx();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CFormViewEx)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FORMVIEWEX_H__833A3815_CD4B_47AD_9AEF_55091D0E7037__INCLUDED_)
