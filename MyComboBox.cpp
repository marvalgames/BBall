// MyComboBox.cpp : implementation file
//

#include "stdafx.h"
#include "bball.h"
#include "MyComboBox.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyComboBox

CMyComboBox::CMyComboBox()
{
	//m_BkBrush.CreateSolidBrush(LISTBOXCOLOR);
}

CMyComboBox::~CMyComboBox()
{
	m_BkBrush.DeleteObject(); 
}


BEGIN_MESSAGE_MAP(CMyComboBox, CComboBox)
	//{{AFX_MSG_MAP(CMyComboBox)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyComboBox message handlers

HBRUSH CMyComboBox::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CComboBox::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO: Change any attributes of the DC here
	pDC->SetTextColor(YELLOW);
	pDC->SetBkColor(RGB(69,94,137));

	//pDC->SetBkMode(TRANSPARENT);

	// TODO: Return a different brush if the default is not desired
	m_BkBrush.Detach();
	m_BkBrush.CreateSolidBrush(RGB(69,94,137));
	return m_BkBrush;




}
