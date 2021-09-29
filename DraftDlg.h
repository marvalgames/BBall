#if !defined(AFX_DRAFTDLG_H__C41182E0_50CF_11D2_8E6C_AE5F97A5675A__INCLUDED_)
#define AFX_DRAFTDLG_H__C41182E0_50CF_11D2_8E6C_AE5F97A5675A__INCLUDED_

#ifndef Player_h
#include "Player.h"
#define Player_h
#endif 
#ifndef Average_h
#include "Average.h"
#define Average_h
#endif 

#include "MyButton.h"


//#include "Average.h"	// Added by ClassView
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
#define HID_LEAGUE_DRAFT 6


// DraftDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDraftDlg dialog

class CDraftDlg : public CDialog
{
// Construction
public:
	CPlayer FA[97];
	CAverage avg;
	BOOL m_checkCareer;
	bool m_allPlayersPool;
	CString m_originalLeagueName;
	int m_originalNumberOfTeams;
//	bool m_shareware;
	bool SortPlayers();
	CStaff* m_scout;
	void SelectPlayer(CString string, bool roundOver, bool draftOver);
//	CPlayer Player[33][16];
	CPlayer* Rating;
	CPlayer* Player;
//	CPlayer Player[481];
//	CPlayer Rating[2881];
	CString m_control[33];
	CString m_leagueTeamNames[33];
	CString m_path;
//	double m_avgFga;
//	double m_avgFta;
//	double m_avgTfga;
	CString m_leagueName;
	CDraftDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDraftDlg)
	enum { IDD = IDD_DIALOG_DRAFT };
	MyButton	m_buttonRandom;
	MyButton	m_buttonSg;
	MyButton	m_buttonSf;
	MyButton	m_buttonPg;
	MyButton	m_buttonPf;
	MyButton	m_buttonC;
	MyButton	m_buttonRatings;
	MyButton	m_buttonDraft;
	CListBox	m_selection;
	CListBox	m_listSg;
	CListBox	m_listSf;
	CListBox	m_listRoster;
	CListBox	m_listPg;
	CListBox	m_listPf;
	CListBox	m_listOrder;
	CListBox	m_listControl;
	CListBox	m_listC;
	CListBox	m_listAll;
	BOOL	m_checkReverse;
	BOOL	m_checkConfirmed;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDraftDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDraftDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnDestroy();
	afx_msg void OnSelchangeListControl();
	afx_msg void OnSelchangeListOrder();
	afx_msg void OnButtonDraft();
	afx_msg void OnDblclkListPg();
	afx_msg void OnDblclkListSg();
	afx_msg void OnDblclkListC();
	afx_msg void OnDblclkListSf();
	afx_msg void OnDblclkListPf();
	afx_msg void OnDblclkListAll();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnDblclkListOrder();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnButtonRatings();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnDblclkListRoster();
	afx_msg void OnButtonC();
	afx_msg void OnButtonPf();
	afx_msg void OnButtonPg();
	afx_msg void OnButtonSf();
	afx_msg void OnButtonSg();
	afx_msg void OnButtonRandom();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void ShowPlayerCard(int pos);
//	CDisk disk;
	void CreateFreeAgentList();
	void ListTeams();

	bool GetConfirmation(CString string);
	CBrush myBrush;
	CBrush myBrush2;
	CFont m_font;
	bool draftOver;
	int m_swap2;
	int m_swap1;
	bool m_orderClicked;
	int m_originalDraftOrder[33];
	int players[6];
	bool m_gm;
	bool Chosen[2881];
	int m_teamsInLeague;
	int PlayerSlot[33][16];
	int PlayerMinutes[33][16];//original player minutes
	int m_currentTeam;
	int m_currentRound;
	bool m_draftStarted;

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAFTDLG_H__C41182E0_50CF_11D2_8E6C_AE5F97A5675A__INCLUDED_)
