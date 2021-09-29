#if !defined(AFX_SCHEDULEVIEW_H__926EE169_0549_11D6_9B5D_444553540000__INCLUDED_)
#define AFX_SCHEDULEVIEW_H__926EE169_0549_11D6_9B5D_444553540000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ScheduleView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CScheduleView form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

#include "MyButton.h"



#ifndef ShadeButtonST_h
#include "ShadeButtonST.h"
#define ShadeButtonST_h
#endif 

#include "MyBitmap.h"


#ifndef OwnCombo_h
#include "OwnCombo.h"
#define OwnCombo_h
#endif

#include "Label.h"


class CScheduleView : public CFormView
{
protected:
public:
	CScheduleView();           // protected constructor used by dynamic creation
protected:
	DECLARE_DYNCREATE(CScheduleView)

	// Form Data
public:
	//{{AFX_DATA(CScheduleView)
	enum { IDD = IDD_DIALOG_SCHEDULE_VIEW };
	CSliderCtrl	m_slider_days;
	MyButton	m_sim_x;
	int m_xdays;
	MyButton	m_button_go;
	MyButton	m_button_previous;
	MyButton	m_button_next;
	MyButton	m_button_gametype;
	MyButton	m_button_sim_til_asw;
	CMyComboBox	m_combo_teams;
	MyButton	m_button_tools;
	MyButton	m_button_history;
	MyButton	m_button_progress;
	MyButton	m_sim_month;
	MyButton	m_sim_week;
	MyButton	m_sim_day;
	CMyComboBox	m_combo_month;
	CMyComboBox	m_combo_day;
	MyButton	m_button_standings;
	MyButton	m_button_schedule;
	MyButton	m_button_setup;
	MyButton	m_button_asw;
	MyButton	m_button_sim_season;
	MyButton	m_button_start_playoff;
	MyButton	m_button_stop_sim;
	//}}AFX_DATA

// Attributes
public:


	//	CMyBitmap bitmapBkgnd;

private:

	MyButton	m_buttons[97];
	CStatic	m_static_score[33];
	CBrush myBrush;
	CBitmap* m_bmp;


	// Operations
public:
	void SetFromDoc();
	BOOL SetToDoc();

	// Overrides
		// ClassWizard generated virtual function overrides
		//{{AFX_VIRTUAL(CScheduleView)
public:
	virtual void OnInitialUpdate();
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
//	virtual void OnDraw(CDC* pDC);
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CScheduleView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CScheduleView)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnSelchangeComboMonth();
	afx_msg void OnSelchangeComboDay();
	afx_msg void OnButtonSchedule();
	afx_msg void OnButtonStandings();
	afx_msg void OnSetupLoad();
	afx_msg void OnButtonSetup();
	afx_msg void OnSelchangeComboTeams();
	afx_msg void OnButtonSim1();
	afx_msg void OnButtonSim10();
	afx_msg void OnButtonSim11();
	afx_msg void OnButtonSim12();
	afx_msg void OnButtonSim13();
	afx_msg void OnButtonSim14();
	afx_msg void OnButtonSim15();
	afx_msg void OnButtonSim16();
	afx_msg void OnButtonSim2();
	afx_msg void OnButtonSim3();
	afx_msg void OnButtonSim4();
	afx_msg void OnButtonSim5();
	afx_msg void OnButtonSim6();
	afx_msg void OnButtonSim7();
	afx_msg void OnButtonSim8();
	afx_msg void OnButtonSim9();
	afx_msg void OnButtonSimday();
	afx_msg void OnButtonSimMonth();
	afx_msg void OnButtonSimWeek();
	afx_msg void OnButtonStopSim();
	afx_msg void OnButtonProgress();
	afx_msg void OnButtonHistory();
	afx_msg void OnButtonTools();
	afx_msg void OnButtonStartPlayoff();
	afx_msg void OnButtonSimPlayoffs();
	afx_msg void OnButtonBox1();
	afx_msg void OnButtonBox2();
	afx_msg void OnButtonBox10();
	afx_msg void OnButtonBox11();
	afx_msg void OnButtonBox12();
	afx_msg void OnButtonBox13();
	afx_msg void OnButtonBox14();
	afx_msg void OnButtonBox15();
	afx_msg void OnButtonBox16();
	afx_msg void OnButtonBox3();
	afx_msg void OnBUTTONBOX4();
	afx_msg void OnButtonBox5();
	afx_msg void OnButtonBox6();
	afx_msg void OnButtonBox7();
	afx_msg void OnButtonBox8();
	afx_msg void OnButtonBox9();
	afx_msg void OnButtonCoach1();
	afx_msg void OnButtonCoach10();
	afx_msg void OnButtonCoach11();
	afx_msg void OnButtonCoach12();
	afx_msg void OnButtonCoach13();
	afx_msg void OnButtonCoach14();
	afx_msg void OnButtonCoach15();
	afx_msg void OnButtonCoach16();
	afx_msg void OnButtonCoach2();
	afx_msg void OnButtonCoach3();
	afx_msg void OnButtonCoach4();
	afx_msg void OnButtonCoach5();
	afx_msg void OnButtonCoach6();
	afx_msg void OnButtonCoach7();
	afx_msg void OnButtonCoach8();
	afx_msg void OnButtonCoach9();
	afx_msg void OnButton1();
	afx_msg void OnButton10();
	afx_msg void OnButton11();
	afx_msg void OnButton12();
	afx_msg void OnButton13();
	afx_msg void OnButton14();
	afx_msg void OnButton15();
	afx_msg void OnButton16();
	afx_msg void OnButton17();
	afx_msg void OnButton18();
	afx_msg void OnButton19();
	afx_msg void OnButton2();
	afx_msg void OnButton20();
	afx_msg void OnButton21();
	afx_msg void OnButton22();
	afx_msg void OnButton23();
	afx_msg void OnButton24();
	afx_msg void OnButton25();
	afx_msg void OnButton26();
	afx_msg void OnButton27();
	afx_msg void OnButton28();
	afx_msg void OnButton29();
	afx_msg void OnButton3();
	afx_msg void OnButton30();
	afx_msg void OnButton31();
	afx_msg void OnButton32();
	afx_msg void OnButton4();
	afx_msg void OnButton5();
	afx_msg void OnButton6();
	afx_msg void OnButton7();
	afx_msg void OnButton8();
	afx_msg void OnButton9();
	afx_msg void OnButtonGametype();
	afx_msg void OnButtonSimtilasw();
	afx_msg void OnButtonPrevious();
	afx_msg void OnButtonNext();
	afx_msg void OnButtonAsw();
	afx_msg void OnButtonGo();
	afx_msg void OnSetupSettings();
	afx_msg void OnSetupSetgameplan();
	afx_msg void OnSetupProposetrade();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnTeamRoster();
	afx_msg void OnTeamResults();
	afx_msg void OnTeamBudget();
	afx_msg void OnTeamDraftpreview();
	afx_msg void OnTeamFreeagents();
	afx_msg void OnTeamHistory();
	afx_msg void OnTeamLineup();
	afx_msg void OnTeamRecords();
	afx_msg void OnTeamStaff();
	afx_msg void OnTeamTrade();
	afx_msg void OnTeamTransactions();
	afx_msg void OnButtonSimdays();
	afx_msg void OnReleasedcaptureSliderDays(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnEditCities();
	afx_msg void OnEditPlayers();
	afx_msg void OnEditStaff();
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void SetCurrentPlayoffGame(int mo, int da, int ga);
	void UpdatePlayoffsAfterCoachedGame();
	bool CheckForCoachControlledGame(int t1, int t2);
	bool m_simmed_asw;
	void SaveAllStarWeekend(int pointer[101], int scores[31]);
	bool m_sim_season;
	void SimAsw();
	void RefillDaysInMonth(int mon);
	int m_days_in_month[13];
	//	bool m_regular_season_ended;
	int m_single_team;
	void DisplayAllStarSchedule();
	void WritePlayoffResults(CString pFileName, int m_currentMonth, int m_currentDay, int m_currentGame,
		int m_team1, int score1, int m_win1, int m_team2, int score2, int m_win2);


	void SimPlayoffGame(bool sim_po_game, bool sim_po_day, bool sim_po_round, bool sim_po_all, int visitor, int home);
	void DisableButtons();
	void SetCurrentGame(int mo, int da, int ga);
	void ListTeamNames();
	void DisplayCoachedGameScore(int row);
	CFont m_font, m_font1, m_font2, m_font3;
	void ShowBox(int game);
	void SimAllStarGame(int row);
	bool m_asw_button_pressed;
	bool m_sim_ok;
	void DisplayScore(int row, int sc1, int sc2);
	void SimGame(int t1, int t2, int row);
	int m_home_teams[16];
	int m_visitor_teams[16];
	void InitControls();
	void DisplaySchedule();
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCHEDULEVIEW_H__926EE169_0549_11D6_9B5D_444553540000__INCLUDED_)
