// BBallView.h : interface of the CBBallView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BBALLVIEW_H__6670D492_047A_11D6_9B5D_444553540000__INCLUDED_)
#define AFX_BBALLVIEW_H__6670D492_047A_11D6_9B5D_444553540000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "MyComboBox.h"
#include "MyButton.h"

#include "MyButton.h"


//#include "FormViewEx.h"
#include "MyBitmap.h"



#ifndef Average_h
#include "Average.h"
#define Average_h
#endif 

#ifndef Career_h
#include "Career.h"
#define Career_h
#endif 

//#include "htmlhelp.h"



class CBBallView : public CFormView
{
protected: // create from serialization only
public:
	CBBallView();
protected:
	DECLARE_DYNCREATE(CBBallView)

public:
	//{{AFX_DATA(CBBallView)
	enum { IDD = IDD_BBALL_FORM };
	MyButton	m_button_quickstart;
	MyButton	m_button_go;
	MyButton	m_button_history;
	MyButton	m_button_progress;
	MyButton	m_button_tools;
	MyButton	m_button_options;
	MyButton m_button_delete;
	MyButton	m_button_load;
	MyButton	m_button_new;
	MyButton	m_button_save;
	MyButton	m_button_quick;
	CMyComboBox	m_combo_teams;
	MyButton	m_button_standings;
	MyButton	m_button_schedule;
	MyButton m_button_setup;
	CString m_edit_quickname;
	//}}AFX_DATA

// Attributes
public:
	CBBallDoc* GetDocument();

private:
	bool m_program_started;
	void ResetComboTeamList();
	CFont m_font, m_font1;
//	CMyBitmap bitmapBkgnd;
	CBrush myBrush;
	CBrush m_tbrush;
	CBitmap* m_bmp;

//	CBitmap bitmap;


// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBBallView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate(); // called first time after construct
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView);
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
//	virtual void OnDraw(CDC* pDC);
	//}}AFX_VIRTUAL

// Implementation
public:


	virtual ~CBBallView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CBBallView)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnButtonBuy();
	afx_msg void OnButtonLoad();
	afx_msg void OnButtonQuick();
	afx_msg void OnButtonNew();
	afx_msg void OnButtonSave();
	afx_msg void OnButtonDelete();
	afx_msg void OnButtonSettings();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnButtonSchedule();
	afx_msg void OnButtonStandings();
	afx_msg void OnSelchangeComboTeams();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnButtonOptions();
	afx_msg void OnButtonTools();
	afx_msg void OnButtonHistory();
	afx_msg void OnButtonProgress();
	afx_msg void OnSetupLoad();
	afx_msg void OnSetupSettings();
	afx_msg void OnSetupSetgameplan();
	afx_msg void OnSetupProposetrade();
	afx_msg void OnButtonGo();
	afx_msg void OnDestroy();
	afx_msg void OnUpdateSetupLoad(CCmdUI* pCmdUI);
	afx_msg void OnUpdateSetupSetgameplan(CCmdUI* pCmdUI);
	afx_msg void OnUpdateSetupProposetrade(CCmdUI* pCmdUI);
	afx_msg void OnUpdateSetupSettings(CCmdUI* pCmdUI);
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
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
	afx_msg void OnUpdateTeamBudget(CCmdUI* pCmdUI);
	afx_msg void OnUpdateTeamDraftpreview(CCmdUI* pCmdUI);
	afx_msg void OnUpdateTeamFreeagents(CCmdUI* pCmdUI);
	afx_msg void OnUpdateTeamHistory(CCmdUI* pCmdUI);
	afx_msg void OnUpdateTeamLineup(CCmdUI* pCmdUI);
	afx_msg void OnUpdateTeamRecords(CCmdUI* pCmdUI);
	afx_msg void OnUpdateTeamResults(CCmdUI* pCmdUI);
	afx_msg void OnUpdateTeamRoster(CCmdUI* pCmdUI);
	afx_msg void OnUpdateTeamStaff(CCmdUI* pCmdUI);
	afx_msg void OnUpdateTeamTrade(CCmdUI* pCmdUI);
	afx_msg void OnUpdateTeamTransactions(CCmdUI* pCmdUI);
	afx_msg void OnEditPlayers();
	afx_msg void OnUpdateEditPlayers(CCmdUI* pCmdUI);
	afx_msg void OnEditStaff();
	afx_msg void OnUpdateEditStaff(CCmdUI* pCmdUI);
	afx_msg void OnEditCities();
	afx_msg void OnUpdateEditCities(CCmdUI* pCmdUI);
	afx_msg void OnDoubleclickedButtonBuy();
	afx_msg void OnButtonQuickstart();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedMfMyButton3();
//	CMFCMFMyButtonm_buttonMfcQuik;
};

#ifndef _DEBUG  // debug version in BBallView.cpp
inline CBBallDoc* CBBallView::GetDocument()
   { return (CBBallDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BBALLVIEW_H__6670D492_047A_11D6_9B5D_444553540000__INCLUDED_)
