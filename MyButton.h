#pragma once
#include "afxbutton.h"
class MyButton :
	public CMFCButton
{
public:
	MyButton(void);
	~MyButton(void);

	//void SetFaceColor(COLORREF crFace, BOOL bRedraw = TRUE);
	CBitmap* m_bmp;
protected:
	afx_msg LRESULT OnSetText(WPARAM wParam,LPARAM lParam);
	DECLARE_MESSAGE_MAP()

	virtual void OnDraw(CDC* pDC, const CRect& rect, UINT uiState);
	virtual void OnDrawParentBackground(CDC* pDC, CRect rectClient);
	virtual void OnFillBackground(CDC* pDC, const CRect& rectClient);
	virtual void OnDrawText(CDC* pDC, const CRect& rect, const CString& strText, UINT uiDTFlags, UINT uiState);
	virtual void OnDrawBorder(CDC* pDC, CRect& rectClient, UINT uiState);
	virtual void OnDrawFocusRect(CDC* pDC, const CRect& rectClient);
	virtual void PreSubclassWindow();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

public:
	void SetMyFont(int weight, int height, CString font);

protected:
	CFont m_font;

public:
	afx_msg void OnNcPaint();
};

