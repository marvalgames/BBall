// MyBitmap.h: interface for the CMyBitmap class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYBITMAP_H__36771ECB_DB20_41A8_955B_098A0B34757D__INCLUDED_)
#define AFX_MYBITMAP_H__36771ECB_DB20_41A8_955B_098A0B34757D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMyBitmap : public CBitmap  
{
public:
	BOOL LoadBitmap(LPCTSTR szFilename);
	CMyBitmap();
	virtual ~CMyBitmap();

};

#endif // !defined(AFX_MYBITMAP_H__36771ECB_DB20_41A8_955B_098A0B34757D__INCLUDED_)
