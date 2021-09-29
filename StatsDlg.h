#if !defined(AFX_STATSDLG_H__0592AE01_50FA_11D1_8C1C_44455354616F__INCLUDED_)
#define AFX_STATSDLG_H__0592AE01_50FA_11D1_8C1C_44455354616F__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
#define HID_STATS_GAME 2

// StatsDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CStatsDlg dialog
#include "BBallDoc.h"
#ifndef Average_h
#include "Average.h"
#define Average_h
#endif 
#ifndef PlayerCardDlg_h
#include "PlayerCardDlg.h"
#define PlayerCardDlg_h
#endif 

class CStatsDlg : public CDialog
{
// Construction
public:
	void SetPtr(CAverage &pAverageClass);
	int m_playing_players_list[61];
	int m_game_type;
	bool m_v_click;
	bool m_saved_box;
	int m_quarter_score[3][6];
	int m_running_total[3][6];
	int m_score[3];
	int m_quarter;
	int m_column;
	int m_team_index;
	int m_visitor_index;
	int m_home_index;
	int m_mo;
	int m_da;
	int m_ga;
	CAverage avg;

	UINT m_att;
	UINT m_cap;
	int m_lines;
	CString m_playByPlay[3201];
	double m_factor;
	CString m_visitor;
	CString m_home;
	CStatsDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CStatsDlg)
	enum { IDD = IDD_STATSBOX };
	MyButton	m_button_pbp;
	CListCtrl	m_list_pct;
	CListCtrl	m_list_scores;
	CListCtrl	m_list_stats;
	MyButton	m_buttonVisitor;
	MyButton	m_buttonHome;
	UINT	m_edit_att;
	UINT	m_edit_cap;
	//}}AFX_DATA
//	CArray< CPlayer, CPlayer& > PlayerArray;
//	CArray< CPlayerStats, CPlayerStats& > PlayerStats;
	


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStatsDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation

protected:

	// Generated message map functions
	//{{AFX_MSG(CStatsDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonHome();
	afx_msg void OnButtonVisitor();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnButtonPbp();
	afx_msg void OnButtonPrnt();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnDestroy();
	afx_msg void OnDblclkListStats(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnColumnclickListStats(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnRadioRunning();
	afx_msg void OnRadioNormal();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	void ConvertStats();
	void ReadSavedBox();
	void ListPct();
	void ListTally();
	void ListScores();
	CFont m_font;
	void InitControls();
	CString m_print_strings[31];
	int m_stats_pointer[33];
	CBrush myBrush;
	void SetPrintAlign(CDC *pDC, HDC hdcPrn);
	CPlayer PlayerStats[31];
};


//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STATSDLG_H__0592AE01_50FA_11D1_8C1C_44455354616F__INCLUDED_)


