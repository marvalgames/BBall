// FormViewX.cpp : implementation file
//

#include "stdafx.h"
#include "bball.h"
#include "FormViewX.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFormViewX

IMPLEMENT_DYNCREATE(CFormViewX, CFormView)

CFormViewX::CFormViewX()
	: CFormView(CFormViewX::IDD)
{
	//{{AFX_DATA_INIT(CFormViewX)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CFormViewX::~CFormViewX()
{
}

void CFormViewX::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFormViewX)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFormViewX, CFormView)
	//{{AFX_MSG_MAP(CFormViewX)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFormViewX diagnostics

#ifdef _DEBUG
void CFormViewX::AssertValid() const
{
	CFormView::AssertValid();
}

void CFormViewX::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CFormViewX message handlers
/////////////////////////////////////////////////////////////////////////////
// CFormViewX

IMPLEMENT_DYNCREATE(CFormViewX, CFormView)

CFormViewX::CFormViewX()
	: CFormView(CFormViewX::IDD)
{
	//{{AFX_DATA_INIT(CFormViewX)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CFormViewX::~CFormViewX()
{
}

void CFormViewX::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFormViewX)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFormViewX, CFormView)
	//{{AFX_MSG_MAP(CFormViewX)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFormViewX diagnostics

#ifdef _DEBUG
void CFormViewX::AssertValid() const
{
	CFormView::AssertValid();
}

void CFormViewX::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CFormViewX message handlers
