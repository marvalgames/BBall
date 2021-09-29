// ddraw_in_mfcwindView.h : interface of the CDdraw_in_mfcwindView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DDRAW_IN_MFCWINDVIEW_H__84D1071B_8ABC_4C15_BBF6_3942D534FCB5__INCLUDED_)
#define AFX_DDRAW_IN_MFCWINDVIEW_H__84D1071B_8ABC_4C15_BBF6_3942D534FCB5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "DDrawSystem.h"

class CDdraw_in_mfcwindView : public CView
{
protected: // create from serialization only
	CDdraw_in_mfcwindView();
	DECLARE_DYNCREATE(CDdraw_in_mfcwindView)

// Attributes
public:
	CDdraw_in_mfcwindDoc* GetDocument();

// Operations
public:
	CDDrawSystem ddobj;
	BOOL bDDrawActive;
	int x;
	int y;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDdraw_in_mfcwindView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDdraw_in_mfcwindView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDdraw_in_mfcwindView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ddraw_in_mfcwindView.cpp
inline CDdraw_in_mfcwindDoc* CDdraw_in_mfcwindView::GetDocument()
   { return (CDdraw_in_mfcwindDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DDRAW_IN_MFCWINDVIEW_H__84D1071B_8ABC_4C15_BBF6_3942D534FCB5__INCLUDED_)
