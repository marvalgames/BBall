#if !defined(AFX_ALLTIMEDLG_H__5CCAEA40_E2F6_11D2_8E70_444553540000__INCLUDED_)
#define AFX_ALLTIMEDLG_H__5CCAEA40_E2F6_11D2_8E70_444553540000__INCLUDED_

#ifndef High_h
#include "High.h"
#define High_h
#endif 
//#include "High.h"	// Added by ClassView

#include "MyButton.h"
#include "afxlistctrl.h"


#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#define HID_STATS_RECORDS 21
// AllTimeDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAllTimeDlg dialog

class CAllTimeDlg : public CDialog
{
// Construction
public:
	int m_default_team;
	bool m_playoff;
	CString m_fileNameAll;
	CString m_leagueName;
	CHigh high;
	CString m_fileName;
	CString m_leagueTeamNames[33];
	int m_offset;
	CAllTimeDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAllTimeDlg)
	enum { IDD = IDD_DIALOG_ALLTIME };
	CListCtrl	m_listCtrlLeaders7;
	CListCtrl	m_listCtrlLeaders6;
	CListCtrl	m_listCtrlLeaders5;
	CListCtrl	m_listCtrlLeaders4;
	CListCtrl	m_listCtrlLeaders3;
	CListCtrl	m_listCtrlLeaders2;
	MyButton	m_button_ok;
	CMyComboBox	m_listTeams;
	CListCtrl	m_listCtrlLeaders1;
	CListCtrl	m_listCtrlLeaders;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAllTimeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAllTimeDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnDestroy();
	afx_msg void OnRadioSeason();
	afx_msg void OnRadioPlayoff();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnRadioPlayoff2();
	afx_msg void OnRadioSeason2();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnSelchangeComboTeams();
	afx_msg void OnDblclkListLeaders(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void SetHeaders();
	CFont m_font;
	int m_type;
	void ListPlayoffHighs();
	void ListSeasonHighs();
	void InitListCtrl();
	CBrush myBrush;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ALLTIMEDLG_H__5CCAEA40_E2F6_11D2_8E70_444553540000__INCLUDED_)
