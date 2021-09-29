#if !defined(AFX_IMPORTDLG_H__B7A713E9_69A8_11D5_B185_D8F04BB93838__INCLUDED_)
#define AFX_IMPORTDLG_H__B7A713E9_69A8_11D5_B185_D8F04BB93838__INCLUDED_

#ifndef Average_h
#include "Average.h"
#define Average_h
#endif 


#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ImportDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CImportDlg dialog

class CImportDlg : public CDialog
{
// Construction
public:
	CString m_path;
	CString m_league_name;
	CString m_full_path;
	int m_year;
	CAverage avg;
	CImportDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CImportDlg)
	enum { IDD = IDD_DIALOG_IMPORT };
	BOOL	m_check_adjust;
	BOOL	m_check_random;
	BOOL	m_check_database;
	UINT	m_draft_year;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CImportDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CImportDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnButtonImport();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	int ReadDraftSpreadSheet();
	CBrush myBrush; 
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IMPORTDLG_H__B7A713E9_69A8_11D5_B185_D8F04BB93838__INCLUDED_)
