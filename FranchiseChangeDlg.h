#if !defined(AFX_FRANCHISECHANGEDLG_H__D867E300_7C4D_11D4_B185_D40C67F2E239__INCLUDED_)
#define AFX_FRANCHISECHANGEDLG_H__D867E300_7C4D_11D4_B185_D40C67F2E239__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define HID_FINANCES_FRANCHISECHANGE 45


#ifndef TeamFinancial_h
#include "TeamFinancial.h"
#define TeamFinancial_h
#endif 
#ifndef Average_h
#include "Average.h"
#define Average_h
#endif 
#ifndef Record_h
#include "Record.h"
#define Record_h
#endif 
#ifndef Staff_h
#include "Staff.h"
#define Staff_h
#endif 

//#include "TeamFinancial.h"
#ifndef Future_h
#include "Future.h"
#define Future_h
#endif 


#ifndef XListCtrl_h
//#include "XListCtrl/XListCtrl.h"
#define XListCtrl_h
#endif 

#include "MyButton.h"
#include "MyListCtrl.h"

// FranchiseChangeDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFranchiseChangeDlg dialog

class CFranchiseChangeDlg : public CDialog
{
// Construction
public:
	int m_hi_games;
	double m_tru;
	bool m_ok;
	CString m_path;
	CString m_league_name;
	CRecord m_standings[33];
	CString m_control[33];
	int m_default_team;
	int m_number_teams;
	CString m_file_name;
	CStaff m_coach[33];
	CTeamFinancial m_finance[201];
	CFuture m_future[101];
	CPlayer m_actual[1601];
	CFranchiseChangeDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CFranchiseChangeDlg)
	enum { IDD = IDD_DIALOG_FRANCHISE_CHANGE };
	CMyComboBox	m_list_teams;
	MyButton	m_button_cancel;
	MyButton	m_button_ok;
	CListBox	m_list_control;
	MyButton	m_button_end;
	CListBox	m_list_result;
	MyButton	m_button_move;
	CMyListCtrl	m_list_ctrl;
	UINT	m_edit_capacity;
	UINT	m_edit_club;
	UINT	m_edit_pct;
	UINT	m_edit_cost;
	UINT	m_edit_suites;
	UINT	m_edit_team_cost;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFranchiseChangeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CFranchiseChangeDlg)
	virtual BOOL OnInitDialog();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnButtonMove();
	afx_msg void OnClickListControl(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnButtonEnd();
	afx_msg void OnKillfocusEditCapacity();
	afx_msg void OnKillfocusEditClub();
	afx_msg void OnKillfocusEditContribution();
	afx_msg void OnKillfocusEditSuites();
	virtual void OnOK();
	afx_msg void OnKillfocusEditTeamCost();
	afx_msg void OnSelchangeListControlMove();
	afx_msg void OnDblclkListControl(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnColumnclickListControl(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnKillfocusEditCost();
	afx_msg void OnSetfocusEditCapacity();
	afx_msg void OnSetfocusEditClub();
	afx_msg void OnSetfocusEditSuites();
	afx_msg void OnSetfocusEditCost();
	afx_msg void OnSetfocusEditContribution();
	afx_msg void OnSelchangeComboTeams();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void EnableEditBoxes(BOOL enable);
	void ListMovement();
	int m_column;
	bool m_stage_end;
	CBrush myBrush;
	CBrush myBrush2;
	void ListControl();
	void DisplayComputerProposals();
	void ComputerProposals();
	void CheckButton();
//	void CalculateMinCost();
	void ListArenaData();
	void ListFinalResult();
	int m_current_city;
	void InitVariables();
	int m_current_team;
	void ListResult();
	void SetColumnHeaders();
	CFont m_font;
	void ListData();
	void InitListCtrl();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FRANCHISECHANGEDLG_H__D867E300_7C4D_11D4_B185_D40C67F2E239__INCLUDED_)
