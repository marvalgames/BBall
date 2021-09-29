#pragma once
#include "afxheaderCtrl.h"
class CMyHeaderCtrl : public CMFCHeaderCtrl
{

protected:
	//virtual BOOL SetBkColor(COLORREF cr);
	//void CMyHeaderCtrl::OnCustomDraw(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg HBRUSH CtlColor(CDC* /*pDC*/, UINT /*nCtlColor*/);
	
	virtual void OnFillBackground(CDC* pDC);



	public:
//	virtual void OnFillBackground(CDC* pDC);

	CMyHeaderCtrl(void);
	~CMyHeaderCtrl(void);


	DECLARE_MESSAGE_MAP()

	
};
