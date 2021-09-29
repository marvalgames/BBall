// DCUtils.cpp: implementation of the CDCUtils class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "dcutils.h"

#include <math.h>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

const double PI = (22.00 / 7.00);

CBitmap	CDCUtils::m_bmpDesktop;

///////////////////////////////////////////////////////////////////////////////////////////////////////////Function Header
CDCUtils::CDCUtils()
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
{
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////Function Header
CDCUtils::~CDCUtils()
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
{
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////Function Header
CDC* CDCUtils::CreateBitmappedDC( CDC * pDC, CBitmap* pBitmap, CSize* pSize, BITMAP* pBmp )
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Requester MUST clean up the pointer returned!
{
	int nWidth, nHeight;

	CDC* pReturnDC = new CDC();

	CRect Client;	pDC->GetClipBox( &Client );

	if ( pSize == NULL )
	{
		nWidth	= Client.Width();
		nHeight	= Client.Height();
	}
	else
	{
		nWidth	= pSize->cx;
		nHeight	= pSize->cy;
	}
		
	pReturnDC->CreateCompatibleDC( pDC );

	if (pBitmap)
	{
		pBitmap->CreateCompatibleBitmap(pDC, nWidth, nHeight);
	}
	else
	{
		static CBitmap bmpImage;
		bmpImage.DeleteObject();
		pBitmap = &bmpImage;
		pBitmap->CreateCompatibleBitmap(pDC, nWidth, nHeight);
	}

	pReturnDC->SelectObject(pBitmap);

	if ( pBmp )
	    pBitmap->GetBitmap(pBmp);

	return pReturnDC;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////Function Header
void CDCUtils::PaintHatch(CDC* pDC, CRect area, COLORREF crFG, COLORREF crBG)
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
{
	pDC->FillSolidRect(&area,crBG);

	pDC->SetBkColor( crBG );

	CBrush bgBrush;

	bgBrush.CreateHatchBrush( HS_CROSS, crFG );

	pDC->FillRect(&area,&bgBrush);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////Function Header
void CDCUtils::Draw3DRect(CDC* pDC, CRect& area, bool bDeflate, COLORREF crFill, COLORREF crHiLite, COLORREF crLoLite)
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
{
	if ( crHiLite == -1 )
		crHiLite = ::GetSysColor(COLOR_BTNHILIGHT);

	if ( crLoLite == -1 )
		crLoLite = ::GetSysColor(COLOR_BTNSHADOW);

	pDC->Draw3dRect( &area, crHiLite, crLoLite );

	if ( crFill != -1 )
	{
		CRect FillRect( area );
		FillRect.DeflateRect(1,1);
		pDC->FillSolidRect( &FillRect, crFill );
	}

	//
	// This is useful if a 3d-rect is drawn and then filled. The filling normally erases the 3d-rect
	//
	if ( bDeflate )
		area.DeflateRect(1,1);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////Function Header
void CDCUtils::DrawText(	CDC *pDC, 
							CPoint Location, 
							CString strText, 
							CString strFontName,
							int nFontWidth, 
							int nFontHeight, 
							COLORREF crFontColour, 
							long FontWeight)
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
{
	pDC->SetBkMode(TRANSPARENT);

	int nCharCount = strText.GetLength();

	//
	// Set the font:
	//
	CFont font;
	LOGFONT lf;										//Stores this fonts LogFont for quick retrieval
	lf.lfHeight			= nFontHeight;
	lf.lfWidth			= nFontWidth;
	lf.lfEscapement		= 0;
	lf.lfOrientation	= 0;
	lf.lfWeight			= FontWeight;				//FW_NORMAL;
	lf.lfItalic			= 0;
	lf.lfUnderline		= 0;
	lf.lfStrikeOut		= 0;
	lf.lfCharSet		= ANSI_CHARSET;
	lf.lfOutPrecision	= OUT_DEFAULT_PRECIS;
	lf.lfClipPrecision	= CLIP_DEFAULT_PRECIS;
	lf.lfQuality		= ANTIALIASED_QUALITY;
	lf.lfPitchAndFamily	= VARIABLE_PITCH | FF_ROMAN;
	
	strcpy( lf.lfFaceName, LPCTSTR(strFontName) );
	
	font.CreateFontIndirect(&lf);

	CFont* pOldFont = pDC->SelectObject(&font);

	CSize size;

	GetTextExtentPoint32(	pDC->m_hDC,				// handle to device context
							(LPCTSTR)strText,		// pointer to text string
							strText.GetLength(),	// number of characters in string
							&size);					// pointer to structure for string size

	CRect TextRect(Location, size);

	pDC->SetTextColor( crFontColour );

	pDC->DrawText(strText, &TextRect, DT_LEFT);		//  << The Text DrawText Command >>

	// Reset the Device Context :

	pDC->SelectObject(pOldFont);
}

/////////////////////////////////////////////////////////////////////////////////////////////// Function Header
void CDCUtils::PaintRect(CDC* pDC, int x, int y, int w, int h, COLORREF color)
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
{
	CBrush brush(color);
	CBrush* pOldBrush = pDC->SelectObject(&brush);
	pDC->PatBlt(x, y, w, h, PATCOPY);
	pDC->SelectObject(pOldBrush);
	brush.DeleteObject();
}


/////////////////////////////////////////////////////////////////////////////////////////////// Function Header
void CDCUtils::RadialGradient(CDC *pDC, CRect &rect, COLORREF clrFrom, COLORREF clrTo)
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
{
    int nR1 = GetRValue(clrFrom);
    int nG1 = GetGValue(clrFrom);
    int nB1 = GetBValue(clrFrom);
    int nR2 = GetRValue(clrTo);
    int nG2 = GetGValue(clrTo);
    int nB2 = GetBValue(clrTo);
    int nGradient;
    int cx = rect.Width()/ 2;
    int cy = rect.Height() / 2;
    int nRadius = (cx < cy) ? cx : cy;

    for (int x = 0; x < rect.Width(); x++) 
	{
        for (int y = 0; y < rect.Height(); y++) 
		{
            nGradient = ((nRadius - (int)sqrt(pow(x - cx, 2) + pow(y - cy, 2))) * 100) / nRadius;

            if (nGradient < 0 )
                nGradient = 0;

            int nR = nR1 + ((nR2 - nR1) * nGradient / 100);
            int nG = nG1 + ((nG2 - nG1) * nGradient / 100);
            int nB = nB1 + ((nB2 - nB1) * nGradient / 100);

            pDC->SetPixel(x+rect.left, y+rect.top, nR + (nG << 8) + (nB << 16));
        }
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////// Function Header
void CDCUtils::LinearGradient(CDC *pDC, CRect &rect, COLORREF clrFrom, COLORREF clrTo, BOOL bHorizontal)
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
{
	const int NCOLORSHADES = 255;

	int cxCap = rect.right - rect.left;
	int cyCap = rect.bottom - rect.top;

	// Get the intensity values for the ending color
	int r1 = GetRValue(clrTo); // red
	int g1 = GetGValue(clrTo); // green
	int b1 = GetBValue(clrTo); // blue
	
	// Get the intensity values for the begining color
	int r2 = GetRValue(clrFrom); // red
	int g2 = GetGValue(clrFrom); // green
	int b2 = GetBValue(clrFrom); // blue

	int r, g, b;

    if(bHorizontal) //paint horizontal rect;
    {
	    int x = cxCap;	
	    int w = x;							// width of area to shade
	    int xDelta= __max(w/NCOLORSHADES,1);	// width of one shade band


	    while (x >= xDelta) {
		    x -= xDelta;
		    if (r1 > r2)
			    r = r1 - (r1-r2)*(w-x)/w;
		    else
			    r = r1 + (r2-r1)*(w-x)/w;

		    if (g1 > g2)
			    g = g1 - (g1-g2)*(w-x)/w;
		    else
			    g = g1 + (g2-g1)*(w-x)/w;

		    if (b1 > b2)
			    b = b1 - (b1-b2)*(w-x)/w;
		    else
			    b = b1 + (b2-b1)*(w-x)/w;

		    PaintRect(pDC, rect.left+x, rect.top, xDelta, cyCap, RGB(r, g, b));
	    }
    }
    else    //paint vertical rect;
    {
	    int y = cyCap;	
	    int w = y;							// height of area to shade
	    int yDelta= max(w/NCOLORSHADES,1);	// height of one shade band


	    //while (y >= yDelta) {
        while (y > 0) {
		    y -= yDelta;
		    if (r1 > r2)
			    r = r1 - (r1-r2)*(w-y)/w;
		    else
			    r = r1 + (r2-r1)*(w-y)/w;

		    if (g1 > g2)
			    g = g1 - (g1-g2)*(w-y)/w;
		    else
			    g = g1 + (g2-g1)*(w-y)/w;

		    if (b1 > b2)
			    b = b1 - (b1-b2)*(w-y)/w;
		    else
			    b = b1 + (b2-b1)*(w-y)/w;
		    
		    PaintRect(pDC, rect.left, rect.top+y, cxCap, yDelta, RGB(r, g, b));
	    }
    }

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////Function Header
void CDCUtils::DrawElectricity(CDC *pDC, CRect rect)
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
{
	static int on1,on2,oon1,oon2;

	CRgn ClipRegion;

	ClipRegion.CreateRectRgnIndirect( &rect );

	pDC->SelectClipRgn( &ClipRegion );

//	pDC->FillSolidRect(&rect,0x00000000);
	
	int nPivot = rect.Width();

	int n1,n2;
	n1 = rand()*nPivot/RAND_MAX-nPivot/2;
	n2 = rand()*nPivot/RAND_MAX-nPivot/2;

	//
	// Add extra random element: (2/10 chance of making some wild stuff on one of the curves)
	//

	int nRandElement = rand()*10/RAND_MAX;

	if(nRandElement < 2)
		n1 = rand()*(nPivot*2)/RAND_MAX-nPivot;
	else if(rand() < RAND_MAX/10)
		n2 = rand()*(nPivot*2)/RAND_MAX-nPivot;

	CPoint TopRight		( rect.right,	rect.top	);
	CPoint TopLeft		( rect.left,	rect.top	);
	CPoint BottomLeft	( rect.left,	rect.bottom );
	CPoint BottomRight	( rect.right,	rect.bottom );
	
	int	nMidHorizontal	= rect.left + ((rect.right-rect.left)/2);
	int	nMidVertical	= rect.top + ((rect.bottom-rect.top)/2);

	//
	// Top Right -> Bottom Left
	//
	CPoint points1[4] = {
		TopRight,
		CPoint( nMidHorizontal+n1,	nMidVertical	),
		CPoint( nMidHorizontal,		nMidVertical-n1	),
		BottomLeft
	};

	//
	//	Top Left -> Bottom Right
	//
	CPoint points2[4] = {
		TopLeft,
		CPoint( nMidHorizontal-n2,nMidVertical ),
		CPoint( nMidHorizontal,nMidVertical-n2 ),
		BottomRight
	};

	//
	//	Top Right -> BottomLeft
	//
	CPoint opoints1[4] = {
		TopRight,
		CPoint( nMidHorizontal+on1,nMidVertical ),
		CPoint( nMidHorizontal,nMidVertical-on1 ),
		BottomLeft
	};

	//
	//	Top Left -> Bottom Right
	//
	CPoint opoints2[4] = {
		TopLeft,
		CPoint( nMidHorizontal-on2,nMidVertical ),
		CPoint( nMidHorizontal,nMidVertical-on2 ),
		BottomRight
	};

	//
	//	Top Right -> BottomLeft
	//
	CPoint oopoints1[4] = {
		TopRight,
		CPoint( nMidHorizontal+oon1,nMidVertical ),
		CPoint( nMidHorizontal,nMidVertical-oon1 ),
		BottomLeft
	};

	//
	//	Top Left -> Bottom Right
	//
	CPoint oopoints2[4] = {
		TopLeft,
		CPoint( nMidHorizontal-oon2,nMidVertical ),
		CPoint( nMidHorizontal,nMidVertical-oon2 ),
		BottomRight
	};

	CPen wpen(	PS_SOLID,1,RGB(150,220,255));
	CPen pen(	PS_SOLID,2,RGB(50,100,255));
	CPen open(	PS_SOLID,1,RGB(50,100,255));
	CPen oopen(	PS_SOLID,1,RGB(0,30,150));
	
	CPen *pOldPen = pDC->SelectObject(&oopen);
	pDC->PolyBezier(oopoints1,4);
	pDC->PolyBezier(oopoints2,4);

	pDC->SelectObject(&open);
	pDC->PolyBezier(opoints1,4);
	pDC->PolyBezier(opoints2,4);
	
	pDC->SelectObject(&pen);
	pDC->PolyBezier(points1,4);
	pDC->PolyBezier(points2,4);
	
	pDC->SelectObject(&wpen);
	pDC->PolyBezier(points1,4);
	pDC->PolyBezier(points2,4);
	
	pDC->SelectObject(pOldPen);

	oon1 = on1;
	oon2 = on2;
	on1 = n1;
	on2 = n2;

	pDC->SelectClipRgn( NULL );
	ClipRegion.DeleteObject();
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////Function Header


///////////////////////////////////////////////////////////////////////////////////////////////////////////Function Header
void CDCUtils::MakeGlass( CDC *pDC, CWnd* pWnd, CRect rect, UINT uBmpID )
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
{
	CDCUtils::PaintDesktop( pDC, pWnd, CRect(0,0,0,0), rect );

	CDCUtils::PaintBitmap( pDC, pWnd, rect, uBmpID, true, true );
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////Function Header
void CDCUtils::PaintBitmap( CDC *pDC, CWnd* pWnd, CRect rect, UINT uBmpID, bool bStretchToFit, bool bOverlay )
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Useful for painting to Screen Related coordinated blitting
//
{
	UINT uCopyOption = SRCCOPY;	if ( bOverlay )	uCopyOption = SRCAND;

	CSize BmpSize;
	CDC* pOverlayDC = GetDCFromBmp( pDC, uBmpID, &BmpSize );

	if ( bStretchToFit )
	{
		pDC->StretchBlt(	rect.left,
							rect.top, 
							rect.Width(), 
							rect.Height(), 
							pOverlayDC, 
							0, 
							0, 
							BmpSize.cx, 
							BmpSize.cy, 
							uCopyOption);
	}
	else
	{
	    pDC->BitBlt(	rect.left, 
						rect.top, 
						rect.Width(),
						rect.Height(), 
						pOverlayDC, 
						0,
						0,
						uCopyOption);
	}

	delete pOverlayDC;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////Function Header
double CDCUtils::DegreeToRadian( double degree )	{	return ( (PI/180) * degree );	}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////Function Header
void CDCUtils::BlitBitmap( CDC *pDC, CRect rect, UINT uResourceID, COLORREF crMask, double dDegreesRotation )
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
{
	CSize	ImageSize;
	COLORREF crPixel;

	CDC*	pBitmapDC		= GetDCFromBmp( pDC, uResourceID, &ImageSize );

	const int nWidth		= ImageSize.cx;
	const int nHeight		= ImageSize.cy;
    CPoint ptAxle			= CPoint(nWidth / 2, nHeight / 2);
    CPoint ptOffset			= CPoint((rect.Width() - nWidth) / 2, (rect.Height() - nHeight) / 2);


	if ( dDegreesRotation > 360.0 )
		dDegreesRotation = (int)dDegreesRotation % 360;

	double dRadians = DegreeToRadian ( dDegreesRotation );

    for (int x1 = 0; x1 < nWidth; x1++) 
	{
        for (int y1 = 0; y1 < nHeight; y1++) 
		{
			crPixel = pBitmapDC->GetPixel(x1, y1);

            int x2 = rect.left + ptOffset.x + (int)(ptAxle.x + ((x1 - ptAxle.x) * sin(dRadians)) + ((y1 - ptAxle.y) * cos(dRadians)));
            int y2 = rect.top + ptOffset.y + (int)(ptAxle.y + ((y1 - ptAxle.y) * sin(dRadians)) - ((x1 - ptAxle.x) * cos(dRadians)));
            
			if (crPixel != crMask) 
			{
                long lRes1 = pDC->SetPixel( x2,		y2, crPixel );
                long lRes2 = pDC->SetPixel( x2 + 1,	y2, crPixel );
            }
			else
			{
				//-------- NOTE: -----------
				//
				//	Here's a cool effect I discovered by mistake: Try it!
				//
                //long lRes2 = pOffScreenDC->SetPixel( x2+1,	y1, pDC->GetPixel(x1, y1) );
			}
        }
    }

	delete pBitmapDC;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////Function Header
void CDCUtils::TileBitmap( CDC *pDC, CRect rect, UINT uResourceID )
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
{
	CBitmap bmpTile;

	CRgn ClipRegion;

	ClipRegion.CreateRectRgnIndirect( &rect );

	pDC->SelectClipRgn( &ClipRegion );

	//    
	// Paint the window background with the bitmap.    
	//    

	CSize TileSize;

	CDC* pTileDC = GetDCFromBmp( pDC, uResourceID, &TileSize );

    bmpTile.CreateCompatibleBitmap( pTileDC, TileSize.cx, TileSize.cy );

	int nTileWidth	= TileSize.cx;
	int nTileHeight	= TileSize.cy;

	int nStartCol	= rect.left / nTileWidth;
    int nEndCol		= (rect.right + nTileWidth + 1) / nTileWidth;
    int nStartRow	= rect.top / nTileHeight;
    int nEndRow		= (rect.bottom + nTileHeight + 1) / nTileHeight;

    for (int i=nStartCol; i<nEndCol; i++) 
	{
        for (int j=nStartRow; j<nEndRow; j++) 
		{
            int x = i * nTileWidth;            
			int y = j * nTileHeight;
            pDC->BitBlt (x, y, nTileWidth, nTileHeight, pTileDC, 0, 0, SRCCOPY);        
		}    
	}

	pDC->SelectClipRgn( NULL );
	ClipRegion.DeleteObject();

	delete pTileDC;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////Function Header
void CDCUtils::DrawSineWave( CDC *pDC, CRect rect, double dwCycles, COLORREF crPen )
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	dwCycles is the number of full waves
//
{
	ASSERT ( dwCycles > 0 );


	CPen Marker( PS_SOLID, 1, crPen );
	CPen *pOldPen = pDC->SelectObject(&Marker);

	int nWidth = rect.Height();
	double dwStep = (2*PI*dwCycles)/((double)rect.Width());
	double dwAmplitude = rect.Height()/2;
	bool bFirstDot = true;
	bool bDotsOnly = false;

    for (int x = 0; x < rect.Width(); x++) 
	{
		int nOffset = (rect.top)+rect.Height()/2;

        int yPos	= (int) (sin( x*dwStep )* (dwAmplitude)) + nOffset;
		int xPos	= x+rect.left;

		if ( bFirstDot && !bDotsOnly )
		{
			pDC->MoveTo( xPos, yPos );
			bFirstDot = false;
		}

		if ( bDotsOnly )
	        pDC->SetPixel(xPos, yPos, crPen);
		else
			pDC->LineTo( xPos, yPos );

    }

	pDC->SelectObject(pOldPen);
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////Function Header
void CDCUtils::DrawLine( CDC *pDC, CPoint From, CPoint To )
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
{
    pDC->MoveTo(From);
    pDC->LineTo(To);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////Function Header
void CDCUtils::PaintDesktop( CDC *pDC, CWnd* pWnd, CRect SourceRect, CRect DestRect )
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
{
	CRect	LastRect;
	CPoint	Point;

	//
	// If source is empty, the user wants it to be the same as the destination rect
	//
	if ( SourceRect == CRect(0,0,0,0) )
	{
		SourceRect = DestRect;
		Point = CPoint( SourceRect.left, SourceRect.top );
		ClientToScreen(pWnd->GetSafeHwnd(), &Point);
	}
	else
	{
		// If the source rect is *specified*, then it is a screen co-ord, not client:
		Point = CPoint( SourceRect.left, SourceRect.top );
	}

	CWnd* pFrameWnd = AfxGetMainWnd();
	
	ASSERT( pFrameWnd );

	pFrameWnd->GetWindowRect( LastRect );

	//
	// Get the Calling Window out the way, so that we can get a clean snapshot...
	//

	CDC* pDesktopDC = GetDCFromBmp( pDC, m_bmpDesktop );

	//
	// Blit the buffer's contents (constrained by incoming size) to the calling DC:
	//

    pDC->BitBlt(		DestRect.left, 
						DestRect.top, 
						DestRect.Width(), 
						DestRect.Height(), 
						pDesktopDC,			// From DC
						Point.x,			// xSrc
						Point.y,			// ySrc
						SRCCOPY);

	//
	//
	//
	
	//
	// Cleanup
	//

	delete pDesktopDC;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////Function Header
CDC* CDCUtils::GetDCFromBmp( CDC *pDC, CBitmap& bmpSource )
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
{
	CDC* pReturnDC = new CDC();
    pReturnDC->CreateCompatibleDC(pDC);
    pReturnDC->SelectObject(&bmpSource);

	//
	// Caller cleans up!!!
	//
	return pReturnDC;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////Function Header
CDC* CDCUtils::GetDCFromBmp( CDC *pDC, UINT uResourceID, CSize* pSize )
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
{
	CBitmap bmpImage;

	HANDLE hBitmap = ::LoadImage (	AfxGetInstanceHandle(),
									MAKEINTRESOURCE (uResourceID), 
									IMAGE_BITMAP, 
									0, 
									0, 
									LR_CREATEDIBSECTION);

	ASSERT (hBitmap); 

	bmpImage.Attach (hBitmap);

	if (pSize)
	{
		BITMAP bmpInfo;
	    bmpImage.GetBitmap(&bmpInfo);
		*pSize = CSize(bmpInfo.bmWidth, bmpInfo.bmHeight );
	}
	
	return GetDCFromBmp( pDC, bmpImage );
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////Function Header
void CDCUtils::GetDesktopImage( CBitmap* pBitmap )
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
{
	if ( pBitmap == NULL )
		pBitmap = &m_bmpDesktop;

    CDC dcDesktop;

    CSize DesktopSize( GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN) );

	//
	// Get the Desktop's Device Context
	//

    dcDesktop.m_hDC = ::GetDC(NULL);

	//
	// Initialise the bitmap according to the Desktop DC
	//

    CDC* pBitmapDC = CreateBitmappedDC(&dcDesktop, pBitmap );

    pBitmapDC->BitBlt(0, 0, DesktopSize.cx, DesktopSize.cy, &dcDesktop, 0, 0, SRCCOPY);

	//
	// Cleanup
	//

    dcDesktop.DeleteDC();

	delete pBitmapDC;
}