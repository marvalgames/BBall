#if !defined(AFX_MYCOMBOBOX_H__F1E4EF09_C2EC_4523_A710_8F8CC8EAF94E__INCLUDED_)
#define AFX_MYCOMBOBOX_H__F1E4EF09_C2EC_4523_A710_8F8CC8EAF94E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "MyComboBox.h"

// MyComboBox.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMyComboBox window

class CMyComboBox : public CComboBox
{
// Construction
public:
	CMyComboBox();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyComboBox)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMyComboBox();

	// Generated message map functions
protected:

	CBrush m_BkBrush;


	//{{AFX_MSG(CMyComboBox)
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYCOMBOBOX_H__F1E4EF09_C2EC_4523_A710_8F8CC8EAF94E__INCLUDED_)
