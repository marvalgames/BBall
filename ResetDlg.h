#if !defined(AFX_RESETDLG_H__638AA720_F510_11D4_B185_444553540000__INCLUDED_)
#define AFX_RESETDLG_H__638AA720_F510_11D4_B185_444553540000__INCLUDED_

#ifndef TeamFinancial_h
#include "TeamFinancial.h"
#define TeamFinancial_h
#endif 

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ResetDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CResetDlg dialog

class CResetDlg : public CDialog
{
// Construction
public:
	CString m_franchise_path;
	CTeamFinancial m_finance[101];
	int m_action;
	CString m_path;
	CString m_league_name;
	CResetDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CResetDlg)
	enum { IDD = IDD_DIALOG_RESET };
	CString	m_edit_name;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CResetDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CResetDlg)
	afx_msg void OnRadioDefault();
	afx_msg void OnRadioCurrent();
	afx_msg void OnRadioRandom();
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	afx_msg void OnRadioImport();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RESETDLG_H__638AA720_F510_11D4_B185_444553540000__INCLUDED_)
