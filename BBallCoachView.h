#if !defined(AFX_BBALLCOACHVIEW_H__04B7C6E4_1CCB_11D6_85B5_00D009EC5254__INCLUDED_)
#define AFX_BBALLCOACHVIEW_H__04B7C6E4_1CCB_11D6_85B5_00D009EC5254__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BBallCoachView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBBallCoachView form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif
#ifndef Engine_h
#include "Engine.h"
#define Engine_h
#endif 

#include "MyBitmap.h"
#include "MyButton.h"
#include "MyListCtrl.h"
#include "MySliderControl.h"
#include "afxlistctrl.h"


class CBBallCoachView : public CFormView
{
protected:
	DECLARE_DYNCREATE(CBBallCoachView)



// Form Data
public:
	CBBallCoachView();           // protected constructor used by dynamic creation

	CBrush myBrush;
	CBrush myBrush2;


	//{{AFX_DATA(CBBallCoachView)
	enum { IDD = IDD_DIALOG_COACH_VIEW };
	MyButton	m_buttonplan;
	MyButton	m_buttonvplan;
	MyButton m_button[3];
	CStatic	m_vlabel;
	CStatic	m_tlabel;
	CStatic	m_hlabel;
	CStatic	m_static_homescore;
	CStatic	m_static_home;
	CStatic	m_static_visitorscore;
	CStatic	m_static_visitor;
	CStatic	m_static_time;
//	CDigiStatic	m_static_time;
	//CDigiStatic	m_vlabel;
//	CDigiStatic	m_tlabel;
	//CDigiStatic	m_hlabel;
//	CDigiStatic	m_static_homescore;
//	CDigiStatic	m_static_home;
//	CDigiStatic	m_static_visitorscore;
//	CDigiStatic	m_static_visitor;
//	CDigiStatic	m_static_time;

	CTransparentStatic	m_static_sub;
	MyButton	m_buttonTo;
	CMySliderControl	m_sim_speed;
	MyButton	m_button_end;
	CMyListCtrl	m_list_visitor_lineup;
	CMyListCtrl	m_list_visitor_shot;
	CMyListCtrl	m_list_visitor_roster;
	CMyListCtrl	m_list_scoreboard;
	CMyListCtrl	m_list_home_shot;
	CMyListCtrl	m_list_home_roster;
	CMyListCtrl	m_list_home_lineup;
	MyButton	m_button_sim;
	MyButton	m_button_play;
	MyButton	m_button_home_card;
	MyButton	m_button_road_card;


	CListBox	m_list_pbp;
	//}}AFX_DATA

// Attributes
public:

// Operations
public:
	
	BOOL SetToDoc();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBBallCoachView)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CBBallCoachView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CBBallCoachView)
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnButtonSim();
	afx_msg void OnButtonPlay();
	afx_msg void OnBegindragListVisitorRoster(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnEnddragListVisitorRoster(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnColumnclickListVisitorRoster(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBegindragListHomeRoster(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDblclkListVisitorRoster(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDblclkListHomeRoster(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnButtonBack();
	afx_msg void OnButtonEnd();
	afx_msg void OnButtonBox();
	afx_msg void OnCheckAutoHome();
	afx_msg void OnCheckAutoVisitor();
	afx_msg void OnButtonDefense();
	afx_msg void OnReleasedcaptureSliderSpeed(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnButtonTo();
	afx_msg void OnSetupSettings();
	afx_msg void OnSetupLoad();
	afx_msg void OnSetupSetgameplan();
	afx_msg void OnSetupProposetrade();
	afx_msg void OnButtonVisitorCard();
	afx_msg void OnButtonHomeCard();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnUpdateSetupLoad(CCmdUI* pCmdUI);
	afx_msg void OnUpdateSetupProposetrade(CCmdUI* pCmdUI);
	afx_msg void OnUpdateSetupSettings(CCmdUI* pCmdUI);
	afx_msg void OnButtonVisitorplan();
	afx_msg void OnButtonHomeplan();
	afx_msg void OnUpdateSetupSetgameplan(CCmdUI* pCmdUI);
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
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void CallGamePlan(int t);
	int m_engine_created;
	
	void SubBox();
	BOOL m_auto_sub[3];
	int m_playing_players_list[61];
	CString m_playByPlay[3201];
	int m_quarter_score[3][6]; 
	int m_quarter;
	int m_score[3];
	int m_pbp_lines;
	bool m_sim_remainder;
	bool m_over;
	void OnButtonStart();
	void Coach();
	void DisplayScore();
	void DisplayLineups();
	void DisplayRosterNames();
	void DisplayRosters();
	void InitControls();
	void ListStrings();
	CEngine *engine;
	void StartGame();
	void EndGame();
	void SetFromDoc();
	CFont m_font;
	CFont m_font_starters;
	CFont m_font_scores;
//MyBitmap bitmapBkgnd;
//	CBrush myBrush;
	//CBrush myBrush2;


	void SetMyFont(int weight, int height, CString font);
	
	void SetMyFontStarters(int weight, int height, CString font);

	void SetMyFontScores(int weight, int height, CString font);


	CBitmap* m_bmp;



public:
	afx_msg void OnStnClickedStaticHome();
private:
//	MyButton m_button_home;
//	MyButton m_button_home;
public:
//	MyButton m_button_home;
	afx_msg void OnLvnItemchangedListScoreboard(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnStnClickedStaticTlabel();
	afx_msg void OnLvnItemchangedListHomeShot(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnLbnSelchangeListPbp();
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BBALLCOACHVIEW_H__04B7C6E4_1CCB_11D6_85B5_00D009EC5254__INCLUDED_)
