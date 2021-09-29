#if !defined(AFX_TEAMSDLG_H__667E9701_03F8_11D1_8C1C_44455354616F__INCLUDED_)
#define AFX_TEAMSDLG_H__667E9701_03F8_11D1_8C1C_44455354616F__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
#define HID_TEAMS_BOX 13

// TeamsDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTeamsDlg dialog

class CTeamsDlg : public CDialog
{
// Construction
private:
	CBrush myBrush;
public:
	CString m_leagueTeamNames[33];
	CString m_path;
	CString m_visitor;
	CString m_home;
	CString m_leagueName;
	CTeamsDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CTeamsDlg)
	enum { IDD = IDD_TEAMSBOX };
	CMyComboBox	m_listTeamsVisitor;
	CMyComboBox	m_listTeamsHome;
	CString	m_currentLeague;
	BOOL	m_computerControlHome;
	BOOL	m_computerControlVisitor;
	BOOL	m_homeCourt;
	BOOL	m_swap;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTeamsDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTeamsDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEAMSDLG_H__667E9701_03F8_11D1_8C1C_44455354616F__INCLUDED_)
