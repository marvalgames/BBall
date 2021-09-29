#if !defined(AFX_SCOUTPROFILEDLG_H__CF136A01_8963_11D3_8E70_444553540000__INCLUDED_)
#define AFX_SCOUTPROFILEDLG_H__CF136A01_8963_11D3_8E70_444553540000__INCLUDED_

//#include "Staff.h"	// Added by ClassView
#ifndef Staff_h
#include "Staff.h"
#define Staff_h
#endif 

#ifndef XListCtrl_h
//#include "XListCtrl/XListCtrl.h"
#define XListCtrl_h
#endif 


#ifndef ScoutEditDlg_h
#include "ScoutEditDlg.h"
#define ScoutEditDlg_h
#endif


#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define HID_SCOUT_PROFILE 39
// ScoutProfileDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CScoutProfileDlg dialog

class CScoutProfileDlg : public CDialog
{
// Construction
public:
	CStaff m_scout;
	int m_type;
	CScoutProfileDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CScoutProfileDlg)
	enum { IDD = IDD_DIALOG_SCOUT_PROFILE };
	CListCtrl	m_list_scouting;
	CListCtrl	m_list_development;
	CListCtrl	m_list_data;
	CListCtrl	m_list_coaching;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScoutProfileDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CScoutProfileDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnButtonEdit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void ListDevelopment();
	void ListCoaching();
	void ListScouting();
	CFont m_font;
	CBrush myBrush; 
	void ListData();
	void InitListCtrl();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCOUTPROFILEDLG_H__CF136A01_8963_11D3_8E70_444553540000__INCLUDED_)
