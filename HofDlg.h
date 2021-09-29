#if !defined(AFX_HOFDLG_H__345CD640_344A_11D3_8E70_444553540000__INCLUDED_)
#define AFX_HOFDLG_H__345CD640_344A_11D3_8E70_444553540000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#define HID_HISTORY_HALL 35
// HofDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CHofDlg dialog

class CHofDlg : public CDialog
{
// Construction
public:
	CString m_leagueName;
	CString m_path;
	CHofDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CHofDlg)
	enum { IDD = IDD_DIALOG_HALLOFFAME };
	CListBox	m_listHof;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHofDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CHofDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonProfile();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnDblclkListHof();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CString m_names_list[5000];
	CBrush myBrush;
	CBrush myBrush2;
	int m_pointer[5000];
	void ListHofPlayers();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HOFDLG_H__345CD640_344A_11D3_8E70_444553540000__INCLUDED_)
