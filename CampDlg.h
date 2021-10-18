#if !defined(AFX_CAMPDLG_H__22E92F60_1DE5_11D3_8E70_444553540000__INCLUDED_)
#define AFX_CAMPDLG_H__22E92F60_1DE5_11D3_8E70_444553540000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#define HID_CAREER_CAMP 37
// CampDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCampDlg dialog

//#include "Player.h"	// Added by ClassView
#ifndef Player_h
#include "Player.h"
#define Player_h
#endif 
//#include "ScoutDlg.h"

#include "MyListCtrl.h"



#ifndef Record_h
#include "Record.h"
#define Record_h
#endif 
#ifndef Average_h
#include "Average.h"
#define Average_h
#endif 

#include "MyButton.h"

#ifndef Retirement_h
#include "Retirement.h"
#define Retirement_h
#endif 

class CCampDlg : public CDialog
{
// Construction
public:
	BOOL m_finances_on;
	int m_default_team;
	CAverage avg;
//	bool m_shareware;
	int m_currentYear;
	CRecord* m_standings;
    int hiFga;
	int hiTfga;
	int hiFta;
	int hiOreb;
	int hiDreb;
	int hiAst;
	int hiStl;
	int hiTo;
	int hiBlk;
/*	double oldHiG;
	double oldAvgG;
	double oldAvgMin;
	double oldFgPct, oldFtPct, oldTfgPct;*/

/*	double avg_min;
	double avgFga;
	double avgTfga;
	double avgFta;
	double avgOreb;
	double avgReb;
	double avgAst;
	double avgStl;
	double avgTo;
	double avgBlk;
	double avgPf;*/
	double avgTru;

	double tMin, tFgm, tFga, tTfga, tTfgm, tFtm;
	double tFta, tOreb, treb, tAst, tStl, tTo, tBlk, tPf, tTru;
	
	void OpenPlayers();
	CPlayer* Rookies;
	//CPlayer* Player;


	CPlayer* FA;
	CString m_leagueTeamNames[33];
	CString m_control[33];
	int m_numberteams;
	CString m_leagueName;
	CString m_path;
	CCampDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCampDlg)
	enum { IDD = IDD_DIALOG_CAMP };
	CMyComboBox	m_listTeams;
	MyButton	m_buttonRelease;
	MyButton	m_buttonSave;
	MyButton	m_buttonHOF;
	CListBox	m_listHallOfFame;
	CMyListCtrl	m_listPlayers;
	CListBox	m_listRetired;
	MyButton	m_saveDraft;
	CListBox	m_listControl;
	CListBox	m_listRookies;
	MyButton	m_buttonDraft;

	MyButton	m_button[3];

	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCampDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCampDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeListControl();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	virtual void OnCancel();
	virtual void OnOK();
	afx_msg void OnColumnclickListPlayers(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnItemdblclickListPlayers(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDestroy();
	afx_msg void OnButtonHof();
	afx_msg void OnButtonSave();
	afx_msg void OnButtonRelease();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnDblclkListPlayers(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSelchangeComboDraftteams();
	afx_msg void OnRadioCoach();
	afx_msg void OnRadioScout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	
	void SortByProgress();
	void ListProgress();
	int m_ratings_view;
	int m_fa_count;

	
	void AdjustData();
	int m_hiG;
	void WriteHallOfFameFile();
	int m_gone;
	CPlayer m_hall[1001];
	void SelectHallOfFame();
	CPlayer m_retired[1001];
	void Retirements();
	void SortAllPlayers();
	void SortFaList();
	void CreateFaList();
	//void SetNextSeasonData();
	void WriteNextSeasonData();
	int m_idCount;
	void DisplayRoster();
	bool m_draftOver;
	int m_currentSelection;
	int m_currentRound;
	//CPlayer m_draft[33][7];
	void SetRatings();
	void ClearRatings();
	void SortByTrue();
	int m_column;
	void SortByPosition();
	CBrush myBrush;
	CBrush myBrush2;
	CFont m_font;
	void InitCtrl();
	void SetCursors();
	void ListControl();
	void ListTeams();
	void ListRookies();
public:
	afx_msg void OnBnClickedOk();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CAMPDLG_H__22E92F60_1DE5_11D3_8E70_444553540000__INCLUDED_)
