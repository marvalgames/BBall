// FormViewEx.cpp : implementation file
//

#include "stdafx.h"
#include "bball.h"
#include "FormViewEx.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFormViewEx

IMPLEMENT_DYNCREATE(CFormViewEx, CFormView)

CFormViewEx::CFormViewEx()
	: CFormView(CFormViewEx::IDD)
{
	//{{AFX_DATA_INIT(CFormViewEx)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CFormViewEx::~CFormViewEx()
{
}

void CFormViewEx::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFormViewEx)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFormViewEx, CFormView)
	//{{AFX_MSG_MAP(CFormViewEx)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFormViewEx diagnostics

#ifdef _DEBUG
void CFormViewEx::AssertValid() const
{
	CFormView::AssertValid();
}

void CFormViewEx::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CFormViewEx message handlers
