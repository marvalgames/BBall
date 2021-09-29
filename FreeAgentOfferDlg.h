#pragma once
#include "afxcmn.h"

#ifndef Average_h
//#pragma once
#include "Average.h"
#define Average_h
#endif 

#ifndef XListCtrl_h
#include "XListCtrl.h"
#define XListCtrl_h
#endif 

#ifndef BtnST_h
#include "BtnST.h"
#include "afxwin.h"
#define BtnST_h
#endif


// CFreeAgentOfferDlg dialog

class CFreeAgentOfferDlg : public CDialog
{
	DECLARE_DYNAMIC(CFreeAgentOfferDlg)

public:
	CFreeAgentOfferDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CFreeAgentOfferDlg();

// Dialog Data
	enum { IDD = IDD_DIALOG_CC_FA };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CMyListCtrl m_list_fa;
	CAverage avg;
	afx_msg void OnBnClickedButtonStandard();

private:
	void InitListCtrl();
	void FillStaticCtrl();
	CFont m_font;
	CFont m_font1;
	CBitmap bitmapBkgnd;
	CBrush myBrush;
	CButtonST	m_radio[12];

	// List Current Team Roster (remember FA yes/no column)
	void ListTeam(int list_type);
public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
private:
public:
	afx_msg void OnBnClickedButtonReport();
	afx_msg void OnBnClickedOk();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedButtonWatch();
	afx_msg void OnBnClickedButtonTeam();
	afx_msg void OnNMClickListFa(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButtonOffer();
private:
	// points to index of player on the listctrl
	short m_pointer[128];
};
