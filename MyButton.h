#pragma once
#include "afxbutton.h"
#include "BBall.h"
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
	void ChangeBitmap(UINT bitmapResourceID);
	void SetMyFont(int weight, int height, CString font);
	//void SetButtonFontSize(LONG height);
	void SetButtonFontSize(int size);
	void SetButtonFontWeight(int weight);
	void SetButtonFontType(CString type);
	BOOL m_useImage = false;
	//UINT m_imageResourceID = IDB_BUTTON;

protected:
	CFont m_font;
	int fontSize = 14;
	int fontWeight = 400;
	CString fontType = "Segoe UI";

	//void SetButtonFontSize(LONG height);

public:
	afx_msg void OnNcPaint();

};

