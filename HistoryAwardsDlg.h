#if !defined(AFX_HISTORYAWARDSDLG_H__26D4B983_05C1_11D5_B185_444553540000__INCLUDED_)
#define AFX_HISTORYAWARDSDLG_H__26D4B983_05C1_11D5_B185_444553540000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#ifndef XListCtrl_h
//#include "XListCtrl/XListCtrl.h"
#define XListCtrl_h
#endif 


//#ifndef PropSheet_h
//#include "PropSheet.h"
//#define PropSheet_h
//#endif 
// HistoryAwardsDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CHistoryAwardsDlg dialog

class CHistoryAwardsDlg : public CDialog
{
// Construction
public:
	CString m_file_name, m_path , m_league_name;
    CString m_league_team_names[33];
	CHistoryAwardsDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CHistoryAwardsDlg)
	enum { IDD = IDD_DIALOG_HISTORY_AWARDS };
	CListCtrl	m_list_players;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHistoryAwardsDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CHistoryAwardsDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnRadioMvp();
	afx_msg void OnRadioDefense();
	afx_msg void OnRadioRookies();
	afx_msg void OnRadioAssists();
	afx_msg void OnRadioBlocks();
	afx_msg void OnRadioPoints();
	afx_msg void OnRadioRebounds();
	afx_msg void OnRadioSteals();
	afx_msg void OnRadioPlayoff();
	afx_msg void OnRadio6th();
	afx_msg void OnRadioChampion();
	afx_msg void OnDblclkListPlayers(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnRadioAllstar();
	afx_msg void OnRadioRookiestar();
	afx_msg void OnRadioThree();
	afx_msg void OnRadioDunk();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void Listdunkcontest();
	void ListThreecontest();
	void ListRookiestarMVP();
	void ListAllstarMVP();
	int m_current_exp_count;
	void ReadOriginalNames();
	CString m_original_names[33][33];
	void SetCursor();
	CFont m_font;
	CBrush myBrush; 
	int m_lines;
	int m_start_year;
	int m_pointer[5000];
	CString m_names_list[5000];
	int m_mvp[5000];
	int m_6th[5000];
    int m_po_mvp_team_index[5000];
	int m_po_mvp[5000];
    int m_mvp_team_index[5000];
    int m_6th_team_index[5000];
	int m_defense[5000];
    int m_defense_team_index[5000];
	int m_rookie[5000];
    int m_rookie_team_index[5000];

	int m_allstar[5000];
	int m_allstar_index[5000];

	int m_rookiestar[5000];
	int m_rookiestar_index[5000];

	int m_3contest[5000];
	int m_3contest_index[5000];

	int m_dunkcontest[5000];
	int m_dunkcontest_index[5000];

	int m_pts[5000];
    int m_pts_team_index[5000];
	int m_pts_avg[5000];

	int m_reb[5000];
    int m_reb_team_index[5000];
	int m_reb_avg[5000];

	int m_ast[5000];
    int m_ast_team_index[5000];
	int m_ast_avg[5000];

	int m_stl[5000];
    int m_stl_team_index[5000];
	int m_stl_avg[5000];

	int m_blk[5000];
    int m_blk_team_index[5000];
	int m_blk_avg[5000];

	int m_champ[5000];

	int m_exp_count[5000];

	void ReadAwards();
	void ListMvp();
	void List6th();
	void ListPoMvp();
	void ListDefense();
	void ListRookie();
	void ListPts();
	void ListReb();
	void ListAst();
	void ListStl();
	void ListBlk();
	void ListChampion();
	void InitControls();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HISTORYAWARDSDLG_H__26D4B983_05C1_11D5_B185_444553540000__INCLUDED_)
