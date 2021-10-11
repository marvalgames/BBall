#if !defined(AFX_STANDINGSVIEW_H__9406530A_142B_11D6_9B5D_444553540000__INCLUDED_)
#define AFX_STANDINGSVIEW_H__9406530A_142B_11D6_9B5D_444553540000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define HID_LEAGUE_STANDINGS 10

// StandingsView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CStandingsView form view









#ifndef Record_h
#include "Record.h"
#define Record_h
#endif // Added by ClassView



//#ifndef Record_h
#include "LeagueTeamSchedule.h"


#ifndef Average_h
#include "Average.h"	// Added by ClassView
#define Average_h
#endif
#include "MyButton.h"
#include "MyListCtrl.h"
#include "afxlistctrl.h"

//#include "SxGroupBox.h"

class CStandingsView : public CFormView
{
public:
	CStandingsView();           // protected constructor used by dynamic creation
protected:
	DECLARE_DYNCREATE(CStandingsView)

// Form Data
public:
	//{{AFX_DATA(CStandingsView)
	enum { IDD = IDD_DIALOG_STANDINGS_VIEW };
	MyButton	m_button_go;
	MyButton	m_button_tools;
	MyButton	m_button_progress;
	MyButton	m_button_history;

	//CTransparentGroup g1,g2,g3;

	CMyComboBox	m_combo_teams;
	MyButton	m_button_standings;
	MyButton	m_button_setup;
	MyButton	m_button_schedule;
	MyButton	m_button_print;
	CMyListCtrl	 m_listVsOpponents;
	CMyListCtrl	 m_listTeams;
	CListBox	m_listChoices;
	//}}AFX_DATA


//	CTransparentGroup	m_g[7];

// Attributes
public:

// Operations
public:
	BOOL SetToDoc();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStandingsView)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CStandingsView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CStandingsView)
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnButtonSetup();
	afx_msg void OnButtonSchedule();
	afx_msg void OnButtonStandings();
	afx_msg void OnSelchangeComboTeams();
	afx_msg void OnSelchangeListChoices();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnButtonPrint();
	afx_msg void OnDblclkListChoices();
	afx_msg void OnDblclkListCtrlTeams(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnClickListCtrlTeams(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnButtonProgress();
	afx_msg void OnButtonHistory();
	afx_msg void OnButtonTools();
	afx_msg void OnSetupLoad();
	afx_msg void OnSetupSettings();
	afx_msg void OnSetupSetgameplan();
	afx_msg void OnSetupProposetrade();
	afx_msg void OnButtonGo();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnTeamRoster();
	afx_msg void OnTeamBudget();
	afx_msg void OnTeamDraftpreview();
	afx_msg void OnTeamFreeagents();
	afx_msg void OnTeamHistory();
	afx_msg void OnTeamLineup();
	afx_msg void OnTeamRecords();
	afx_msg void OnTeamResults();
	afx_msg void OnTeamStaff();
	afx_msg void OnTeamTrade();
	afx_msg void OnTeamTransactions();
	afx_msg void OnEditCities();
	afx_msg void OnEditPlayers();
	afx_msg void OnEditStaff();
	afx_msg void OnMove(int x, int y);
	afx_msg void OnPaint();
	afx_msg void OnCancelMode();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
//	int m_current_year;
//	int m_default_team;
//	CString m_leagueName;
//	int m_teamsInLeague;
//	CString m_path;

void HighlightRow();
	int m_selection_row;
	CString m_strings[33];
	void SelectChange();
	CFont m_font;
	void InitControls();

	void SetPrintAlign(CDC *pDC, HDC hdcPrn);
//	CString m_playoffFormat;
//	CString m_rd1Format;
//	CString m_rd2Format;
//	CString m_rd3Format;
//	CString m_rd4Format;
//	CString m_conferenceName1;
//	CString m_conferenceName2;
//	CString m_divisionName1;
//	CString m_divisionName2;
//	CString m_divisionName3;
//	CString m_divisionName4;
//	int m_gameScore[13][32][17];
//	int m_schedule[13][32][17];
	CBrush myBrush;
	CString m_initialLeagueTeamNames[33];
	CString	m_initialCityNames[33];

//CMyBitmap bitmapBkgnd;

public:
	//CFont m_font1;
//	CAverage avg;
	//change to structure later
//	struct RECORD
//	{
//		CString m_leagueTeamNames;
//		CString m_control;
//		CString m_conference;
//		CString m_division;
//		CString m_city_name;
//		int m_leagueRecord;
//		int m_divisionRecord;
//		int m_conferenceRecord;
//		int m_homeRecord;
//		int m_visitorRecord;
//		double m_leaguePct;
//		double m_divisionPct;
//		double m_conferencePct;
//		int m_leagueGamesBack;
//		int m_vsOpponent[33];
//		int m_initialNumber;
//		double m_vsOpponentPct[33];
//	};
//	RECORD record[34];

	private:
		CBrush m_brush;
	  CBrush m_tbrush;
	CBitmap* m_bmp;

		  //m_tbrush.CreateSolidBrush(LISTBOXCOLOR); 		
	  void InitView();
		int m_standings_default_team;
	
	CStatic m_static;
	CRecord standing[33];
	int m_default_team;	


public:
	afx_msg void OnLvnItemchangedListCtrlVsOpp(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBnClickedStaticG3();
	afx_msg void OnLvnItemchangedListCtrlTeams(NMHDR* pNMHDR, LRESULT* pResult);
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STANDINGSVIEW_H__9406530A_142B_11D6_9B5D_444553540000__INCLUDED_)
