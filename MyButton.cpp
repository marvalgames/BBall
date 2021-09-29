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
	m_bmp = new CBitmap;
	m_bmp->LoadBitmap(IDB_BUTTON);
	m_bmp->SetBitmapDimension(128, 32); /* if the size of bitmap is 50 by 40 */

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

	////LOGFONT lf;                        // Used to create the CFont.   
	////memset(&lf, 0, sizeof(LOGFONT));   // Clear out structure.              
	////lf.lfWeight = weight;
	////lf.lfHeight = height;
	////strcpy_s(lf.lfFaceName, font);    //    with face name "Arial".
	////m_font.CreateFontIndirect(&lf);    // Create the font.

	////EnableMenuFont(FALSE);
	//if (GetFont())
	//{
	//	//m_font.DeleteObject();
	//	m_font.Detach();
	//	LOGFONT lf;
	//	GetFont()->GetLogFont(&lf);
	//	//lf.lfUnderline = (BYTE)m_bUnderline;
	//	//lf.lfItalic = (BYTE)m_bItalic;
	//	//lf.lfHeight = 800;
	//	lf.lfWeight = (LONG)900; // (900 = BOLD)

	//	m_font.CreateFontIndirect(&lf);
	//	//CString Text;
	//	//RedrawWindow();
	//}


	///*
	//	LOGFONT lf;                        // Used to create the CFont.
	//	memset(&lf, 0, sizeof(LOGFONT));   // Clear out structure.
	//	lf.lfWeight = 800;
	//	lf.lfHeight = 20;
	//	strcpy_s(lf.lfFaceName, "Courier New");    //    with face name "Arial"
	//	m_font.CreateFontIndirect(&lf);    // Create the font.
	//	*/


	//	//	SetFont(&m_font);

	//		/*

	//	CString Text;
	//	GetWindowText(Text);
	//	CRect Rect;
	//	GetWindowRect(&Rect);

	//	CDC *pDC = GetDC();
	//	CFont *pOldFont = pDC->SelectObject(&m_font);
	//	CSize Size = pDC->GetTextExtent(Text);
	//	pDC->SelectObject(pOldFont);
	//	ReleaseDC(pDC);

	//	SetWindowPos(NULL,0,0,Size.cx +
	//	10,Rect.Height(),SWP_NOMOVE|SWP_NOZORDER);

	//	*/

}


void MyButton::PreSubclassWindow()
{


	CMFCButton::PreSubclassWindow();
	//EnableMenuFont(FALSE);
	LOGFONT lf;
	GetFont()->GetLogFont(&lf);
	//lf.lfUnderline = (BYTE)m_bUnderline;
	//lf.lfItalic = (BYTE)m_bItalic;
	lf.lfHeight = 20;
	lf.lfWeight = (LONG)300; // (900 = BOLD)
	strcpy_s(lf.lfFaceName, "Verdana");    //    with face name "Arial"
	m_font.CreateFontIndirect(&lf);
	SetFont(&m_font);

	// ResizeButton();

}



MyButton::~MyButton(void)
{
	delete m_bmp;
}


//void MyButton::SetFaceColor(COLORREF crFace, BOOL bRedraw)
//{

//}



void MyButton::OnDraw(CDC* pDC, const CRect& rect, UINT uiState)
{
	SetMouseCursorHand();
	if (m_bTransparent == false)
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
