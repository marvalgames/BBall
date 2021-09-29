#pragma once

#define OFS_X	10 // distance from left/right side to beginning/end of text
// CTransparentStatic

class CTransparentGroup : public CButton
{
	DECLARE_DYNAMIC(CTransparentGroup)

public:
	CTransparentGroup();
	virtual ~CTransparentGroup();

protected:
   afx_msg LRESULT OnSetText(WPARAM,LPARAM);
   afx_msg HBRUSH CtlColor(CDC* /*pDC*/, UINT /*nCtlColor*/);
   DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};


