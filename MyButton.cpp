#include "stdafx.h"
#include "MyButton.h"
#include "BBall.h"

BEGIN_MESSAGE_MAP(MyButton, CMFCButton)
	ON_MESSAGE(WM_SETTEXT, OnSetText)
	ON_WM_NCPAINT()
END_MESSAGE_MAP()

MyButton::MyButton(void)
{
	m_clrFace = RGB(255, 255, 255);
	m_clrRegular = RGB(255, 255, 255);
	m_nFlatStyle = CMFCButton::BUTTONSTYLE_SEMIFLAT;
	//m_imageResourceID = IDB_BUTTON;


	m_bmp = new CBitmap;
	if (m_useImage)
	{
		m_bmp->LoadBitmap(IDB_BUTTON);
		//TRACE("int = % d\n", m_imageResourceID);
		m_bmp->SetBitmapDimension(64, 16); /* if the size of bitmap is 50 by 40 */
	}



}

void MyButton::ChangeBitmap(UINT bitmapResourceID)
{
	m_bmp->DeleteObject();
	m_bmp = new CBitmap;
	m_bmp->LoadBitmap(bitmapResourceID);
	//TRACE("int = % d\n", m_imageResourceID);
	m_bmp->SetBitmapDimension(64, 16); /* if the size of bitmap is 50 by 40 */



}


LRESULT MyButton::OnSetText(WPARAM wParam, LPARAM lParam)
{
	LRESULT Result = Default();
	return Result;
}

BOOL MyButton::PreCreateWindow(CREATESTRUCT& cs)
{
	if (CMFCButton::PreCreateWindow(cs))
	{
		return TRUE;
	}
	return FALSE;
}



void MyButton::SetMyFont(int weight, int height, CString font)
{


}


void MyButton::PreSubclassWindow()
{


	CMFCButton::PreSubclassWindow();








	//EnableMenuFont(FALSE);
	LOGFONT lf;
	GetFont()->GetLogFont(&lf);
	//lf.lfUnderline = (BYTE)m_bUnderline;
	//lf.lfItalic = (BYTE)m_bItalic;
	lf.lfHeight = fontSize;
	lf.lfWeight = (LONG)fontWeight; // (900 = BOLD)
	strcpy_s(lf.lfFaceName, fontType);    //    with face name "Arial"
	m_font.CreateFontIndirect(&lf);
	SetFont(&m_font);
	//SizeToContent();
	//SetButtonFontSize(size);

	// ResizeButton();

}


void MyButton::SetButtonFontSize(int size)
{
	fontSize = size;
}

void MyButton::SetButtonFontWeight(int weight)
{
	fontWeight = weight;
}

void MyButton::SetButtonFontType(CString type)
{
	fontType = type;
}


MyButton::~MyButton(void)
{
	delete m_bmp;
}





void MyButton::OnDraw(CDC* pDC, const CRect& rect, UINT uiState)
{
	SetMouseCursorHand();
	if (m_useImage == TRUE)
	{
		CDC memdc;
		memdc.CreateCompatibleDC(pDC);
		CBitmap* pOldBitmap = memdc.SelectObject(m_bmp);
		CRect rc;
		GetClientRect(&rc);

		//pDC->SetBkMode(TRANSPARENT);

		const CSize sz = m_bmp->GetBitmapDimension();
		BITMAP bits;
		m_bmp->GetObject(sizeof(BITMAP), &bits);


		for (int y = 0; y <= rc.Height() - 1; y += sz.cy)
		{
			for (int x = 0; x <= rc.Width() - 1; x += sz.cx)
			{
				//pDC->BitBlt(x, y, sz.cx, sz.cy, &memdc, 0, 0, SRCCOPY);

				pDC->StretchBlt(rect.left, rect.top, rect.Width() + 1, rect.Height() + 1,
					&memdc, 0, 0, bits.bmWidth, bits.bmHeight, SRCCOPY);

			}
		}

		memdc.SelectObject(pOldBitmap);

	}
	return CMFCButton::OnDraw(pDC, rect, uiState);

	/*


		pDC->SetBkMode(TRANSPARENT);
		// TODO: Add your specialized code here and/or call the base class


		// TODO: Add your specialized code here and/or call the base class

		CRect rect0;
			GetClientRect(rect0);
			CBrush brush0(RGB(176, 196, 222));


					pDC->Draw3dRect(&rect0,RGB(0,0,0), RGB(0,0,0));
		//	pDC->Ellipse(rect0);

			//brush0.DeleteObject();
		//	CString sTitle;
		//GetWindowText(sTitle);

		//pDC->DrawText(sTitle, rect0,  DT_SINGLELINE | DT_CENTER | DT_VCENTER);



			return CMFCButton::OnDraw(pDC, rect, uiState);

			*/

}


void MyButton::OnDrawParentBackground(CDC* pDC, CRect rectClient)
{
	// TODO: Add your specialized code here and/or call the base class

	return CMFCButton::OnDrawParentBackground(pDC, rectClient);
}


void MyButton::OnFillBackground(CDC* pDC, const CRect& rectClient)
{
	// TODO: Add your specialized code here and/or call the base class
	//pDC->SetBkMode(TRANSPARENT);	
//	pDC->Ellipse(0,0,100,100);



	//CRect rect;
		//GetClientRect(rect);
		//CBrush brush0(RGB(176, 196, 222));
		//pDC->FillRect(&rect,&brush0);
		//brush0.DeleteObject();

	return CMFCButton::OnFillBackground(pDC, rectClient);
}


void MyButton::OnDrawText(CDC* pDC, const CRect& rect, const CString& strText, UINT uiDTFlags, UINT uiState)
{
	// TODO: Add your specialized code here and/or call the base class
	//pDC->Ellipse(0,0,100,100);



	return CMFCButton::OnDrawText(pDC, rect, strText, uiDTFlags, uiState);
}


void MyButton::OnDrawBorder(CDC* pDC, CRect& rectClient, UINT uiState)
{
	// TODO: Add your specialized code here and/or call the base class

	return CMFCButton::OnDrawBorder(pDC, rectClient, uiState);
}


void MyButton::OnDrawFocusRect(CDC* pDC, const CRect& rectClient)
{
	// TODO: Add your specialized code here and/or call the base class

	return CMFCButton::OnDrawFocusRect(pDC, rectClient);
}


void MyButton::OnNcPaint()
{
	// TODO: Add your message handler code here
	// Do not call CMFCButton::OnNcPaint() for painting messages


	SetFont(&m_font);


}
