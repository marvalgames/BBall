// dcutils.h: interface for the CDCUtils class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DCUTILS_H__E2D3C5A3_8841_4FAB_80F2_940FF382C7B2__INCLUDED_)
#define AFX_DCUTILS_H__E2D3C5A3_8841_4FAB_80F2_940FF382C7B2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CDCUtils  
{
public:

	//
	// Helper Functions and variables:
	//

    static CBitmap	m_bmpDesktop;

	static double DegreeToRadian( double degree );

	static CDC* GetDCFromBmp(		CDC *pDC, CBitmap& bmpSource );

	static CDC* GetDCFromBmp(		CDC *pDC, UINT uResourceID, CSize* pSize=NULL );

	static CDC* CreateBitmappedDC(	CDC * pDC, CBitmap* pBitmap = NULL, CSize* pSize=NULL, BITMAP* pBmp=NULL );

	//
	//	"Worker Functions"
	//

	static void GetDesktopImage(	CBitmap* pBitmap = NULL );

	static void	PaintRect(			CDC* pDC, int x, int y, int w, int h, COLORREF color);

	static void DrawText(			CDC* pDC, CPoint Location,	CString strText, CString strFontName, int nFontWidth, int nFontHeight, COLORREF crFontColour, long FontWeight=FW_BOLD);
	
	static void PaintHatch(			CDC* pDC, CRect area,		COLORREF crFG=RGB(0,70,30), COLORREF crBG=NULL);

	static void Draw3DRect(			CDC* pDC, CRect& area,		bool bDeflate=false, COLORREF crFill=-1, COLORREF crHilite=-1, COLORREF crLoLite=-1);

	static void LinearGradient(		CDC *pDC, CRect &rect,		COLORREF clrFrom, COLORREF clrTo, BOOL bHorizontal = TRUE);

	static void RadialGradient(		CDC *pDC, CRect &rect,		COLORREF clrFrom, COLORREF clrTo );

	static void DrawElectricity(	CDC *pDC, CRect rect );

	static void MakeGlass(			CDC *pDC, CWnd* pWnd, CRect rect, UINT uBmpID );

	static void PaintDesktop(		CDC *pDC, CWnd* pWnd, CRect SourceRect, CRect DestRect);

	static void DrawLine(			CDC *pDC, CPoint From, CPoint To );

	static void DrawSineWave(		CDC *pDC, CRect rect, double dwCycles, COLORREF crPen = 0x000 );

	static void TileBitmap(			CDC *pDC, CRect rect, UINT uResourceID );

	static void PaintBitmap(		CDC *pDC, CWnd* pWnd, CRect rect, UINT uBmpID, bool bStretchToFit = true, bool bOverlay=false );

	static void BlitBitmap(			CDC *pDC, CRect rect, UINT uResourceID, COLORREF crMask=RGB(0,0,0), double dDegreesRotation=0 );

	//
	// Other
	//

	CDCUtils();
	virtual ~CDCUtils();
};

#endif // !defined(AFX_DCUTILS_H__E2D3C5A3_8841_4FAB_80F2_940FF382C7B2__INCLUDED_)
