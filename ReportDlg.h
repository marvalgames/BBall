#if !defined(AFX_REPORTDLG_H__A6FB0840_9307_11D3_8E70_B5D64F7B9350__INCLUDED_)
#define AFX_REPORTDLG_H__A6FB0840_9307_11D3_8E70_B5D64F7B9350__INCLUDED_

//#include "Player.h"	// Added by ClassView


//#include "xShadeButton.h"


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

#ifndef GamePlan_h
#include "GamePlan.h"
#define GamePlan_h
#endif 

#include "MyButton.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define HID_PLAYERS_EDITDEPTH 40


// ReportDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CReportDlg dialog

class CReportDlg : public CDialog
{
// Construction

private:

	CBitmap bitmapBkgnd;
	MyButton m_button[6];

public:
	bool m_in_game;
//	CString m_plan_strings[65];
	void InitDepthChartCombos();
	CString m_league_name;
	CString m_path;
	CAverage avg;
	
	int m_default_team;
	CString m_leagueTeamNames[33];
//	CPlayer* m_actual;
	CReportDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CReportDlg)
	enum { IDD = IDD_DIALOG_REPORT };

	CTabCtrl	m_tab;
	CMyComboBox	m_listTeams;
	//}}AFX_DATA
	CStatic	m_edit[22];
	CMyComboBox	m_combo[99];
	

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CReportDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CReportDlg)
	virtual BOOL OnInitDialog();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual void OnOK();
	afx_msg void OnSelchangeComboTeams();
	afx_msg void OnStatic1();
	afx_msg void OnSelchangeTabMenu(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnStatic10();
	afx_msg void OnStatic11();
	afx_msg void OnStatic12();
	afx_msg void OnStatic13();
	afx_msg void OnStatic14();
	afx_msg void OnStatic15();
	afx_msg void OnStatic2();
	afx_msg void OnStatic3();
	afx_msg void OnStatic4();
	afx_msg void OnStatic5();
	afx_msg void OnStatic6();
	afx_msg void OnStatic7();
	afx_msg void OnStatic8();
	afx_msg void OnStatic9();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnButtonExport();
	afx_msg void OnButtonImport();
	afx_msg void OnButtonReset();
	afx_msg void OnButtonExportall();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void DisplayReport(int index);
	void ViewPlan();
	void SavePlan();
	int m_category;
	void InitGamePlanCombos();
	void UpdateData();
	int m_current;
	void SaveRoster();
	void ViewRoster();
	void InitControls();
	CBrush myBrush;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REPORTDLG_H__A6FB0840_9307_11D3_8E70_B5D64F7B9350__INCLUDED_)
