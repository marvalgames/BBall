#if !defined(AFX_MYLISTCTRL_H__58DA76A0_1402_11D5_B185_444553540000__INCLUDED_)
#define AFX_MYLISTCTRL_H__58DA76A0_1402_11D5_B185_444553540000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyListCtrl.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMyListCtrl window

class CMyListCtrl : public CListCtrl
{
// Construction
public:
	CMyListCtrl();

// Attributes
public:

// Operations
public:

// Overrides
//	void DrawItem(lpDrawItemStruct LPDRAWITEMSTRUCT);
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyListCtrl)
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMyListCtrl();

	enum EHighlight {HIGHLIGHT_NORMAL, HIGHLIGHT_ALLCOLUMNS, HIGHLIGHT_ROW};

	// Generated message map functions
protected:

	int  m_nHighlight;		// Indicate type of selection highlighting

	void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct); 

	//{{AFX_MSG(CMyListCtrl)
	afx_msg void OnPaint();
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
private:
	void RepaintSelectedItems();
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYLISTCTRL_H__58DA76A0_1402_11D5_B185_444553540000__INCLUDED_)
