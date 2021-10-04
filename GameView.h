#if !defined(AFX_GAMEVIEW_H__926EE168_0549_11D6_9B5D_444553540000__INCLUDED_)
#define AFX_GAMEVIEW_H__926EE168_0549_11D6_9B5D_444553540000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// GameView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CGameView form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif
#include "MyButton.h"



#include "MyBitmap.h"





#ifndef Record_h
#include "Record.h"
#define Record_h
#endif // Added by ClassView
//#include "Player.h"	// Added by ClassView

#ifndef Player_h
#include "Player.h"
#define Player_h
#endif 



#ifndef ScoutProfileDlg
#include "ScoutProfileDlg.h"
#define ScoutProfileDlg_h
#endif 
#ifndef Average_h
#include "Average.h"
#define Average_h
#endif 

#include "MyListCtrl.h"



#include "label.h"




class CGameView : public CFormView
{
protected:
public:
	bool m_off_season;
	int m_stat_type;
	CGameView();           // protected constructor used by dynamic creation
protected:
	DECLARE_DYNCREATE(CGameView)

// Form Data
public:
	//{{AFX_DATA(CGameView)
	enum { IDD = IDD_DIALOG_GAME_VIEW };
	MyButton	m_check_rookies;
	MyButton	m_button_leaders;
	MyButton	m_button_awards;
	MyButton	m_button_go;
	MyButton	m_radio_all;
	MyButton	m_radio_pg;
	MyButton	m_radio_sg;
	MyButton	m_radio_sf;
	MyButton	m_radio_pf;
	MyButton	m_radio_c;
	MyButton	m_radio_teams;
	MyButton	m_radio_players;
	MyButton	m_radio_defense;
	MyButton	m_radio_high;
	MyButton	m_radio_low;
	MyButton	m_button_print;
	MyButton	m_button_html;
	MyButton	m_radio_simulated;
	MyButton	m_radio_playoffs;
	MyButton	m_radio_ratings;
	MyButton	m_radio_contracts;
	MyButton	m_radio_actual;
	MyButton	m_button_history;
	MyButton	m_button_tools;
	MyButton	m_button_progress;
	CMyListCtrl	m_list_stats;
	CMyComboBox	m_listTeams;
	MyButton	m_buttonRatings;
	CListBox	m_listSimulatedStats2;
	CListBox	m_listSimulatedStats;
	CString	m_teamWL;
	MyButton	m_button_team_page;
	CMyComboBox	m_combo_teams;
	MyButton	m_button_standings;
	MyButton	m_button_schedule;
	MyButton	m_button_setup;
	//}}AFX_DATA




// Attributes

private:
//	CMyBitmap bitmapBkgnd;
		CBitmap* m_bmp;



public:

// Operations
public:
	void SetFromDoc();
//	void OnInitialUpdate();
	BOOL SetToDoc();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGameView)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
//	virtual void OnDraw(CDC* pDC);
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CGameView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CGameView)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnButtonSchedule();
	afx_msg void OnButtonStandings();
	afx_msg void OnSetupLoad();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnButtonSetup();
	afx_msg void OnSelchangeComboTeams();
	afx_msg void OnButtonTeamPage();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnButtonPrint();
	afx_msg void OnRadioActual();
	afx_msg void OnRadioSimulated();
	afx_msg void OnRadioRatings();
	afx_msg void OnRadioPlayers();
	afx_msg void OnRadioTeams();
	afx_msg void OnRadioDefense();
	afx_msg void OnRadioHigh();
	afx_msg void OnRadioLow();
	afx_msg void OnRadioPlayoffs();
	afx_msg void OnRadioPg();
	afx_msg void OnRadioPf();
	afx_msg void OnRadioSf();
	afx_msg void OnRadioSg();
	afx_msg void OnRadioC();
	afx_msg void OnRadioAll();
	afx_msg void OnDblclkListControlStats(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSelchangeComboTeamNames();
	afx_msg void OnRadioContracts();
	afx_msg void OnButtonHtml();
	afx_msg void OnDestroy();
	afx_msg void OnButtonProgress();
	afx_msg void OnButtonHistory();
	afx_msg void OnButtonTools();
	afx_msg void OnButtonAwards();
	afx_msg void OnButtonLeaders();
	afx_msg void OnSetupSettings();
	afx_msg void OnSetupSetgameplan();
	afx_msg void OnSetupProposetrade();
	afx_msg void OnButtonGo();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnCheckRookies();
	afx_msg void OnTeamBudget();
	afx_msg void OnTeamDraftpreview();
	afx_msg void OnTeamFreeagents();
	afx_msg void OnTeamHistory();
	afx_msg void OnTeamLineup();
	afx_msg void OnTeamRecords();
	afx_msg void OnTeamResults();
	afx_msg void OnTeamRoster();
	afx_msg void OnTeamStaff();
	afx_msg void OnTeamTrade();
	afx_msg void OnTeamTransactions();
	afx_msg void OnEditPlayers();
	afx_msg void OnEditCopy();
	afx_msg void OnEditCities();
	afx_msg void OnEditStaff();
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	bool m_rookie_view;
	CAverage avg;

	void CalculateCurrentPayroll();
	void SetContractHeaders();
	bool SortContracts(CPlayer m_player, CPlayer temp);
	void ListContracts();
	BOOL InitImageList();
	void InitHeadings();
	CString m_column_headers[3][27];
	CString m_print_strings[1601][27];
	void BuildString(CString s[255], int co, int columns);
	int m_co;
	int m_player_pointer[1601];
	CFont m_font, m_font1, m_font2;
	void InitListCtrl();
	CString m_position;
	void SetAdjustedRatings();
	bool m_switch_sort;	
	void ChooseStatsToList();
	int m_row;
	int m_column;
	bool SortFunction(CPlayer m_player, CPlayer temp);
	bool SortStats(CPlayer m_player, CPlayer temp);
	bool SortPlayoffStats(CPlayer m_player, CPlayer temp);
	bool SortRatings(CPlayer m_player, CPlayer temp);
	bool SortActual(CPlayer m_player, CPlayer temp);
	void QuickSort();
	int m_main_category;

	void ListPlayoffStats();
	void SetRatingsHeaders();
	void ListRatings();
	void ListSimulatedStats();
	void SetSeasonAverages();
	
	void ListStats();
	int m_changeHeading;
	void SetColumnHeaders();
	int m_category;
	int m_default_team;	
	int m_currentTeam;
	CBrush myBrush;
	void SetPrintAlign(CDC *pDC, HDC hdcPrn);

public:
	afx_msg void OnItemclickListControlStats(NMHDR *pNMHDR, LRESULT *pResult);
	//CButton m_radio_simulated;
	
	//CButton m_g1;
		//CTransparentGroup	m_g[7];
		//afx_msg void OnBnClickedStaticG1();
	afx_msg void OnLvnItemchangedListControlStats(NMHDR* pNMHDR, LRESULT* pResult);
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GAMEVIEW_H__926EE168_0549_11D6_9B5D_444553540000__INCLUDED_)
