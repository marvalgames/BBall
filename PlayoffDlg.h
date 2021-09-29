#if !defined(AFX_PLAYOFFDLG_H__D359E260_A60B_11D2_8E70_444553540000__INCLUDED_)
#define AFX_PLAYOFFDLG_H__D359E260_A60B_11D2_8E70_444553540000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
#define HID_LEAGUE_PLAYOFFS 16
// PlayoffDlg.h : header file
//

#ifndef Playoff_h
#include "Playoff.h"
#define Playoff_h
#endif 



/////////////////////////////////////////////////////////////////////////////
// CPlayoffDlg dialog

class CPlayoffDlg : public CDialog
{
// Construction
public:
	CString m_leagueTeamNames[33];
	CRecord m_record[33];
	CString m_leagueName;
	CString m_path;
	CPlayoffDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPlayoffDlg)
	enum { IDD = IDD_DIALOG_PLAYOFFS };
	CListBox	m_list_results;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPlayoffDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPlayoffDlg)
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnButtonPrint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	CBrush myBrush;
	CBrush myBrush2;
	void SetPrintAlign(CDC *pDC, HDC hdcPrn);

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PLAYOFFDLG_H__D359E260_A60B_11D2_8E70_444553540000__INCLUDED_)
