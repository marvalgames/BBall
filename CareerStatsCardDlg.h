#if !defined(AFX_CAREERSTATSCARDDLG_H__0655BD0C_E950_4000_8C2B_524F131EE5DA__INCLUDED_)
#define AFX_CAREERSTATSCARDDLG_H__0655BD0C_E950_4000_8C2B_524F131EE5DA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


//#include "XListCtrl/XListCtrl.h"
#include "MyListCtrl.h"


#ifndef Player_h
#include "Player.h"
#define Player_h
#endif 

// CareerStatsCardDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCareerStatsCardDlg dialog

class CCareerStatsCardDlg : public CDialog
{
// Construction
public:
	CCareerStatsCardDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCareerStatsCardDlg)
	enum { IDD = IDD_DIALOG_CAREERSTATSCARD };
	CListBox	m_listPosition;
	CListBox	m_list_awards;
	CMyListCtrl	m_listCtrl;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCareerStatsCardDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation


public:
	int m_pl_index_start;
	int m_pl_index_end;
	
	CString m_leagueName;
	CString m_path;
	int m_pointer[1001];
	CString m_names_list[1001];
	int m_player_index;



private:
	CPlayer m_stats[31];
	CFont m_font;
	CBrush myBrush;
	CBrush myBrush2;

	
protected:

	// Generated message map functions
	//{{AFX_MSG(CCareerStatsCardDlg)
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonBack();
	afx_msg void OnButtonNext();
	afx_msg void OnColumnclickListCtrlStats(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void ListStats();
	void InitListCtrl();
	void ListPlayerAwards();
	void Player();
public:
	afx_msg void OnLvnItemchangedListCtrlStats(NMHDR* pNMHDR, LRESULT* pResult);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CAREERSTATSCARDDLG_H__0655BD0C_E950_4000_8C2B_524F131EE5DA__INCLUDED_)
