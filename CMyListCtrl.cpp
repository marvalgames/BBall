#include "stdafx.h"
#include "CMyListCtrl.h"

#include "BBall.h"
//#include "afxlistctrl.h"
//#include "afxbutton.h"
//#include "afxglobaldata.h"
//#include "afxvisualmanager.h"

BEGIN_MESSAGE_MAP(CMyListCtrl, CMFCListCtrl)
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()


CMyHeaderCtrl& CMyListCtrl::GetHeaderCtrl()
{
	return m_myHeaderCtrl;


}


void CMyListCtrl::PreSubclassWindow()
{
	CMFCListCtrl::PreSubclassWindow();
	LOGFONT lf;                        // Used to create the CFont.   
	memset(&lf, 0, sizeof(LOGFONT));   // Clear out structure.              
	lf.lfWeight = 900;
	lf.lfHeight = 11;
	strcpy_s(lf.lfFaceName, "Arial");    //    with face name "Arial"
	m_font.CreateFontIndirect(&lf);    // Create the font.
	SetFont(&m_font);
}


void CMyListCtrl::InitHeader() 
{ // Initialize header control:
		m_myHeaderCtrl.SubclassDlgItem(0, this); 
	
}


COLORREF CMyListCtrl::OnGetCellTextColor(int nRow, int nColum)
{
	if (!m_bColor)
	{
		return CMFCListCtrl::OnGetCellTextColor(nRow, nColum);
	}

	return(nRow % 2) == 0 ? LISTCOLOR1  : LISTCOLOR2;
}

COLORREF CMyListCtrl::OnGetCellBkColor(int nRow, int nColum)
{
	if (!m_bColor)
	{
		return CMFCListCtrl::OnGetCellBkColor(nRow, nColum);
	}

	if (m_bMarkSortedColumn && nColum == m_iSortedColumn)
	{
		//return(nRow % 2) == 0 ? RGB(233, 221, 229) : RGB(176, 218, 234);
		return(nRow % 2) == 0 ? COLCOLOR1 : COLCOLOR2;
	}
		
	return(nRow % 2) == 0 ? ROWCOLOR1 : ROWCOLOR2;
}











HFONT CMyListCtrl::OnGetCellFont(int nRow, int nColum, DWORD /*dwData* = 0*/)
{
//	if (!m_bModifyFont)
	//{
		//return NULL;
	//}

	//if (nColum == 2 &&(nRow >= 4 && nRow <= 8))
	//{
	//	return afxGlobalData.fontDefaultGUIBold;
	//}




//	if (!m_bModifyFont)
//	{
//		return NULL;
//	}

	return FALSE;



}

int CMyListCtrl::OnCompareItems(LPARAM lParam1, LPARAM lParam2, int iColumn)
{
	CString strItem1 = GetItemText((int)(lParam1 < lParam2 ? lParam1 : lParam2), iColumn);
	CString strItem2 = GetItemText((int)(lParam1 < lParam2 ? lParam2 : lParam1), iColumn);

	if (iColumn == 0)
	{
		int nItem1 = _ttoi(strItem1);
		int nItem2 = _ttoi(strItem2);
		return(nItem1 < nItem2 ? -1 : 1);
	}
	else
	{
		int iSort = _tcsicmp(strItem1, strItem2);
		return(iSort);
	}
}


BOOL CMyListCtrl::OnEraseBkgnd(CDC* pDC) 
{
  // TODO: Add your message handler code here

  //       and/or call default


  CRect rect;
  CMyListCtrl::GetClientRect(rect);


  POINT mypoint;  
  
  CBrush brush0(ROWCOLOR1);
  CBrush brush1(ROWCOLOR2);


 
  int chunk_height=GetCountPerPage();
  pDC->FillRect(&rect,&brush1);

  for (int i=0;i<=chunk_height;i++)
  {
    GetItemPosition(i,&mypoint);
    rect.top=mypoint.y ;
    GetItemPosition(i+1,&mypoint);
    rect.bottom =mypoint.y;
    pDC->FillRect(&rect,i %2 ? &brush1 : &brush0);
  }
  brush0.DeleteObject();
  brush1.DeleteObject();


  	
	


  return FALSE;

}



CMyListCtrl::CMyListCtrl(void)
{
	m_bColor = TRUE;
	m_bMarkSortedColumn = TRUE;
}


CMyListCtrl::~CMyListCtrl(void)
{

}


