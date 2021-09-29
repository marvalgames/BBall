// BBall.h : main header file for the BBALL application
//

#if !defined(AFX_BBALL_H__6670D48A_047A_11D6_9B5D_444553540000__INCLUDED_)
#define AFX_BBALL_H__6670D48A_047A_11D6_9B5D_444553540000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "Constants.h" 
#include "Externs.h" 

//#include "XListCtrl/XListCtrl.h"
#include "TransparentStatic.h"
#include "TransparentGroup.h"

#include "resource.h"       // main symbols
#define NUMVIEWS 9


#include "afxvisualmanager.h"
#include "afxvisualmanagerwindows7.h"


/////////////////////////////////////////////////////////////////////////////
// CBBallApp:
// See BBall.cpp for the implementation of this class
//

class CBBallApp : public CWinApp
{
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CBBallApp();
	CView * SwitchView( UINT nIndex ); 
	BOOL SaveActiveViewsData();
    UINT m_nCurView;    
//	GdiplusStartupInput gdiplusStartupInput;
	//ULONG          gdiplusToken;
	ULONG m_gdiplusToken;

protected:
 // Array of views attached to single document
    CView * m_pViews[NUMVIEWS];
    // Index to current view
	
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBBallApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CBBallApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BBALL_H__6670D48A_047A_11D6_9B5D_444553540000__INCLUDED_)
