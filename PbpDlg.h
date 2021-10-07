#if !defined(AFX_PBPDLG_H__AFCB3E80_E615_11D2_8E70_444553540000__INCLUDED_)
#define AFX_PBPDLG_H__AFCB3E80_E615_11D2_8E70_444553540000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#define HID_VIEW_SAVEDPBP 24

#include "MyListCtrl.h"

// PbpDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPbpDlg dialog

class CPbpDlg : public CDialog
{
// Construction
public:
	int m_default_team;
	CString m_fileName;
	CString m_leagueTeamNames[33];
	CPbpDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPbpDlg)
	enum { IDD = IDD_DIALOG_SAVEDPBP };
	CMyListCtrl	m_listGames;
	CMyComboBox	m_listTeams;
	CListBox	m_listPbp;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPbpDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPbpDlg)
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnButtonPrint();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnSelchangeComboListTeams();
	afx_msg void OnClickListCtrlGames(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void OnChangeGames();
	CFont m_font;
	void InitControls();
	void SetGames();
	CBrush myBrush;
	CBrush myBrush2;
	int m_games[10000];
	void SetPrintAlign(CDC *pDC, HDC hdcPrn);
public:
	afx_msg void OnLvnItemchangedListCtrlGames(NMHDR* pNMHDR, LRESULT* pResult);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PBPDLG_H__AFCB3E80_E615_11D2_8E70_444553540000__INCLUDED_)
