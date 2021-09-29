// ddraw_in_mfcwindView.cpp : implementation of the CDdraw_in_mfcwindView class
//

#include "stdafx.h"
#include "ddraw_in_mfcwind.h"

#include "ddraw_in_mfcwindDoc.h"
#include "ddraw_in_mfcwindView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDdraw_in_mfcwindView

IMPLEMENT_DYNCREATE(CDdraw_in_mfcwindView, CView)

BEGIN_MESSAGE_MAP(CDdraw_in_mfcwindView, CView)
	//{{AFX_MSG_MAP(CDdraw_in_mfcwindView)
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDdraw_in_mfcwindView construction/destruction

CDdraw_in_mfcwindView::CDdraw_in_mfcwindView()
{
	// TODO: add construction code here
	bDDrawActive = FALSE;
	x = -100;
	y = -100;
}

CDdraw_in_mfcwindView::~CDdraw_in_mfcwindView()
{
	bDDrawActive = FALSE;
}

BOOL CDdraw_in_mfcwindView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDdraw_in_mfcwindView drawing

void CDdraw_in_mfcwindView::OnDraw(CDC* pDC)
{
//	CDdraw_in_mfcwindDoc* pDoc = GetDocument();
//	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here

	// Now you can call CDDrawSystem member functions for drawings
	if(bDDrawActive) // make sure directdraw interfaces are 
	{
		ddobj.Clear();
		ddobj.TestDraw(x, y);
		ddobj.Display();
	}
}

/////////////////////////////////////////////////////////////////////////////
// CDdraw_in_mfcwindView diagnostics

#ifdef _DEBUG
void CDdraw_in_mfcwindView::AssertValid() const
{
	CView::AssertValid();
}

void CDdraw_in_mfcwindView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDdraw_in_mfcwindDoc* CDdraw_in_mfcwindView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDdraw_in_mfcwindDoc)));
	return (CDdraw_in_mfcwindDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDdraw_in_mfcwindView message handlers

void CDdraw_in_mfcwindView::OnInitialUpdate() 
{
	CView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	// OK, here is where you initialize the DirectDraw interface.
	if (!ddobj.Init(GetSafeHwnd()))
	{
		AfxMessageBox("Failed to Create DirectDraw Interface.");
	}
	else
	{
		bDDrawActive = TRUE;
	}
}

void CDdraw_in_mfcwindView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	x = point.x;
	y = point.y;

	ddobj.Clear();
	ddobj.TestDraw(x, y);
	ddobj.Display();

	CView::OnLButtonDown(nFlags, point);
}
