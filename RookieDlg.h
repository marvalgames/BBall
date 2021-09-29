#if !defined(AFX_ROOKIEDLG_H__6C287C60_1478_11D3_8E70_444553540000__INCLUDED_)
#define AFX_ROOKIEDLG_H__6C287C60_1478_11D3_8E70_444553540000__INCLUDED_

//#include "Player.h"	// Added by ClassView
#ifndef Player_h
#include "Player.h"
#define Player_h
#endif 
//#include "ScoutDlg.h"
#ifndef Staff_h
#include "Staff.h"
#define Staff_h
#endif 
#ifndef Record_h
#include "Record.h"
#define Record_h
#endif 
#ifndef Average_h
#include "Average.h"
#define Average_h
#endif 
#ifndef Own_h
#include "Own.h"
#define Own_h
#endif



#ifndef XListCtrl_h
//#include "XListCtrl/XListCtrl.h"
#define XListCtrl_h
#endif // Added by ClassView

#include "MyButton.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#define HID_CAREER_ROOKIE 30
// RookieDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRookieDlg dialog

class CRookieDlg : public CDialog
{
// Construction
public:
	bool m_shareware;
	int m_orig_win[33];//tracks wins of team for trading in draft so its not swapped during draft
	int m_orig_loss[33];
	CString m_column_headers[33];
	//COwn m_own[33];
	int m_default_team;
	CAverage avg;
	//CStaff m_scout[101];
	//CStaff m_gm[101];
	//CStaff m_coach[101];
	int m_currentYear;
	void FinalizeNewRosters();
	void GmChoiceBox();
	CRecord* m_orig_standings;
int hiFga;
	int hiTfga;
	int hiFta;
	int hiOreb;
	int hiDreb;
	int hiAst;
	int hiStl;
	int hiTo;
	int hiBlk;
	double avgFga;
	double avgTfga;
	double avgFta;
	double avgOreb;
	double avgDreb;
	double avgAst;
	double avgStl;
	double avgTo;
	double avgBlk;
//	double avgTru;
	void OpenRookies();
	CPlayer* Rookies;
	//CPlayer* Player;
	CPlayer* New;
	//CPlayer* FA;
	CString m_leagueTeamNames[33];
	CString m_control[33];
	int m_numberteams;
	CString m_leagueName;
	CString m_path;
	CRookieDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CRookieDlg)
	enum { IDD = IDD_DIALOG_ROOKIES };
	MyButton	m_button_next;
	MyButton	m_button_trade;
	MyButton	m_button_edit;
	MyButton	m_button_cancel;
	CMyComboBox	m_listTeams;
	MyButton	m_button_report;
	MyButton	m_button_lottery;
	CListBox	m_list_draft_order;
	MyButton	m_buttonRandom;
	MyButton	m_saveDraft;
	MyButton	m_buttonScout;
	CListBox	m_listDisplayDraft;
	CListBox	m_listRosters;
	CListCtrl	m_listPlayers;
	CListBox	m_listControl;
	CListBox	m_listRookies;
	MyButton	m_buttonDraft;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRookieDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CRookieDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeListControl();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	virtual void OnCancel();
	virtual void OnOK();
	afx_msg void OnColumnclickListPlayers(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnItemdblclickListPlayers(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnButtonDraft();
	afx_msg void OnDestroy();
	afx_msg void OnDblclkListPlayers(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnButtonRandom();
	afx_msg void OnButtonReport();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnDblclkListRosters();
	afx_msg void OnButtonLottery();
	afx_msg void OnSelchangeComboListTeams();
	afx_msg void OnButtonPrint();
	afx_msg void OnButtonEdit();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnButtonTrade();
	afx_msg void OnButtonHtml();
	afx_msg void OnButtonNext();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CString m_print_strings[193][27];
	int m_origslot[34];
	int m_original_id_count;
	CBitmap bitmapBkgnd;
	void ReadNewID();
	void SetPrintAlign(CDC *pDC, HDC hdcPrn);
//	CString m_strings[101];
	bool m_roo_exists;
//	void AutoSignRookies();
	int m_lottery_teams;
	int m_lottery_odds[33];
	void InitLotteryOdds();
	void ListDraftOrder();
	void WritePlayerDraftPosition();
	int m_selection;
	int m_choices[100];
	void UpdateCareerYear();
	void CreateEmptyDraftFile();
	void WriteDraftFile();
	bool m_draftStarted;

	void CreateCampRosterFile();

	
	void WriteNewID();
	int m_idCount;
	void initNewRoster();
	void CreateNewRoster(int pick);
	void DisplayRoster();
	void SelectionMade(int p);
	bool m_draftOver;
	void SortDraftSlots();


	struct DRAFT
	{
		int slot;
		int round;
		int pick;
	};



	DRAFT m_initDraftSlot[3][34];
	void ResetRookieList(int p);
	int GetComputerSelection();
	int m_currentSelection;
	int m_currentRound;
	CPlayer m_draft[33][7];
	void SetRatings();
	void ClearRatings();
	void SortByTrue();
	int m_column;
	void SortByPosition();
	CBrush myBrush;
	CBrush myBrush2;
	CFont m_font;
	void InitListCtrl();
	void SetCursors();
	void ListControl();
	void ListTeams();
	void ListRookies();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ROOKIEDLG_H__6C287C60_1478_11D3_8E70_444553540000__INCLUDED_)
