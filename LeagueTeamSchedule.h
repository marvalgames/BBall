#if !defined(AFX_LEAGUETEAMSCHEDULE_H__4400E861_4B1D_11D1_8C1C_44455354616F__INCLUDED_)
#define AFX_LEAGUETEAMSCHEDULE_H__4400E861_4B1D_11D1_8C1C_44455354616F__INCLUDED_

#ifndef Player_h
#include "Player.h"
#define Player_h
#endif 

#include "MyListCtrl.h"

#ifndef Average_h
#include "Average.h"	// Added by ClassView
#define Average_h
#endif

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#define HID_LEAGUE_TEAMS 12

// LeagueTeamSchedule.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLeagueTeamSchedule dialog

class CLeagueTeamSchedule : public CDialog
{
// Construction
public:
	CAverage avg;
	int m_default_team;
	CLeagueTeamSchedule(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLeagueTeamSchedule)
	enum { IDD = IDD_TEAM_SCHEDULE };
	CMyListCtrl	m_listSchedule;
	CMyComboBox	m_listTeam;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLeagueTeamSchedule)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLeagueTeamSchedule)
	virtual BOOL OnInitDialog();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnButtonPrint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnSelchangeComboListTeam();
	afx_msg void OnDblclkListCtrlTeamSch(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	int m_mo_list[100];
	int m_da_list[100];
	int m_ga_list[100];
	int m_v_list[100];
	CFont m_font;
	CString m_strings[201];
	void InitControls();
	CBrush myBrush;

	void SetPrintAlign(CDC *pDC, HDC hdcPrn);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LEAGUETEAMSCHEDULE_H__4400E861_4B1D_11D1_8C1C_44455354616F__INCLUDED_)
