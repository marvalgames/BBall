#if !defined(AFX_LEADERSDLG_H__5D9CC301_7DF1_11D1_8C1C_44455354616F__INCLUDED_)
#define AFX_LEADERSDLG_H__5D9CC301_7DF1_11D1_8C1C_44455354616F__INCLUDED_

#ifndef Player_h
#include "Player.h"
#define Player_h
#endif 

//#ifndef SeasonStats_h
//#include "SeasonStats.h"	// Added by ClassView
//#define SeasonStats_h
//#endif 
#ifndef Average_h
#include "Average.h"
#define Average_h
#endif 




//#include "Average.h"	// Added by ClassView

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#define HID_LEAGUE_LEADERS 7
// leadersDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLeadersDlg dialog

class CLeadersDlg : public CDialog
{
// Construction
public:
	CAverage avg;
	CString m_leagueTeamNames[33];
	BOOL m_checkCareer;
	int m_hiGames;
	CString m_path;
	CString m_leagueName;
	int m_statType;
	int m_statStyle;
	CString m_sortPosition;
	CLeadersDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLeadersDlg)
	enum { IDD = IDD_LEADERSBOX };
	CListCtrl	m_listLeaders;
	MyButton	m_buttonLeaders;
	CListBox	m_listStats;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLeadersDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLeadersDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeListStats();
	afx_msg void OnRadioTeams();
	afx_msg void OnRadioPlayers();
	afx_msg void OnRadioActual();
	afx_msg void OnRadioSimulated();
	afx_msg void OnRadioAll();
	afx_msg void OnRadioSg();
	afx_msg void OnRadioSf();
	afx_msg void OnRadioPg();
	afx_msg void OnRadioPf();
	afx_msg void OnRadioC();
	afx_msg void OnRadioTeamsDefense();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnDestroy();
	afx_msg void OnRadioPlayoff();
	afx_msg void OnButtonReport();
	afx_msg void OnDoubleclickedButtonReport();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnDblclkListCtrlLeaders(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	int m_id_list[1601];
	CFont m_font;
	void InitControls();
	int m_team_hi_g[33];
	int m_po_team_hi_g[33];
	void ChooseStatsToList();
	bool SortFunction(CPlayer m_player, CPlayer temp);
	void QuickSort();
	void ListStats();
	bool SortSimulatedStats(CPlayer m_player, CPlayer temp);
	bool SortPlayoffStats(CPlayer m_player, CPlayer temp);
	bool SortActualStats(CPlayer m_player, CPlayer temp);
	CBrush myBrush;
	CBrush myBrush2;
	BOOL m_playersSelected;
	BOOL m_teamOffenseSelected;
	BOOL m_teamDefenseSelected;
	BOOL m_simulatedSelected;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LEADERSDLG_H__5D9CC301_7DF1_11D1_8C1C_44455354616F__INCLUDED_)

