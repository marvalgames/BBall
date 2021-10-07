#if !defined(AFX_OFFERTRADES1_H__04B48240_CFB3_11D2_8E70_444553540000__INCLUDED_)
#define AFX_OFFERTRADES1_H__04B48240_CFB3_11D2_8E70_444553540000__INCLUDED_

#include "BBall.h"
//#include "constants.h"
//#include "resource.h"


#ifndef Player_h
#include "Player.h"
#define Player_h
#endif 

#ifndef Staff_h
#include "Staff.h"
#define Staff_h
#endif 
#ifndef Average_h
#include "Average.h"
#define Average_h
#endif 


#include "MyButton.h"
#include "MyListCtrl.h"


#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#define HID_OFFER_TRADE 27
// OfferTrades.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// COfferTrades dialog

class COfferTrades : public CDialog
{
// Construction
public:
	bool m_trade_made_via_trading_screen;
	int m_player_list[11];
	int m_standing_team;
	CString m_leagueTeamNames[33];
	int m_current_year;
	int m_value_picks1[4];
	int m_value_picks2[4];
	CString m_control[33];
	CAverage avg;
	CString m_leagueName;
	CString m_path;
	int m_team1;
	int m_team2; 
//	CString m_fileName;
	CStaff m_scout[101];
	CStaff m_gm[101];
	CStaff m_coach[101];	
	CPlayer NewTeam[41];
	int players[41];
	COfferTrades(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(COfferTrades)
	enum { IDD = IDD_DIALOG_OFFERTRADE };
	CMyListCtrl	m_listVisitor;
	CMyListCtrl	m_listTeam2;
	CMyListCtrl	m_listTeam1;
	CMyListCtrl	m_listHome;
	MyButton	m_buttonScoutVisitor;
	MyButton	m_buttonScoutHome;
	CString	m_team1Name;
	CString	m_team2Name;
	CString	m_teamOffering;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COfferTrades)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(COfferTrades)
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonScoutVisitor();
	afx_msg void OnButtonScoutHome();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnDblclkListCtrlHomeRoster(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDblclkListCtrlVisitorRoster(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnButtonTrade();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void InitControls();
	CFont m_font;
	CBrush myBrush;
	CPlayer *m_player;
public:
	afx_msg void OnLvnItemchangedListCtrlHomeRoster(NMHDR* pNMHDR, LRESULT* pResult);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OFFERTRADES1_H__04B48240_CFB3_11D2_8E70_444553540000__INCLUDED_)
