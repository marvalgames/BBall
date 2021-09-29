#if !defined(AFX_FORMVIEWX_H__3D31819E_2F4E_48FD_AE52_D7240310453B__INCLUDED_)
#define AFX_FORMVIEWX_H__3D31819E_2F4E_48FD_AE52_D7240310453B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FormViewX.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFormViewX form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CFormViewX : public CFormView
{
protected:
	CFormViewX();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CFormViewX)

// Form Data
public:
	//{{AFX_DATA(CFormViewX)
	enum { IDD = IDD_FORMVIEW };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFormViewX)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CFormViewX();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CFormViewX)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FORMVIEWX_H__3D31819E_2F4E_48FD_AE52_D7240310453B__INCLUDED_)
