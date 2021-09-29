#ifndef Player_h
#include "Player.h"
#define Player_h
#endif 



#if !defined(AFX_MISCDLG_H__3B5980A0_104B_11D4_A752_444553540000__INCLUDED_)
#define AFX_MISCDLG_H__3B5980A0_104B_11D4_A752_444553540000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define HID_EDIT_OFF_COURT_RATINGS 49


// MiscDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMiscDlg dialog

class CMiscDlg : public CDialog
{
// Construction
public:
	CMiscDlg(CWnd* pParent = NULL);   // standard constructor

	CPlayer m_contract;

// Dialog Data
	//{{AFX_DATA(CMiscDlg)
	enum { IDD = IDD_DIALOG_MISC_RATINGS };
	CMyComboBox	m_combo_current_contract_yr;
	BOOL	m_check_random_yrs;
	UINT	m_edit_yrs_pro;
	UINT	m_edit_yrs_team;
	UINT	m_edit_intangibles;
	UINT	m_edit_skill;
	UINT	m_edit_talent;
	BOOL	m_check_career_projections;
	BOOL	m_check_contract;
	BOOL	m_check_ratings;
	UINT	m_edit_coach;
	UINT	m_edit_loyalty;
	UINT	m_edit_pt;
	UINT	m_edit_security;
	UINT	m_edit_tradition;
	UINT	m_edit_winning;
	UINT	m_edit_year_1;
	UINT	m_edit_year_2;
	UINT	m_edit_year_3;
	UINT	m_edit_year_4;
	UINT	m_edit_year_5;
	UINT	m_edit_year_6;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMiscDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMiscDlg)
	virtual BOOL OnInitDialog();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void DisplayRatings();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MISCDLG_H__3B5980A0_104B_11D4_A752_444553540000__INCLUDED_)
