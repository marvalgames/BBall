#if !defined(AFX_TIMEOUTDLG_H__BFB4B8A0_BED1_11D2_8E70_444553540000__INCLUDED_)
#define AFX_TIMEOUTDLG_H__BFB4B8A0_BED1_11D2_8E70_444553540000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
#define HID_GAME_TIMEOUTS 18

#include "MyButton.h"



// TimeoutDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTimeoutDlg dialog

class CTimeoutDlg : public CDialog
{
// Construction
public:
	int m_toOk;
	int m_pos;
	bool m_visitorTo;
	bool m_homeTo;
	bool m_visitorTo20;
	bool m_homeTo20;
	CString m_home;
	CString m_visitor;
	int m_toVisitor;
	int m_toHome;
	int m_toVisitor20;
	int m_toHome20;
	CTimeoutDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CTimeoutDlg)
	enum { IDD = IDD_DIALOG_TO };
	MyButton	m_buttonVisitor;
	MyButton	m_buttonHome;
	BOOL	m_checkTo20;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTimeoutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTimeoutDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonHome();
	afx_msg void OnButtonVisitor();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void DisableButtons();
	CBrush myBrush;
	void UpdateButtons();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TIMEOUTDLG_H__BFB4B8A0_BED1_11D2_8E70_444553540000__INCLUDED_)
