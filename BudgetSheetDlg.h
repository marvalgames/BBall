#if !defined(AFX_BUDGETSHEETDLG_H__2F3221E0_3F82_11D4_A752_444553540000__INCLUDED_)
#define AFX_BUDGETSHEETDLG_H__2F3221E0_3F82_11D4_A752_444553540000__INCLUDED_

#ifndef TeamFinancial_h
#include "TeamFinancial.h"
#define TeamFinancial_h
#endif 

#ifndef XListCtrl_h
//#include "XListCtrl/XListCtrl.h"
#define XListCtrl_h
#endif 


#include "MyButton.h"
#include "MyListCtrl.h"



//#ifndef Average_h
//#include "Average.h"
//#define Average_h
//#endif 

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define HID_FINANCES_BUDGETSHEET 43


// BudgetSheetDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBudgetSheetDlg dialog

class CBudgetSheetDlg : public CDialog
{
// Construction
public:
//	CAverage avg;
	bool m_ok;
	int m_number_teams;
	int m_default_team;
	CString m_control[33];
	int m_hi_games;
	CString m_league_name;
	CString m_path;
	CTeamFinancial m_finance[201];
	CBudgetSheetDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CBudgetSheetDlg)
	enum { IDD = IDD_DIALOG_BUDGET_SHEET };
	MyButton m_button[4];
	MyButton	m_button_cancel;
	MyButton	m_edit_ok;
	CListBox	m_list_control;
	CMyListCtrl	m_list_stats;
	CMyListCtrl	m_list_ctrl;
	UINT	m_edit_ticket_price;
	UINT	m_edit_suite_price;
	UINT	m_edit_con_price;
	UINT	m_edit_club_price;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBudgetSheetDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation


protected:

	// Generated message map functions
	//{{AFX_MSG(CBudgetSheetDlg)
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	virtual BOOL OnInitDialog();
	afx_msg void OnDblclkListControl(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnClickListControl(NMHDR* pNMHDR, LRESULT* pResult);
	virtual void OnOK();
	afx_msg void OnRadioExpenses();
	afx_msg void OnRadioRevenues();
	afx_msg void OnRadioCity();
	afx_msg void OnRadioArena();
	afx_msg void OnSelchangeListControlTeams();
	afx_msg void OnColumnclickListControl(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void PassMembers();
	void ClickListControlFunction();
	void SortCities();
	void SortArenas();
	void SortRevenues();
	void SortExpenses();
	int m_column;
	void ListControl();
//	int m_category_year;
	CBrush myBrush;
	void ListDataRevenue();
	void ListDataCity();
	void ListDataArena();
	void SetListBoxHeaders();
	void SetColumnHeadersArena();
	void SetColumnHeadersRevenues();
	void SetColumnHeadersCity();
	int m_category;
	
	void ListEditableData();
	void UpdateFranchiseData();
	CString m_label[65];
	void InitLabels();
	int m_current_choice;
	void ListStats();
	CString m_print_strings[51][26];
	CFont m_font;
	int m_co;
	void ListData();
	void SetColumnHeaders();
	void InitListCtrl();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BUDGETSHEETDLG_H__2F3221E0_3F82_11D4_A752_444553540000__INCLUDED_)
