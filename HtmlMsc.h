#if !defined(AFX_HTMLMSC_H__0281E8C0_5786_11D5_B0E1_0080C6FA79BD__INCLUDED_)
#define AFX_HTMLMSC_H__0281E8C0_5786_11D5_B0E1_0080C6FA79BD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// HtmlMsc.h : header file
//

#ifndef ColorStaticST_h
#include "ColorStaticST.h"
#define ColorStaticST_h
#endif
#include "MyButton.h"

/////////////////////////////////////////////////////////////////////////////
// CHtmlMsc dialog

class CHtmlMsc : public CDialog
{
// Construction
public:
	CString m_file_name;
	CString m_label;
	CString m_headers[28];
	CString m_strings[1601][28];
	CString m_path;
	CString m_league_name;
	CString m_text_color;
	CString m_bk_color;
	CString m_link_color;
	CString m_vlink_color;
	CString m_html_font;
	UINT m_items;

	CHtmlMsc(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CHtmlMsc)
	enum { IDD = IDD_DIALOG_HTML_MISC };
	MyButton	m_button_font;
	MyButton	m_button_preview;
	UINT	m_edit_1;
	UINT	m_edit_2;
	CString	m_name;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHtmlMsc)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CHtmlMsc)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnButtonCreate();
	afx_msg void OnButtonView();
	afx_msg void OnButtonPageColor();
	afx_msg void OnButtonLinkColor();
	afx_msg void OnButtonTextColor();
	afx_msg void OnButtonVlinkColor();
	afx_msg void OnButtonFont();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CColorStaticST	m_static_lc;
	CColorStaticST	m_static_vl;
	CColorStaticST	m_static_tc;
	CColorStaticST	m_static_bg;
	CBrush myBrush; 


	void InitData();
	void SetButtonColors();

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HTMLMSC_H__0281E8C0_5786_11D5_B0E1_0080C6FA79BD__INCLUDED_)
