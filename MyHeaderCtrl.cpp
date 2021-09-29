#include "stdafx.h"
#include "MyHeaderCtrl.h"
#include "BBall.h"


BEGIN_MESSAGE_MAP(CMyHeaderCtrl, CMFCHeaderCtrl)
	//ON_WM_ERASEBKGND()
	ON_WM_CTLCOLOR_REFLECT()
END_MESSAGE_MAP()



BOOL CMyHeaderCtrl::OnEraseBkgnd(CDC* pDC) 
{
	CRect rect;
	CMyHeaderCtrl::GetClientRect(rect);
	CBrush brush0(RGB(176, 196, 222));
	pDC->FillRect(&rect,&brush0);
	brush0.DeleteObject();
	return FALSE;

}






void CMyHeaderCtrl::OnFillBackground(CDC* pDC) 
{

	CRect rect;
	CMyHeaderCtrl::GetClientRect(rect);
  //CBrush brush0(RGB(176, 196, 222));
  CBrush brush0(HDRCOLOR1);
  pDC->FillRect(&rect,&brush0);
  brush0.DeleteObject();
//	return CMFCHeaderCtrl::OnFillBackground(pDC);
}


CMyHeaderCtrl::CMyHeaderCtrl(void)
{

}


CMyHeaderCtrl::~CMyHeaderCtrl(void)
{

}






HBRUSH CMyHeaderCtrl::CtlColor(CDC* pDC, UINT nCtlColor)
{
	// TODO:  Change any attributes of the DC here

	// TODO:  Return a non-NULL brush if the parent's handler should not be called
	CRect rect;
	CMyHeaderCtrl::GetClientRect(rect);
  CBrush brush0(RGB(176, 196, 222));
  pDC->FillRect(&rect,&brush0);
  brush0.DeleteObject();




	return NULL;
}
