#if !defined(AFX_BOXDLG_H__68D83780_E6E7_11D2_8E70_444553540000__INCLUDED_)
#define AFX_BOXDLG_H__68D83780_E6E7_11D2_8E70_444553540000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define HID_VIEW_SAVEDBOXSCORE 23
#ifndef Player_h
#include "Player.h"
#define Player_h
#endif 



#include "MyListCtrl.h"
#include "MyButton.h"
// BoxDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBoxDlg dialog

class CBoxDlg : public CDialog
{
// Construction
public:

	int m_default_team;

	CString m_fileName;
	CString m_leagueTeamNames[33];

	CBoxDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CBoxDlg)
	enum { IDD = IDD_DIALOG_SAVEDBOX };
	CMyListCtrl	m_listGames;
	CMyListCtrl	m_listBox;
	CMyComboBox	m_listTeams;
	MyButton	m_buttonVisitor;
	MyButton	m_buttonHome;
	MyButton	m_button[2];
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBoxDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CBoxDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonVisitor();
	afx_msg void OnButtonHome();
	afx_msg void OnButtonPrint();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnSelchangeComboTeams();
	afx_msg void OnClickListCtrlSavedBox(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnColumnclickListCtrlSavedBox(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDestroy();
	afx_msg void OnClickListCtrlGames(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDblclkListCtrlSavedBox(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	CString m_league_name;
	int m_id_list[16];
	CString m_names_list[16];
	void ListGames();
	CFont m_font;
	int m_column;
	void InitGameStats();
	void InitControls();
	CString m_currentTeam;
	CBrush myBrush;
	int m_start;
	CString m_home;
	CString m_visitor;
	void DisplayBox();
	CPlayer* m_player;
	void SetGames();
	int m_games[10000];
	CString m_print_strings[33];	
	void SetPrintAlign(CDC *pDC, HDC hdcPrn);

public:
	afx_msg void OnLvnItemchangedListCtrlSavedBox(NMHDR* pNMHDR, LRESULT* pResult);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BOXDLG_H__68D83780_E6E7_11D2_8E70_444553540000__INCLUDED_)
