#if !defined(AFX_CITYPROFILEDLG_H__5A62F1E0_B5BC_11D4_B185_444553540000__INCLUDED_)
#define AFX_CITYPROFILEDLG_H__5A62F1E0_B5BC_11D4_B185_444553540000__INCLUDED_

#ifndef TeamFinancial_h
#include "TeamFinancial.h"
#define TeamFinancial_h
#endif 


#include "MyListCtrl.h"




#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define HID_FINANCES_CITYPROFILE 44

// CityProfileDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCityProfileDlg dialog

class CCityProfileDlg : public CDialog
{
// Construction
public:
	int m_hi_games;
	CFont m_font;
	CBrush myBrush;
	CTeamFinancial m_finance[201];
	CCityProfileDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCityProfileDlg)
	enum { IDD = IDD_DIALOG_CITY_PROFILE };
	CMyListCtrl	m_list_revenues;
	CMyListCtrl	m_list_expenses;
	CMyListCtrl	m_list_city;
	CMyListCtrl	m_list_arena;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCityProfileDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCityProfileDlg)
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void ListCity();
	void ListArena();
	void ListRevenues();
	void SetListBoxHeaders();
	CString m_label[6][26];
	void ListExpenses();
	void InitLabels();
	void InitListCtrl();
public:
	afx_msg void OnBnClickedOk();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CITYPROFILEDLG_H__5A62F1E0_B5BC_11D4_B185_444553540000__INCLUDED_)
