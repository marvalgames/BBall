#if !defined(AFX_HTMLDLG_H__11CAB0C0_540A_11D5_B185_444553540000__INCLUDED_)
#define AFX_HTMLDLG_H__11CAB0C0_540A_11D5_B185_444553540000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef HtmlDlg_h
#include "HtmlDlg.h"
#define HtmlDlg_h
#endif 
#include "bball.h"
//#include "constants.h"
//#include "resource.h"
#ifndef ColorStaticST_h
#include "ColorStaticST.h"
#define ColorStaticST_h
#endif



#ifndef Average_h
#include "Average.h"
#define Average_h
#endif 
#include "MyButton.h"



//#include "Average.h"	// Added by ClassView
// HtmlDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CHtmlDlg dialog

class CHtmlDlg : public CDialog
{
// Construction
public:
	CString m_bk_color;
	CString m_text_color;
	CString m_link_color;
	CString m_vlink_color;
	CString m_html_font;
	bool m_save_selection;
	int m_stage;
	int m_leadScout;
	CAverage avg;
	CString m_league_name;
	CString m_path;
	COLORREF m_b;
	COLORREF m_t;
	COLORREF m_l;
	COLORREF m_v;


	CStaff* m_scout;
	CHtmlDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CHtmlDlg)
	enum { IDD = IDD_DIALOG_HTML };
	MyButton	m_button_font;
	MyButton	m_button_delete;
	MyButton	m_button_view;
	CMyComboBox	m_combo_player;
	CMyComboBox	m_combo_box;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHtmlDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CHtmlDlg)
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	virtual BOOL OnInitDialog();
	afx_msg void OnDestroy();
	afx_msg void OnButtonCreate();
	afx_msg void OnButtonView();
	afx_msg void OnButtonDelete();
	afx_msg void OnButtonPageColor();
	afx_msg void OnButtonTextColor();
	afx_msg void OnButtonLinkColor();
	afx_msg void OnButtonViewTest();
	virtual void OnOK();
	afx_msg void OnButtonSave();
	afx_msg void OnButtonFont();
	afx_msg void OnButtonVlinkColor();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:

	CColorStaticST	m_static_lc;
	CColorStaticST	m_static_vl;
	CColorStaticST	m_static_tc;
	CColorStaticST	m_static_bg;
	CBrush myBrush; 
	void SetButtonColors();
	void InitData();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HTMLDLG_H__11CAB0C0_540A_11D5_B185_444553540000__INCLUDED_)
