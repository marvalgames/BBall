#if !defined(AFX_PROGRESSDLG1_H__246F52C1_40DA_11D3_8E70_444553540000__INCLUDED_)
#define AFX_PROGRESSDLG1_H__246F52C1_40DA_11D3_8E70_444553540000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ProgressDlg1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CProgressDlg dialog



class CProgressDlg : public CDialog
{
// Construction
public:
	CString m_text;
//	CString m_text;
	CProgressDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CProgressDlg)
	enum { IDD = 288 };
	CEdit	m_editText;
	CProgressCtrl	m_progress;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProgressDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CProgressDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROGRESSDLG1_H__246F52C1_40DA_11D3_8E70_444553540000__INCLUDED_)
