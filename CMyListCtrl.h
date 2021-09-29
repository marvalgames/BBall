#pragma once
#include "afxlistctrl.h"
#include "MyHeaderCtrl.h"

class CMyListCtrl : public CMFCListCtrl
{
	virtual COLORREF OnGetCellTextColor(int nRow, int nColum);
	virtual COLORREF OnGetCellBkColor(int nRow, int nColum);
	virtual HFONT OnGetCellFont(int nRow, int nColum, DWORD dwData = 0);
	virtual CMyHeaderCtrl& GetHeaderCtrl(); 
	virtual void InitHeader();
	virtual void PreSubclassWindow();
	virtual int OnCompareItems(LPARAM lParam1, LPARAM lParam2, int iColumn);


protected:
	//virtual BOOL SetBkColor(COLORREF cr);
	//void CMyListCtrl::OnCustomDraw(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	DECLARE_MESSAGE_MAP()

	CMyHeaderCtrl m_myHeaderCtrl;

	CFont m_font;

	public:
	BOOL m_bColor;
	BOOL m_bModifyFont;
	BOOL m_bDescrArea;
	BOOL m_bDotNetLook;
	BOOL m_bHeader;
	BOOL m_bMarkSortedColumn;
	
	BOOL m_bPropListCustomColors;
	BOOL m_bPropListCategorized;
	BOOL m_bShowDragContext;
	BOOL m_bMarkChanged;
	BOOL m_bHideFontProps;

	CMyListCtrl(void);
	~CMyListCtrl(void);


	
};


