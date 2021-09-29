#if !defined(AFX_TRADEBLOCKDLG_H__911920B1_15AD_4D82_8597_0917530C332D__INCLUDED_)
#define AFX_TRADEBLOCKDLG_H__911920B1_15AD_4D82_8597_0917530C332D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TradeBlockDlg.h : header file
//



#ifndef Average_h
#include "Average.h"
#define Average_h
#endif 

#include "MyButton.h"

/////////////////////////////////////////////////////////////////////////////
// CTradeBlockDlg dialog

class CTradeBlockDlg : public CDialog
{
// Construction
public:
	CString m_trans_str[2001];
	int m_default_team;
	int m_getoffersforteam;
	CAverage avg;
	CTradeBlockDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CTradeBlockDlg)
	enum { IDD = IDD_DIALOG_TRADEBLOCK };
	MyButton	m_button_getoffers;
	CMyComboBox	m_maxoffers;
	CMyComboBox	m_comboteams;
	CListCtrl	m_listblock;
	CListCtrl	m_listroster;
	BOOL	m_checkoffers;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTradeBlockDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTradeBlockDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnCheckOffers();
	afx_msg void OnButtonAdd();
	afx_msg void OnButtonRemove();
	virtual void OnOK();
	afx_msg void OnButtonGetoffers();
	afx_msg void OnSelchangeComboTeams();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnDblclkListRoster(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDblclkListBlock(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	int m_players_on_block;
	CFont m_font;
	CBrush myBrush;
//CBitmap bitmapBkgnd;
	void ListBlock();
	void ListRoster();
	void InitData();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRADEBLOCKDLG_H__911920B1_15AD_4D82_8597_0917530C332D__INCLUDED_)
