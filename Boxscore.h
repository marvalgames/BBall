#if !defined(AFX_BOXSCORE_H__EE530CA0_E520_11D2_8E70_444553540000__INCLUDED_)
#define AFX_BOXSCORE_H__EE530CA0_E520_11D2_8E70_444553540000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define HID_STATS_GAME_PBP 25

// Boxscore.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBoxscore dialog

class CBoxscore : public CDialog
{
// Construction
public:
	CString m_playByPlay[3201];
	CBoxscore(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CBoxscore)
	enum { IDD = IDD_DIALOG_BOXSCORES };
	CListBox	m_listPBP;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBoxscore)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CBoxscore)
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonPrint();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CBrush myBrush;
	CBrush myBrush2;
	void DisplayPBP();
	void SetPrintAlign(CDC *pDC, HDC hdcPrn);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BOXSCORE_H__EE530CA0_E520_11D2_8E70_444553540000__INCLUDED_)
