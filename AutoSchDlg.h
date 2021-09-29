#if !defined(AFX_AUTOSCHDLG_H__37175E20_06B2_11D3_8E70_444553540000__INCLUDED_)
#define AFX_AUTOSCHDLG_H__37175E20_06B2_11D3_8E70_444553540000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#define HID_AUTO_SCHEDULE 36
// AutoSchDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAutoSchDlg dialog

class CAutoSchDlg : public CDialog
{
// Construction
public:
	int teams;
	CString m_division[33];
	CString m_conference[33];
	CString m_conferenceName1;
	CString m_conferenceName2;
	CString m_divisionName1;
	CString m_divisionName2;
	CString m_divisionName3;
	CString m_divisionName4;
	CString m_leagueTeamNames[33];

	int m_currentDay;
	int m_currentMonth;
	int m_sch[14][33][17];
	CAutoSchDlg(CWnd* pParent = NULL);   // standard constructor
	CString m_leagueName;
	CString m_path;

// Dialog Data
	//{{AFX_DATA(CAutoSchDlg)
	enum { IDD = IDD_DIALOG_AUTOSCHEDULE };
	CListBox	m_listOtherConf;
	CListBox	m_listDiv;
	CListBox	m_listOther;
	CListBox	m_listConf;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAutoSchDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAutoSchDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnButtonCreate();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CBrush myBrush;
	CBrush myBrush2;
	bool m_unable;
	int m_seasonGames;
	void ScrambleTeams();
	void SetSchedule();
	int m_gamesPlayed[33];
	void SetOtherGames();
	void CreateDivisionMatchups(int m_divisionTeams, int division);
	void CreateOtherDivisionMatchups(int division1Teams, int division2Teams, int division1, int division2);
	void CreateOtherConferenceMatchups(int division1Teams, int division2Teams, int division1, int division2);
	int  IntRandom(int n);


	int m_schedule[3651];
	int m_currentGame;
	void CreateTables();
	int m_divisionTable[5][33];
	int m_conferenceTable[3][33];
	void SetListBoxes();
	void LoadLeagueFormat();
	int m_division1Teams;
	int m_division2Teams;
	int m_division3Teams;
	int m_division4Teams;
	int m_conference1Teams;
	int m_conference2Teams;

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AUTOSCHDLG_H__37175E20_06B2_11D3_8E70_444553540000__INCLUDED_)
