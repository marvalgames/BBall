#if !defined(AFX_SUBSTITUTEDLG_H__A35456A1_5679_11D1_8C1C_44455354616F__INCLUDED_)
#define AFX_SUBSTITUTEDLG_H__A35456A1_5679_11D1_8C1C_44455354616F__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
#define HID_PLAYERS_SUBSTITUTE 11

// SubstituteDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSubstituteDlg dialog
#include "BBallDoc.h"
#ifndef Staff_h
#include "Staff.h"
#define Staff_h
#endif 
#ifndef MyListCtrl_h
#include "MyListCtrl.h"
#define MyListCtrl_h
#endif 

class CSubstituteDlg : public CDialog
{
// Construction
public:
	int m_roster_index;
	CStaff m_scout[101];
	CStaff m_gm[101];
	CStaff m_coach[101];
	int m_homeIndex;
	int m_visitorIndex;
	int SetCur();
	int m_index;
	bool m_toOk;
	int m_possesion;
	int Lineup[3][6];
	CString m_visitor;
	CString m_home;
	CSubstituteDlg(CWnd* pParent = NULL);   // standard constructor

		int hiFga;
		int hiTfga;
		int hiFta;
		int hiOreb;
		int hiDreb;
		int hiAst;
		int hiStl;
		int hiTo;
		int hiBlk;

// Dialog Data
	//{{AFX_DATA(CSubstituteDlg)
	enum { IDD = IDD_SUBBOX };
	CButton	m_buttonHome;
	CButton	m_buttonVisitor;
	CMyListCtrl	m_listCtrlGame;
	CMyListCtrl	m_listCtrl;
	CMyListCtrl	m_listCtrlShot;
	CMyListCtrl	m_listCtrlStats;
	CListBox	m_listRoster;
	CListBox	m_listLineup;
	CString	m_teamName;
	BOOL	m_autoSubHome;
	BOOL	m_autoSubVisitor;
	CString	m_displayString;
	//}}AFX_DATA
//	CArray< CPlayer, CPlayer& > PlayerArray;
	CPlayer PlayerArray[31];
	CPlayerStats PlayerStats[31];



// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSubstituteDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSubstituteDlg)
	afx_msg void OnButtonVisitor();
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonHome();
	afx_msg void OnDblclkListRoster();
	virtual void OnOK();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnSelchangeListRoster();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void DisplayStats();
	int m_slot;
	CBrush myBrush;
	int m_currentTeam;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SUBSTITUTEDLG_H__A35456A1_5679_11D1_8C1C_44455354616F__INCLUDED_)
