// ddraw_in_mfcwind.h : main header file for the DDRAW_IN_MFCWIND application
//

#if !defined(AFX_DDRAW_IN_MFCWIND_H__D528D293_6435_4E2A_80FE_897AA563D89B__INCLUDED_)
#define AFX_DDRAW_IN_MFCWIND_H__D528D293_6435_4E2A_80FE_897AA563D89B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDdraw_in_mfcwindApp:
// See ddraw_in_mfcwind.cpp for the implementation of this class
//

class CDdraw_in_mfcwindApp : public CWinApp
{
public:
	CDdraw_in_mfcwindApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDdraw_in_mfcwindApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CDdraw_in_mfcwindApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DDRAW_IN_MFCWIND_H__D528D293_6435_4E2A_80FE_897AA563D89B__INCLUDED_)
