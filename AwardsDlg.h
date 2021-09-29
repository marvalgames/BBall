#if !defined(AFX_AWARDSDLG_H__26D4B982_05C1_11D5_B185_444553540000__INCLUDED_)
#define AFX_AWARDSDLG_H__26D4B982_05C1_11D5_B185_444553540000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "afxlistctrl.h"


#ifndef Average_h
#include "Average.h"
#define Average_h
#endif 

// AwardsDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAwardsDlg dialog

class CAwardsDlg : public CDialog
{
// Construction
public:
	CString m_path;
	CString m_league_name;
	


	int m_mvp[11];
	int m_6th[11];
	int m_po_mvp;
	int m_defense[11];
	int m_rookie[11];
	int m_pts[11];
	int m_reb[11];
	int m_ast[11];
	int m_stl[11];
	int m_blk[11];
	int m_all_league[6][4];
	int m_all_defense[6][4];
	int m_all_rookie[6][4];

	CAwardsDlg(CWnd* pParent = NULL);   // standard constructor
    CAverage avg;
// Dialog Data
	//{{AFX_DATA(CAwardsDlg)
	enum { IDD = IDD_DIALOG_AWARDS };
	CListCtrl	m_list_all_rookie;
	CListCtrl	m_list_all_league;
	CListCtrl	m_list_all_defense;
	CListCtrl	m_list_6th;
	CListCtrl	m_list_leaders;
	CListCtrl	m_list_rookie;
	CListCtrl	m_list_defense;
	CListCtrl	m_list_mvp;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAwardsDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAwardsDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnRadioPoints();
	afx_msg void OnRadioRebounds();
	afx_msg void OnRadioBlocks();
	afx_msg void OnRadioAssists();
	afx_msg void OnRadioSteals();
	afx_msg void OnRadioMvp();
	afx_msg void OnRadioPlayoff();
	afx_msg void OnRadioAllLeague1();
	afx_msg void OnRadioAllLeague2();
	afx_msg void OnRadioAllLeague3();
	afx_msg void OnRadioAllDefense1();
	afx_msg void OnRadioAllDefense2();
	afx_msg void OnRadioAllDefense3();
	afx_msg void OnRadioAllRookie7();
	afx_msg void OnRadioAllRookie8();
	afx_msg void OnRadioAllRookie9();
	afx_msg void OnDblclkList6th(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDblclkListAllDefense(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDblclkListAllLeague(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDblclkListAllRookie(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDblclkListDefense(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDblclkListLeaders(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDblclkListMvp(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDblclkListRookies(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CBrush myBrush;
	CFont m_font;
	int m_defense_pointer[11];
	int m_mvp_pointer[11];
	int m_rookie_pointer[11];
	int m_6th_pointer[11];
	int m_leaders_pointer[11];
	int m_all_league_pointer[11];
	int m_all_defense_pointer[11];
	int m_all_rookie_pointer[11];
	int m_category;
	int m_mvp_category;
	int m_all_league_category;
	int m_all_defense_category;
	int m_all_rookie_category;
	void ListDefense();
	void ListMvp();
	void ListRookie();
	void List6th();
	void ListLeaders();
	void ListAllLeague();
	void ListAllDefense();
	void ListAllRookie();
	
	void InitControls();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AWARDSDLG_H__26D4B982_05C1_11D5_B185_444553540000__INCLUDED_)
