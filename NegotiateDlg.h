#if !defined(AFX_NEGOTIATEDLG_H__19A3CCA0_FA4C_11D3_A752_444553540000__INCLUDED_)
#define AFX_NEGOTIATEDLG_H__19A3CCA0_FA4C_11D3_A752_444553540000__INCLUDED_



#ifndef HireStaff_h
#include "HireStaff.h"	
#define HireStaff_h
#endif 

#ifndef XListCtrl_h
//#include "XListCtrl/XListCtrl.h"
#define XListCtrl_h
#endif 

#include "MyButton.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define HID_FINANCES_FRANCHISENEGOTIATE 47


// NegotiateDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CNegotiateDlg dialog

class CNegotiateDlg : public CDialog
{
// Construction
public:
	double m_tru;
	int game_season;
	int m_pointer_id;
	bool m_content_changed;
	int m_player_pointer;
	bool m_offer_cleared;
	int m_pointer;
	bool m_signed_extension;
	int m_coach_rating;
	int m_number_teams;
	bool m_negotiate_extension;
	CString m_league_team_names[33];

	int m_cap;
	int m_salary_cap;
	CHireStaff m_owner;
	int m_team_negotiating;
	int m_total_yrs;
	int m_total_salary;
	int m_yr_salary[7];
	CPlayer m_player;
	CNegotiateDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CNegotiateDlg)
	enum { IDD = IDD_DIALOG_NEGOTIATE };
	CMyComboBox	m_combo_mid_years;
	MyButton	m_button_clear;
	CListCtrl	m_list_ctrl_bid;
	CStatic	m_static_y6;
	CListCtrl	m_list_ctrl;
	UINT	m_edit1;
	UINT	m_edit2;
	UINT	m_edit3;
	UINT	m_edit4;
	UINT	m_edit5;
	UINT	m_edit6;
	CString	m_edit_choice_1;
	CString	m_edit_choice_2;
	CString	m_edit_choice_3;
	CString	m_edit_bird;
	BOOL	m_check_allow;
	CString	m_edit_payroll;
	CString	m_edit_owner_cap;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNegotiateDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CNegotiateDlg)
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	virtual void OnOK();
	afx_msg void OnRadioMinExc();
	afx_msg void OnRadioMin();
	afx_msg void OnRadioMid();
	afx_msg void OnRadioEdit();
	afx_msg void OnRadioMax();
	afx_msg void OnButtonClear();
	afx_msg void OnSelchangeComboMidYears();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void Analyze();
	void EvaluateExtensionOffer();
	int m_seeking_factor;
	void SetExtensionRequest();
	bool m_no_ratings;
	bool m_over_owner_cap;
	int m_maximum[31];
	void SetListCtrlHeaders();
	CString m_label[33];
	CFont m_font;
	void ListStats();
	void InitLabels();
	int m_category;
	bool AllowMinimum();
	bool m_exception;
	bool AffordContract();
	bool DataOK();
	UINT min[7];
	UINT max[7];
	CBrush myBrush; 
	int m_minimum[11];
	void SetMinMaxSalaries(int player_max_money);
	void InitControls();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NEGOTIATEDLG_H__19A3CCA0_FA4C_11D3_A752_444553540000__INCLUDED_)
