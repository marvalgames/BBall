// TransparentStatic.cpp : implementation file
//

#include "stdafx.h"
#include "TransparentGroup.h"


// CTransparentGroup

IMPLEMENT_DYNAMIC(CTransparentGroup, CButton)
CTransparentGroup::CTransparentGroup()
{
}

CTransparentGroup::~CTransparentGroup()
{
}


BEGIN_MESSAGE_MAP(CTransparentGroup, CStatic)
   ON_MESSAGE(WM_SETTEXT,OnSetText)
   ON_WM_CTLCOLOR_REFLECT()
   ON_WM_PAINT()
END_MESSAGE_MAP()



// CTransparentGroup message handlers

LRESULT CTransparentGroup::OnSetText(WPARAM wParam,LPARAM lParam)
{
   LRESULT Result = Default();
   CRect Rect;
   GetWindowRect(&Rect);
   GetParent()->ScreenToClient(&Rect);
   GetParent()->InvalidateRect(&Rect);
   GetParent()->UpdateWindow();
   return Result;
}


HBRUSH CTransparentGroup::CtlColor(CDC* pDC, UINT /*nCtlColor*/)
{
   pDC->SetBkMode(TRANSPARENT);
   //pDC->SetBkColor(RGB(128,128,128));
   return (HBRUSH)GetStockObject(NULL_BRUSH);
}



void CTransparentGroup::OnPaint()
{
	// TODO: Add your message handler code here
	// Do not call CButton::OnPaint() for painting messages


	CRect rc;
	CPoint ptStart, ptEnd;
	CSize seText;
	CString sText, sTemp;
	CPen pnFrmDark, pnFrmLight, *ppnOldPen;
	int iUpDist, nSavedDC;
	DWORD dwStyle, dwExStyle;


	CPaintDC dc(this); // device context for painting

	// save dc state
	nSavedDC = dc.SaveDC();

	// window rect
	GetWindowRect(&rc);
	ScreenToClient(&rc);

	// determine text length
	GetWindowText(sTemp);
	sText.Format(" %s ", sTemp); // looks better with a blank on each side	
	seText = dc.GetTextExtent(sText);

	// distance from window top to group rect
	iUpDist = (seText.cy / 2);

	// calc rect and start/end points
	dwStyle = GetStyle();
	dwExStyle = GetExStyle();

	// handle the extended windows styles
	if (dwExStyle & WS_EX_DLGMODALFRAME)
	{
		rc.DeflateRect(2*GetSystemMetrics(SM_CXEDGE), 2*GetSystemMetrics(SM_CYEDGE));
		rc.left--;
	}
	if (dwExStyle & WS_EX_CLIENTEDGE)
	{
		rc.DeflateRect(GetSystemMetrics(SM_CXEDGE)+1, GetSystemMetrics(SM_CYEDGE)+1);
		rc.left--;
		if (dwExStyle & WS_EX_DLGMODALFRAME)
		{
			rc.right++;
		}
	}	
	if(dwExStyle & WS_EX_STATICEDGE)
	{
		rc.DeflateRect(2*GetSystemMetrics(SM_CXBORDER), 2*GetSystemMetrics(SM_CYBORDER));
		rc.left--;
	}

	// handle text alignment (Caution: BS_CENTER == BS_LEFT|BS_RIGHT!!!)
	ptStart.y = ptEnd.y = rc.top + iUpDist;
	if ((dwStyle & BS_CENTER) == BS_RIGHT) // right aligned
	{
		ptEnd.x = rc.right - OFS_X;
		ptStart.x = ptEnd.x - seText.cx;
	}
	else if ((!(dwStyle & BS_CENTER)) || ((dwStyle & BS_CENTER) == BS_LEFT))// left aligned	/ default
	{
		ptStart.x = rc.left + OFS_X;
		ptEnd.x = ptStart.x + seText.cx;
	}
	else if ((dwStyle & BS_CENTER) == BS_CENTER) // text centered
	{
		ptStart.x = (rc.Width() - seText.cx) / 2;
		ptEnd.x = ptStart.x + seText.cx;
	}	
	

	if (dwStyle & BS_FLAT) // "flat" frame
	{
		VERIFY(pnFrmDark.CreatePen(PS_SOLID, 1, RGB(0, 0, 0)));
		VERIFY(pnFrmLight.CreatePen(PS_SOLID, 1, ::GetSysColor(COLOR_3DHILIGHT)));

		ppnOldPen = dc.SelectObject(&pnFrmDark);

		dc.MoveTo(ptStart);
		dc.LineTo(rc.left, ptStart.y);
		dc.LineTo(rc.left, rc.bottom);
		dc.LineTo(rc.right, rc.bottom);
		dc.LineTo(rc.right, ptEnd.y);
		dc.LineTo(ptEnd);

		dc.SelectObject(&pnFrmLight);

		dc.MoveTo(ptStart.x, ptStart.y+1);
		dc.LineTo(rc.left+1, ptStart.y+1);
		dc.LineTo(rc.left+1, rc.bottom-1);
		dc.LineTo(rc.right-1, rc.bottom-1);
		dc.LineTo(rc.right-1, ptEnd.y+1);
		dc.LineTo(ptEnd.x, ptEnd.y+1);

	}
	else // 3D frame
	{
		VERIFY(pnFrmDark.CreatePen(PS_SOLID, 1, ::GetSysColor(COLOR_3DSHADOW)));
		VERIFY(pnFrmLight.CreatePen(PS_SOLID, 1, ::GetSysColor(COLOR_3DHILIGHT)));

		ppnOldPen = dc.SelectObject(&pnFrmDark);

		dc.MoveTo(ptStart);
		dc.LineTo(rc.left, ptStart.y);
		dc.LineTo(rc.left, rc.bottom-1);
		dc.LineTo(rc.right-1, rc.bottom-1);
		dc.LineTo(rc.right-1, ptEnd.y);
		dc.LineTo(ptEnd);

		dc.SelectObject(&pnFrmLight);

		dc.MoveTo(ptStart.x, ptStart.y+1);
		dc.LineTo(rc.left+1, ptStart.y+1);
		dc.LineTo(rc.left+1, rc.bottom-1);
		dc.MoveTo(rc.left, rc.bottom);
		dc.LineTo(rc.right, rc.bottom);
		dc.LineTo(rc.right, ptEnd.y-1);
		dc.MoveTo(rc.right-2, ptEnd.y+1);
		dc.LineTo(ptEnd.x, ptEnd.y+1);	
	}

	// draw text (if any)
	if (!sText.IsEmpty() && !(dwExStyle & (BS_ICON|BS_BITMAP)))
	{
		if (!IsWindowEnabled())
		{
			ptStart.y -= iUpDist;
			dc.DrawState(ptStart, seText, sText, DSS_DISABLED, TRUE, 0, (HBRUSH)NULL);
		}
		else
		{
			dc.SetBkMode(TRANSPARENT);
			dc.DrawText(sText, CRect(ptStart, ptEnd), DT_VCENTER|DT_LEFT|DT_SINGLELINE|DT_NOCLIP);
		}
	}

	// cleanup
	dc.SelectObject(ppnOldPen);
	dc.RestoreDC(nSavedDC);


}
