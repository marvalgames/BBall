#if !defined(AFX_SEARCHDLG_H__AD33A020_F03D_11D4_B185_444553540000__INCLUDED_)
#define AFX_SEARCHDLG_H__AD33A020_F03D_11D4_B185_444553540000__INCLUDED_

#ifndef Average_h
#include "Average.h"
#define Average_h
#endif 
#ifndef Staff_h
#include "Staff.h"
#define Staff_h
#endif 
#include "MyButton.h"
#include "MyListCtrl.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SearchDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSearchDlg dialog

class CSearchDlg : public CDialog
{
// Construction
public:
	CString m_league_team_names[33];
	int m_team_index;
	CString m_path;
	CString m_league_name;
	int m_selected_player_id; 
	CStaff m_scout;
	CAverage avg;
	CSearchDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSearchDlg)
	enum { IDD = IDD_DIALOG_SEARCH };
	CMyComboBox	m_combo_fayrs;
	MyButton	m_button_ok;
	CMyComboBox	m_combo_age;
	CMyComboBox	m_combo_ppg;
	CMyComboBox	m_combo_blkpg;
	CMyComboBox	m_combo_stlpg;
	CMyComboBox	m_combo_astpg;
	CMyComboBox	m_combo_rpg;
	CMyComboBox	m_combo_ftppg;
	CMyComboBox	m_combo_tgppg;
	CMyComboBox	m_combo_fgppg;
	CMyComboBox	m_combo_mpg;
	CMyComboBox	m_combo_teams;
	CMyComboBox	m_combo_pos;
	CMyComboBox	m_combo_blk;
	CMyComboBox	m_combo_to;
	CMyComboBox	m_combo_stl;
	CMyComboBox	m_combo_ast;
	CMyComboBox	m_combo_drb;
	CMyComboBox	m_combo_orb;
	CMyComboBox	m_combo_ftp;
	CMyComboBox	m_combo_fta;
	CMyComboBox	m_combo_tgp;
	CMyComboBox	m_combo_tga;
	CMyComboBox	m_combo_fgp;
	CMyComboBox	m_combo_oo;
	CMyComboBox	m_combo_do;
	CMyComboBox	m_combo_poo;
	CMyComboBox	m_combo_tro;
	CMyComboBox	m_combo_od;
	CMyComboBox	m_combo_dd;
	CMyComboBox	m_combo_pd;
	CMyComboBox	m_combo_td;
	CMyListCtrl	m_list_players;
	MyButton	m_button_find;
	CMyComboBox	m_combo_max_sal;
	CMyComboBox	m_combo_min_sal;
	CMyComboBox	m_combo_fga;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSearchDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSearchDlg)
	virtual BOOL OnInitDialog();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnButtonFind();
	afx_msg void OnDblclkListPlayers(NMHDR* pNMHDR, LRESULT* pResult);
	virtual void OnOK();
	afx_msg void OnColumnclickListPlayers(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnClickListPlayers(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CBrush myBrush;
	int m_pointers[1601];
	int m_count;
	bool SortStats(CPlayer m_actual_i, CPlayer m_actual_j);
	bool SortFunction(CPlayer m_player, CPlayer temp);
	void QuickSort();
	int m_column;
	int m_pointer[1601];
	void SetScoutRatings();
	CFont m_font;
	void InitControls();
	void ListPlayers();
	int m_min_sal;
	int	m_max_sal;
	int m_search_fayrs;
	int	m_search_fga;
	int	m_search_fgp;
	int	m_search_tga;
	int	m_search_tgp;
	int	m_search_fta;
	int	m_search_ftp;
	int	m_search_orb;
	int	m_search_drb;
	int	m_search_ast;
	int	m_search_stl;
	int	m_search_to; 
	int	m_search_blk;
	int m_search_age;

	int m_search_oo;
	int m_search_do;
	int m_search_poo;
	int m_search_tro;

	int m_search_od;
	int m_search_dd;
	int m_search_pd;
	int m_search_td;



	double m_search_mpg;
	double m_search_fgppg;		
	double m_search_ftppg;
	double m_search_tgppg;		
	double m_search_rebpg;
	double m_search_astpg;
	double m_search_stlpg;
	double m_search_blkpg;
	double m_search_ppg;


	CString m_search_team;
	CString m_search_po;

public:
	afx_msg void OnLvnItemchangedListPlayers(NMHDR* pNMHDR, LRESULT* pResult);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SEARCHDLG_H__AD33A020_F03D_11D4_B185_444553540000__INCLUDED_)
