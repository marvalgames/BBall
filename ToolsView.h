#if !defined(AFX_TOOLSVIEW_H__A7282DE9_35FB_11D6_9B5D_444553540000__INCLUDED_)
#define AFX_TOOLSVIEW_H__A7282DE9_35FB_11D6_9B5D_444553540000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ToolsView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CToolsView form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif



#include "MyBitmap.h"
#include "MyButton.h"

class CToolsView : public CFormView
{

public:
	CToolsView();           // protected constructor used by dynamic creation


protected:

	DECLARE_DYNCREATE(CToolsView)

public:

// Form Data
	//{{AFX_DATA(CToolsView)
	enum { IDD = IDD_DIALOG_TOOLS };
	MyButton	m_button_staff;
	MyButton	m_button_go;
	MyButton	m_button_pbp;
	MyButton	m_button_box;
	MyButton	m_button_scheduler;
	MyButton	m_button_tools;
	MyButton	m_button_standings;
	MyButton	m_button_setup;
	MyButton	m_button_schedule;
	MyButton	m_button_progress;
	MyButton	m_button_player_edit;
	MyButton	m_button_import;
	MyButton	m_button_html;
	MyButton	m_button_history;
	MyButton	m_button_city_edit;
	CMyComboBox	m_combo_teams;
	//}}AFX_DATA

// Attributes

private:
//	CMyBitmap bitmapBkgnd;

public:

// Operations
public:
	void SetFromDoc();
	BOOL SetToDoc();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CToolsView)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
//	virtual void OnDraw(CDC* pDC);
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CToolsView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CToolsView)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnButtonTools();
	afx_msg void OnButtonHistory();
	afx_msg void OnButtonProgress();
	afx_msg void OnButtonSetup();
	afx_msg void OnButtonSchedule();
	afx_msg void OnButtonStandings();
	afx_msg void OnSelchangeComboTeams();
	afx_msg void OnButtonPlayerEdit();
	afx_msg void OnButtonCityEdit();
	afx_msg void OnButtonHtml();
	afx_msg void OnButtonImport();
	afx_msg void OnButtonScheduler();
	afx_msg void OnButtonBox();
	afx_msg void OnButtonPbp();
	afx_msg void OnSetupLoad();
	afx_msg void OnSetupSettings();
	afx_msg void OnSetupSetgameplan();
	afx_msg void OnSetupProposetrade();
	afx_msg void OnButtonGo();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnTeamRoster();
	afx_msg void OnTeamBudget();
	afx_msg void OnTeamDraftpreview();
	afx_msg void OnTeamFreeagents();
	afx_msg void OnTeamHistory();
	afx_msg void OnTeamLineup();
	afx_msg void OnTeamRecords();
	afx_msg void OnTeamResults();
	afx_msg void OnTeamStaff();
	afx_msg void OnTeamTrade();
	afx_msg void OnTeamTransactions();
	afx_msg void OnButtonEditstaff();
	afx_msg void OnEditCities();
	afx_msg void OnEditPlayers();
	afx_msg void OnEditStaff();
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CFont m_font, m_font1;
	CBrush myBrush;
	CBitmap* m_bmp;

	void InitControls();
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TOOLSVIEW_H__A7282DE9_35FB_11D6_9B5D_444553540000__INCLUDED_)
