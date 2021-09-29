#if !defined(AFX_DEFENSEDLG_H__3800F780_BA16_11D2_8E70_DA16EA615310__INCLUDED_)
#define AFX_DEFENSEDLG_H__3800F780_BA16_11D2_8E70_DA16EA615310__INCLUDED_

//#include "Player.h"	// Added by ClassView
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
#define HID_PLAYERS_DEFENSE 17

// DefenseDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDefenseDlg dialog
#include "BBallDoc.h"
#ifndef Average_h
#include "Average.h"
#define Average_h
#endif 

#ifndef XListCtrl_h
//#include "XListCtrl/XListCtrl.h"
#define XListCtrl_h
#endif 

#include "MyButton.h"
#include "MyComboBox.h"

//#include "Average.h"	// Added by ClassView
//#include "Player.h"	// Added by ClassView

class CDefenseDlg : public CDialog
{
// Construction
public:
	int m_other_index;
	CAverage avg;
	
	int m_home_index;
	int m_visitor_index;
	CString m_league_name;
	CString m_path;
	int m_match[11];
	int m_index;
	int m_possesion;
	CString m_home;
	CString m_visitor;
	int Defense[3][6];
	int Lineup[3][6];
	CDefenseDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDefenseDlg)
	enum { IDD = IDD_DIALOG_DEFENSE };
	CMyComboBox	m_listSg;
	CMyComboBox	m_listSf;
	CMyComboBox	m_listPf;
	CMyComboBox	m_listC;
	CMyComboBox	m_listPg;
	CListCtrl	m_listCtrlDef;
	CListCtrl	m_listCtrlOff;
	CListBox	m_listDefense;
	CListBox	m_listOffense;
	MyButton	m_buttonVisitor;
	MyButton	m_buttonHome;
	CString	m_teamName;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDefenseDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDefenseDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonHome();
	afx_msg void OnButtonVisitor();
	afx_msg void OnDblclkListDefense();
	virtual void OnOK();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnDblclkListCtrlOffense(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDblclkListCtrlDefense(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CFont m_font1;
	CFont m_font;
//	int m_lastClicked;
	void SetMatchArray(int start);
	void MatchupSelections(int start);
	void FillLists();
	void DisplayReport();
	CBrush myBrush;
	CBrush myBrush2;
	int m_team;
	void DisplayMatchups();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEFENSEDLG_H__3800F780_BA16_11D2_8E70_DA16EA615310__INCLUDED_)
