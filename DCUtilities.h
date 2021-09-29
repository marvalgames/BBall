// DCUtilities.h : main header file for the DCUTILITIES application
//

#if !defined(AFX_DCUTILITIES_H__464F5C03_7157_4C06_AC3A_105810F71EC8__INCLUDED_)
#define AFX_DCUTILITIES_H__464F5C03_7157_4C06_AC3A_105810F71EC8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDCUtilitiesApp:
// See DCUtilities.cpp for the implementation of this class
//

class CDCUtilitiesApp : public CWinApp
{
public:
	CDCUtilitiesApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDCUtilitiesApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CDCUtilitiesApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DCUTILITIES_H__464F5C03_7157_4C06_AC3A_105810F71EC8__INCLUDED_)
