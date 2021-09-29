#if !defined(AFX_TEAMVIEW_H__8B3AFAB5_104E_11D6_9B5D_BF53BC85C97B__INCLUDED_)
#define AFX_TEAMVIEW_H__8B3AFAB5_104E_11D6_9B5D_BF53BC85C97B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TeamView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTeamView form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

#ifndef ShadeButtonST
#include "ShadeButtonST.h"
#define ShadeButtonST
#endif 
#include "MyButton.h"
#include "MyBitmap.h"

class CTeamView : public CFormView
{
public:
	CTeamView();           // protected constructor used by dynamic creation
protected:
	DECLARE_DYNCREATE(CTeamView)

// Form Data
public:
	//{{AFX_DATA(CTeamView)
	enum { IDD = IDD_DIALOG_TEAM_VIEW };
	MyButton	m_button_next;
	MyButton	m_button_back;
	MyButton	m_button_go;
	MyButton	m_button_records;
	MyButton	m_button_tools;
	MyButton	m_button_history;
	MyButton	m_button_budget_sheet;
	MyButton	m_button_progress;
	MyButton	m_button_trade;
	MyButton	m_button_transaction;
	MyButton	m_button_depth;
	MyButton	m_button_history_team;
	MyButton	m_button_fa;
	MyButton	m_button_staffs;
	MyButton	m_button_rookies;
	MyButton	m_button_team_schedule;
	MyButton m_button_view_roster;
	MyButton	m_button_standings;
	MyButton	m_button_setup;
	MyButton	m_button_schedule;
	CMyComboBox	m_combo_teams;
	//}}AFX_DATA

// Attributes

private:
	void InitView();
	int m_backnextindex;
	void ViewTeamRosters();
	void OpenTeamScheduleDlg();
	void OpenTransactionsDlg();
	void OpenTradeDlg();
	CFont m_font2;
	void OpenTeamHistory();
	void OpenRecords();
	void OpenDepthChart();
	void OpenBudget();
	void OpenStaff();
	void OpenFreeAgentDlg();
	void OpenRookieDlg();
	void FillButtons();
	CString m_button_text[49];
	int m_button_id[49];
	
	CFont m_font1;
	CFont m_font;
	CBrush myBrush;
//	CMyBitmap bitmapBkgnd;
	MyButton	m_buttons[33];
	CBitmap* m_bmp;

public:

// Operations
public:
	void DisplayPlayerCard(int id, int pointer);
//	int m_page;
	BOOL SetToDoc();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTeamView)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
//	virtual void OnDraw(CDC* pDC);
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CTeamView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CTeamView)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnSelchangeComboTeams();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnButtonSetup();
	afx_msg void OnButtonSchedule();
	afx_msg void OnButtonStandings();
	afx_msg void OnButtonViewRoster();
	afx_msg void OnButtonTeamSchedule();
	afx_msg void OnButtonHistoryTeamResults();
	afx_msg void OnButtonDepthCharts();
	afx_msg void OnButtonTransactions();
	afx_msg void OnButtonTrade();
	afx_msg void OnButtonRecords();
	afx_msg void OnButtonProgress();
	afx_msg void OnButtonTools();
	afx_msg void OnButtonHistory();
	afx_msg void OnButtonRookies();
	afx_msg void OnButton32();
	afx_msg void OnButtonFa();
	afx_msg void OnButtonStaffs();
	afx_msg void OnButtonBudgetSheet();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	afx_msg void OnButton4();
	afx_msg void OnButton5();
	afx_msg void OnButton6();
	afx_msg void OnButton7();
	afx_msg void OnButton8();
	afx_msg void OnButton9();
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
	afx_msg void OnButton30();
	afx_msg void OnButton31();
	afx_msg void OnSetupLoad();
	afx_msg void OnSetupSettings();
	afx_msg void OnSetupSetgameplan();
	afx_msg void OnSetupProposetrade();
	afx_msg void OnButtonGo();
	afx_msg void OnButtonBack();
	afx_msg void OnButtonNext();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
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
	afx_msg void OnEditCities();
	afx_msg void OnEditStaff();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEAMVIEW_H__8B3AFAB5_104E_11D6_9B5D_BF53BC85C97B__INCLUDED_)
