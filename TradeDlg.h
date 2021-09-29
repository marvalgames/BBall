#if !defined(AFX_TRADEDLG_H__DB72BEE3_3F8B_11D2_8C1C_FB2DA1E39583__INCLUDED_)
#define AFX_TRADEDLG_H__DB72BEE3_3F8B_11D2_8C1C_FB2DA1E39583__INCLUDED_

#include "ProgressDlg1.h"
#include "MyComboBox.h"

#ifndef Future_h
#include "Future.h"
#define Future_h
#endif 

#ifndef Staff_h
#include "Staff.h"
#define Staff_h
#endif 

#ifndef Player_h
#include "Player.h"
#define Player_h
#endif 


    

//#ifndef SeasonStats_h
//#include "SeasonStats.h"
//#define SeasonStats_h
//#endif 
//#include "SeasonStats.h"
#include "TradeDlg.h"
#ifndef Average_h
#include "Average.h"
#define Average_h
#endif 

#ifndef Own_h
#include "Own.h"	// Added by ClassView
#define Own_h
#endif

//#include "Average.h"	// Added by ClassView

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
#define HID_LEAGUE_TRADE 14

#ifndef XListCtrl_h
//#include "XListCtrl/XListCtrl.h"
#define XListCtrl_h
#endif 

#include "MyButton.h"
#include "afxlistctrl.h"
// TradeDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTradeDlg dialog

class CTradeDlg : public CDialog
{
// Construction
public:
	int m_slot_used[3][33];
	int m_player_list[11];
	 
	int m_draftround;
	int m_draftpick;
	bool m_off_season;
//	CRecord* m_standings;
	int m_cap;
	int m_current_stage;
	BOOL m_salaries_match;
	int m_current_year;
	COwn m_own[33];
	BOOL m_ast_gm;
	int m_default_team;
	CAverage avg;
	CStaff m_scout[101];
	CStaff m_gm[101];
	CStaff m_coach[101];
	BOOL m_checkCareer;
	int m_currentDay;
	int m_currentMonth;
	void WriteTransaction(CPlayer NewTeam[41], int Signed[481]);
	int m_team3index;
	int facount;
	double m_factor;
	int m_team1index;
	int m_team2index;
	CString m_control[33];
	CString m_leagueTeamNames[33];
	CString m_path;
	CString m_leagueName;
	int m_slots;
	
	CPlayer PlayerList[33][31];
//	CSeasonStats PlayerStats[512];
	CPlayer FA[481];

	CTradeDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CTradeDlg)
	enum { IDD = IDD_TRADEBOX };
	MyButton	m_button_cancel;
	CListCtrl	m_list_team1_draft;
	CListCtrl	m_listroster3;
	CListCtrl	m_listroster2;
	CListCtrl	m_listplayers2;
	CListCtrl	m_listplayers1;
	CListCtrl	m_list_team2_draft;
	CListCtrl	m_listfa;
	CListCtrl	m_listroster1;
	CMyComboBox	m_listteams3;
	CMyComboBox	m_listteams2;
	CMyComboBox	m_listteams1;
	MyButton	m_button_search;
	MyButton	m_button_add_pick2;
	MyButton	m_button_add_pick1;
	MyButton	m_button_team2;
	MyButton	m_button_team1;
	MyButton	m_buttonOk;
	MyButton	m_button_release;
	MyButton	m_button_sign;
	MyButton	m_button_trade;
	CListBox	m_listcontrol;
	CString	m_edit_salary_1;
	CString	m_edit_salary_2;
	CString	m_edit_salary_fit;
	CString	m_edit_payroll1;
	CString	m_edit_payroll2;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTradeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTradeDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonTrade();
	afx_msg void OnSelchangeListControl();
	afx_msg void OnButtonRelease();
	afx_msg void OnButtonSign();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnDestroy();
	afx_msg void OnButtonTeam1();
	afx_msg void OnButtonTeam2();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnButtonAddPick1();
	afx_msg void OnButtonAddPick2();
	afx_msg void OnButtonSearch();
	afx_msg void OnSelchangeCombo1();
	afx_msg void OnSelchangeCombo2();
	afx_msg void OnSelchangeCombo3();
	afx_msg void OnClickListCtrlRoster1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDblclkListCtrlRoster1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnClickListCtrlRoster2(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnClickListCtrlFa(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDblclkListCtrlPlayers1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDblclkListCtrlPlayers2(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDblclkListCtrlRoster2(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDblclkListCtrlFa(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnClickListCtrlRoster3(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDblclkListCtrlRoster3(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnClickListCtrlPlayers1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnClickListCtrlPlayers2(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void AddOfferedPicks();
	void ListPlayersInTradeOffer();
	
	void DeleteListCtrlRow(int row, int ctrl);
	CFont m_font;
	void InitControls();
//	void DisplayPlayerSalaryVisitor();
//	void DisplayPlayerSalaryHome();
	CString DisplayFaSalarySeeking(int fa);
	int m_cap_1;
	int m_cap_2;
	void CheckButton();
	void DeletePicks(bool t1, int t, int o_t);
	int m_draft_choice[3][19];
	void ClearDraftPickData(int t1, int t2, int o_t, int d1, int d2);
	bool m_salary_fit;
	void DisplayTradeSalaries();
	CFuture m_future;
	void SetProposedPicks(int index, int i, int o_i);
	void ListOwnDraftPicks(bool t1, bool t2);
//	void OpenInjuries();
	CBrush myBrush;
	int m_length;
	void WriteSign(int team, int player_index, bool sign);
	int m_seek;
	int m_team1;
	int m_team2;
	int slots[61];
	int InjuredList[33][31];
	CPlayer* List;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRADEDLG_H__DB72BEE3_3F8B_11D2_8C1C_FB2DA1E39583__INCLUDED_)
