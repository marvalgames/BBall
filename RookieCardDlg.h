#if !defined(AFX_ROOKIECARDDLG_H__0059B456_3EC9_4BA8_ABA2_938A66BEDF42__INCLUDED_)
#define AFX_ROOKIECARDDLG_H__0059B456_3EC9_4BA8_ABA2_938A66BEDF42__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000



#ifndef Average_h
#include "Average.h"	// Added by ClassView
#define Average_h
#endif
#ifndef Player_h
#include "Player.h"
#define Player_h
#endif 

#ifndef ScoutProfileDlg_h
#include "ScoutProfileDlg.h"
#define ScoutProfileDlg_h
#endif 

#include "MyButton.h"
#include "MyListCtrl.h"

// RookieCardDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRookieCardDlg dialog

class CRookieCardDlg : public CDialog
{
// Construction
public:
	int m_pl_index_start;
	int m_pl_index_end;
	
	CString m_title;
	CStaff m_scout;
	CString m_leagueName;
	CString m_path;
	CAverage avg;
	int m_pointer;
	int m_player_index;
	CRookieCardDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CRookieCardDlg)
	enum { IDD = IDD_DIALOG_ROOKIECARD };
	MyButton	m_buttonScout;
	CMyListCtrl	m_listctrlskill;
	CMyListCtrl	m_listFuture;
	CMyListCtrl	m_listCtrlStats;
	CMyListCtrl	m_listCtrlShot;
	CListBox	m_list_report;
	CMyListCtrl	m_listctrlstats;
	CListBox	m_listPosition;
	CMyListCtrl	m_listCtrl;
	CListBox	m_list_awards;
	CString	m_edit_owner;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRookieCardDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CRookieCardDlg)
	virtual BOOL OnInitDialog();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnButtonBack();
	afx_msg void OnButtonForward();
	afx_msg void OnButtonScout();
	afx_msg void OnButtonOk();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void ListHighs();
	CString m_label[33];
	void DisplayRating();
	CPlayer m_stats[31];
	void Player();
	void InitListCtrl();

	CFont m_font;
	CBrush myBrush;
	CBrush myBrush2;
public:
	afx_msg void OnLbnSelchangeListReport2();
};


//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ROOKIECARDDLG_H__0059B456_3EC9_4BA8_ABA2_938A66BEDF42__INCLUDED_)
