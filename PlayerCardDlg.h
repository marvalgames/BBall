#if !defined(AFX_PLAYERCARDDLG_H__5F4E7641_57D0_11D6_9B5D_9B1D0C92617A__INCLUDED_)
#define AFX_PLAYERCARDDLG_H__5F4E7641_57D0_11D6_9B5D_9B1D0C92617A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


//#include "XListCtrl/XListCtrl.h"
#ifndef Average_h
#include "Average.h"	// Added by ClassView
#define Average_h
#endif
#ifndef Player_h
#include "Player.h"
#define Player_h
#endif 
#include "MyButton.h"
#include "afxlistctrl.h"
#ifndef ScoutProfileDlg_h
#include "ScoutProfileDlg.h"
#define ScoutProfileDlg_h
#endif 
//#include "Staff.h"	// Added by ClassView


// PlayerCardDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPlayerCardDlg dialog

class CPlayerCardDlg : public CDialog
{
// Construction
public:
	int m_data_slot;
	bool m_extension_allowed;
	int m_pl_index_start;
	int m_pl_index_end;
	int m_default_scout;
	CString m_title;
	CStaff m_scout;
	CString m_leagueName;
	CString m_path;
	CAverage avg;
	int m_pointer;
	int m_player_index;
	CPlayerCardDlg(CWnd* pParent = NULL);   // standard constructor
	~CPlayerCardDlg(void);
	//CListCtrl::~CListCtrl(void)
//{

//}
// Dialog Data
	//{{AFX_DATA(CPlayerCardDlg)
	enum { IDD = IDD_DIALOG_PLAYERCARD };
	MyButton	m_button_extend;
	CListCtrl	m_list_highs;
	CListCtrl	m_list_ctrl_3;
	CListCtrl	m_list_ctrl_2;
	CListCtrl	m_list_ctrl_1;
	MyButton	m_buttonScout;
	CListCtrl	m_listctrlskill;
	CListCtrl	m_listFuture;
	CListCtrl	m_listCtrlStats;
	CListCtrl	m_listCtrlShot;
	CListBox	m_list_report;
	CListCtrl	m_listctrlstats;
	CListBox	m_listPosition;
	CListCtrl	m_listCtrl;
	CListBox	m_list_awards;
	CString	m_edit_owner;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPlayerCardDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPlayerCardDlg)
	afx_msg void OnColumnclickListCtrlStats(NMHDR* pNMHDR, LRESULT* pResult);
	virtual BOOL OnInitDialog();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnButtonBack();
	afx_msg void OnButtonForward();
	afx_msg void OnButtonScout();
	afx_msg void OnButtonExtend();
	afx_msg void OnMove(int x, int y);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void ListHighs();
	CString m_label[33];
	void DisplayRating();
	void ListSeasonStats();
	void ListStats();
	CPlayer m_stats[31];
	void Player();
	void ListPlayerAwards();
	void InitListCtrl();
	CBitmap bitmapBkgnd;
	//CBitmap bm;
	CFont m_font;
	CBrush myBrush;
	CBrush myBrush2;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PLAYERCARDDLG_H__5F4E7641_57D0_11D6_9B5D_9B1D0C92617A__INCLUDED_)
