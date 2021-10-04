#if !defined(AFX_ABOUTDLG1_H__0F83BEEF_93C9_420F_8DA4_8960C3A48BB4__INCLUDED_)
#define AFX_ABOUTDLG1_H__0F83BEEF_93C9_420F_8DA4_8960C3A48BB4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AboutDlg1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg1 dialog

#include "MyButton.h"

class CAboutDlg1 : public CDialog
{
// Construction
public:
	CAboutDlg1(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAboutDlg1)
	enum { IDD = IDD_ABOUTBOX };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg1)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CBrush myBrush;	
	// Generated message map functions
	//{{AFX_MSG(CAboutDlg1)
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonWeb();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
private:
	MyButton m_btnWeb;
public:
	MyButton m_btnOk;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ABOUTDLG1_H__0F83BEEF_93C9_420F_8DA4_8960C3A48BB4__INCLUDED_)
