#if !defined(AFX_PROGRESSVIEW_H__A7282DEA_35FB_11D6_9B5D_444553540000__INCLUDED_)
#define AFX_PROGRESSVIEW_H__A7282DEA_35FB_11D6_9B5D_444553540000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ProgressView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CProgressView form view

#include "MyButton.h"

#ifndef ShadeButtonST
#include "ShadeButtonST.h"
#define ShadeButtonST
#endif 

#include "MyBitmap.h"

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CProgressView : public CFormView
{

public:
	CProgressView();           // protected constructor used by dynamic creation


protected:
	DECLARE_DYNCREATE(CProgressView)

// Form Data
public:
	//{{AFX_DATA(CProgressView)
	enum { IDD = IDD_DIALOG_PROGRESS };
	MyButton	m_button_expand;
	MyButton m_button_go;
	MyButton	m_button_tools;
	MyButton	m_button_standings;
	MyButton	m_button_staffs;
	MyButton	m_button_setup;
	MyButton	m_button_schedule;
	MyButton	m_button_rookies;
	MyButton	m_button_progress;
	MyButton	m_button_history;
	MyButton	m_button_fa;
	MyButton	m_button_end;
	MyButton	m_button_camp;
	MyButton	m_button_budget;
	MyButton	m_button_arena;
	CMyComboBox	m_combo_teams;
	//}}AFX_DATA

// Attributes
public:

//	CMyBitmap bitmapBkgnd;

// Operations
public:
	void SetFromDoc();
	BOOL SetToDoc();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProgressView)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
//	virtual void OnDraw(CDC* pDC);
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CProgressView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CProgressView)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnButtonProgress();
	afx_msg void OnButtonHistory();
	afx_msg void OnButtonTools();
	afx_msg void OnButtonSetup();
	afx_msg void OnButtonSchedule();
	afx_msg void OnButtonStandings();
	afx_msg void OnSelchangeComboTeams();
	afx_msg void OnButtonArena();
	afx_msg void OnButtonBudgetSheet();
	afx_msg void OnButtonCamp();
	afx_msg void OnButtonEnd();
	afx_msg void OnButtonFa();
	afx_msg void OnButtonRookies();
	afx_msg void OnButtonStaffs();
	afx_msg void OnSetupLoad();
	afx_msg void OnSetupSettings();
	afx_msg void OnSetupSetgameplan();
	afx_msg void OnButtonGo();
	afx_msg void OnButtonExpand();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnTeamBudget();
	afx_msg void OnTeamDraftpreview();
	afx_msg void OnTeamFreeagents();
	afx_msg void OnTeamHistory();
	afx_msg void OnTeamLineup();
	afx_msg void OnTeamRecords();
	afx_msg void OnTeamResults();
	afx_msg void OnTeamRoster();
	afx_msg void OnTeamStaff();
	afx_msg void OnTeamTrade();
	afx_msg void OnTeamTransactions();
	afx_msg void OnEditPlayers();
	afx_msg void OnEditCities();
	afx_msg void OnEditStaff();
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void CheckButtons();
	CFont m_font, m_font1;
	CBrush myBrush; 
		CBitmap* m_bmp;

	
	void InitControls();
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROGRESSVIEW_H__A7282DEA_35FB_11D6_9B5D_444553540000__INCLUDED_)
