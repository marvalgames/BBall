#if !defined(AFX_SCHEDULEDLG_H__3F374B41_432E_11D1_8C1C_44455354616F__INCLUDED_)
#define AFX_SCHEDULEDLG_H__3F374B41_432E_11D1_8C1C_44455354616F__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000




#ifndef Average_h
#include "Average.h"
#define Average_h
#endif 
 #include "MyButton.h"


#define HID_LEAGUE_SCHEDULE 9
// ScheduleDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CScheduleDlg dialog

class CScheduleDlg : public CDialog
{
// Construction
public:
	CAverage avg;
	bool m_start_playoff_clicked;

	bool m_playoffJustStarted;
	BOOL m_resetStats;
	BOOL m_seasonStarted;
	bool m_seasonOver;
	BOOL m_swapOk;
	int m_swapIndex;
	CString m_swapTeam;
	int m_schedule[14][32][17];
	CString m_leagueTeamNames[33];
	CScheduleDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CScheduleDlg)
	enum { IDD = IDD_SCHEDULEBOX };
	MyButton	m_button_reset;
	MyButton	m_button[2];
	CMyComboBox	m_scheduleMonth;
	CMyComboBox	m_scheduleDay;
	MyButton	m_buttonAuto;
	MyButton	m_buttonRemove;
	MyButton	m_buttonAddVisitor;
	MyButton	m_buttonAddHome;
	CListBox	m_scheduleVisitor;
	CListBox	m_scheduleTeam;
	CListBox	m_scheduleHome;
	CString	m_leagueName;
	CString	m_edit_text;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScheduleDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CScheduleDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonAddHome();
	afx_msg void OnButtonRemove();
	afx_msg void OnSelchangeListHome();
	afx_msg void OnSelchangeListVisitor();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnButtonReset();
	afx_msg void OnButtonAddVisitor();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnButtonAutosch();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnDblclkListControl();
	afx_msg void OnSelchangeListMonth();
	afx_msg void OnSelchangeListDay();
	afx_msg void OnDblclkListVisitorScore();
	afx_msg void OnDblclkListHomeScore();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CBrush myBrush;
	CBrush myBrush2;
//	MyButtonST *m_playoffStart;
	int day;//used to save schedule to correct date when 
	int month;//selection in day or month list box is changed
//	int m_schedule[13][32][17];
//	CString m_leagueTeamNames[33];
	struct TEAM
	{
		CString Name;
		int Number;
	};
	
	void CScheduleDlg::SeasonEnd();


	TEAM m_leagueTeam[33];
	BOOL m_listHome;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCHEDULEDLG_H__3F374B41_432E_11D1_8C1C_44455354616F__INCLUDED_)







