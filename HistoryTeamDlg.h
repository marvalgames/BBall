#if !defined(AFX_HISTORYTEAMDLG_H__316EFB00_38B1_11D3_8E70_B01EC6B9A25C__INCLUDED_)
#define AFX_HISTORYTEAMDLG_H__316EFB00_38B1_11D3_8E70_B01EC6B9A25C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#define HID_HISTORY_TEAM 34
// HistoryTeamDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CHistoryTeamDlg dialog

class CHistoryTeamDlg : public CDialog
{
// Construction
public:
	int m_default_team;

	CString m_leagueTeamNames[33];
	CString m_leagueName;
	CString m_path;
	CHistoryTeamDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CHistoryTeamDlg)
	enum { IDD = IDD_DIALOG_TEAMHISTORY };
	CMyComboBox	m_listTeams;
	CListBox	m_listRings;
	CListBox	m_listHistory;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHistoryTeamDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CHistoryTeamDlg)
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnSelchangeComboTeams();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CBrush myBrush;
	CBrush myBrush2;
	void FillHistory();
	void ListTeams();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HISTORYTEAMDLG_H__316EFB00_38B1_11D3_8E70_B01EC6B9A25C__INCLUDED_)
