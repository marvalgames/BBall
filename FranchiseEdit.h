#if !defined(AFX_FRANCHISEEDIT_H__FFD16D60_595E_11D4_A752_444553540000__INCLUDED_)
#define AFX_FRANCHISEEDIT_H__FFD16D60_595E_11D4_A752_444553540000__INCLUDED_

#ifndef TeamFinancial_h
#include "TeamFinancial.h"
#define TeamFinancial_h
#endif 

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define HID_FINANCES_FRANCHISEEDIT 46


// FranchiseEdit.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFranchiseEdit dialog

class CFranchiseEdit : public CDialog
{
// Construction
public:
	CString m_league_team_names[33];
	CString m_league_name;
	CString m_path;
	int m_default_team;
	CTeamFinancial m_finance[101];
	CBrush myBrush; 

	CFranchiseEdit(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CFranchiseEdit)
	enum { IDD = IDD_DIALOG_FRANCHISE_EDITOR };
	CMyComboBox	m_list_teams;
	CMyComboBox	m_list_arena;
	CMyComboBox	m_list_franchise;
	UINT	m_edit_capacity;
	UINT	m_edit_club_seats;
	UINT	m_edit_suites;
	CString	m_edit_city_name;
//	CString	m_edit_team_name;
	CString	m_edit_arena;
	UINT	m_edit_comp;
	UINT	m_edit_cost;
	UINT	m_edit_eco;
	UINT	m_edit_fan;
	UINT	m_edit_int;
	UINT	m_edit_pol;
	UINT	m_edit_pop;
	UINT	m_edit_spots;
	UINT	m_edit_arena_value;
	UINT	m_edit_club_price;
	UINT	m_edit_con_price;
	UINT	m_edit_current_value;
	UINT	m_edit_suite_price;
	UINT	m_edit_ticket_price;
//	CString	m_edit_city;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFranchiseEdit)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CFranchiseEdit)
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	virtual void OnOK();
	afx_msg void OnSelchangeComboListCities();
	afx_msg void OnSelchangeComboListCities2();
	afx_msg void OnSelchangeComboListTeams();
	afx_msg void OnButtonSave();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void UpdateFranchiseData(bool update_city, bool update_arena, int current_selection, int current_selection1);
	void ListFranchises();
	void ListFranchiseProfile(bool update_city, bool update_arena,  int current_selection, int current_selection1);
	int m_current_selection;
	int m_current_selection1;
	int m_current_selection2;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FRANCHISEEDIT_H__FFD16D60_595E_11D4_A752_444553540000__INCLUDED_)
