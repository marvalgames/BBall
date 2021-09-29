#if !defined(AFX_HISTORYSTATS_H__F33A7861_242D_11D3_8E70_444553540000__INCLUDED_)
#define AFX_HISTORYSTATS_H__F33A7861_242D_11D3_8E70_444553540000__INCLUDED_

//#include "Player.h"	// Added by ClassView
#ifndef Player_h
#include "Player.h"
#define Player_h
#endif 

#ifndef Career_h
#include "Career.h"
#define Career_h
#endif 

#ifndef XListCtrl_h
//#include "XListCtrl/XListCtrl.h"
#define XListCtrl_h
#endif 

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#define HID_HISTORY_CAREER 32
// HistoryStats.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CHistoryStats dialog

class CHistoryStats : public CDialog
{
// Construction
public:
	CString m_leagueName;
	CString m_path;
	CHistoryStats(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CHistoryStats)
	enum { IDD = IDD_DIALOG_HISTORYSTATS };
	CMyComboBox	m_listYears;
	CMyComboBox	m_listPlayers;
	CListBox	m_list_awards;
	CListBox	m_listDraft;
	CListCtrl	m_listCtrl;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHistoryStats)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CHistoryStats)
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	virtual BOOL OnInitDialog();
	afx_msg void OnDblclkListCtrlStats(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnDestroy();
	afx_msg void OnSelchangeComboListPlayers();
	afx_msg void OnSelchangeComboListYears();
	afx_msg void OnColumnclickListCtrlStats(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnButtonBack();
	afx_msg void OnButtonNext();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void ShowStuff(int pointer);
	bool m_exists;
	void ListAwards();
	CString names[99999];
	CString positions[99999];
	void SortPlayers();
	CBrush myBrush;
	CBrush myBrush2;
	CFont m_font;
	void ListStats();
	CPlayer* m_stats;
	int m_slot[1001];
	void InitListCtrl();
	int m_id;
	void GetCurrentID();
	void FillListYears();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HISTORYSTATS_H__F33A7861_242D_11D3_8E70_444553540000__INCLUDED_)
